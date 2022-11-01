#include <stdio.h>
#include "simulator.h"
#include "../point/point.c"
#include "../string/string.c"

/* Konstruktor */
void CreateSimulation (Simulator *s, String name, int x, int y) {
// I.S Simulator sembarang
// F.S Membuat simulasi kosong
    setName(name, s);
    setLocation(x, y, s);
}

/* Setter */
void setName(String name, Simulator *s) {
// I.S Nama pengguna pada simulator sembarang
// F.S Nama pengguna terisi
    assignString(name, &(*s).name);
}

void setLocation(int x, int y, Simulator *s) {
// I.S Lokasi simulator sembarang
// F.S Lokasi simulator terisi (x,y)
    CreatePoint(&Loc(*s), x, y);
}