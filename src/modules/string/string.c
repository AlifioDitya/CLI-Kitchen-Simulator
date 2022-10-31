#include <stdio.h>
#include "../boolean.h"
#include "string.h"
#include "../word-machine/wordmachine.c"

String currentString;

void strfy() {
    IgnoreBlanks();
    currentString.Length = 0;
    while (!endWord && currentChar != '\0' && currentChar != '\n') {
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
    strfy();
}

void assignString(String a, String *b) {
// Assign string a ke b
    int i;

    (*b).Length = (a).Length;
    for (i=0; i<(*b).Length; i++) {
        (*b).str[i] = (a).str[i];
    }
}