#include <stdio.h>
#include "makanan.h"
#include "../liststatik/liststatik.c"
#include "../peta/peta.c"

/* Konstruktor */
void CreateMakanan(Makanan *m, IDType ID, String name, TIME expire, Point loc, TIME delivery) {
// I.S Makanan sembarang
// F.S Membuat object makanan kosong
    setID(m, ID);
    setFoodName(m, name);
    setExpiryDate(m, expire);
    setActionLocation(m, loc);
    setDeliveryTime(m, delivery);
}

/* Setter */
void setID(Makanan *m, IDType id) {
// I.S Makanan sembarang
// ID makanan terisi
    ID(*m) = id;
}

void setFoodName(Makanan *m, String name) {
// I.S Makanan sembarang, String name terdefinisi
// Nama makanan terisi
    int i;
    i = 0;

    FoodName(*m).Length = name.Length;
    while (i < name.Length) {
        FoodName(*m).str[i] = name.str[i];
    }
}

void setExpiryDate(Makanan *m, TIME expire) {
// I.S Makanan sembarang
// Expired date makanan terisi
    CreateTime(&Expire(*m), Day(expire), Hour(expire), Minute(expire));
}

void setActionLocation(Makanan *m, Point loc) {
// I.S Makanan sembarang
// F.S Lokasi aksi terhadap makanan pada peta terisi
    CreatePoint(&ActionLoc(*m), Absis(loc), Ordinat(loc));
}

void setDeliveryTime(Makanan *m, TIME delivery) {
// I.S Makanan sembarang
// F.S Waktu delivery makanan terisi
    CreateTime(&DeliveryTime(*m), Day(delivery), Hour(delivery), Minute(delivery));
}

boolean isBuy(Word w) {
    return (w.Length == 3 && w.TabWord[0] == 'B' && w.TabWord[1] == 'U' && w.TabWord[2] == 'Y');
}
boolean isChop(Word w) {
    return (w.Length == 4 && w.TabWord[0] == 'C' && w.TabWord[1] == 'H' && w.TabWord[2] == 'O' && w.TabWord[3] == 'P');
}
boolean isFry(Word w) {
    return (w.Length == 3 && w.TabWord[0] == 'F' && w.TabWord[1] == 'R' && w.TabWord[2] == 'Y');
}
boolean isBoil(Word w) {
    return (w.Length == 4 && w.TabWord[0] == 'B' && w.TabWord[1] == 'O' && w.TabWord[2] == 'I' && w.TabWord[3] == 'L');
}
boolean isMix(Word w) {
    return (w.Length == 3 && w.TabWord[0] == 'M' && w.TabWord[1] == 'I' && w.TabWord[2] == 'X');
}


/* Membaca dari file */
void readMakanan(char* filename, Peta p, ListStatik *l) {
    int n, i, j, k;
    int ID, DD, HH, MM;
    TIME expire, delivery;
    Makanan currMakanan;

    STARTWORDFILE(filename);
    n = 0;
    for (i=0; i<currentWord.Length; i++) {
        n = n*10 + ((int) currentWord.TabWord[i]-48);
    }
    printf("N = ");
    printWord(currentWord);
    ADVWORD();

    for (i=0; i<n; i++) {
        ID = 0;
        for (j=0; j<currentWord.Length; j++) {
            ID = ID*10 + ((int) currentWord.TabWord[i]-48);
        }
        setID(&currMakanan, ID);
        printf("ID = ");
        printWord(currentWord);

        strfy();
        printf("Name = ");
        printString(currentString);
        // setFoodName(&currMakanan, currentString);

        ADVWORD();
        DD = 0;
        for (k=0; k<currentWord.Length; k++) {
            DD = DD*10 + ((int) currentWord.TabWord[k]-48);
        }
        ADVWORD();
        HH = 0;
        for (k=0; k<currentWord.Length; k++) {
            HH = HH*10 + ((int) currentWord.TabWord[k]-48);
        }
        ADVWORD();
        MM = 0;
        for (k=0; k<currentWord.Length; k++) {
            MM = MM*10 + ((int) currentWord.TabWord[k]-48);
        }
        
        CreateTime(&expire, DD, HH, MM);
        setExpiryDate(&currMakanan, expire);
        printf("Expiry date = ");
        TulisTIME(Expire(currMakanan));
        
        ADVWORD();
        DD = 0;
        for (k=0; k<currentWord.Length; k++) {
            DD = DD*10 + ((int) currentWord.TabWord[k]-48);
        }
        ADVWORD();
        HH = 0;
        for (k=0; k<currentWord.Length; k++) {
            HH = HH*10 + ((int) currentWord.TabWord[k]-48);
        }
        ADVWORD();
        MM = 0;
        for (k=0; k<currentWord.Length; k++) {
            MM = MM*10 + ((int) currentWord.TabWord[k]-48);
        }
        
        CreateTime(&delivery, DD, HH, MM);
        setDeliveryTime(&currMakanan, delivery);
        printf("Delivery time = ");
        TulisTIME(DeliveryTime(currMakanan));

        ADVWORD();
        printWord(currentWord);
        if (isBuy(currentWord)) {
            CreatePoint(&ActionLoc(currMakanan), Absis(Locate(p, 'T')), Ordinat(Locate(p, 'T')));
        } else if (isChop(currentWord)) {
            CreatePoint(&ActionLoc(currMakanan), Absis(Locate(p, 'C')), Ordinat(Locate(p, 'C')));
        } else if (isFry(currentWord)) {
            CreatePoint(&ActionLoc(currMakanan), Absis(Locate(p, 'F')), Ordinat(Locate(p, 'F')));
        } else if (isBoil(currentWord)) {
            CreatePoint(&ActionLoc(currMakanan), Absis(Locate(p, 'B')), Ordinat(Locate(p, 'B')));
        } else if (isMix(currentWord)) {
            CreatePoint(&ActionLoc(currMakanan), Absis(Locate(p, 'M')), Ordinat(Locate(p, 'M')));
        } else {
            CreatePoint(&ActionLoc(currMakanan), POINT_UNDEF, POINT_UNDEF);
        }
        printf("Action = ");
        printf("Absis : %d, Ordinat : %d\n", Absis(ActionLoc(currMakanan)), Ordinat(ActionLoc(currMakanan)));
        TulisPoint(ActionLoc(currMakanan));
        
        insertLast(l, currMakanan);
        ADVWORD();
    }
}