#include <stdio.h>
#include "makanan.h"
#include "../point/point.c"
#include "../time/time.c"
#include "../string/string.h"

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
    CreateTime(&Expire(*m), Hour(expire), Minute(expire), Second(expire));
}

void setActionLocation(Makanan *m, Point loc) {
// I.S Makanan sembarang
// F.S Lokasi aksi terhadap makanan pada peta terisi
    CreatePoint(&ActionLoc(*m), Absis(loc), Ordinat(loc));
}

void setDeliveryTime(Makanan *m, TIME delivery) {
// I.S Makanan sembarang
// F.S Waktu delivery makanan terisi
    CreateTime(&DeliveryTime(*m), Hour(delivery), Minute(delivery), Second(delivery));
}