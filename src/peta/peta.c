#include <stdio.h>
#include "../boolean.h"
#include "peta.h"

/* *** Konstruktor membentuk Matrix peta *** */
void createPeta(int nRows, int nCols, Peta *p) {
    ROW_EFF(*p) = nRows;
    COL_EFF(*p) = nCols;
}
/* Membentuk sebuah peta "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Getter *** */
boolean isIdxValid(int i, int j) {
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks peta */
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

int getLastIdxRow(Peta p) {
/* Mengirimkan Index baris terbesar p */
    return ROW_EFF(p)-1;
}

int getLastIdxCol(Peta p) {
/* Mengirimkan Index kolom terbesar p */
    return COL_EFF(p)-1;
}

boolean isIdxEff(Peta p, int i, int j) {
/* Mengirimkan true jika i, j adalah Index efektif bagi p */
    return(i >= 0 && j >= 0 && i < ROW_EFF(p) && j < COL_EFF(p));
}

/* ********** Assignment Peta ********** */
void copyPeta(Peta pIn, Peta *pOut) {
/* Melakukan assignment pOut <- pIn */
    int i, j;
    ROW_EFF(*pOut) = ROW_EFF(pIn);
    COL_EFF(*pOut) = COL_EFF(pIn);
    for (i=0; i<ROW_EFF(pIn); i++) {
        for (j=0; j<COL_EFF(pIn); j++) {
            ELMT(*pOut, i, j) = ELMT(pIn, i, j);
        }
    }
}



/* ********** KELOMPOK BACA/TULIS ********** */
void readPeta(Peta *p, int nRow, int nCol) {
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. p terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreatePeta(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks peta :
# # #
# # #
# # # 
*/
    int i;
    int j;

    createMatrix(nRow, nCol, p);
    for (i=0; i<ROW_EFF(*p); i++) {
        for (j=0; j<COL_EFF(*p); j++) {
            int val;
            scanf("%c", &val);
            ELMT(*p, i, j) = val;
        }
    }
}

void displayPeta(Peta p) {
/* I.S. m terdefinisi */
/* F.S. Nilai p(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen p ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis peta 3x3
# # #
# # #
# # #
*/
    int i;
    int j;

    for (i=0; i<ROW_EFF(p); i++) {
        for (j=0; j<COL_EFF(p); j++) {
            if (j != COL_EFF(p)-1) {
                printf("%c ", ELMT(p, i, j));
            }
            else {
                printf("%c\n", ELMT(p, i, j));
            }
        }
    }
}