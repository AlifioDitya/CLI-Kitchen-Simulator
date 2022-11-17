/* Implementasi ADT Inventory dengan List Berkait */

#include "inventory.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(InfotypeInventory val) {
    /* I.S. sembarang                                */
    /* F.S. Terbentuk suatu node dengan infotypeInventory val */

    // KAMUS
    Address p;

    // ALGORITMA
    p = (Address) malloc(sizeof(Node));

    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }

    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateInventory(Inventory *I) {
    /* I.S. sembarang             */
    /* F.S. Terbentuk list kosong */

    // KAMUS

    // ALGORITMA
    FIRST(*I) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmptyInventory(Inventory I) {
    /* Mengirim true jika list kosong */

    // KAMUS

    // ALGORITMA
    return (FIRST(I) == NULL);
}

/****************** GETTER SETTER ******************/
InfotypeInventory getElmtInventory(Inventory I, int idx) {
    /* I.S. I terdefinisi, idx indeks yang valid dalam I, yaitu 0..length(I) - 1*/
    /* F.S. Mengembalikan nilai elemen I pada indeks idx */

    // KAMUS
    int ctr;
    Address p;

    // ALGORITMA
    ctr = 0;
    p = FIRST(I);

    while (ctr < idx) {
        ctr++;
        p = NEXT(p);
    }

    return (INFO(p));
}

void setElmtInventory(Inventory *I, int idx, InfotypeInventory val) {
    /* I.S. I terdefinisi, idx indeks yang valid dalam I, yaitu 0..length(I) - 1 */
    /* F.S. Mengubah elemen I pada indeks ke-idx menjadi val */

    // KAMUS
    int ctr;
    Address p;

    // ALGORITMA
    ctr = 0;
    p = FIRST(*I);

    while (ctr < idx) {
        ctr++;
        p = NEXT(p);
    }
    
    INFO(p) = val;
}

int indexOfInventory(Inventory I, InfotypeInventory val) {
    /* I.S. I, val terdefinisi */
    /* F.S. Mencari apakah ada elemen list I yang bernilai val */
    /* Jika ada, mengembalikan indeks elemen pertama I yang bernilai val */
    /* Mengembalikan IDXINV_UNDEF jika tidak ditemukan */

    // KAMUS
    Address p;
    int idx;
    boolean found;

    // ALGORITMA
    p = FIRST(I);
    found = false;
    idx = 0;

    while (p != NULL && !found) {
        if (ID(val) == ID(INFO(p))) {
            found = true;
        } else {
            idx++;
            p = NEXT(p);
        }
    }

    if (found) {
        return idx;
    } else {
        return IDXINV_UNDEF;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertInventory(Inventory *I, InfotypeInventory val) {
    /* I.S. I mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen dengan nilai val terurut berdasarkan expiry time jika alokasi berhasil. */
    /* Jika alokasi gagal: I.S. = F.S. */

    // KAMUS
    Address p, prev, loc;

    // ALGORITMA
    p = newNode(val);
    loc = FIRST(*I);
    prev = NULL;

    if (p != NULL) {
        if (isEmptyInventory(*I)) {
            NEXT(p) = NULL;
            FIRST(*I) = p;
        } else {
            while (loc != NULL && TLT(Expire(INFO(loc)), Expire(val))) {
                prev = loc;
                loc = NEXT(loc);
                printf("Tes\n");
            }

            NEXT(p) = loc;

            if (prev != NULL) {
                NEXT(prev) = p;
            } else {
                FIRST(*I) = p;
            }
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstInventory(Inventory *I, InfotypeInventory *val) {
    /* I.S. List I tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
    /*      dan alamat elemen pertama di-dealokasi */

    // KAMUS
    Address p;

    // ALGORITMA
    p = FIRST(*I);
    *val = INFO(p);
    FIRST(*I) = NEXT(p);
    free(p);
}

void deleteAtInventory(Inventory *I, int idx, InfotypeInventory *val) {
    /* I.S. list tidak kosong, idx indeks yang valid dalam I, yaitu 0..length(l) - 1 */
    /* F.S. val diset dengan elemen I pada indeks ke-idx. */
    /*      Elemen I pada indeks ke-idx dihapus dari I */

    // KAMUS
    int ctr;
    Address p, loc;

    // ALGORITMA
    if (idx == 0) {
        deleteFirstInventory(I, val);
    } else {
        ctr = 0;
        loc = FIRST(*I);

        while (ctr < idx - 1) {
            ctr++;
            loc = NEXT(loc);
        }

        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayInventory(Inventory I) {
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, isi list dicetak dengan format sebagai berikut : */
    /* No | Nama       | Durasi Expired */
    /* 1  | <nama-1>   | <durasi-1> */
    /* 2  | <nama-2>   | <durasi-2> */
    /* dst..                   */
    /* Jika list kosong : menulis "Inventory Kosong" */
    /* Diakhiri dengan newline */

    // KAMUS
    Address p;
    int i;

    // ALGORITMA
    if (isEmptyInventory(I)) {
        printf("Inventory Kosong.\n");
    } else {
        i = 1;
        
        printf("List Makanan di Inventory\n\n");
        printf("(nama) - (waktu - sisa kedaluarsa)\n");

        p = FIRST(I);
        while (p != NULL) {
            printf("%d. ", i);
            printString(FoodName(INFO(p)));
            printf(" - ");
            TulisTIME(Expire(INFO(p)));
            p = NEXT(p);
            i++;
        }
    }
}

int LengthInventory(Inventory I) {
    /* Mengirimkan banyaknya elemen list  mengirimkan 0 jika list kosong */

    // KAMUS
    int ctr;
    Address p;

    // ALGORITMA
    ctr = 0;
    p = FIRST(I);

    while (p != NULL) {
        ctr++;
        p = NEXT(p);
    }

    return ctr;
}


void DecExpiredTimeInv(Inventory *I) {
    Address p;
    
    if (!isEmptyInventory(*I)) {
        p = FIRST(*I);
        while (p != NULL) {
            DecMinute(&Expire(INFO(p)));
            p = NEXT(p);
        }
    }
}

void deleteExpired(Inventory *I) {
    Address p;
    int idx;
    Makanan val;
    p = FIRST(*I);

    if (!isEmptyInventory(*I)) {
        idx = 0;
        while (p != NULL) {
            if (Day(Expire(INFO(p))) <= 0 && Hour(Expire(INFO(p))) <= 0 && Minute(Expire(INFO(p))) <= 0) {
                deleteAtInventory(I, idx, &val);
            }
            p = NEXT(p);
            idx++;
        }
    }
}