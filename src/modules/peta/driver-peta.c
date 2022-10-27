#include <stdio.h>
#include "peta.c"
#include "../simulator/simulator.c"

int main() {
    Peta p;
    Simulator s;

    CreateSimulation("fio", &s);
    char* filename = "map.txt";
    readPeta(filename, &p, &s);
    displayPeta(p);

    printf("nRow = %d\n", ROW_EFF(p));
    printf("nCol = %d\n", COL_EFF(p));

    printf("(x,y) = (%d,%d)", Absis(Loc(s)), Ordinat(Loc(s)));

    return 0;
}