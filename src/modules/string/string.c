#include <stdio.h>
#include "string.h"
#include "../boolean.h"
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