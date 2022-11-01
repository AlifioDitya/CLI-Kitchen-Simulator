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

void createTIMEWord(TIME *T) {
// I.S Pita karakter sudah mulai dibaca
// F.S Terbentuk T dengan komponennya yang dibaca dalam Word
// Contoh: 1 0 0;
// Akan terbaca Day = 1, Hour = 0, Minute = 0;
    int D, H, M;
    int j;
    D = 0;
    H = 0;
    M = 0;
    IgnoreBlanks();
    for (j=0; j<currentWord.Length; j++) {
        D = D*10 + ((int) currentWord.TabWord[j]-48);
    }
    ADVWORD();
    for (j=0; j<currentWord.Length; j++) {
        H = H*10 + ((int) currentWord.TabWord[j]-48);
    }
    ADVWORD();
    for (j=0; j<currentWord.Length; j++) {
        M = M*10 + ((int) currentWord.TabWord[j]-48);
    }
    ADVWORD();

    CreateTime(T, D, H, M);
}