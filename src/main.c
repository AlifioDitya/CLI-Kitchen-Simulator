#include <stdio.h>
#include "./modules/boolean.h"
#include "./modules/menu/menu.h"
// #include "./modules/pengolahan/pengolahan.h"

int main() {
    boolean running = true;
    boolean valid = false;
    String cmd;
    Peta p;
    Simulator s;
    TIME currTime;
    ListStatik Catalog, canBuy, canFry, canChop, canBoil, canMix;
    PrioQueueMakanan pesanan;

    // ALGORITMA
    running = true;
    Initiate(&s, &p, &Catalog);
    CreateTime(&currTime, 0, 0, 0);
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
        printf("Inventory saat ini :\n");
        displayInventory(Inv(s));
        printf("\n");
        printf("BNMO di posisi: ");
        TulisPoint(Loc(s));
        printf("Waktu: ");
        TulisTIME(currTime);
        printf("\n");
        displayPeta(p);
        printf("\n");
        inputCommand(&cmd);

        if (isExit(cmd)) {
            running = false;
            printf("Goodbye!");
        } else if (isBuy(cmd)) {
            // Buy(&s, &currTime, &cmd, &pesanan, p, canBuy);
        } else if (isFry(cmd)) {
            printf("Frying here!\n");
            AdvMinute(&currTime);
        } else if (isChop(cmd)) {
            printf("Chopping here!\n");
            AdvMinute(&currTime);
        } else if (isBoil(cmd)) {
            printf("Boiling here!\n");
            AdvMinute(&currTime);
        } else if (isMix(cmd)) {
            printf("Mixing here!\n");
            AdvMinute(&currTime);
        } else if (isMoveEast(cmd)) {
            if (canMoveEast(s, p)) {
                moveEast(&s, &p);
                progressTime(&s, &pesanan, &currTime);
            } else {
                printf("Tidak bisa bergerak ke timur!\n");
            }
        } else if (isMoveWest(cmd)) {
            if (canMoveWest(s, p)) {
                moveWest(&s, &p);
                progressTime(&s, &pesanan, &currTime);
            } else {
                printf("Tidak bisa bergerak ke barat!\n");
            }
        } else if (isMoveNorth(cmd)) {
            if (canMoveNorth(s, p)) {
                moveNorth(&s, &p);
                progressTime(&s, &pesanan, &currTime);
            } else {
                printf("Tidak bisa bergerak ke utara!\n");
            }
        } else if (isMoveSouth(cmd)) {
            if (canMoveSouth(s, p)) {
                moveSouth(&s, &p);
                progressTime(&s, &pesanan, &currTime);
            } else {
                printf("Tidak bisa bergerak ke selatan!\n");
            }
        } else {
            printf("Command tidak valid.\n");
        }
        printf("\n");
    }
}
