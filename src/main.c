#include <stdio.h>
#include "./modules/boolean.h"
<<<<<<< HEAD
#include "./modules/menu/menu.c"
#include "./modules/pengolahan makanan/pengolahan.c"
=======
#include "./modules/menu/menu.h"
>>>>>>> 05f38de1a7f63097594c3d743b1be96469ff09dc

int main() {
    boolean running = true;
    boolean valid = false;
    String cmd;
    Peta p;
    Simulator s;
    TIME progTime;
    ListStatik Catalog, canBuy, canFry, canChop, canBoil, canMix;
    PrioQueueMakanan pesanan;

    // ALGORITMA
    running = true;
    Initiate(&s, &p, &Catalog);
    CreateTime(&progTime, 0, 0, 0);
    CreateListBuyMakanan(&canBuy, Catalog, p);
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
        printf("Pesanan yang ada :\n");
        PrintPrioQueueMakanan(pesanan);
        printf("\n");
        printf("BNMO di posisi: ");
        TulisPoint(Loc(s));
        printf("Waktu: ");
        TulisTIME(progTime);
        printf("\n");
        displayPeta(p);
        printf("\n");
        inputCommand(&cmd);

        if (isExit(cmd)) {
            running = false;
            printf("Goodbye!");
        } else if (isBuy(cmd)) {
            Buy(&s, &progTime, &cmd, &pesanan, p, canBuy);
        } else if (isFry(cmd)) {
<<<<<<< HEAD
            boolean frying = true;
            ListStatik Goreng;
            while (frying) {
                printf("======================\n");
                printf("=        FRY         =\n");
                printf("======================\n");
                printf("List bahan makanan yang bisa digoreng:\n");
                // Print list here
                printf("Kirim 0 untuk Exit\n\n");
                inputCommand(&cmd);

                Word temp;
                createWord("0", 1, &temp);
                if (isWordEqual(cmd, temp)) {
                    frying = false;
                } else {
                    printf("Command tidak valid.\n");
                    valid = false;
                }

                if (valid) {
                    AdvTime(&progTime);
                }
            }

=======
>>>>>>> 05f38de1a7f63097594c3d743b1be96469ff09dc
            printf("Frying here!\n");
            AdvMinute(&progTime);
        } else if (isChop(cmd)) {
            printf("Chopping here!\n");
            AdvMinute(&progTime);
        } else if (isBoil(cmd)) {
            printf("Boiling here!\n");
<<<<<<< HEAD
            Boil();
            // if (valid) {
            //      AdvTime(&progTime);
            // }
=======
            AdvMinute(&progTime);
>>>>>>> 05f38de1a7f63097594c3d743b1be96469ff09dc
        } else if (isMix(cmd)) {
            printf("Mixing here!\n");
            AdvMinute(&progTime);
        } else if (isMoveEast(cmd)) {
            if (canMoveEast(s, p)) {
                moveEast(&s, &p);
                AdvMinute(&progTime);
                DecDeliveryTimeQueue(&pesanan);
            } else {
                printf("Tidak bisa bergerak ke timur!\n");
            }
        } else if (isMoveWest(cmd)) {
            if (canMoveWest(s, p)) {
                moveWest(&s, &p);
                AdvMinute(&progTime);
                DecDeliveryTimeQueue(&pesanan);
            } else {
                printf("Tidak bisa bergerak ke barat!\n");
            }
        } else if (isMoveNorth(cmd)) {
            if (canMoveNorth(s, p)) {
                moveNorth(&s, &p);
                AdvMinute(&progTime);
                DecDeliveryTimeQueue(&pesanan);
            } else {
                printf("Tidak bisa bergerak ke utara!\n");
            }
        } else if (isMoveSouth(cmd)) {
            if (canMoveSouth(s, p)) {
                moveSouth(&s, &p);
                AdvMinute(&progTime);
                DecDeliveryTimeQueue(&pesanan);
            } else {
                printf("Tidak bisa bergerak ke selatan!\n");
            }
        } else {
            printf("Command tidak valid.\n");
        }
        printf("\n");
    }
}
