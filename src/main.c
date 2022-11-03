#include <stdio.h>
#include "./modules/boolean.h"
#include "./util/util.h"

int main() {
    boolean running = true;
    boolean valid;
    Word cmd;
    Peta p;
    Simulator s;
    TIME progTime;
    ListStatik Catalog;

    // ALGORITMA
    running = true;
    Initiate(&s, &p, &Catalog);
    CreateTime(&progTime, 0, 0, 0);

    valid = false;
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
        valid = true;
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
            printf("Buying here!\n");
        } else if (isFry(cmd)) {
            boolean frying = true;
            while (frying) {
                printf("======================\n");
                printf("=        FRY         =\n");
                printf("======================\n");
                printf("List bahan makanan yang bisa digoreng:\n");
                // Print list here
                printf("\n");
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

            printf("Frying here!\n");
        } else if (isChop(cmd)) {
            printf("Chopping here!\n");
            if (valid) {
                 AdvTime(&progTime);
            }
        } else if (isBoil(cmd)) {
            printf("Boiling here!\n");
            if (valid) {
                 AdvTime(&progTime);
            }
        } else if (isMix(cmd)) {
            printf("Mixing here!\n");
            if (valid) {
                 AdvTime(&progTime);
            }
        } else {
            printf("Command tidak valid.\n");
        }
        printf("\n");
    }
}