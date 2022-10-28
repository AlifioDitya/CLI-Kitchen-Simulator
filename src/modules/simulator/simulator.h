#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <stdio.h>
#include "../boolean.h"
#include "../point/point.h"

typedef struct {
    char* name;
    Point loc;  // Koordinat (0,0) ada pada kiri atas matriks peta, koordinat == indeks matriks.
    // Inventory inv;
} Simulator;

#define Name(S) (S).name
#define Loc(S) (S).loc

/* Konstruktor */
void CreateSimulation (Simulator *s);
// I.S Simulator sembarang
// F.S Membuat simulasi kosong

/* Setter */
void setName(char* name, Simulator *s);
// I.S Nama pengguna pada simulator sembarang
// F.S Nama pengguna terisi
void setLocation(int x, int y, Simulator *s);
// I.S Lokasi simulator sembarang
// F.S Lokasi simulator terisi (x,y)

#endif