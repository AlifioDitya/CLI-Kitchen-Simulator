#include <stdio.h>
#include "../modules/peta/peta.c"
// #include "../modules/boolean.h"
// #include "../modules/simulator/simulator.c"
// #include "../modules/string/string.c"

boolean isExit() {
    if (currentWord.Length == 4 && currentWord.TabWord[0] == 'E' && currentWord.TabWord[1] == 'X' && currentWord.TabWord[2] == 'I' && currentWord.TabWord[3] == 'T') {
        return true;
    } else {
        return false;
    }
}

boolean isStart() {
    if (currentWord.Length == 5 && currentWord.TabWord[0] == 'S' && currentWord.TabWord[1] == 'T' && currentWord.TabWord[2] == 'A' && currentWord.TabWord[3] == 'R' && currentWord.TabWord[4] == 'T') {
        return true;
    } else {
        return false;
    }
}

void Splash() {
    printf("  ;)( ;\n");
    printf(" :----:     o8Oo./\n");
    printf("C|====| ._o8o8o8Oo_.\n");
    printf(" |    |  \\========/\n");
    printf(" `----'   `------'\n");
    printf("\n");
    printf("Welcome to BNMO!");
}

void Initiate(Simulator *s, Peta *p) {

    printf("Enter your name: ");
    startString();
    // STARTWORD();
    printf("\n");

    for (int i=0; i<currentString.Length; i++) {
        printf("%c", currentString.str[i]);
    }
    printf("\n");

    CreateSimulation(s, currentString, POINT_UNDEF, POINT_UNDEF);
    readPeta("C:/Users/Alifio/Kuliah/Semester 3/Algoritma dan Struktur Data/Tubes/Tubes-Alstrukdat-D/src/data/map.txt", p, s);  // User location is assigned here
    printf("\n");
}

void inputCommand() {
    printf("Enter command : ");
    STARTWORD();
    printf("\n");
}

