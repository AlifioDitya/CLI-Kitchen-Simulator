#include <stdio.h>
#include "liststatik.h"

void CreateListStatik(ListStatik *l){
    for (int i=0 ; i<CAPACITY; i++) {
        ELMT(*l,i)=MARK; 
    }
};

int listLength(ListStatik l) {
    int counter = 0 ; 
    while (counter!=CAPACITY && ELMT(l ,counter)!=MARK) 
    { 
        counter++ ; 
    }
    return counter  ; 
};

IdxType getFirstIdx(ListStatik l) {
    
    return IDX_MIN;
}; 

IdxType getLastIdx(ListStatik l) {
    
    return listLength(l) - 1 ;
}; 

boolean isIdxValid(ListStatik l, IdxType i) {
    return ((i >= IDX_MIN)&&(i < CAPACITY));
};

boolean isIdxEff(ListStatik l, IdxType i) {
    return ((i >= IDX_MIN)&&(i < listLength(l)));
} 

boolean isEmpty(ListStatik l) {
    return listLength(l)==0 ;
};

boolean isFull(ListStatik l) {
    return listLength(l)==CAPACITY;
};

void readList(ListStatik *l) {
    int n  ; 
    scanf("%d", &n) ; 
    while (n<IDX_MIN || n> CAPACITY)
    {
        scanf("%d", &n) ; 
    }
    for (int k = 0 ; k < n ; k++ )
    { 
        scanf("%d", ELMT(*l,k))  ; 
    }
};

void printList(ListStatik l) {
    int len = listLength(l) ; 
    printf("[") ; 
    for ( int i = 0 ; i< len ; i ++ ) 
    { 
        if (i!=0) printf(",") ; 
        printf("%d" , ELMT(l,i)); 
    }
    printf("]") ; 
};

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    ListStatik lstatik;
    int i;
    int len = listLength(l1) ; 

    CreateListStatik(&lstatik) ; 

    for ( i=0;i< len;i++){
		
		if (plus==true){
			ELMT(lstatik,i) =ELMT(l1,i) +ELMT(l2,i);
		}
	 	else{
			ELMT(lstatik,i) =ELMT(l1,i) -ELMT(l2,i);
		};
    }
};

boolean isListEqual(ListStatik l1, ListStatik l2) {
    int len1 = listLength(l1) , len2 = listLength(l2) ;  
    if (len1 == len2) 
    { 
        boolean equal = true;
        int i = 0 ; 
        while (i< len1 && equal )  
        { 
            if(ELMT(l1,i) != ELMT(l2 , i ))
            { 
                equal = false ; 
            }
        }
        if (equal) 
        {
            return true ; 
        }
        else 
        { 
            return false ; 
        }
    }
    else  
    {  
        return false;
    }  
}

int indexOf(ListStatik l, ElType val) {
    int i = 0 , len = listLength(l) ;
    boolean found = true ;  
    while (i<len && found)
    { 
        if (ELMT(l,i)==val)
        { 
            found = false ; 
        }
        i++ ; 
    }
    return i; 

}

void extremeValues(ListStatik l, ElType *max, ElType *min) {
    int i, len;
   // Algoritma
    len = listLength(l);
    *max = *min = ELMT(l,0);
    for (i = 1;i < len;i++){
      if (ELMT(l,i) > *max) *max = ELMT(l,i);
      if (ELMT(l,i) < *min) *min = ELMT(l,i);
    } 
};


/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val)
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
{
   // Kamus Lokal
   int last_idx,i;
   // Algoritma
   last_idx = getLastIdx(*l);
   for (i = last_idx;i >= 0;i--){
      ELMT(*l,i+1) = ELMT(*l,i);
   }
   ELMT(*l,0) = val;
}
void insertAt(ListStatik *l, ElType val, IdxType idx)
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
{
   // Kamus Lokal
   int last_idx,i;
   // Algoritma
   last_idx = getLastIdx(*l);
   for (i = last_idx;i >= idx;i--){
      ELMT(*l,i+1) = ELMT(*l,i);
   }
   ELMT(*l,idx) = val;
}
void insertLast(ListStatik *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
   // Kamus Lokal
   int last_idx;
   // Algoritma
   last_idx = getLastIdx(*l);
   ELMT(*l,last_idx+1) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val)
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
   // Kamus Lokal
   int idx_val,i,last_idx;
   // Algoritma
   last_idx = getLastIdx(*l);
   *val = ELMT(*l,0);
   ELMT(*l,0) = MARK;
   for (i = 1;i <= last_idx;i++){
      ELMT(*l,i-1) = ELMT(*l,i);
      ELMT(*l,i) = MARK;
   }
}
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx)
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
   // Kamus Lokal
   int i,last_idx;
   // Algoritma
   last_idx = getLastIdx(*l);
   *val = ELMT(*l,idx);
   ELMT(*l,idx) = MARK;
   for (i = idx+1;i <= last_idx;i++){
      ELMT(*l,i-1) = ELMT(*l,i);
      ELMT(*l,i) = MARK;
   }
}
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
   // Kamus Lokal
   int last_idx;
   // Algoritma
   last_idx = getLastIdx(*l);
   *val = ELMT(*l,last_idx);
   ELMT(*l,last_idx) = MARK;
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
   // Kamus Lokal
   int i, j, last_idx, tmp;
   // Algoritma
   last_idx = getLastIdx(*l);
   for (i = 1;i <= last_idx;i++){
      tmp = ELMT(*l,i);
      j = i-1;
      if (asc){
         while (j >= 0 && tmp < ELMT(*l,j)){
            ELMT(*l,j+1) = ELMT(*l,j);
            j--;
         }
      } else {
         while (j >= 0 && tmp > ELMT(*l,j)){
            ELMT(*l,j+1) = ELMT(*l,j);
            j--;
         }
      }
      ELMT(*l,j+1) = tmp;
   }
}
 