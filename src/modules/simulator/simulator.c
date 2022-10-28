#include <stdio.h>
#include "../boolean.h"
#include "simulator.h"
#include "../point/point.c"

/* Konstruktor */
void CreateSimulation (Simulator *s) {
// I.S Simulator sembarang
// F.S Membuat simulasi kosong
    Name(*s) = "";
    CreatePoint(&Loc(*s), POINT_UNDEF, POINT_UNDEF);
}

/* Setter */
void setName(char* name, Simulator *s) {
// I.S Nama pengguna pada simulator sembarang
// F.S Nama pengguna terisi
    Name(*s) = name;
}

void setLocation(int x, int y, Simulator *s) {
// I.S Lokasi simulator sembarang
// F.S Lokasi simulator terisi (x,y)
    CreatePoint(&Loc(*s), x, y);
}