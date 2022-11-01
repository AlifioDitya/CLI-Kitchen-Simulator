#include <stdio.h>
#include "makanan.h"
#include "../point/point.c"
#include "../time/time.c"
#include "../string/string.h"
#include "../liststatik/liststatik.c"

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

/* Membaca dari file */
void readMakanan(char* filename, Makanan *m) {
    int n, i, j;
    int ID, HH, MM, SS;
    TIME expire, delivery;

    STARTWORDFILE(filename);
    n = 0;
    for (i=0; i<currentWord.Length; i++) {
        n = n*10 + ((int) currentWord.TabWord[i]-48);
    }
    ADVWORD();

    for (i=0; i<n; i++) {
        ID = 0;
        for (j=0; j<currentWord.Length; j++) {
            ID = ID*10 + ((int) currentWord.TabWord[i]-48);
        }
        setID(m, ID);

        strfy();
        setFoodName(m, currentString);

        createTIMEWord(&expire);
        setExpiryDate(m, expire);
        
        createTIMEWord(&delivery);
        setDeliveryTime(m, delivery);

        ADVWORD();
        // if (isBuy(currentWord)) { Locate(p, 'T') }
        // else if (isChop) { Locate(p, 'C') }
        // else if (isFry) { Locate(p, 'F') }
        // else if (isBoil) { Locate(p, 'B') }
        
        // enqueue(Inventory &inv);
        ADVWORD();
    }
}

Makanan getFoodByID(IDType ID, ListStatik l){
    // I.S. ID Sembarang
    // membaca makanan dari file catalog
    return Elmt(l,indexOf(l,ID));
}