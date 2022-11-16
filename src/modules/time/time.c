/* Enrique Alifio Ditya */
/* 13521142 */
/* 4 September 2022 */
/* REALISASI TIME */

#include <stdio.h>
#include "time.h"

/* REALISASI PRIMITIF                                                */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int D, int H, int M) {
/* Mengirim true jika D,H,M dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
// KAMUS LOKAL
// ALGORITMA
    if (D >= 0 && H >= 0 && H <= 23 && M >= 0 && M <= 59) {
        return true;
    }
    else {
        return false;
    }
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int D, int H, int M) {
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : D, H, M valid untuk membentuk TIME */
// KAMUS LOKAL
// ALGORITMA
    Day(*T) = D;
    Hour(*T) = H;
    Minute(*T) = M;
}

void TulisTIME (TIME T) {
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format DD:HH:MM */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
// KAMUS LOKAL
// ALGORITMA
    printf("%02d:%02d:%02d\n", Day(T), Hour(T), Minute(T));
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
long TIMEToMinute (TIME T) {
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah menit dari waktu 0:0:0 */
// KAMUS LOKAL
// ALGORITMA
    return (1440*Day(T) + 60*Hour(T) + Minute(T));
}

TIME MinuteToTIME (long N) {
/* Mengirim  konversi menit ke TIME */
/* Pre-kondisi: N >= 0 */
// KAMUS LOKAL
    TIME result;
// ALGORITMA
    if (N >= 0) {
        CreateTime (&result, N/1440, (N % 1440) / 60, (N % 1440) % 60);
    } else {
        CreateTime (&result, 0, 0, 0);
    }
    return result;
}

/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2) {
/* Mengirimkan true jika T1=T2, false jika tidak */
// KAMUS LOKAL
// ALGORITMA
    return (Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2) && Day(T1) == Day(T2));
}

boolean TNEQ (TIME T1, TIME T2) {
/* Mengirimkan true jika T1 tidak sama dengan T2 */
// KAMUS LOKAL
// ALGORITMA
    return (!(TEQ(T1, T2)));
}

boolean TLT (TIME T1, TIME T2) {
/* Mengirimkan true jika T1<T2, false jika tidak */
// KAMUS LOKAL
// ALGORITMA
    return (TIMEToMinute(T1) < TIMEToMinute(T2));
}

boolean TGT (TIME T1, TIME T2) {
/* Mengirimkan true jika T1>T2, false jika tidak */
// KAMUS LOKAL
// ALGORITMA
    return (TIMEToMinute(T1) > TIMEToMinute(T2));
}

/* *** Operator aritmatika TIME *** */
TIME NextMinute (TIME T) {
/* Mengirim 1 menit setelah T dalam bentuk TIME */
// KAMUS LOKAL
// ALGORITMA
    return MinuteToTIME(TIMEToMinute(T)+1);
}

TIME NextNMinute (TIME T, int N) {
/* Mengirim N Minute setelah T dalam bentuk TIME */
// KAMUS LOKAL
// ALGORITMA
    return MinuteToTIME(TIMEToMinute(T)+N);
}

TIME PrevMinute (TIME T) {
/* Mengirim 1 menit sebelum T dalam bentuk TIME */
// KAMUS LOKAL
// ALGORITMA
    return MinuteToTIME(TIMEToMinute(T)-1);
}

TIME PrevNMinute (TIME T, int N) {
/* Mengirim N menit sebelum T dalam bentuk TIME */
// KAMUS LOKAL
// ALGORITMA
    return MinuteToTIME(TIMEToMinute(T)-N);
}

void AdvMinute(TIME *T) {
    TIME temp = NextMinute(*T);
    Day(*T) = Day(temp);
    Hour(*T) = Hour(temp);
    Minute(*T) = Minute(temp);
}

void AdvNMinute(TIME *T, int N) {
    TIME temp = NextNMinute(*T, N);
    Day(*T) = Day(temp);
    Hour(*T) = Hour(temp);
    Minute(*T) = Minute(temp);
}

void DecMinute(TIME *T) {
    TIME temp = PrevMinute(*T);
    Day(*T) = Day(temp);
    Hour(*T) = Hour(temp);
    Minute(*T) = Minute(temp);
}

void DecNMinute(TIME *T, int N) {
    TIME temp = PrevNMinute(*T, N);
    Day(*T) = Day(temp);
    Hour(*T) = Hour(temp);
    Minute(*T) = Minute(temp);
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh) {
/* Mengirim TAkh-TAw dlm Menit, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
// KAMUS LOKAL
// ALGORITMA
    if (TIMEToMinute(TAw) <= TIMEToMinute(TAkh)) {
        return (TIMEToMinute(TAkh) - TIMEToMinute(TAw));
    }
    else {
        return (1440 + (TIMEToMinute(TAkh) - TIMEToMinute(TAw)));
    }
}
