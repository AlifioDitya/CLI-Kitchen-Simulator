/* Implementasi Undo dan Redo */

#include "ur.h"

void InitiateURStacks(Stack *U, Stack *R) {
    // Membuat 2 Stack untuk Undo dan Redo

    // KAMUS

    // ALGORITMA
    CreateEmpty(U);
    CreateEmpty(R);
}

infotypeStack CreateSave(Simulator S, PrioQueueMakanan PQ, TIME CT) {
    // Membuat sebuah save kondisi program disuatu waktu

    // KAMUS
    infotypeStack SS;
    int i;
    boolean cnt;
    Address p;

    // ALGORITMA
    // Mensave Current Time
    CreateTime(&SS.currentTime, CT.D, CT.H, CT.M);

    // Mensave List Pesanan saat ini
    MakeEmptyQueue(&SS.pesanan, PQ.MaxEl);

    if (!IsEmptyQueue(PQ)) {
        i = Head(PQ);
        cnt = true;

        while (cnt) {
            if (i == Tail(PQ)) {
                cnt = false;
            }

            Enqueue(&SS.pesanan, PQ.T[i]);
            
            i = (i + 1) % MaxEl(PQ);
        }
    }

    // Mensave Kondisi Simulator saat ini
    CreateInventory(&SS.simul.inv);

    for (i = 0; i < LengthInventory(S.inv); i++) {
        if (i == 0) {
            p = FIRST(S.inv);
        } else {
            p = NEXT(p);
        }

        insertInventory(&SS.simul.inv, INFO(p));
    }

    CreatePoint(&SS.simul.loc, S.loc.X, S.loc.Y);

    assignString(S.name, &SS.simul.name);

    return SS;
}

void outputNotification(Inventory OldInv, Inventory NewInv, PrioQueueMakanan OldPQ, PrioQueueMakanan NewPQ) {
    // Mengeluarkan Notifikasi setelah Undo/Redo

    // KAMUS
    int i, j, idxBool, idxNotif;
    boolean found, cont;
    boolean doneInv[LengthInventory(OldInv)], donePQ[NBElmtQueue(OldPQ)];
    Address p1, p2;

    // ALGORITMA
    printf("Notifikasi:\n");
    idxNotif = 1;

    // Inisiasi Array Boolean
    for (i = 0; i < LengthInventory(OldInv); i++) {
        doneInv[i] = false;
    }

    for (i = 0; i < NBElmtQueue(OldPQ); i++) {
        donePQ[i] = false;
    }
    
    // Mengecek Ketidaksamaan Inventory
    for (i = 0; i < LengthInventory(NewInv); i++) {
        // Indeks New Inventory
        if (i == 0) {
            p1 = FIRST(NewInv);
        } else {
            p1 = NEXT(p1);
        }

        // Mencari Makanan di Old Inventory yang Ekivalen dengan Makanan yang berada di New Inventory
        found = false;
        idxBool = 0;
        for (j = 0; j < LengthInventory(OldInv); j++) {
            if (j == 0) {
                p2 = FIRST(OldInv);
            } else {
                p2 = NEXT(p2);
            }

            if (isStringEqual(INFO(p1).name, INFO(p2).name)) {
                // Buat Menghindari Kasus Makanan dihitung 2x
                if (doneInv[idxBool]) {
                    continue;
                } else {
                    doneInv[idxBool] = true;
                    found = true;
                    break;
                }
            }

            idxBool++;
        }

        if (!found) {
            printf("%d. ", idxNotif);
            idxNotif++;
            printString(INFO(p1).name);
            printf(" telah dimasukkan ke dalam inventory.\n");
        }
    }

    for (i = 0; i < LengthInventory(OldInv); i++) {
        if (i == 0) {
            p1 = FIRST(OldInv);
        } else {
            p1 = NEXT(p1);
        }

        if (!doneInv[i]) {
            printf("%d. ", idxNotif);
            idxNotif++;
            printString(INFO(p1).name);
            printf(" telah dikeluarkan dari inventory.\n");
        }
    }

    if (idxNotif == 1) {
        printf("-\n");
    }
}

void LoadSave(infotypeStack Saved, Simulator *S, PrioQueueMakanan *PQ, TIME *CT) {
    // Menload Save yang tersimpan

    // KAMUS
    int i;
    boolean cnt;
    Address p;

    // ALGORITMA
    // Load Current Time
    CreateTime(CT, Saved.currentTime.D, Saved.currentTime.H, Saved.currentTime.M);
    
    // Load Antrian Pesanan
    MakeEmptyQueue(PQ, Saved.pesanan.MaxEl);

    if (!IsEmptyQueue(Saved.pesanan)) {
        i = Head(Saved.pesanan);
        cnt = true;

        while (cnt) {
            if (i == Tail(Saved.pesanan)) {
                cnt = false;
            }

            Enqueue(PQ, Saved.pesanan.T[i]);
            
            i = (i + 1) % MaxEl(Saved.pesanan);
        }
    }

    // Load Simulator
    CreateInventory(&((*S).inv));

    for (i = 0; i < LengthInventory(Saved.simul.inv); i++) {
        if (i == 0) {
            p = FIRST(Saved.simul.inv);
        } else {
            p = NEXT(p);
        }

        insertInventory(&((*S).inv), INFO(p));
    }

    CreatePoint(&((*S).loc), Saved.simul.loc.X, Saved.simul.loc.Y);

    assignString(Saved.simul.name, &((*S).name));
}
