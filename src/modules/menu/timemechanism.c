#include <stdio.h>
#include "timemechanism.h"

void wait(Simulator *s, PrioQueueMakanan *pesanan, TIME *currTime, int x, int y) {
// I.S Simulator, pesanan, dan waktu program terdefinisi
// F.S Simulator progress waktu sebanyak x jam y menit
    // KAMUS
    TIME t;
    int i;

    // ALGORITMA
    CreateTime(&t, 0, x, y);

    for (i = 0; i < TIMEToMinute(t); i++) {
        progressTime(s, pesanan, currTime);
    }
}

void progressTime(Simulator *s, PrioQueueMakanan *pesanan, TIME *currTime) {
// I.S Simulator, pesanan, dan waktu program terdefinisi
// F.S Simulator progress waktu sebanyak 1 menit  
    AdvMinute(currTime);
    DecDeliveryTimeQueue(pesanan);
    DecExpiredTimeInv(&Inv(*s));
    DequeueZeroToInventory(pesanan, s);
    deleteExpired(&Inv(*s));
}