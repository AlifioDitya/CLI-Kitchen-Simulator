#include <stdio.h>
#include "pengolahan.h"


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
        printf("\n");
        displayPeta(p);
        printf("\n");
        inputCommand(&cmd);
        commandValid = true;


        if (isExit(cmd)) {
            running = false;
            printf("Goodbye!");
        } else if (isBuy(cmd)) {
            Buy(&s, &currTime, &cmd, &pesanan, p, canBuy);
        } else if (isFry(cmd)) {
            if (isObjectInRadius(s, p, 'F')) {
                fry(Catalog, cmd, p, &s, resep, &currTime, &pesanan);
            } else {
                printf("BNMO tidak berada di area F!\n");
            }
        } else if (isChop(cmd)) {
            if (isObjectInRadius(s, p, 'C')) {
                chop(Catalog, cmd, p, &s, resep, &currTime, &pesanan);
            } else {
                printf("BNMO tidak berada di area C!\n");
            }
        } else if (isBoil(cmd)) {
            if (isObjectInRadius(s, p, 'B')) {
                Boil(Catalog, cmd, p, &s, resep, &currTime, &pesanan);
            } else {
                printf("BNMO tidak berada di area B!\n");
            }
        } else if (isMix(cmd)) {
            if (isObjectInRadius(s, p, 'M')) {
                mix(Catalog, cmd, p, &s, resep, &currTime, &pesanan);
            } else {
                printf("BNMO tidak berada di area M!\n");
            }
        } else if (isCookBook(cmd)) {
            printListResep(p, Catalog);
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
        } else if (isWait(cmd)) {

            int i = 0;
            
            while (currentString.str[i] != ' ') {
                i++;
            }
            
            int jam = 0;
            i++;
            while (currentString.str[i] != ' ') {
                jam = 10 * jam + (currentString.str[i] - '0');
                i++;
            }

            int menit = 0;
            i++;
            while (i < currentString.Length) {
                menit = 10 * menit + (currentString.str[i] - '0');
                i++;
            }

            wait(&s, &pesanan, &currTime, jam, menit);
        } else if (isCatalog(cmd)) {
            displayCatalog(Catalog, p);
        } else if (isDisplayInventory(cmd)) {
            displayInventory(Inv(s));
        } else if (isDisplayDelivery(cmd)) {
            PrintPrioQueueMakanan(pesanan);
        } else {
            commandValid = false;
            printf("Command tidak valid.\n");
        }


        printf("\n");
    }
}
