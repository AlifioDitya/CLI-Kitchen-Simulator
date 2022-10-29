#include <stdio.h>
#include "string.h"
#include "../boolean.h"
#include "../word-machine/wordmachine.c"

String currentString;

void strfy() {
    currentString.Length = 0;
    START();

    while (!endWord || currentChar != '\0') {
        if (currentString.Length < STR_CAP) {
            currentString.str[currentString.Length] = currentChar;
            ADV();
            currentString.Length++;
        } else {
            break;
        }
    }
    if (endWord && (currentString.Length+1) < STR_CAP) {
        currentString.str[currentString.Length+1] = '\0';
    } else {
        currentString.str[currentString.Length] = '\0';
        currentString.Length--;
        // Maximum string length 499, array of character always ends in \0 escape sequence
    }
}