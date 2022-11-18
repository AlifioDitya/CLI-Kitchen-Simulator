#include <stdio.h>
#include "timemechanism.h"

void wait(Simulator *s, PrioQueueMakanan *pesanan, TIME *currTime, int x, int y) {
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
    AdvMinute(currTime);
    DecDeliveryTimeQueue(pesanan);
    DecExpiredTimeInv(&Inv(*s));
    DequeueZeroToInventory(pesanan, s);
    deleteExpired(&Inv(*s));
}