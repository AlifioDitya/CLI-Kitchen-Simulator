/* File : prioqueuemakanan.h */
/* Definisi ADT Priority Queue Time dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#ifndef PRIOQUEUEMAKANAN_H
#define PRIOQUEUEMAKANAN_H

#include "../boolean.h"
#include "../makanan/makanan.h"
#include "../simulator/simulator.h"

#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef Makanan infotype;
typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueueMakanan : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    infotype * T;   /* tabel penyimpan elemen */
    address HEAD;  /* alamat penghapusan */
    address TAIL;  /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
} PrioQueueMakanan;
/* Definisi PrioQueueMakanan kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueMakanan, maka akses elemen : */
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q)    (Q).MaxEl
#define ElmtQueue(Q,i)   (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmptyQueue (PrioQueueMakanan Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQueue (PrioQueueMakanan Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmtQueue (PrioQueueMakanan Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmptyQueue (PrioQueueMakanan * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DealokasiQueue(PrioQueueMakanan * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueMakanan * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueueMakanan * Q, infotype * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueMakanan (PrioQueueMakanan Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar */

void DecDeliveryTimeQueue(PrioQueueMakanan *PQ);
// I.S Prio queue makanan terdefinisi
// F.S Seluruh makanan dalam prio queue makanan dikurangi waktu sisa delivery sebanyak 1 menit

void DequeueZeroToInventory(PrioQueueMakanan *PQ, Simulator *s);
// I.S Prio queue makanan dan simulator terdefinisi
// F.S Seluruh makanan dengan sisa waktu delivery sama dengan nol di-dequeue dan dimasukkan ke inventory 

#endif