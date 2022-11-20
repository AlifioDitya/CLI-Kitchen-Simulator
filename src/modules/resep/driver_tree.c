#include "tree.h"
#include "../pengolahan/pengolahan.h"
#include "../makanan/makanan.h"
#include "../string/string.h"
#include "../liststatik/liststatik.h"
#include "../pengolahan/pengolahan.h"
#include "../menu/menu.h"

void fry_test(ListStatik katalog, String cmd, Peta map, Simulator *s, BinTree resep, TIME *currTime, PrioQueueMakanan *pesanan){
    ListStatik Goreng, unHave;
    ListIDBahan bahan;
    Makanan val;

    int target;
    AddressTree p;
    printf("======================\n");
    printf("=      FRY_TEST      =\n");
    printf("======================\n");
    CreateListStatik(&Goreng);
    CreateListBahan(&bahan);
    Goreng = katalogByProses(katalog, cmd, map);
    displayKatalogProses(Goreng);
    printf("\n");
    printf("Kirim 0 untuk exit\n");
    printf("\n");
    inputCommand(&cmd);

    while (!isCommandInteger(cmd)) {
        printf("\n");
        printf("Command tidak valid.\n");
        printf("\n");
        inputCommand(&cmd);
    }

    target = parseToInteger(cmd);
    while(target != 0){
        if(target >= 0 && target <= listLength(Goreng)){
            p = searchByID(ID(Elmt(Goreng,(target-1))), resep);
            bahan = listBahan(p);
            if(isCookable(bahan, Inv(*s), katalog)){
                for(int i = 0; i<lengthListBahan(bahan); i++){
                    deleteAtInventory(&Inv(*s), indexOfInventory(Inv(*s), getFoodByID(ELMTLB(bahan,i), katalog)), &val);
                }
                insertInventory(&Inv(*s), Elmt(Goreng, (target-1)));
                printString(FoodName(Elmt(Goreng, target-1)));
                printf(" berhasil dibuat dan sudah dimasukkan di inventory\n");
                progressTime(s, pesanan, currTime);
            }
            else{
                CreateListStatik(&unHave);
                unHave = TidakDimiliki(Inv(*s), bahan, katalog);
                printf("Gagal membuat ");
                printString(FoodName(Elmt(Goreng, target-1)));
                printf(" karena tidak memiliki bahan berikut : \n");
                for(int i = 0; i<listLength(unHave); i++){
                    printf("%d. ", (i+1));
                    printString(FoodName(Elmt(unHave,i)));
                    printf("\n");
                }
            }
        }
        else{
            printf("Target tidak valid!\n");
        }
        printf("\n");
        inputCommand(&cmd);
        while (!isCommandInteger(cmd)) {
            printf("\n");
            printf("Command tidak valid.\n");
            printf("\n");
            inputCommand(&cmd);
        }
        target = parseToInteger(cmd);
    }
}

int main() {
    boolean running = true;
    boolean valid = false;
    boolean commandValid;
    String cmd, mode;
    BinTree resep;
    Peta p;
    Simulator s;
    TIME currTime;
    ListStatik Catalog, canBuy, canFry, canChop, canBoil, canMix;
    PrioQueueMakanan pesanan;
    ElType tempPeta;

    // ALGORITMA
    running = true;
    Initiate(&s, &p, &Catalog, &resep);
    CreateTime(&currTime, 0, 0, 0);
    createString("BUY", 3, &mode);
    createSpecificCatalog(&canBuy, Catalog, p, mode);
    createString("FRY", 3, &mode);
    createSpecificCatalog(&canFry, Catalog, p, mode);
    createString("CHOP", 4, &mode);
    createSpecificCatalog(&canChop, Catalog, p, mode);
    createString("BOIL", 4, &mode);
    createSpecificCatalog(&canBoil, Catalog, p, mode);
    createString("MIX", 3, &mode);
    createSpecificCatalog(&canMix, Catalog, p, mode);
    MakeEmptyQueue(&pesanan, 100);

    inputCommand(&cmd);
    while (!valid) {
        if (isExit(cmd)) {
            running = false;
            valid = true;
            printf("Goodbye!\n");
        } else if (isStart(cmd)) {
            running = true;
            valid = true;
        } else {
            printf("Command tidak valid.\n");
            printf("\n");
            inputCommand(&cmd);
        }
    }

    while (running) {
        printf("BNMO di posisi: ");
        TulisPoint(Loc(s));
        printf("Waktu: ");
        TulisTIME(currTime);
        // outputNotification(Last.simul.inv, s.inv, Last.pesanan, pesanan);
        printf("\n");
        inputCommand(&cmd);
        commandValid = true;

        // Last = CreateSave(s, pesanan, currTime);

        if (isExit(cmd)) {
            running = false;
            printf("Goodbye!");
        } else if (isFry(cmd)) {
            printf("COOKBOOK: \n");
            printListResep(p, Catalog);
            printf("\n");
            fry_test(Catalog, cmd, p, &s, resep, &currTime, &pesanan);
        } else {
            commandValid = false;
            printf("Command tidak valid.\n");
        }
    return 0;
    }   
}