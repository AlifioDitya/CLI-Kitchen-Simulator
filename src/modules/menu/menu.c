#include <stdio.h>
#include "menu.h"

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
    printf("\n");
}

void inputCommand(String *cmd) {
    printf("Enter command : ");
    startString();
    assignString(currentString, cmd);
    printf("\n");
}

int parseToInteger(String s) {
    int i;
    int total = 0;
    if (isCommandInteger(s)) {
        for (i=0; i<s.Length; i++) {
            total = total*10 + (s.str[i]-48);
        }
    }
    return total;
}

void printBuyMakanan(ListStatik canBuy) {
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
                printf("\n");
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

void wait(Simulator *s, PrioQueueMakanan *pesanan, TIME *currTime, int x, int y) {
    // KAMUS
    TIME t;
    int i;

    // ALGORITMA
    CreateTime(&t, 0, x, y);

    for (i = 0; i < TIMEToMinute(t); i++) {
        progressTime(s, pesanan, currTime);
    }
}

void progressTime(Simulator *s, PrioQueueMakanan *pesanan, TIME *currTime) {
    AdvMinute(currTime);
    DecDeliveryTimeQueue(pesanan);
    DecExpiredTimeInv(&Inv(*s));
    DequeueZeroToInventory(pesanan, s);
    deleteExpired(&Inv(*s));
}