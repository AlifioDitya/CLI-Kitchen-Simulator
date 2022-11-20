/* Header untuk file MENU */
/* Implementasi driver ada pada program utama main.c */

#ifndef MENU_H
#define MENU_H

#include "../word-machine/wordmachine.h"
#include "../string/string.h"
#include "../simulator/simulator.h"
#include "../peta/peta.h"
#include "../liststatik/liststatik.h"
#include "../pengolahan/pengolahan.h"
#include "../prioqueuemakanan/prioqueuemakanan.h"

void Splash(String name);
// I.S Tampilan sembarang
// F.S Tampilan berupa splash screen

void Initiate(Simulator *s, Peta *p, ListStatik *catalog, BinTree *resep);
// I.S Data terdefinisi dan valid
// F.S Data loaded ke dalam program

void printBuyMakanan(ListStatik canBuy);
// I.S List makanan yang bisa dibeli terdefinisi
// F.S Makanan yang bisa dibeli ditampilkan

void Buy(Simulator *s, TIME *currTIME, String *cmd, PrioQueueMakanan *prioQueue, Peta p, ListStatik canBuy);
// I.S List makanan yang bisa dibeli terdefinisi
// F.S Makanan dipesan


#endif