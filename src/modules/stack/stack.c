/* Implementasi ADT Stack */

#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S) {
    /* I.S. sembarang  */
    /* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStack */
    /* jadi indeksnya antara 0.. MaxElStack */
    /* Ciri stack kosong : TOP bernilai StackUndef */

    // KAMUS

    // ALGORITMA
    Top(*S) = StackUndef;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S) {
    /* Mengirim true jika Stack kosong: lihat definisi di atas */

    // KAMUS

    // ALGORITMA
    return (Top(S) == StackUndef);
}

boolean IsFull(Stack S) {
    /* Mengirim true jika tabel penampung nilai elemen stack penuh */

    // KAMUS

    // ALGORITMA
    return (Top(S) == MaxElStack - 1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotypeStack SS) {
    /* Menambahkan X sebagai elemen Stack S. */
    /* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
    /* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

    // KAMUS

    // ALGORITMA
    Top(*S)++;
    InfoTop(*S).currentTime = SS.currentTime;
    InfoTop(*S).pesanan = SS.pesanan;
    InfoTop(*S).simul = SS.simul;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotypeStack *SS) {
    /* Menghapus X dari Stack S. */
    /* I.S. S  tidak mungkin kosong */
    /* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

    // KAMUS

    // ALGORITMA
    (*SS).simul = InfoTop(*S).simul;
    (*SS).pesanan = InfoTop(*S).pesanan;
    (*SS).currentTime = InfoTop(*S).currentTime;
    Top(*S)--;
}
