/* File: mesinkata.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "charmachine.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
extern boolean endWord;
extern Word currentWord;

/* Pemrosesan Mesin Kata Input */
void IGNOREBLANKS();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTWORD();
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = MARK;
          atau EndWord = false, CWord adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CWord adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void COPYWORD();
/* Mengakuisisi kata, menyimpan dalam CWord
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CWord berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

/* Pemrosesan Mesin Kata File */
void IGNOREBLANKSFILE();
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = NEWLINE */

void STARTWORDFILE(char filename[]);
/* Memulai Pembacaan Kata pada File */

void ADVWORDFILE();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
         currentChar adalah karakter pertama dari kata berikutnya, mungkin NEWLINE
         Jika currentChar = NEWLINE, endWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWord */

void COPYWORDFILE();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
         currentChar = BLANK atau currentChar = NEWLINE;
         currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
         Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

void STOPWORDFILE();
/* Memberhentikan Pembacaan Kata pada File */

/* Pemrosesan Word */
void printWord(Word w);
/* Mengoutput isi Word w pada terminal */

boolean isWordEqual(Word w1, Word w2);
/* Mengembalikan true bila kata w1 dan kata w2 sama dan sebaliknya */

void assignWord(Word a, Word *b);
/* Menduplikasi Word a dengan cara membuat Word b menjadi duplikat dari Word a */

Word createWord(char str[], int len);
/* Membuat suatu Word dari masukan array of char dan panjang word */

#endif
