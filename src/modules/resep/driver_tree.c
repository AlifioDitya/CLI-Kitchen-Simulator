#include "tree.c"
#include <stdio.h>

int main() {

    Peta map;
    ListStatik l;
    BinTree resep;
    Address p;
    ListIDBahan lBahan;
    int i = 0;

    CreateListBahan(&lBahan);

    CreateTree(VAL_UNDEF, NULL, NULL, &resep);
    // readResepFromFile(resep);

    p = searchByID(1,resep);
    lBahan = listBahan(p);

    printf("Daftar ID bahan: ");

    for (i; i<len(lBahan.bahan); i++) {
        printf("%d", lBahan.bahan[i]);
        if (i+1 <len(lBahan.bahan)) {
            printf(",");
        } else {
            printf("\n");
        }
    }
    
    printListResep(resep, map, l);
}
