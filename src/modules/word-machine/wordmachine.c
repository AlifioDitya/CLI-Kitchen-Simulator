#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.c"
#include "../time/time.c"

boolean endWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK || currentChar == NEWLINE)
    {
        ADV();
    }
}

void STARTWORD()
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK && currentChar != NEWLINE)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}



void STARTWORDFILE(char* filename) {
    STARTFILE(filename);
    IgnoreBlanks();
    if (currentChar == MARK) {
        endWord = true;
    } else {
        endWord = false;
        CopyWord();
    }
}

void ForceTerminate() {
    endWord = true;
    fclose(pita);
    pita = NULL;
}

void printWord(Word w) {
    int i;
    for (i=0; i<w.Length; i++) {
        printf("%c", w.TabWord[i]);
    }
    printf("\n");
}

void STOPWORD() {
    STOP();
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
    int i;
    (*b).Length = (a).Length;
    for (i=0; i<(*b).Length; i++) {
        (*b).TabWord[i] = (a).TabWord[i];
    }
}

void createWord(char* kata, int length, Word *w) {
    /* Membuat suatu Word dari masukan array of char dan panjang word */

    // KAMUS
    Word temp;
    int i;

    // ALGORITMA
    temp.Length = length;

    for (i = 0; i < length; i++) {
        temp.TabWord[i] = kata[i];
    }

    assignWord(temp, w);
}

