/* File: time.h */
/* Tanggal: 3 September 2022 */
/* Definisi ADT TIME */

#ifndef TIME_H
#define TIME_H

#define TIME_UNDEF (-1)

#include "../boolean.h" 

/* *** Definisi TYPE TIME <HH:MM:SS> *** */
typedef struct { 
	int D; /* integer >= 0 */
	int H; /* integer [0..23] */
	int M; /* integer [0..59] */
} TIME;

/* *** Notasi Akses: selektor TIME *** */
#define Day(T) (T).D
#define Hour(T) (T).H
#define Minute(T) (T).M

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int D, int H, int M);
/* Mengirim true jika D,H,M dapat membentuk T yang valid */

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int D, int H, int M);
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : D, H, M valid untuk membentuk TIME */
   
void TulisTIME (TIME T);
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format DD:HH:MM */
/* Proses : menulis nilai setiap komponen T ke layar dalam format DD:HH:MM */ 

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
long TIMEToMinute (TIME T);
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah menit dari waktu 0:0:0 */
// KAMUS LOKAL
// ALGORITMA

TIME MinuteToTIME (long N);
/* Mengirim  konversi menit ke TIME */
/* Pre-kondisi: N >= 0 */
// KAMUS LOKAL

/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2);
/* Mengirimkan true jika T1=T2, false jika tidak */
boolean TNEQ (TIME T1, TIME T2);
/* Mengirimkan true jika T1 tidak sama dengan T2 */
boolean TLT (TIME T1, TIME T2);
/* Mengirimkan true jika T1<T2, false jika tidak */
boolean TGT (TIME T1, TIME T2);
/* Mengirimkan true jika T1>T2, false jika tidak */

/* *** Operator aritmatika TIME *** */
TIME NextMinute (TIME T);
/* Mengirim 1 Minute setelah T dalam bentuk TIME */
TIME NextNMinute (TIME T, int N);
/* Mengirim N Minute setelah T dalam bentuk TIME */
TIME PrevMinute (TIME T);
/* Mengirim 1 Minute sebelum T dalam bentuk TIME */
TIME PrevNMinute (TIME T, int N);
/* Mengirim N Minute sebelum T dalam bentuk TIME */

void AdvMinute(TIME *T);
/* I.S T terdefinisi */
/* F.S Increment waktu T sebanyak 1 menit */
void AdvNMinute(TIME *T, int N);
/* I.S T terdefinisi */
/* F.S Increment waktu T sebanyak N menit */
void DecMinute(TIME *T);
/* I.S T terdefinisi */
/* F.S Decrement waktu T sebanyak 1 menit */
void DecNMinute(TIME *T, int N);
/* I.S T terdefinisi */
/* F.S Decrement waktu T sebanyak N menit */

/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh);
/* Mengirim TAkh-TAw dlm menit, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */

#endif