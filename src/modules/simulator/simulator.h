#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <stdio.h>
#include "../boolean.h"
#include "../inventory/inventory.h"

#define INFO(p) (p) -> info
#define NEXT(p) (p) -> next
#define IDXINV_UNDEF (-1)
#define FIRST(l) (l)

typedef struct {
    String name;
    Point loc;  // Koordinat (0,0) ada pada kiri atas matriks peta, koordinat == indeks matriks.
    Inventory inv;
} Simulator;

#define Name(S) (S).name
#define Loc(S) (S).loc
#define Inv(S) (S).inv

/* Konstruktor */
void CreateSimulation (Simulator *s, String name, int x, int y);
// I.S Simulator sembarang
// F.S Membuat simulasi kosong

/* Setter */
void setName(String name, Simulator *s);
// I.S Nama pengguna pada simulator sembarang
// F.S Nama pengguna terisi
void setLocation(int x, int y, Simulator *s);
// I.S Lokasi simulator sembarang
// F.S Lokasi simulator terisi (x,y)
void setInventory(Simulator *s);
// I.S Inventory simulator sembarang
// F.S Inventory simulator terbuat

#endif