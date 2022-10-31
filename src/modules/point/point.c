/* Realisasi Point */

#include <stdio.h>
#include "point.h"

/* *** Konstruktor *** */
void CreatePoint (Point * P, int X, int Y) {
/* Membentuk sebuah Point dari komponen-komponennya */
/* I.S P tidak terdefinisi, F.S P terdefinisi bertipe Point */
// KAMUS LOKAL
//ALGORITMA
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */ 
void BacaPoint (Point * P) {
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   Point P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk Point <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
// KAMUS LOKAL
    int X, Y;
// ALGORITMA
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}

void TulisPoint (Point P) {
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma. */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
// KAMUS
// ALGORITMA
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */ 
Point NextX (Point P) {
/* Mengirim salinan P dengan absis ditambah satu */
// KAMUS LOKAL
    Point result;
// ALGORITMA
    result = P;
    Absis(result) += 1;
    return result;
}

Point NextY (Point P) {
/* Mengirim salinan P dengan ordinat ditambah satu */
// KAMUS LOKAL
    Point result;
// ALGORITMA
    result = P;
    Ordinat(result) += 1;
    return result;
}

Point PlusDelta (Point P, int deltaX, int deltaY) {
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
// KAMUS LOKAL
    Point result;
// ALGORITMA
    result = P;
    Absis(result) += deltaX;
    Ordinat(result) += deltaY;
    return result;
}

void shiftPoint (Point *P, int deltaX, int deltaY) {
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
// KAMUS LOKAL
// ALGORITMA
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}