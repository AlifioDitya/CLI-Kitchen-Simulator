#ifndef STRING_H
#define STRING_H

#include "../word-machine/wordmachine.c"

#define STR_CAP 250

typedef struct {
    char str[STR_CAP];
    int Length;
} String;

extern String currentString;

void strfy();
// I.S currenctString sembarang
// F.S endWord = true, currentChar = MARK, currentString terisi oleh seluruh Word sebelum mark. 
// Beda dari mesin kata, string mungkin mengandung BLANK di dalamnya.

#endif