/* Header untuk file Utility */

#ifndef UTIL_H
#define UTIL_H

#include "../word-machine/wordmachine.h"
#include "../string/string.h"
#include "../simulator/simulator.h"
#include "../peta/peta.h"
#include "../liststatik/liststatik.h"
#include "../prioqueuemakanan/prioqueuemakanan.h"

boolean isExit(String s);

boolean isStart(String s);

boolean isMoveEast(String s);

boolean isMoveWest(String s);

boolean isMoveNorth(String s);

boolean isMoveSouth(String s);

boolean isWait(String s);

void Splash(String name);

void Initiate(Simulator *s, Peta *p, ListStatik *catalog);

void inputCommand(String *cmd);

boolean isCommandInteger(String cmd);

void printBuyMakanan(ListStatik canBuy);

void Buy(Simulator *s, TIME *currTIME, String *cmd, PrioQueueMakanan *prioQueue, Peta p, ListStatik canBuy);

void wait(Simulator *s, PrioQueueMakanan *pesanan, TIME *currTime, int x, int y);

void progressTime(Simulator *s, PrioQueueMakanan *pesanan, TIME *currTime);

#endif