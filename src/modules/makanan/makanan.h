#ifndef MAKANAN_H
#define MAKANAN_H

#include "../boolean.h"
#include "../time/time.h"
#include "../point/point.h"
#include "../word-machine/wordmachine.h"

#define IDType int
#define ID_UNDEF (-1)

typedef struct {
    IDType ID;
    Word name;
    TIME expire;
    Point loc;
    TIME delivery;
} Makanan;

/* Selektor */
#define ID(M) (M).ID
#define Expire(M) (M).expire
#define Loc(M) (M).Loc
#define DeliveryTime(M) (M).delivery

/* Konstruktor */
void CreateMakanan(Makanan *m);
// I.S Makanan sembarang
// F.S Membuat object makanan kosong

/* Setter */
void setID(Makanan *m, IDType id);
// I.S Makanan sembarang
// ID makanan terisi
void setFoodName(Makanan *m, Word name);
// I.S Makanan sembarang
// Nama makanan terisi
void setExpiryDate(Makanan *m, int HH, int MM, int SS);
// I.S Makanan sembarang
// Expired date makanan terisi
void setFoodLocation(Makanan *m, int x, int y);
// I.S Makanan sembarang
// F.S Lokasi makanan pada peta terisi 
void setDeliveryTime(Makanan *m, int HH, int MM, int SS);
// I.S Makanan sembarang
// F.S Waktu delivery makanan terisi

#endif