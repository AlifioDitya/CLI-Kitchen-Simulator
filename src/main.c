#include <stdio.h>
#include "./modules/boolean.h"
#include "./modules/menu/menu.h"
#include "./modules/resep/tree.h"
#include "./modules/pengolahan/pengolahan.h"
#include "./modules/menu/command.h"
#include "./modules/menu/timemechanism.h"
#include "./modules/undoredo/ur.h"

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
    Stack Undo, Redo;
    ElType tempPeta;
    infotypeStack NewSave, Last;

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
    InitiateURStacks(&Undo, &Redo);

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

    Last = CreateSave(s, pesanan, currTime);

    while (running) {
        printf("BNMO di posisi: ");
        TulisPoint(Loc(s));
        printf("Waktu: ");
        TulisTIME(currTime);
        outputNotification(Last.simul.inv, s.inv, Last.pesanan, pesanan);
        printf("\n");
        displayPeta(p);
        printf("\n");
        inputCommand(&cmd);
        commandValid = true;

        Last = CreateSave(s, pesanan, currTime);

        if (isExit(cmd)) {
            running = false;
            printf("Goodbye!");
        } else if (isBuy(cmd)) {
            Push(&Undo, CreateSave(s, pesanan, currTime));
            Buy(&s, &currTime, &cmd, &pesanan, p, canBuy);
        } else if (isFry(cmd)) {
            if (isObjectInRadius(s, p, 'F')) {
                Push(&Undo, CreateSave(s, pesanan, currTime));
                fry(Catalog, cmd, p, &s, resep, currTime, pesanan);
            } else {
                printf("BNMO tidak berada di area F!\n");
            }
        } else if (isChop(cmd)) {
            if (isObjectInRadius(s, p, 'C')) {
                Push(&Undo, CreateSave(s, pesanan, currTime));
                chop(Catalog, cmd, p, &s, resep, currTime, pesanan);
            } else {
                printf("BNMO tidak berada di area C!\n");
            }
        } else if (isBoil(cmd)) {
            if (isObjectInRadius(s, p, 'B')) {
                Push(&Undo, CreateSave(s, pesanan, currTime));
                Boil(Catalog, cmd, p, &s, resep, currTime, pesanan);
            } else {
                printf("BNMO tidak berada di area B!\n");
            }
        } else if (isMix(cmd)) {
            if (isObjectInRadius(s, p, 'M')) {
                Push(&Undo, CreateSave(s, pesanan, currTime));
                mix(Catalog, cmd, p, &s, resep, currTime, pesanan);
            } else {
                printf("BNMO tidak berada di area M!\n");
            }
        } else if (isMoveEast(cmd)) {
            if (canMoveEast(s, p)) {
                Push(&Undo, CreateSave(s, pesanan, currTime));
                moveEast(&s, &p);
                progressTime(&s, &pesanan, &currTime);
            } else {
                printf("Tidak bisa bergerak ke timur!\n");
            }
        } else if (isMoveWest(cmd)) {
            if (canMoveWest(s, p)) {
                Push(&Undo, CreateSave(s, pesanan, currTime));
                moveWest(&s, &p);
                progressTime(&s, &pesanan, &currTime);
            } else {
                printf("Tidak bisa bergerak ke barat!\n");
            }
        } else if (isMoveNorth(cmd)) {
            if (canMoveNorth(s, p)) {
                Push(&Undo, CreateSave(s, pesanan, currTime));
                moveNorth(&s, &p);
                progressTime(&s, &pesanan, &currTime);
            } else {
                printf("Tidak bisa bergerak ke utara!\n");
            }
        } else if (isMoveSouth(cmd)) {
            if (canMoveSouth(s, p)) {
                Push(&Undo, CreateSave(s, pesanan, currTime));
                moveSouth(&s, &p);
                progressTime(&s, &pesanan, &currTime);
            } else {
                printf("Tidak bisa bergerak ke selatan!\n");
            }
        } else if (isWait(cmd)) {
            Push(&Undo, CreateSave(s, pesanan, currTime));

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
        } else if (isUndo(cmd)) {
            if (IsEmpty(Undo)) {
                printf("Tidak bisa melakukan Undo\n");
            } else {
                Push(&Redo, CreateSave(s, pesanan, currTime));
                Pop(&Undo, &NewSave);
                LoadSave(NewSave, &s, &pesanan, &currTime);
                // TulisPoint(InfoTop(Redo).simul.loc);
                // TulisPoint(s.loc);
                tempPeta = ELMT(p, Ordinat(InfoTop(Redo).simul.loc), Absis(InfoTop(Redo).simul.loc));
                ELMT(p, Ordinat(InfoTop(Redo).simul.loc), Absis(InfoTop(Redo).simul.loc)) = ELMT(p, Ordinat(s.loc), Absis(s.loc));
                ELMT(p, Ordinat(s.loc), Absis(s.loc)) = tempPeta;
            }
        } else if (isRedo(cmd)) {
            if (IsEmpty(Redo)) {
                printf("Tidak bisa melakukan Redo\n");
            } else {
                Push(&Undo, CreateSave(s, pesanan, currTime));
                Pop(&Redo, &NewSave);
                LoadSave(NewSave, &s, &pesanan, &currTime);
                tempPeta = ELMT(p, Ordinat(InfoTop(Undo).simul.loc), Absis(InfoTop(Undo).simul.loc));
                ELMT(p, Ordinat(InfoTop(Undo).simul.loc), Absis(InfoTop(Undo).simul.loc)) = ELMT(p, Ordinat(s.loc), Absis(s.loc));
                ELMT(p, Ordinat(s.loc), Absis(s.loc)) = tempPeta;
            }
        } else {
            commandValid = false;
            printf("Command tidak valid.\n");
        }

        if (commandValid && !isUndo(cmd) && !isRedo(cmd)) {
            CreateEmpty(&Redo);
        }

        printf("\n");
    }
}
