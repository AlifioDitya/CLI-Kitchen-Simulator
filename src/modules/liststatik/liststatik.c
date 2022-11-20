#include <stdio.h>
#include "liststatik.h"

/* ********** KONSTRUKTOR ********** */
void CreateListStatik(ListStatik *l) {
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */
    Neff(*l) = 0;
}

void createSpecificCatalog(ListStatik *specList, ListStatik catalog, Peta p, String mode) {
    int i;
    char label;

    if (isBuy(mode)) {
        label = 'T';
    } else if (isBoil(mode)) {
        label = 'B';
    } else if (isFry(mode)) {
        label = 'F';
    } else if (isChop(mode)) {
        label = 'C';
    } else if (isMix(mode)) {
        label = 'M';
    } else {
        label = 'T';
    }

    CreateListStatik(specList);
    for (i=0; i<catalog.nEff; i++) {
        if (EQ(ActionLoc(Elmt(catalog, i)), Locate(p, label))) {
            insertLast(specList, Elmt(catalog, i));
        }
    }
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
        else{
            i++ ; 
        }
        
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
    
    ADVWORDFILE();

    for (i=0; i<n; i++) {
        ID = 0;
        for (j=0; j<currentWord.Length; j++) {
            ID = ID*10 + ((int) currentWord.TabWord[j]-'0');
        }
        setID(&currMakanan, ID);

        advStringFILE();
        setFoodName(&currMakanan, currentString);

        ADVWORDFILE();
        DD = 0;
        for (k=0; k<currentWord.Length; k++) {
            DD = DD*10 + ((int) currentWord.TabWord[k]-48);
        }
        ADVWORDFILE();
        HH = 0;
        for (k=0; k<currentWord.Length; k++) {
            HH = HH*10 + ((int) currentWord.TabWord[k]-48);
        }
        ADVWORDFILE();
        MM = 0;
        for (k=0; k<currentWord.Length; k++) {
            MM = MM*10 + ((int) currentWord.TabWord[k]-48);
        }
        
        CreateTime(&expire, DD, HH, MM);
        setExpiryDate(&currMakanan, expire);
        
        ADVWORDFILE();
        DD = 0;
        for (k=0; k<currentWord.Length; k++) {
            DD = DD*10 + ((int) currentWord.TabWord[k]-48);
        }
        ADVWORDFILE();
        HH = 0;
        for (k=0; k<currentWord.Length; k++) {
            HH = HH*10 + ((int) currentWord.TabWord[k]-48);
        }
        ADVWORDFILE();
        MM = 0;
        for (k=0; k<currentWord.Length; k++) {
            MM = MM*10 + ((int) currentWord.TabWord[k]-48);
        }
        
        CreateTime(&delivery, DD, HH, MM);
        setDeliveryTime(&currMakanan, delivery);

        advStringFILE();
        
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
        
        insertLast(l, currMakanan);

        if (i != (n-1)) {
            ADVWORDFILE();
        } else {
            endWord = true;
        }
    }
}

void displayCatalog(ListStatik catalog, Peta p) {
// I.S Catalog terdefinisi
// F.S Catalog terdisplay
    int i;

    printf("List Makanan:\n");
    printf("(Nama - Durasi kedaluwarsa - Aksi yang diperlukan - Delivery time)\n");
    for (i=0; i<listLength(catalog); i++) {
        printf("%d. ", i+1);
        printString(FoodName(Elmt(catalog, i)));

        printf(" - ");
        if (Day(Expire(Elmt(catalog, i))) != 0) {
            printf("%d Hari", Day(Expire(Elmt(catalog, i))));
            if (Hour(Expire(Elmt(catalog, i))) != 0 && Minute(Expire(Elmt(catalog, i))) != 0) {
                printf(", ");
            }
        }
        if (Hour(Expire(Elmt(catalog, i))) != 0) {
            printf("%d Jam", Hour(Expire(Elmt(catalog, i))));
            if (Minute(Expire(Elmt(catalog, i))) != 0) {
                printf(", ");
            }
        }
        if (Minute(Expire(Elmt(catalog, i))) != 0) {
            printf("%d Menit", Minute(Expire(Elmt(catalog, i))));
        }

        printf(" - ");
        if (EQ(ActionLoc(Elmt(catalog, i)), Locate(p, 'T'))) {
            printf("BUY");
        } else if (EQ(ActionLoc(Elmt(catalog, i)), Locate(p, 'C'))) {
            printf("CHOP");
        } else if (EQ(ActionLoc(Elmt(catalog, i)), Locate(p, 'F'))) {
            printf("FRY");
        } else if (EQ(ActionLoc(Elmt(catalog, i)), Locate(p, 'B'))) {
            printf("BOIL");
        } else if (EQ(ActionLoc(Elmt(catalog, i)), Locate(p, 'M'))) {
            printf("MIX");
        } else {
            printf("undefined");
        }

        if ((Day(DeliveryTime(Elmt(catalog, i))) != 0) || (Hour(DeliveryTime(Elmt(catalog, i))) != 0) || (Minute(DeliveryTime(Elmt(catalog, i))) != 0)) {
            printf(" - ");
        } else {
            printf(" - Non-delivery");
        }
        if (Day(DeliveryTime(Elmt(catalog, i))) != 0) {
            printf("%d Hari", Day(DeliveryTime(Elmt(catalog, i))));
            if (Hour(DeliveryTime(Elmt(catalog, i))) != 0 && Minute(DeliveryTime(Elmt(catalog, i))) != 0) {
                printf(", ");
            }
        }
        if (Hour(DeliveryTime(Elmt(catalog, i))) != 0) {
            printf("%d Jam", Hour(DeliveryTime(Elmt(catalog, i))));
            if (Minute(DeliveryTime(Elmt(catalog, i))) != 0) {
                printf(", ");
            }
        }
        if (Minute(DeliveryTime(Elmt(catalog, i))) != 0) {
            printf("%d Menit", Minute(DeliveryTime(Elmt(catalog, i))));
        }
        printf("\n");
    }
}