#include <stdio.h>
#include "time.c"

int main() {
    TIME T1;
    TIME T2;

    CreateTime(&T1, 1, 20, 35);
    printf("T1: ");
    TulisTIME(T1);
    printf("\n");

    printf("to Minute: %d\n", TIMEToMinute(T1));
    printf("Back to Time: ");
    TulisTIME(MinuteToTIME(TIMEToMinute(T1)));
    printf("\n");

    CreateTime(&T2, 2, 10, 12);
    printf("T2: ");
    TulisTIME(T2);
    printf("\n");

    printf("is Equal: ");
    if (TEQ(T1, T2)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    printf("is Not Equal: ");
    if (TNEQ(T1, T2)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    printf("T1 is Less Than T2: ");
    if (TLT(T1, T2)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    printf("T1 is Greater Than T2: ");
    if (TGT(T1, T2)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    printf("\n");

    printf("Next Minute on T1: ");
    TulisTIME(NextMinute(T1));

    printf("Next 30 Minutes on T1: ");
    TulisTIME(NextNMinute(T1, 30));
    printf("\n");

    printf("Previous Minute on T2: ");
    TulisTIME(PrevMinute(T2));

    printf("Previous 30 Minutes on T2: ");
    TulisTIME(PrevNMinute(T2, 30));
    printf("\n");

    printf("Time difference T1 to T2: ");
    TulisTIME(MinuteToTIME(Durasi(T1, T2)));

    return 0;
}