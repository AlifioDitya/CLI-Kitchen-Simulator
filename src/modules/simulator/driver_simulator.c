#include <stdio.h>
#include "simulator.h"
#include "../peta/peta.h"

int main() {
    Simulator s;
    Peta p;
    String name;
    int x, y;

    char* filepeta = "src/data/map.txt";
    readPeta(filepeta, &p);
    createString("Username", 8, &name);
    x = Absis(Locate(p, 'S'));
    y = Ordinat(Locate(p, 'S'));

    CreateSimulation(&s, name, x, y);
    printf("Peta simulasi:\n");
    displayPeta(p);
    printf("\n");
    printf("Nama user: ");
    printString(Name(s));
    printf("\n");
    printf("Lokasi user pada peta: ");
    TulisPoint(Loc(s));
    printf("\n");
    printf("Inventory awal:\n");
    displayInventory(Inv(s));

    return 0;
}