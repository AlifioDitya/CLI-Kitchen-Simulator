#include "inventory.h"
#include <stdio.h>

int main() {
    // KAMUS
    TIME ex, del;
    Makanan m, temp;
    String sname, mname;
    Point P;
    Inventory I;
    char cmname[20] = "Ayam Goreng";

    // ALGORITMA
    // Inisiasi Inventory
    CreateInventory(&I);

    // Membuat contoh makanan
    createString(cmname, 11, &mname);
    CreateTime(&ex, 0, 4, 0);
    CreatePoint(&P, 3, 3);
    CreateTime(&del, 0, 0, 15);
    CreateMakanan(&m, 1, mname, ex, P, del);

    // Print Inventory Kosong
    printf("Tes 1 (Inventory Kosong):\n");
    displayInventory(I);

    // Memasukkan ke Inventory
    insertInventory(&I, m);

    // Output Inventory berisi 1
    printf("\nTes 2 (Inventory Isi 1):\n");
    displayInventory(I);

    // Decrement Expire Time
    printf("\nTes 3 (Decrement):\n");
    DecExpiredTimeInv(&I);
    displayInventory(I);

    // Cek IndexOf
    printf("\nTes 4 (Cek Index):\n");
    printf("%d\n", indexOfInventory(I, m));

    // Delete
    printf("\nTes 5 (Delete, menjadi kosong):\n");
    deleteFirstInventory(&I, &temp);
    displayInventory(I);
}