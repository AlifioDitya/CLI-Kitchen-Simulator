#ifndef TIMEMECHANISM_H
#define TIMEMECHANISM_H

#include "../simulator/simulator.h"
#include "../prioqueuemakanan/prioqueuemakanan.h"

void wait(Simulator *s, PrioQueueMakanan *pesanan, TIME *currTime, int x, int y);

void progressTime(Simulator *s, PrioQueueMakanan *pesanan, TIME *currTime);

#endif