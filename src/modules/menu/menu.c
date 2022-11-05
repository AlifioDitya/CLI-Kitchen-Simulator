#include <stdio.h>
#include "menu.h"

boolean isExit(String s) {
    String temp;
    createString("EXIT", 4, &temp);
    return (isStringEqual(s, temp));
}

boolean isStart(String s) {
    String temp;
    createString("START", 5, &temp);
    return (isStringEqual(s, temp));
}

void Splash(String name) {
    printf("  ;)( ;\n");
    printf(" :----:     o8Oo./\n");
    printf("C|====| ._o8o8o8Oo_.\n");
    printf(" |    |  \\========/\n");
    printf(" `----'   `------'\n");
    printf("\n");
    printf("Welcome to BNMO, ");
    printString(name);
    printf("!\n");
}

void Initiate(Simulator *s, Peta *p, ListStatik *catalog) {
    char* petaFileName = "src/data/map.txt";
    char* makananFileName = "src/data/makanan.txt";
    String name;

    readPeta(petaFileName, p);
    printf("\n");

    printf("Enter your name: ");
    startString();
    assignString(currentString, &name);
    printf("\n");

    // while (currentString.Length == 0) {
    //     printf("Nama tidak boleh kosong!\n\n");
    //     printf("Enter your name: ");
    //     startString();
    //     assignString(currentString, &name);
    // }


    CreateSimulation(s, name, Absis(Locate(*p, 'S')), Ordinat(Locate(*p, 'S')));

    Splash(name);

    CreateListStatik(catalog);
    readMakanan(makananFileName, *p, catalog);
    printf("Catalog = ");
    printListMakanan(*catalog);
    printf("\n");
}

void inputCommand(String *cmd) {
    printf("Enter command : ");
    startString();
    assignString(currentString, cmd);
    printf("\n");
}

boolean isMoveEast(String s) {
    int i;
    char* command = "MOVE EAST";
    int len = 9;
    if (len == s.Length) {
        for (i=0; i<s.Length; i++) {
            if (s.str[i] != command[i]) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

boolean isMoveWest(String s) {
    int i;
    char* command = "MOVE WEST";
    int len = 9;
    if (len == s.Length) {
        for (i=0; i<s.Length; i++) {
            if (s.str[i] != command[i]) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

boolean isMoveNorth(String s) {
    int i;
    char* command = "MOVE NORTH";
    int len = 10;
    if (len == s.Length) {
        for (i=0; i<s.Length; i++) {
            if (s.str[i] != command[i]) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

boolean isMoveSouth(String s) {
    int i;
    char* command = "MOVE SOUTH";
    int len = 10;
    if (len == s.Length) {
        for (i=0; i<s.Length; i++) {
            if (s.str[i] != command[i]) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}