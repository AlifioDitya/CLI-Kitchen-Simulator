/* ADT Inventory dengan List Berkait */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "../boolean.h"
#include "../makanan/makanan.h"

typedef Makanan Infotype;

typedef struct node* Address;
typedef struct node {
    Infotype info;
    Address next;
} Node;
typedef Address Inventory;

#define INFO(p) (p) -> info
#define NEXT(p) (p) -> next
#define IDX_UNDEF (-1)
#define FIRST(l) (l)

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

Address newNode(Infotype val);
/* I.S. sembarang                                */
/* F.S. Terbentuk suatu node dengan infotype val */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateInventory(Inventory *I);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(Inventory I);
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
Infotype getElmt(Inventory I, int idx);
/* I.S. I terdefinisi, idx indeks yang valid dalam I, yaitu 0..length(I) - 1 */
/* F.S. Mengembalikan nilai elemen I pada indeks idx */

void setElmt(Inventory *I, int idx, Infotype val);
/* I.S. I terdefinisi, idx indeks yang valid dalam I, yaitu 0..length(I) - 1 */
/* F.S. Mengubah elemen I pada indeks ke-idx menjadi val */

int indexOf(Inventory I, Infotype val);
/* I.S. I, val terdefinisi */
/* F.S. Mencari apakah ada elemen list I yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama I yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insert(Inventory *I, Infotype val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen dengan nilai val terurut berdasarkan expiry time jika alokasi berhasil. */
/* Jika alokasi gagal: I.S. = F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(Inventory *I, Infotype *val);
/* I.S. List I tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen pertama di-dealokasi */

void deleteAt(Inventory *I, int idx, Infotype *val);
/* I.S. list tidak kosong, idx indeks yang valid dalam I, yaitu 0..length(I) - 1 */
/* F.S. val diset dengan elemen I pada indeks ke-idx. */
/*      Elemen I pada indeks ke-idx dihapus dari I */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayInventory(Inventory I);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dengan format sebagai berikut : */
/* Nama       | Durasi Expired */
/* <nama-1>   | <durasi-1> */
/* <nama-2>   | <durasi-2> */
/* dst..                   */
/* Jika list kosong : menulis "Inventory Kosong" */
/* Diakhiri dengan newline */

int invLength(Inventory I);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

#endif