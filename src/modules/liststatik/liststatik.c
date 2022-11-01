#include <stdio.h>
#include "liststatik.h"
// #include "../makanan/makanan.c"

/* ********** KONSTRUKTOR ********** */
void CreateListStatik(ListStatik *l) {
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */
    Neff(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l) {
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  
    return Neff(l);
};

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    return IDX_MIN;
}; 

IdxType getLastIdx(ListStatik l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return listLength(l) - 1 ;
}; 

/* ********** Test Indeks yang valid ********** */
boolean isIdxListValid(ListStatik l, IdxType i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= IDX_MIN)&&(i < CAPACITY));
};

boolean isIdxListEff(ListStatik l, IdxType i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
    return ((i >= IDX_MIN)&&(i < listLength(l)));
} 

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isListEmpty(ListStatik l) {
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
    return listLength(l)==0 ;
};

boolean isListFull(ListStatik l) {
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return listLength(l)==CAPACITY;
};

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, int IDMakanan) {
/* Search apakah ada elemen List l yang bernilai memiliki IDMakanan */
/* Jika ada, menghasilkan indeks i terkecil, dengan Elmt(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    int i = 0 , len = listLength(l);
    boolean found = true ;  
    while (i<len && found)
    { 
        if (ID(Elmt(l,i)) == IDMakanan)
        { 
            found = false;
        }
        i++ ; 
    }
    return i; 
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, Makanan val) {
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
    int i;
    for (i=listLength(*l)-1; i >= 0; i--) {
        Elmt(*l,i+1) = Elmt(*l,i);
    }
    Elmt(*l, 0) = val;
}

void insertAt(ListStatik *l, Makanan val, IdxType idx) {
// KAMUS
    int i;
// ALGORITMA
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
/* Proses: Menambahkan val sebagai elemen pada index idx List */
    for (i=listLength(*l)-1; i >= idx; i--) {
        Elmt(*l,i+1) = Elmt(*l,i);
    }
    Elmt(*l, idx) = val;   
}

void insertLast(ListStatik *l, Makanan val) {
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    Elmt(*l, getLastIdx(*l)+1) = val;
}

void deleteFirst(ListStatik *l, Makanan *val) {
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
// KAMUS
    int i;
// ALGORITMA
    *val = Elmt(*l, 0);
    for (i=0; i < getLastIdx(*l); i++) {
        Elmt(*l, i) = Elmt(*l, i+1);
    }
    Neff(*l)--;
}

/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, Makanan *val, IdxType idx) {
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
// KAMUS
    int i;
// ALGORITMA
    *val = Elmt(*l, idx);
    for (i=idx; i<getLastIdx(*l); i++) {
        Elmt(*l,i) = Elmt(*l,i+1);
    }
    Neff(*l)--;
}

/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, Makanan *val) {
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
// KAMUS
// ALGORITMA
    *val = Elmt(*l, listLength(*l)-1);
    Neff(*l)--;
}

/* Interaksi I/O */
// void printList(ListStatik l){
// /* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
//    siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
//    karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
// /* I.S. l boleh kosong */
// /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
// /* Jika List kosong : menulis [] */
// // KAMUS
//     IdxType i;
// // ALGORITMA
//     printf("[");

//     for (i=0; i<=getLastIdx(l); i++) {
//         printString(Foo(ELMT(l,i)));
//         if (i < getLastIdx(l)) {
//         printf(",");
//         }
//     }

//     printf("]");
// }