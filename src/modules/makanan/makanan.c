#include <stdio.h>
#include "makanan.h"
// #include "../liststatik/liststatik.c"
// #include "../peta/peta.c"

/* Konstruktor */
void CreateMakanan(Makanan *m, IDType ID, String name, TIME expire, Point loc, TIME delivery) {
    // I.S Makanan sembarang
    // F.S Membuat object makanan kosong

    // KAMUS

    // ALGORITMA
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

    // KAMUS

    // ALGORITMA
    ID(*m) = id;
}

void setFoodName(Makanan *m, String name) {
    // I.S Makanan sembarang, String name terdefinisi
    // Nama makanan terisi

    // KAMUS

    // ALGORITMA
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

boolean isBuy(String s) {
    String temp;
    createString("BUY", 3, &temp);
    return (isStringEqual(s, temp));
}
boolean isChop(String s) {
    String temp;
    createString("CHOP", 4, &temp);
    return (isStringEqual(s, temp));
}
boolean isFry(String s) {
    String temp;
    createString("FRY", 3, &temp);
    return (isStringEqual(s, temp));
}
boolean isBoil(String s) {
    String temp;
    createString("BOIL", 4, &temp);
    return (isStringEqual(s, temp));
}
boolean isMix(String s) {
    String temp;
    createString("MIX", 3, &temp);
    return (isStringEqual(s, temp));
}