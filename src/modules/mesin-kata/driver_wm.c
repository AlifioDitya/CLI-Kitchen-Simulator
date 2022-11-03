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
    printf("put in path file\n");
    scanf("%[^\n]s", input);

    STARTWORDFILE(input);
    printf("isi dari file adalah sebagai berikut: \n\n");

    while (!EOP) {
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
        // if (currentChar == MARK) {
        if (EOP) {
            STOPWORDFILE();
        }
    }

    printf("Sukses\n");
    return 0;
}
