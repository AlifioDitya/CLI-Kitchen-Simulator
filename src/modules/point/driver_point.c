#include <stdio.h>
#include "point.h"

int main(){
    Point P1, P2;
    CreatePoint(&P1, 0, 0);
    CreatePoint(&P2, 1, -1);

    printf("Point 1: ");
    TulisPoint(P1);
    printf("Point 2: ");
    TulisPoint(P2);
    if(EQ(P1,P2)){
        printf("SAMA\n");
    }
    else{
        printf("TIDAK SAMA\n");
    }

    printf("test nextX dan nextY pada P1: \n");
    P1 = NextX(P1);
    printf("Point 1: ");
    TulisPoint(P1);
    P1 = NextY(P1);
    printf("Point 1: ");
    TulisPoint(P1);
    
    printf("test nextX dan nextY pada P2: \n");
    P2 = NextX(P2);
    printf("Point 2: ");
    TulisPoint(P2);
    P2 = NextY(P2);
    printf("Point 2: ");
    TulisPoint(P2);

    shiftPoint(&P1, 1, 0);
    shiftPoint(&P2, 1, 0);
    if(EQ(P1,P2)){
        printf("SAMA\n");
    }
    else{
        printf("TIDAK SAMA\n");
    }

    printf("Point 1: ");
    TulisPoint(P1);

    printf("Point 2: ");
    TulisPoint(P2);

    P1 = PlusDelta(P1, 3, 2);
    printf("Point 1: ");
    TulisPoint(P1);
    P2 = PlusDelta(P2, 2, 3);
    printf("Point 2: ");
    TulisPoint(P2);
    if(EQ(P1,P2)){
        printf("SAMA\n");
    }
    else{
        printf("TIDAK SAMA\n");
    }
}