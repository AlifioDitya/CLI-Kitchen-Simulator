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
    assignString(name, &FoodName(*m));
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
    Word temp;
    createWord("BUY", 3, &temp);
    return (isWordEqual(w, temp));
}
boolean isChop(Word w) {
    Word temp;
    createWord("CHOP", 4, &temp);
    return (isWordEqual(w, temp));
}
boolean isFry(Word w) {
    Word temp;
    createWord("FRY", 3, &temp);
    return (isWordEqual(w, temp));
}
boolean isBoil(Word w) {
    Word temp;
    createWord("BOIL", 4, &temp);
    return (isWordEqual(w, temp));
}
boolean isMix(Word w) {
    Word temp;
    createWord("MIX", 3, &temp);
    return (isWordEqual(w, temp));
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
        n = n*10 + ((int) currentWord.TabWord[i]-'0');
    }
    
    ADVWORD();

    for (i=0; i<n; i++) {
        ID = 0;
        for (j=0; j<currentWord.Length; j++) {
            ID = ID*10 + ((int) currentWord.TabWord[j]-'0');
        }
        setID(&currMakanan, ID);

        strfy();
        setFoodName(&currMakanan, currentString);

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
        // printf("Expiry date = ");
        // TulisTIME(Expire(currMakanan));
        
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

        ADVWORD();
        
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
        
        printf("ID : %d\n", ID(currMakanan));
        printf("Food Name : ");
        printString(FoodName(currMakanan));
        printf("\n");
        printf("Expiry date : ");
        TulisTIME(Expire(currMakanan));
        printf("Action location : ");
        TulisPoint(ActionLoc(currMakanan));
        printf("Delivery time :");
        TulisTIME(DeliveryTime(currMakanan));
        
        insertLast(l, currMakanan);
        printf("Makanan inserted -> ");
        printf("Food name inserted : ");
        printString(FoodName(Elmt(*l, getLastIdx(*l))));
        printf(" ; ");
        printf("ID-inserted : %d\n", ID(Elmt(*l, getLastIdx(*l))));
        printf("\n\n");

        if (i != (n-1)) {
            ADVWORD();
        } else {
            endWord = true;
        }
    }
}

Makanan getFoodByID(IDType ID, ListStatik l){
    // I.S. ID Sembarang
    // membaca makanan dari file catalog
    return Elmt(l,indexOf(l,ID));
}

void printListMakanan(ListStatik l){
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Jika List kosong : menulis [] */
// KAMUS
    IdxType i;
// ALGORITMA
    printf("[");

    for (i=0; i<=getLastIdx(l); i++) {
        printString(FoodName(Elmt(l,i)));
        if (i < getLastIdx(l)) {
            printf(",");
        }
    }

    printf("]\n");
}