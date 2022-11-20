#include <stdio.h>
#include "string.h"
#include "../boolean.h"
#include "../word-machine/wordmachine.h"

// boolean endWord;
String currentString;

void strfy() {
// I.S currentString sembarang
// F.S endWord = true, currentChar = MARK, currentString terisi oleh seluruh Word sebelum mark. 
// Beda dari mesin kata, string mungkin mengandung BLANK di dalamnya, kecuali di awal kalimat.
    currentString.Length = 0;
    while (currentChar != MARK && currentChar != NEWLINE) {
        if (currentString.Length < STR_CAP) {
            currentString.str[currentString.Length] = currentChar;
            currentString.Length++;
            ADV();
        } else {
            break;
        }
    }
}

void strfyFILE() {
// I.S currentString sembarang
// F.S endWord = true, currentChar = MARK, currentString terisi oleh seluruh Word sebelum mark. 
// Beda dari mesin kata, string mungkin mengandung BLANK di dalamnya, kecuali di awal kalimat.
    currentString.Length = 0;
    while (!EOP && currentChar != NEWLINE) {
        if (currentString.Length < STR_CAP) {
            currentString.str[currentString.Length] = currentChar;
            currentString.Length++;
            ADVFILE();
        } else {
            break;
        }
    }
}

void startString() {
// I.S currentString sembarang
// F.S currentString diinisiasi untuk dibaca
    START();
    IGNOREBLANKS();
    if (currentChar == MARK || currentChar == NEWLINE) {
        endWord = true;
    } else {
        endWord = false;
        strfy();
    }
}

void advString() {
// I.S currentString sembarang
// F.S Terbaca next string dari pita karakter
    IGNOREBLANKS();
    if (currentChar == MARK || currentChar == NEWLINE) {
        endWord = true;
    } else {
        strfy();
        IGNOREBLANKS();
    }
}

void advStringFILE() {
// I.S currentString sembarang
// F.S Terbaca next string dari pita karakter dalam file
    IGNOREBLANKSFILE();
    if (currentChar == MARK || currentChar == NEWLINE) {
        endWord = true;
    } else {
        strfyFILE();
        IGNOREBLANKSFILE();
    }
}

void assignString(String a, String *b) {
// I.S String b sembarang
// F.S String a diassign ke b
    int i;

    (*b).Length = (a).Length;
    for (i=0; i<(*b).Length; i++) {
        (*b).str[i] = (a).str[i];
    }
}

boolean isStringEqual(String a, String b) {
// Mengembalikan true apabila string a == b
    int i;
    boolean equal = true;
    if (a.Length == b.Length) {
        for (i=0; i<a.Length; i++) {
            if (a.str[i] != b.str[i]) {
                equal = false;
                break;
            }
        }
    } else {
        equal = false;
    }
    return equal;
}

void createString(char* kata, int length, String *w) {
/* Membuat suatu String dari masukan array of char dan panjang String */

    // KAMUS
    String temp;
    int i;

    // ALGORITMA
    temp.Length = length;

    for (i = 0; i < length; i++) {
        temp.str[i] = kata[i];
    }

    assignString(temp, w);
}

void printString(String a) {
// Memberi output print dari tipe data String
    int i;
    for (i=0; i < (a).Length; i++) {
        printf("%c", (a).str[i]);
    }
}