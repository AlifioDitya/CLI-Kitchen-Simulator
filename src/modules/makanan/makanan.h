#ifndef MAKANAN_H
#define MAKANAN_H

#include "../boolean.h"
#include "../time/time.h"
#include "../point/point.h"
#include "../string/string.h"

#define IDType int
#define ID_UNDEF (-1)

typedef struct {
    IDType ID;
    String name;
    TIME expire;
    Point loc;
    TIME delivery;
} Makanan;

/* Selektor */
#define ID(M) (M).ID
#define FoodName(M) (M).name
#define Expire(M) (M).expire
#define ActionLoc(M) (M).loc
#define DeliveryTime(M) (M).delivery

/* Konstruktor */
void CreateMakanan(Makanan *m, IDType ID, String name, TIME expire, Point loc, TIME delivery);
// I.S Makanan sembarang
// F.S Membuat object makanan kosong

/* Setter */
void setID(Makanan *m, IDType id);
// I.S Makanan sembarang
// ID makanan terisi
void setFoodName(Makanan *m, String name);
// I.S Makanan sembarang
// Nama makanan terisi
void setExpiryDate(Makanan *m, TIME expire);
// I.S Makanan sembarang
// Expired date makanan terisi
void setActionLocation(Makanan *m, Point loc);
// I.S Makanan sembarang
// F.S Lokasi aksi terhadap makanan pada peta terisi
void setDeliveryTime(Makanan *m, TIME delivery);
// I.S Makanan sembarang
// F.S Waktu delivery makanan terisi

boolean isBuy(String s);

boolean isChop(String s);

boolean isFry(String s);

boolean isBoil(String s);

boolean isMix(String s);

#endif