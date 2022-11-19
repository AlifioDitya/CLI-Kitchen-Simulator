#include "string.h"
#include <stdio.h>

int main() {
    String s, t;
    int i;

    // Start Pembacaan String
    printf("Baca : ");
    startString();

    // Mengeprint String yang telah dibaca saat Start (Kata Pertama)
    printf("Telah Dibaca : ");
    printString(currentString);
    printf("\n");

    // Mengassign String
    assignString(currentString, &s);
    printf("Telah Diassign : ");
    printString(s);
    printf("\n");

    // Membuat String
    createString("Wow", 3, &t);

    // Membandingkan 2 String
    printf("%d %d\n", isStringEqual(currentString, s), isStringEqual(currentString, t));
}