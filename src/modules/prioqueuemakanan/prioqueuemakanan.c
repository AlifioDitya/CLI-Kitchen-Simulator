#include "prioqueuemakanan.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmptyQueue (PrioQueueMakanan Q) {
    /* Mengirim true jika Q kosong: lihat definisi di atas */

    // KAMUS

    // ALGORITMA
    return (Head(Q) == Nil);
}

boolean IsFullQueue (PrioQueueMakanan Q) {
    /* Mengirim true jika tabel penampung elemen Q sudah penuh */
    /* yaitu mengandung elemen sebanyak MaxEl */

    // KAMUS

    // ALGORITMA
    return ((Tail(Q) + 1) % MaxEl(Q) == Head(Q));
}

int NBElmtQueue (PrioQueueMakanan Q) {
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

    // KAMUS

    // ALGORITMA
    if (IsEmptyQueue(Q)) {
        return 0;
    } else if (IsFullQueue(Q)) {
        return MaxEl(Q);
    } else {
        return ((Tail(Q) + MaxEl(Q) - Head(Q) + 1) % MaxEl(Q));
    }
    
}

/* *** Kreator *** */
void MakeEmptyQueue (PrioQueueMakanan * Q, int Max) {
    /* I.S. sembarang */
    /* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
    /* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
    /* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
    /* Proses : Melakukan alokasi, membuat sebuah Q kosong */

    // KAMUS

    // ALGORITMA
    (*Q).T = (infotype *) malloc ((Max) * sizeof(infotype));
    Head(*Q) = Nil;
    Tail(*Q) = Nil;

    MaxEl(*Q) = Max;
}

/* *** Destruktor *** */
void DealokasiQueue(PrioQueueMakanan * Q) {
    /* Proses: Mengembalikan memori Q */
    /* I.S. Q pernah dialokasi */
    /* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

    // KAMUS

    // ALGORITMA
    free((*Q).T);
    MaxEl(*Q) = 0;
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueMakanan * Q, infotype X) {
    /* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
    /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
    /* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
            TAIL "maju" dengan mekanisme circular buffer  */

    // KAMUS
    int i;
    infotype temp;

    // ALGORITMA
    if (IsEmptyQueue(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
    } else {
        Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
    }

    InfoTail(*Q) = X;

    i = Tail(*Q);

    while (i != Head(*Q)) {
        if (TLT(DeliveryTime((*Q).T[i]), (DeliveryTime((*Q).T[(i + MaxEl(*Q) - 1) % MaxEl(*Q)])))) {
            temp = (*Q).T[i];
            (*Q).T[i] = (*Q).T[(i + MaxEl(*Q) - 1) % MaxEl(*Q)];
            (*Q).T[(i + MaxEl(*Q) - 1) % MaxEl(*Q)] = temp;
        }

        i = (i + MaxEl(*Q) - 1) % MaxEl(*Q);
    }
    
}

void Dequeue (PrioQueueMakanan * Q, infotype * X) {
    /* Proses: Menghapus X pada Q dengan aturan FIFO */
    /* I.S. Q tidak mungkin kosong */
    /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer 
            Q mungkin kosong */

    // KAMUS

    // ALGORITMA
    *X = InfoHead(*Q);

    if (NBElmtQueue(*Q) == 1) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Head(*Q) = (Head(*Q) + 1) % MaxEl(*Q);
    }
}

/* Operasi Tambahan */
void PrintPrioQueueMakanan (PrioQueueMakanan Q) {
    /* Mencetak isi queue Q ke layar */
    /* I.S. Q terdefinisi, mungkin kosong */
    /* F.S. Q tercetak ke layar */

    // KAMUS
    int i;
    boolean cont;
    infotype currMakanan;

    // ALGORITMA
    if (!IsEmptyQueue(Q)) {
        i = Head(Q);
        cont = true;

        while (cont)
        {   
            currMakanan = (Q).T[i];
            printf("ID : %d\n", ID(currMakanan));
            printf("Food Name : ");
            printString(FoodName(currMakanan));
            printf("\n");
            printf("Expiry date : ");
            TulisTIME(Expire(currMakanan));
            printf("Action location : ");
            TulisPoint(ActionLoc(currMakanan));
            printf("Delivery time :");
            TulisTIME(DeliveryTime(currMakanan));
            printf("\n");

            if (i == Tail(Q)) {
                cont = false;
            }

            i = (i + 1) % MaxEl(Q);
        }
    }
}

void DecDeliveryTimeQueue(PrioQueueMakanan *PQ) {
    int i;
    i = Head(*PQ);
    if (!IsEmptyQueue(*PQ)) {
        do {
            DecMinute(&DeliveryTime(ElmtQueue(*PQ, i)));
            i++;
        } while ((i % (NBElmtQueue(*PQ))) != Tail(*PQ));
        if (NBElmtQueue(*PQ) != 1) {
            DecMinute(&DeliveryTime(ElmtQueue(*PQ, i)));
        }
    }
}