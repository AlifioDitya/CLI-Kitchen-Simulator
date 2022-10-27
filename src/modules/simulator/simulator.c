#include <stdio.h>
#include "../boolean.h"
#include "simulator.h"
#include "../point/point.c"

/* Konstruktor */
void CreateSimulation (char* name, Simulator *s) {
// I.S Simulator sembarang
// F.S Membuat simulasi baru dengan properti name dan lokasi terisi
    Name(*s) = name;
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