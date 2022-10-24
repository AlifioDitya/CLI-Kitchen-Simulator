/* File: Point.h */

#ifndef POINT_H
#define POINT_H

#include "../boolean.h"

typedef struct { 
	float X; /* absis   */
	float Y; /* ordinat */
} Point;

/* *** Notasi Akses: Selektor Point *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y


/* *** Konstruktor *** */
void CreatePoint (Point * P, float X, float Y);
/* Membentuk sebuah Point dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPoint (Point * P); 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   Point P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk Point <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPoint (Point P);
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                


/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
Point NextX (Point P);
/* Mengirim salinan P dengan absis ditambah satu */              
Point NextY (Point P);
/* Mengirim salinan P dengan ordinat ditambah satu */
Point PlusDelta (Point P, float deltaX, float deltaY);
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
void Geser (Point *P, float deltaX, float deltaY);
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */

#endif