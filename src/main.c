#include <stdio.h>
#include "./modules/boolean.h"
#include "./util/util.c"

int main() {
    int running = true;
    Word cmd;
    Peta p;
    Simulator s;
    TIME currentTime;
    ListStatik Catalog;

    Initiate(&s, &p, &Catalog);

    if (isExit(cmd)) {
        running = false;
        printf("Goodbye!\n");
    } else if (isStart(cmd)) {
        running = true;
    }

    while (running) {
        printf("BNMO di posisi: ");
        TulisPoint(Loc(s));
        printf("\n");
        displayPeta(p);
        printf("\n");
        inputCommand(&cmd);

        if (isExit(cmd)) {
            running = false;
            printf("Goodbye!\n");
        } else if (isBuy(cmd)) {
            printf("Buying here!\n");
        } else if (isFry(cmd)) {
            printf("Frying here!\n");
        } else if (isChop(cmd)) {
            printf("Chopping here!\n");
        } else if (isBoil(cmd)) {
            printf("Boiling here!\n");
        } else if (isMix(cmd)) {
            printf("Mixing here!\n");
        } else {
            printf("Command tidak valid.\n");
        }

        printf("\n");
    }
}