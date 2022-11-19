#include <stdio.h>
#include "makanan.h"

int main() {
    Makanan m;
    String name;
    TIME expire, delivery;
    Point loc;

    createString("Cake", 4, &name);
    CreatePoint(&loc, 6, 9);
    CreateTime(&expire, 1, 2, 3);
    CreateTime(&delivery, 4, 5, 6);

    CreateMakanan(&m, 1, name, expire, loc, delivery);
    printf("ID : %d\n", ID(m));
    printf("Food Name : ");
    printString(FoodName(m));
    printf("\n");
    printf("Expiry date : ");
    TulisTIME(Expire(m));
    printf("Action location : ");
    TulisPoint(ActionLoc(m));
    printf("Delivery time :");
    TulisTIME(DeliveryTime(m));
    printf("\n");
    return 0;
}