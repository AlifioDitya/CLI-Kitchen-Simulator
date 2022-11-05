#include <stdio.h>
#include "liststatik.h"

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
    return listLength(l) - 1;
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
    Neff(*l)++;
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
    Neff(*l)++;
}

void insertLast(ListStatik *l, Makanan val) {
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    // ID(Elmt(*l, getLastIdx(*l)+1)) = ID(val);
    // assignString(FoodName(val), &FoodName(Elmt(*l, getLastIdx(*l)+1)));
    // CreateTime(&Expire(Elmt(*l, getLastIdx(*l)+1)), Day(Expire(val)), Hour(Expire(val)), Minute(Expire(val)));
    // CreatePoint(&ActionLoc(Elmt(*l, getLastIdx(*l)+1)), Absis(ActionLoc(val)), Ordinat(ActionLoc(val)));
    // CreateTime(&DeliveryTime(Elmt(*l, getLastIdx(*l)+1)), Day(DeliveryTime(val)), Hour(DeliveryTime(val)), Minute(DeliveryTime(val)));
    Elmt(*l, getLastIdx(*l)+1) = val;
    Neff(*l)++;
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

/* Getter */
Makanan getFoodByID(IDType ID, ListStatik l){
    // I.S. ID Sembarang
    // membaca makanan dari file catalog
    return Elmt(l,indexOf(l,ID));
}

/* Interaksi I/O */
void readMakanan(char* filename, Peta p, ListStatik *l) {
    int n, i, j, k;
    int ID, DD, HH, MM;
    TIME expire, delivery;
    Makanan currMakanan;

    STARTWORDFILE(filename);
    n = 0;
    for (i=0; i<currentWord.Length; i++) {
        n = n*10 + ((int) currentWord.TabWord[i]-'0');
    }
    
    ADVWORD();

    for (i=0; i<n; i++) {
        ID = 0;
        for (j=0; j<currentWord.Length; j++) {
            ID = ID*10 + ((int) currentWord.TabWord[j]-'0');
        }
        setID(&currMakanan, ID);

        strfy();
        setFoodName(&currMakanan, currentString);

        ADVWORD();
        DD = 0;
        for (k=0; k<currentWord.Length; k++) {
            DD = DD*10 + ((int) currentWord.TabWord[k]-48);
        }
        ADVWORD();
        HH = 0;
        for (k=0; k<currentWord.Length; k++) {
            HH = HH*10 + ((int) currentWord.TabWord[k]-48);
        }
        ADVWORD();
        MM = 0;
        for (k=0; k<currentWord.Length; k++) {
            MM = MM*10 + ((int) currentWord.TabWord[k]-48);
        }
        
        CreateTime(&expire, DD, HH, MM);
        setExpiryDate(&currMakanan, expire);
        
        ADVWORD();
        DD = 0;
        for (k=0; k<currentWord.Length; k++) {
            DD = DD*10 + ((int) currentWord.TabWord[k]-48);
        }
        ADVWORD();
        HH = 0;
        for (k=0; k<currentWord.Length; k++) {
            HH = HH*10 + ((int) currentWord.TabWord[k]-48);
        }
        ADVWORD();
        MM = 0;
        for (k=0; k<currentWord.Length; k++) {
            MM = MM*10 + ((int) currentWord.TabWord[k]-48);
        }
        
        CreateTime(&delivery, DD, HH, MM);
        setDeliveryTime(&currMakanan, delivery);

        strfy();
        
        if (isBuy(currentString)) {
            CreatePoint(&ActionLoc(currMakanan), Absis(Locate(p, 'T')), Ordinat(Locate(p, 'T')));
        } else if (isChop(currentString)) {
            CreatePoint(&ActionLoc(currMakanan), Absis(Locate(p, 'C')), Ordinat(Locate(p, 'C')));
        } else if (isFry(currentString)) {
            CreatePoint(&ActionLoc(currMakanan), Absis(Locate(p, 'F')), Ordinat(Locate(p, 'F')));
        } else if (isBoil(currentString)) {
            CreatePoint(&ActionLoc(currMakanan), Absis(Locate(p, 'B')), Ordinat(Locate(p, 'B')));
        } else if (isMix(currentString)) {
            CreatePoint(&ActionLoc(currMakanan), Absis(Locate(p, 'M')), Ordinat(Locate(p, 'M')));
        } else {
            CreatePoint(&ActionLoc(currMakanan), POINT_UNDEF, POINT_UNDEF);
        }
        
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
        
        insertLast(l, currMakanan);
        // printf("Makanan inserted -> ");
        // printString(FoodName(Elmt(*l, getLastIdx(*l))));
        // printf("\n\n");

        if (i != (n-1)) {
            ADVWORD();
        } else {
            endWord = true;
        }
    }
}

void printListMakanan(ListStatik l){
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Jika List kosong : menulis [] */
// KAMUS
    IdxType i;
// ALGORITMA
    printf("[");
    
    for (i=0; i<=getLastIdx(l); i++) {
        printString(FoodName(Elmt(l,i)));
        if (i < getLastIdx(l)) {
            printf(", ");
        }
    }

    printf("]\n");
}