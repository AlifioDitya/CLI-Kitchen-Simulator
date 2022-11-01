#include <stdio.h>
#include "../modules/makanan/makanan.c"
// #include "../modules/peta/peta.c"
// #include "../modules/time/time.c"
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

void Initiate(Simulator *s, Peta *p, ListStatik *catalog) {
    char* petaFileName = "src/data/map.txt";
    char* makananFileName = "src/data/makanan.txt";
    String name;

    readPeta(petaFileName, p);
    printf("\n");

    printf("Enter your name: ");
    // STARTWORD();
    startString();
    assignString(currentString, &name);
    // ForceTerminate();
    printf("\n");

    // while (currentString.Length == 0) {
    //     printf("Nama tidak boleh kosong!\n\n");
    //     printf("Enter your name: ");
    //     startString();
    //     assignString(currentString, &name);
    // }

    CreateSimulation(s, name, Absis(Locate(*p, 'S')), Ordinat(Locate(*p, 'S')));
    displayPeta(*p);
    printf("Nama: ");
    printString(Name(*s));
    printf("Posisi user: ");
    TulisPoint(Locate(*p, 'S'));
    printf("\n");
    printf("Absis: %d\n", Absis(Locate(*p, 'S')));
    printf("Ordinat: %d\n", Ordinat(Locate(*p, 'S')));
    printf("\n");

    CreateListStatik(catalog);
    readMakanan(makananFileName, *p, catalog);
    printf("\n");

}

void inputCommand() {
    printf("Enter command : ");
    STARTWORD();
    printf("\n");
}

