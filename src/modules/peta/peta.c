#include <stdio.h>
#include "peta.h"
// #include "../simulator/simulator.c"
// #include "../point/point.c"
// #include "../word-machine/wordmachine.c"

/* *** Konstruktor membentuk Matrix peta *** */
void createPeta(int nRows, int nCols, Peta *p) {
/* Membentuk sebuah peta "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    ROW_EFF(*p) = nRows;
    COL_EFF(*p) = nCols;
}

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
void readPeta(char* filename, Peta *pOut) {
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. p terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreatePeta(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom dari file */
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
    int i, j;
    int nRow, nCol;
    int loc;

    loc = 0;

    STARTWORDFILE(filename);

    while (!endWord) {
        boolean done;
        if (loc == 0) {
            nRow = 0;
            for (i=0; i<currentWord.Length; i++) {
                nRow = nRow*10 + ((int) currentWord.TabWord[i]-48);
            }
        } else if (loc == 1) {
            nCol = 0;
            for (i=0; i<currentWord.Length; i++) {
                nCol = nCol*10 + ((int) currentWord.TabWord[i]-48);
            }
        } else {
            createPeta(nRow, nCol, pOut);
            for (i=0; i<currentWord.Length; i++) {
                ELMT(*pOut, loc-2, i) = currentWord.TabWord[i];
                if ((loc-1 == nRow) && (i == currentWord.Length-1)) {
                    done = true;
                }
            }
        }

        if (done) {
            endWord = true;
        } else {
            ADVWORDFILE();
            loc++;
        }
    }
}

void displayPeta(Peta p) {
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
    int i;
    int j;

    for (i=0; i<ROW_EFF(p)+2; i++) {
        printf("*");

        if (i < ROW_EFF(p)+1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    for (i=0; i<ROW_EFF(p); i++) {
        printf("* ");
        for (j=0; j<COL_EFF(p); j++) {
            if (ELMT(p, i, j) == '#') {
                printf(" ");
            } else {
                printf("%c", ELMT(p, i, j));
            }
            printf(" ");
        }
        printf("*\n");
    }


    for (i=0; i<ROW_EFF(p)+2; i++) {
        printf("*");
        if (i < ROW_EFF(p)+1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}

boolean canMoveEast(Simulator s, Peta p) {
    return (isIdxEff(p, Ordinat(Loc(s)), (Absis(Loc(s)) + 1)) && ELMT(p, Ordinat(Loc(s)), (Absis(Loc(s)) + 1)) == '#');
}

boolean canMoveWest(Simulator s, Peta p) {
    return (isIdxEff(p, Ordinat(Loc(s)), (Absis(Loc(s)) - 1)) && ELMT(p, Ordinat(Loc(s)), (Absis(Loc(s)) - 1)) == '#');
}

boolean canMoveNorth(Simulator s, Peta p) {
    return (isIdxEff(p, (Ordinat(Loc(s)) - 1), Absis(Loc(s))) && ELMT(p, (Ordinat(Loc(s)) - 1), Absis(Loc(s))) == '#');
}

boolean canMoveSouth(Simulator s, Peta p) {
    return (isIdxEff(p, (Ordinat(Loc(s)) + 1), Absis(Loc(s))) && ELMT(p, (Ordinat(Loc(s)) + 1), Absis(Loc(s))) == '#');
}

/* Operasi menggerakkan user pada peta */
void moveEast(Simulator *s, Peta *p) {
/* Menggerakkan posisi user ke kanan pada peta*/
    ElType temp;
    if (canMoveEast(*s, *p)) {
        temp = ELMT(*p, Ordinat(Loc(*s)), (Absis(Loc(*s))));
        ELMT(*p, Ordinat(Loc(*s)), (Absis(Loc(*s)))) = ELMT(*p, Ordinat(Loc(*s)), (Absis(Loc(*s)) + 1));
        ELMT(*p, Ordinat(Loc(*s)), (Absis(Loc(*s)) + 1)) = temp;
        shiftPoint(&Loc(*s), 1, 0);
    }
}

void moveWest(Simulator *s, Peta *p) {
/* Menggerakkan posisi user ke kiri pada peta*/
    ElType temp;
    if (canMoveWest(*s, *p)) {
        temp = ELMT(*p, Ordinat(Loc(*s)), Absis(Loc(*s)));
        ELMT(*p, Ordinat(Loc(*s)), Absis(Loc(*s))) = ELMT(*p, Ordinat(Loc(*s)), (Absis(Loc(*s)) - 1));
        ELMT(*p, Ordinat(Loc(*s)), (Absis(Loc(*s)) - 1)) = temp;
        shiftPoint(&Loc(*s), (-1), 0);
    }
}

void moveNorth(Simulator *s, Peta *p) {
/* Menggerakkan posisi user ke atas pada peta*/
    ElType temp;
    if (canMoveNorth(*s, *p)) {
        temp = ELMT(*p, Ordinat(Loc(*s)), Absis(Loc(*s)));
        ELMT(*p, Ordinat(Loc(*s)), Absis(Loc(*s))) = ELMT(*p, (Ordinat(Loc(*s)) - 1), Absis(Loc(*s)));
        ELMT(*p, (Ordinat(Loc(*s)) - 1), Absis(Loc(*s))) = temp;
        shiftPoint(&Loc(*s), 0, (-1));
    }
}

void moveSouth(Simulator *s, Peta *p) {
/* Menggerakkan posisi user ke bawah pada peta*/
    ElType temp;
    if (canMoveSouth(*s, *p)) {
        temp = ELMT(*p, Ordinat(Loc(*s)), Absis(Loc(*s)));
        ELMT(*p, Ordinat(Loc(*s)), Absis(Loc(*s))) = ELMT(*p, (Ordinat(Loc(*s)) + 1), Absis(Loc(*s)));
        ELMT(*p, (Ordinat(Loc(*s)) + 1), Absis(Loc(*s))) = temp;
        shiftPoint(&Loc(*s), 0, 1);
    }
}
  
/* Mengetahui posisi pada peta */
boolean isObjectInRadius(Simulator s, Peta p, char object) {
/* Mengecek apabila object ada pada sekitar user */
    int i, j;
    boolean found;

    found = false;
    for (i=Ordinat(Loc(s))-1; i<=Ordinat(Loc(s))+1; i++) {
        for (j=Absis(Loc(s))-1; j<=Absis(Loc(s))+1; j++) {
            if (isIdxEff(p, i, j) && (i != Ordinat(Loc(s)) || j != Absis(Loc(s)))) {
                if (ELMT(p, i, j) == object) {
                    found = true;
                    break;
                }
            }
        }
    }
    return found;
}

Point Locate(Peta p, char object) {
/* Mengembalikan posisi (koordinat) pertama kali ditemukan object bertipe char dalam peta */
/* Mengembalikan POINT_UNDEF jika object tidak dalam peta */
    int i, j;
    Point loc;
    boolean found;

    found = false; 
    for (i=0; i<ROW_EFF(p); i++) {
        for (j=0; j<COL_EFF(p); j++) {
            if (ELMT(p, i, j) == object) {
                CreatePoint(&loc, j, i);
                found = true;
                break;
            }
        }
    }

    if (found) {
        return loc;
    } else {
        CreatePoint(&loc, POINT_UNDEF, POINT_UNDEF);
        return loc;
    }
}