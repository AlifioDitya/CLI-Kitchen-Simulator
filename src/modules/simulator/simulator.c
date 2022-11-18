#include <stdio.h>
#include "simulator.h"

/* Konstruktor */
void CreateSimulation (Simulator *s, String name, int x, int y) {
    // I.S Simulator sembarang
    // F.S Membuat simulasi kosong
    setName(name, s);
    setLocation(x, y, s);
    setInventory(s);
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

void setInventory(Simulator *s) {
    // I.S Inventory simulator sembarang
    // F.S Inventory simulator terbuat
    CreateInventory(&Inv(*s));
}