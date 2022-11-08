#include <stdio.h>
#include "./modules/boolean.h"
#include "./modules/menu/menu.h"

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
            printf("Frying here!\n");
            AdvMinute(&progTime);
        } else if (isChop(cmd)) {
            printf("Chopping here!\n");
            AdvMinute(&progTime);
        } else if (isBoil(cmd)) {
            printf("Boiling here!\n");
            AdvMinute(&progTime);
        } else if (isMix(cmd)) {
            printf("Mixing here!\n");
            AdvMinute(&progTime);
        } else if (isMoveEast(cmd)) {
            if (canMoveEast(s, p)) {
                moveEast(&s, &p);
                AdvMinute(&progTime);
            } else {
                printf("Tidak bisa bergerak ke timur!\n");
            }
        } else if (isMoveWest(cmd)) {
            if (canMoveWest(s, p)) {
                moveWest(&s, &p);
                AdvMinute(&progTime);
            } else {
                printf("Tidak bisa bergerak ke barat!\n");
            }
        } else if (isMoveNorth(cmd)) {
            if (canMoveNorth(s, p)) {
                moveNorth(&s, &p);
                AdvMinute(&progTime);
            } else {
                printf("Tidak bisa bergerak ke utara!\n");
            }
        } else if (isMoveSouth(cmd)) {
            if (canMoveSouth(s, p)) {
                moveSouth(&s, &p);
                AdvMinute(&progTime);
            } else {
                printf("Tidak bisa bergerak ke selatan!\n");
            }
        } else {
            printf("Command tidak valid.\n");
        }
        printf("\n");
    }
}
