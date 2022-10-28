#include <stdio.h>
#include "peta.c"
#include "../simulator/simulator.c"

int main() {
    Peta p;
    Simulator s;

    CreateSimulation(&s);
    setName("fio", &s);
    char* filename = "../../data/map.txt";
    readPeta(filename, &p, &s);
    displayPeta(p);
    printf("\n");

    printf("nRow = %d\n", ROW_EFF(p));
    printf("nCol = %d\n", COL_EFF(p));

    printf("User location (x,y): (%d,%d)\n\n", Absis(Loc(s)), Ordinat(Loc(s)));

    printf("Move east:\n");
    moveEast(&s, &p);
    displayPeta(p);
    printf("\n");
    printf("User location (x,y): (%d,%d)\n\n", Absis(Loc(s)), Ordinat(Loc(s)));

    printf("Move south:\n");
    moveSouth(&s, &p);
    displayPeta(p);
    printf("\n");
    printf("User location (x,y): (%d,%d)\n\n", Absis(Loc(s)), Ordinat(Loc(s)));

    printf("Move south:\n");
    moveSouth(&s, &p);
    displayPeta(p);
    printf("\n");
    printf("User location (x,y): (%d,%d)\n\n", Absis(Loc(s)), Ordinat(Loc(s)));

    printf("Move west:\n");
    moveWest(&s, &p);
    displayPeta(p);
    printf("\n");
    printf("User location (x,y): (%d,%d)\n\n", Absis(Loc(s)), Ordinat(Loc(s)));

    printf("Move north:\n");
    moveNorth(&s, &p);
    displayPeta(p);
    printf("\n");
    printf("User location (x,y): (%d,%d)\n\n", Absis(Loc(s)), Ordinat(Loc(s)));

    printf("Move west:\n");
    moveWest(&s, &p);
    displayPeta(p);
    printf("\n");
    printf("User location (x,y): (%d,%d)\n\n", Absis(Loc(s)), Ordinat(Loc(s)));

    return 0;
}