/* Header untuk file MENU */

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

void Initiate(Simulator *s, Peta *p, ListStatik *catalog, BinTree *resep);

void printBuyMakanan(ListStatik canBuy);

void Buy(Simulator *s, TIME *currTIME, String *cmd, PrioQueueMakanan *prioQueue, Peta p, ListStatik canBuy);

#endif