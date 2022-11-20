#ifndef TIMEMECHANISM_H
#define TIMEMECHANISM_H

#include "../simulator/simulator.h"
#include "../prioqueuemakanan/prioqueuemakanan.h"

void wait(Simulator *s, PrioQueueMakanan *pesanan, TIME *currTime, int x, int y);
// I.S Simulator, pesanan, dan waktu program terdefinisi
// F.S Simulator progress waktu sebanyak x jam y menit

void progressTime(Simulator *s, PrioQueueMakanan *pesanan, TIME *currTime);
// I.S Simulator, pesanan, dan waktu program terdefinisi
// F.S Simulator progress waktu sebanyak 1 menit  

#endif