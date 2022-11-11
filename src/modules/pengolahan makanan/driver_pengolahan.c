#include <stdio.h>
#include "pengolahan.c"
#include "../word-machine/wordmachine.h"
#include "../string/string.h"
#include "../simulator/simulator.h"
#include "../peta/peta.h"
#include "../liststatik/liststatik.h"
#include "../prioqueuemakanan/prioqueuemakanan.h"

int main(){
    boolean running = true;
    boolean valid = false;
    String cmd;
    Peta p;
    Simulator s;
    TIME progTime;
    ListStatik Catalog, canBuy, canFry, canChop, canBoil, canMix;
    PrioQueueMakanan pesanan;

    // ALGORITMA
    running = true;
    Initiate(&s, &p, &Catalog);
    CreateTime(&progTime, 0, 0, 0);
    CreateListBuyMakanan(&canBuy, Catalog, p);
    MakeEmptyQueue(&pesanan, 100);

    inputCommand(&cmd);
}