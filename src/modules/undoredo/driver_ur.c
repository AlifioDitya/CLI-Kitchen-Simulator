// How to Compile :
// cd to undoredo folder
// gcc driver_ur.c ur.c ../inventory/inventory.c ../time/time.c ../point/point.c ../string/string.c ../word-machine/charmachine.c ../word-machine/wordmachine.c ../prioqueuemakanan/prioqueuemakanan.c ../stack/stack.c ../simulator/simulator.c ../makanan/makanan.c -o driver_ur

#include "ur.h"

// Ini ide cara implement nya

void driverUndo(infotypeStack *New, infotypeStack Old, Stack *Undo, Stack *Redo) {
    Push(Redo, Old);
    Pop(Undo, New);

    printf("\n");
    outputNotification(Old.simul.inv, (*New).simul.inv, Old.pesanan, (*New).pesanan);
    printf("\n");
}

void driverRedo(infotypeStack *New, infotypeStack Old, Stack *Undo, Stack *Redo) {
    Push(Undo, Old);
    Pop(Redo, New);

    printf("\n");
    outputNotification(Old.simul.inv, (*New).simul.inv, Old.pesanan, (*New).pesanan);
    printf("\n");
}

// Setelah itu LoadSave dari New

int main() {
    // KAMUS
    Stack Undo, Redo;
    infotypeStack temp;
    Simulator S;
    PrioQueueMakanan PQ;
    TIME CT, ex, del;
    Makanan m;
    String sname, mname;
    Point P;
    char csname[10] = "Far", cmname[20] = "Ayam Goreng";

    // ALGORITMA
    // Inisiasi Undo Redo
    InitiateURStacks(&Undo, &Redo);

    // Inisiasi Driver (Tidak perlu ketika implementasi Undo Redo)
    createString(csname, 3, &sname);
    CreateSimulation(&S, sname, 1, 1);
    MakeEmptyQueue(&PQ, 100);
    CreateTime(&CT, 0, 0, 0);

    // Membuat contoh makanan
    createString(cmname, 11, &mname);
    CreateTime(&ex, 0, 4, 0);
    CreatePoint(&P, 3, 3);
    CreateTime(&del, 0, 0, 15);
    CreateMakanan(&m, 1, mname, ex, P, del);

    // Contoh Menyimpan State untuk Undo
    Push(&Undo, CreateSave(S, PQ, CT));

    // Melakukan kegiatan, misal advance Time 10 menit
    CreateTime(&CT, 0, 0, 10);
    insertInventory(&S.inv, m);

    printf("State Awal:\n");
    TulisTIME(CT);
    displayInventory(S.inv);

    // Contoh Melakukan Undo dan Menyimpan State untuk Redo
    Push(&Redo, CreateSave(S, PQ, CT));
    Pop(&Undo, &temp);
    LoadSave(temp, &S, &PQ, &CT);

    printf("\nState Setelah Undo:\n");

    printf("\n");
    outputNotification(InfoTop(Redo).simul.inv, S.inv, InfoTop(Redo).pesanan, PQ);
    printf("\n");

    TulisTIME(CT);
    displayInventory(S.inv);

    // Contoh Melakukan Redo dan Menyimpan State untuk Undo
    Push(&Undo, CreateSave(S, PQ, CT));
    Pop(&Redo, &temp);
    LoadSave(temp, &S, &PQ, &CT);

    printf("\nState Setelah Redo:\n");

    printf("\n");
    outputNotification(InfoTop(Undo).simul.inv, S.inv, InfoTop(Undo).pesanan, PQ);
    printf("\n");

    TulisTIME(CT);
    displayInventory(S.inv);
}
