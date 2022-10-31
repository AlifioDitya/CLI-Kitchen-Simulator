#ifndef PETA_H
#define PETA_H

#include "../boolean.h"
#include "../simulator/simulator.h"
// #include "../point/point.h"

#define ROW_CAP 100
#define COL_CAP 100

typedef char ElType;
typedef struct {
    ElType mem[ROW_CAP][COL_CAP];
    int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
    int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Peta;

/* *** Konstruktor membentuk Matrix peta *** */
void createPeta(int nRows, int nCols, Peta *p);
/* Membentuk sebuah peta "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROW_EFF(P) (P).rowEff
#define COL_EFF(P) (P).colEff
#define ELMT(P, i, j) (P).mem[(i)][(j)]

/* *** Getter *** */
boolean isIdxValid(int i, int j);
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks peta */
int getLastIdxRow(Peta p);
/* Mengirimkan Index baris terbesar p */
int getLastIdxCol(Peta p);
/* Mengirimkan Index kolom terbesar p */
boolean isIdxEff(Peta p, int i, int j);
/* Mengirimkan true jika i, j adalah Index efektif bagi p */

/* ********** Assignment Peta ********** */
void copyPeta(Peta pIn, Peta *pOut);
/* Melakukan assignment pOut <- pIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readPeta(char* filename, Peta *pOut, Simulator *s);
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. p terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreatePeta(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 10 dan nCol = 10, maka cara membaca isi matriks peta dari file :
S#########
####T##X##
#M#####X##
#######X##
####XXXX##
#X########
#X######C#
#XXX##F###
##########
######B###
*/
void displayPeta(Peta p);
/* I.S. m terdefinisi */
/* F.S. Nilai p(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen p ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis peta 10x10
* * * * * * * * * * * *
* S                   *
*         T     X     *
*   M           X     *
*               X     *
*         X X X X     *
*   X                 *
*   X             C   *
*   X X X     F       *
*                     *
*             B       *
* * * * * * * * * * * *
*/

/* Operasi menggerakkan user pada peta */
void moveEast(Simulator *s, Peta *p);
/* Menggerakkan posisi user ke kanan pada peta*/
void moveWest(Simulator *s, Peta *p);
/* Menggerakkan posisi user ke kiri pada peta*/
void moveNorth(Simulator *s, Peta *p);
/* Menggerakkan posisi user ke atas pada peta*/
void moveSouth(Simulator *s, Peta *p);
/* Menggerakkan posisi user ke bawah pada peta*/

/* Mengetahui posisi pada peta */
boolean isObjectInRadius(Simulator s, Peta p, char object);
/* Mengecek apabila symbol ada pada sekitar user */
Point Locate(Peta p, char object);
/* Mencari posisi (koordinat) object bertipe char dalam peta */
/* Mengembalikan POINT_UNDEF jika object tidak dalam peta */


#endif