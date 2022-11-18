// Testing ADT list statik makanan dan ADT Makanan

#include "liststatik.h"

int main() {
    Peta p;
    ListStatik l;
    char* filepeta = "src/data/map.txt";
    char* filemakanan = "src/data/makanan.txt";
    readPeta(filepeta, &p);
    readMakanan(filemakanan, p, &l);

    printf("Deskripsi makanan yang terbaca dari file:\n");
    for (int i=0; i<listLength(l); i++) {
        printf("ID : %d\n", ID(Elmt(l, i)));
        printf("Food Name : ");
        printString(FoodName(Elmt(l, i)));
        printf("\n");
        printf("Expiry date : ");
        TulisTIME(Expire(Elmt(l, i)));
        printf("Action location : ");
        TulisPoint(ActionLoc(Elmt(l, i)));
        printf("Delivery time :");
        TulisTIME(DeliveryTime(Elmt(l, i)));
        printf("\n");
    }

    printf("Daftar Katalog:");
    displayCatalog(l, p);
}