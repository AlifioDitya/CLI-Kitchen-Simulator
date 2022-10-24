#include <stdio.h>
#include "../boolean.h"

int main() {
    int running = true;
    char cmd[100];

    printf("Selamat datang di BNMO!\n\n");
    while (running) {
        printf("Enter command : ");
        scanf("%s", &cmd);
        printf("\n");

        if (cmd[0] == 'E' && cmd[1] == 'X' && cmd[2] == 'I' && cmd[3] == 'T') {
            running = false;
            printf("Goodbye!\n");
        } else {
            printf("Main is running.\n\n");
        }
    }
}