#ifndef STRING_H
#define STRING_H

#include "../word-machine/wordmachine.h"

#define STR_CAP 250

typedef struct {
    char str[STR_CAP];
    int Length;
} String;

extern String currentString;

void strfy();
// I.S currentString sembarang
// F.S endWord = true, currentChar = MARK, currentString terisi oleh seluruh Word sebelum mark. 
// Beda dari mesin kata, string mungkin mengandung BLANK di dalamnya, kecuali di awal kalimat.

void startString();
// I.S currentString sembarang
// I.S currentString diinisiasi untuk dibaca

void assignString(String a, String *b);
// I.S String b sembarang
// F.S String a diassign ke b

#endif