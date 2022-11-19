#include <stdio.h>
#include "wordmachine.h"

boolean endWord;
Word currentWord;

/* Pemrosesan Mesin Kata Input */
void IGNOREBLANKS() {
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */

    // KAMUS

    // ALGORITMA
    while (currentChar == BLANK) {
        ADV();
    }
}

void STARTWORD() {
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    
    // KAMUS

    // ALGORITMA
    START();
    IGNOREBLANKS();
    if (currentChar == MARK) {
        endWord = true;
    } else {
        endWord = false;
        COPYWORD();
    }
}

void ADVWORD() {
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    
    // KAMUS

    // ALGORITMA
    IGNOREBLANKS();
    if (currentChar == MARK) {
        endWord = true;
    } else {
        COPYWORD();
        IGNOREBLANKS();
    }
}

void COPYWORD() {
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    
    // KAMUS
    int i;

    // ALGORITMA
    i = 0;
    while (currentChar != BLANK && currentChar != MARK) {
        if (i < NMax) {
            currentWord.TabWord[i] = currentChar;
        }
        ADV();
        i++;
    }

    if (i >= NMax) {
        currentWord.Length = NMax;
    } else {
        currentWord.Length = i;
    }
}

/* Pemrosesan Mesin Kata File */
void IGNOREBLANKSFILE() {
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = NEWLINE */
    
    // KAMUS

    // ALGORITMA
    while (currentChar == BLANK || currentChar == NEWLINE) {
        ADVFILE();

        if (EOP) {
            break;
        }
    }
}

void STARTWORDFILE(char filename[]) {
    /* Memulai Pembacaan Kata pada File */

    // KAMUS

    // ALGORITMA
    STARTFILE(filename);
    IGNOREBLANKSFILE();

    if (currentChar == NEWLINE) {
        endWord = true;
    } else {
        endWord = false;
        ADVWORDFILE();
    }
}

void ADVWORDFILE() {
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin NEWLINE
              Jika currentChar = NEWLINE, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    
    // KAMUS

    // ALGORITMA
    IGNOREBLANKSFILE();
    if (currentChar == NEWLINE) {
        endWord = true;
    } else {
        COPYWORDFILE();
    }
}

void COPYWORDFILE() {
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = NEWLINE;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
        
    // KAMUS
    int i;

    // ALGORITMA
    i = 0;
    while (currentChar != BLANK && currentChar != NEWLINE) {
        if (i < NMax) {
            currentWord.TabWord[i] = currentChar;
        }

        if (EOP) {
            break;
        } else {
            ADVFILE();
        }
        i++;
    }

    if (i >= NMax) {
        currentWord.Length = NMax;
    } else {
        currentWord.Length = i;
    }
}

void STOPWORDFILE() {
    /* Memberhentikan Pembacaan Kata pada File */
    
    // KAMUS

    // ALGORITMA
    STOPFILE();
}

/* Pemrosesan Word */
void printWord(Word w) {
    /* Mengoutput isi Word w pada terminal */

    // KAMUS
    int i;

    // ALGORITMA
    for (i = 0; i < w.Length; i++) {
        printf("%c", w.TabWord[i]);
    }
    printf("\n");
}

boolean isWordEqual(Word w1, Word w2) {
    /* Mengembalikan true bila kata w1 dan kata w2 sama dan sebaliknya */

    // KAMUS
    int i;

    // ALGORITMA
    if (w1.Length != w2.Length) {
        return false;
    }

    for (i = 0; i < w1.Length; i++) {
        if (w1.TabWord[i] != w2.TabWord[i]) {
            return false;
        }
    }

    return true;
}

void assignWord(Word a, Word *b) {
    /* Menduplikasi Word a dengan cara membuat Word b menjadi duplikat dari Word a */

    // KAMUS
    int i;

    // ALGORITMA
    (*b).Length = (a).Length;
    for (i = 0; i < (*b).Length; i++) {
        (*b).TabWord[i] = (a).TabWord[i];
    }
}

Word createWord(char str[], int len) {
    /* Membuat suatu Word dari masukan array of char dan panjang word */

    // KAMUS
    int i;
    Word ret;

    // ALGORITMA
    ret.Length = len;
    for (i = 0; i < len; i++) {
        ret.TabWord[i] = str[i];
    }
    
    return ret;
}
