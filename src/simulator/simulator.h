#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <stdio.h>
#include "../boolean.h"
#include "../point/point.h"
#include "../word-machine/wordmachine.h"

typedef struct {
    Word name;
    Point loc;
    // Inventory inv;
} Simulator;

/* Konstruktor */
void CreateSimulation (Simulator *s);
// I.S Simulator sembarang
// F.S Membuat simulasi baru dengan properti kosong

/* Setter */
void setName(Word name, Simulator *s);
// I.S Nama pengguna pada simulator sembarang
// F.S Nama pengguna terisi
void setLocation(int x, int y, Simulator *s);
// I.S Lokasi simulator sembarang
// F.S Lokasi simulator terisi (x,y)

/* Selektor */
Word getName(Simulator s);
// Mengembalikan properti nama pengguna dari simulator
Point getLocation(Simulator s);
// Mengembalikan properti lokasi BNMO saat ini dari simulator


#endif