// Driver Pembacaan File

#include <stdio.h>
#include "wordmachine.h"

boolean endWord, EOP;
Word currentWord;

int main() {
    // KAMUS
    int i;
    char input[20];

    // ALGORITMA
    printf("Masukkan File Path: ");
    scanf("%s", input);

    STARTWORDFILE(input);
    printf("isi dari file adalah sebagai berikut: \n\n");

    while (true) {
        // Menampilkan Kata yang Dibaca
        for (i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        printf("\n");

        // Melanjutkan ke Kata Berikutnya
        ADVWORDFILE();
        if (currentChar = '\n'){
            ADVFILE();
        }

        // Pembacaan Berhenti
        if (EOP) {
            for (i = 0; i < currentWord.Length; i++) {
                printf("%c", currentWord.TabWord[i]);
            }
            printf("\n");
            break;
        }
    }

    printf("Sukses\n");
    return 0;
}
