/* Implementasi driver ada pada program utama main.c */

#include <stdio.h>
#include "menu.h"
#include "../resep/tree.h"
#include "command.h"
#include "timemechanism.h"

void Splash(String name) {
// I.S Tampilan sembarang
// F.S Tampilan berupa splash screen
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

void Initiate(Simulator *s, Peta *p, ListStatik *catalog, BinTree *resep) {
// I.S Data terdefinisi dan valid
// F.S Data loaded ke dalam program
    char* petaFileName = "src/data/map.txt";
    char* makananFileName = "src/data/makanan.txt";
    char* resepFileName = "src/data/Recipe.txt";
    
    String name;
    
    readPeta(petaFileName, p);
    readResep(resepFileName, resep);
    
    printf("Enter your name: ");
    startString();
    assignString(currentString, &name);
    printf("\n");

    CreateSimulation(s, name, Absis(Locate(*p, 'S')), Ordinat(Locate(*p, 'S')));

    Splash(name);

    CreateListStatik(catalog);
    readMakanan(makananFileName, *p, catalog);
    printf("\n");
}

void printBuyMakanan(ListStatik canBuy) {
// I.S List makanan yang bisa dibeli terdefinisi
// F.S Makanan yang bisa dibeli ditampilkan
    int i;
    int ctr = 1;
    for (i=0; i<canBuy.nEff; i++) {
        printf("%d. ", ctr);
        printString(FoodName(Elmt(canBuy, i)));
        printf(" (");
        if (Day(DeliveryTime(Elmt(canBuy, i))) != 0) {
            printf("%d Hari", Day(DeliveryTime(Elmt(canBuy, i))));
            if (Hour(DeliveryTime(Elmt(canBuy, i))) != 0 && Minute(DeliveryTime(Elmt(canBuy, i))) != 0) {
                printf(", ");
            }
        }
        if (Hour(DeliveryTime(Elmt(canBuy, i))) != 0) {
            printf("%d Jam", Hour(DeliveryTime(Elmt(canBuy, i))));
            if (Minute(DeliveryTime(Elmt(canBuy, i))) != 0) {
                printf(", ");
            }
        }
        if (Minute(DeliveryTime(Elmt(canBuy, i))) != 0) {
            printf("%d Menit", Minute(DeliveryTime(Elmt(canBuy, i))));
        }
        printf(")\n");
        ctr++;
    }
}

void Buy(Simulator *s, TIME *currTIME, String *cmd, PrioQueueMakanan *prioQueue, Peta p, ListStatik canBuy) {
// I.S List makanan yang bisa dibeli terdefinisi
// F.S Makanan dipesan
    if (isObjectInRadius(*s, p, 'T')) {
        boolean buying = true;
        int select;
        while (buying) {
            printf("======================\n");
            printf("=        BUY         =\n");
            printf("======================\n");
            printf("List Bahan Makanan:\n");
            printBuyMakanan(canBuy);
            printf("\n");
            printf("Kirim 0 untuk exit.\n");
            printf("\n");

            inputCommand(cmd);
            while (!isCommandInteger(*cmd)) {
                printf("Command tidak valid.\n");
                printf("\n");
                inputCommand(cmd);
            }

            select = parseToInteger(*cmd);
            if (select == 0) {
                buying = false;
            } else if (isIdxListEff(canBuy, select-1)) {
                progressTime(s, prioQueue, currTIME);
                Enqueue(prioQueue, Elmt(canBuy, select-1));
                printf("Berhasil memesan ");
                printString(FoodName(Elmt(canBuy, select-1)));
                printf(". ");
                printString(FoodName(Elmt(canBuy, select-1)));
                printf(" akan diantar dalam ");
                if (Day(DeliveryTime(Elmt(canBuy, select-1))) != 0) {
                    printf("%d Hari", Day(DeliveryTime(Elmt(canBuy, select-1))));
                    if (Hour(DeliveryTime(Elmt(canBuy, select-1))) != 0 && Minute(DeliveryTime(Elmt(canBuy, select-1))) != 0) {
                        printf(", ");
                    }
                }
                if (Hour(DeliveryTime(Elmt(canBuy, select-1))) != 0) {
                    printf("%d Jam", Hour(DeliveryTime(Elmt(canBuy, select-1))));
                    if (Minute(DeliveryTime(Elmt(canBuy, select-1))) != 0) {
                        printf(", ");
                    }
                }
                if (Minute(DeliveryTime(Elmt(canBuy, select-1))) != 0) {
                    printf("%d Menit", Minute(DeliveryTime(Elmt(canBuy, select-1))));
                }
                printf(".\n\n");
            } else {
                printf("\n");
                printf("Index di luar range.\n");
                printf("\n");
            }
        }
    } else {
        printf("BNMO tidak berada di area telepon!\n");
    }
}