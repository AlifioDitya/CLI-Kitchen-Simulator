/* File: charmachine.c */
/* Implementasi Mesin Karakter untuk Pembacaan Input dan File */

#include "charmachine.h"
#include <stdio.h>
#include <stdlib.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START() {
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
       Karakter pertama yang ada pada pita posisinya adalah pada jendela.
       I.S. : sembarang
       F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
              Jika currentChar = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    pita = stdin;
    ADV();
}

void ADV() {
    /* Pita dimajukan satu karakter.
       I.S. : Karakter pada jendela =
              , currentChar != MARK
       F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
              currentChar mungkin = MARK.
              Jika  currentChar = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP) {
        fclose(pita);
    }
}

void STARTFILE(char filename[]) {
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
       Karakter pertama yang ada pada pita posisinya adalah pada jendela.
       I.S. : sembarang
       F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
              Jika currentChar = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    pita = fopen(filename, "r");
    if (pita == NULL) {
        printf("File tidak ada. Exiting...\n");
        exit(1);
    } else {
        ADVFILE();
    }
}

void ADVFILE() {
    /* Pita dimajukan satu karakter.
       I.S. : Karakter pada jendela =
              , currentChar != NEWLINE
       F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
              currentChar mungkin = NEWLINE.
              Jika  currentChar = NEWLINE maka EOP akan menyala (true) */

    /* Algoritma */
    retval = fscanf(pita, "%c", &currentChar);
    // EOP = (currentChar == MARK);

    if (retval == EOF) {
        STOPFILE();
    }
}

void STOPFILE() {
    /* Memberhentikan Pembacaan File */
    fclose(pita);
}