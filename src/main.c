#include <stdio.h>
#include "./modules/boolean.h"
#include "./util/util.c"

int main() {
    int running = true;
    Word cmd;
    Peta p;
    Simulator s;
    TIME currentTime;
    ListStatik Catalog;

    Initiate(&s, &p, &Catalog);

    while (running) {
        inputCommand();

        if (isExit()) {
            running = false;
            printf("Goodbye!\n");
        } else {
            printf("Main is running.\n\n");
        }
    }
}