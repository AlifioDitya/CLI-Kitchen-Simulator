#include <stdio.h>
#include "../boolean.h"
#include "string.h"
#include "../word-machine/wordmachine.c"

boolean endWord;
String currentString;

void strfy() {
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

void startString() {
// I.S currentString sembarang
// I.S currentString diinisiasi untuk dibaca
    START();
    IgnoreBlanks();
    if (currentChar == MARK || currentChar == NEWLINE) {
        endWord = true;
    } else {
        endWord = false;
        strfy();
    }
}

void advString() {
    IgnoreBlanks();
    if (currentChar == MARK || currentChar == NEWLINE) {
        endWord = true;
    } else {
        strfy();
        IgnoreBlanks();
    }
}

void assignString(String a, String *b) {
// Assign string a ke b
    int i;

    (*b).Length = (a).Length;
    for (i=0; i<(*b).Length; i++) {
        (*b).str[i] = (a).str[i];
    }
}

void printString(String a) {
    int i;
    for (i=0; i<(a).Length; i++) {
        printf("%c", (a).str[i]);
    }
    printf("\n");
}