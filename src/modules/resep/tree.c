/* File : tree.c */
/* ADT pohon N-Ary */
/* Representasi AddressTree dengan pointer */
/* TreeElType adalah integer */

#include "../boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* Definisi PohonBiner */
/* pohon Biner kosong p = NULL */

void CreateListBahan(ListIDBahan * List) {

   int i = 0;

   for (i; i<CAPACITY; i++) {
      ELMTLB(*List,i) = VAL_UNDEF;
   }
}

BinTree NewTree (TreeElType info, BinTree fc, BinTree nsb) {
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

   BinTree p;
   p = (BinTree) malloc(sizeof(TreeNode));
   if (p != NULL) {
      INFOTREE(p) = info;
      FCHD(p) = fc;
      NSBG(p) = nsb;
   }
   return p;

} 

void CreateTree (TreeElType info, BinTree fc, BinTree nsb, BinTree *p) {
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */
   
   *p = NewTree(info, fc, nsb);

}

AddressTree newTreeNode(TreeElType val) {
/* Alokasi sebuah addressTreeAddressTree p, bernilai tidak NULL jika berhasil */
/* Mengirimkan addressTreeAddressTree hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka addressTreeAddressTree tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

   AddressTree p;
   p = (AddressTree) malloc(sizeof(TreeNode));
   if (p != NULL) {
      INFOTREE(p) = val;
      FCHD(p) = NULL;
      NSBG(p) = NULL;
   }

   return p;
}

ListIDBahan listBahan(AddressTree targetMakanan) {
// Memberikan keluaran ListIDBahan dari input addressTreeAddressTree targetMakanan

   AddressTree fc = FCHD(targetMakanan);
   ListIDBahan listID;
   int i = 0;

   CreateListBahan(&listID);

   while (fc != NULL) {
      ELMTLB(listID,i) = INFOTREE(fc);
      fc = NSBG(fc);
   } 

   return listID;
}

int lengthListBahan (ListIDBahan listID) {
   // Memberi keluaran panjang listID

   return sizeof(listID.bahan)/sizeof(int);
}

void copyListBahan(ListIDBahan *listID1, ListIDBahan *listID2) {
   // I.S listID1 terdefinisi dan listID2 belum terdefinisi
   // F.S. Menyalin isi listIDBahan listID1 ke listID2

   int i = 0;

   CreateListBahan(listID2);
   for (i; i<CAPACITY; i++) {
      (*listID2).bahan[i] = (*listID1).bahan[i]; 
   }
   
}

AddressTree searchByID(TreeElType id, BinTree resep) {
// Memberi keluaran addressTreeAddressTree dari makanan berdasarkan input id dan resep

   TreeElType root = INFOTREE(resep);
   AddressTree fc = FCHD(resep);
   AddressTree p;  

   if (root == id) {
      p = resep;
   } 

   if (fc != NULL && p == NULL) {
      return searchByID(id, fc);
   }
   
   if (NSBG(resep) != NULL && p == NULL) { 
      return searchByID(id, NSBG(resep));
   }

   return p;

}

void printListResep(BinTree resep, Peta p, ListStatik l) {   // Masih perlu revisi di bagian conditional
// Mencetak List Resep 

   int i = 0;
   int idx = 1;
   AddressTree fc;
   Makanan target, bahan;

   if (FCHD(FCHD(resep)) != NULL && resep != NULL) {
      target = getFoodByID(INFOTREE(resep), l);
      int nBahan = lengthListBahan(listBahan(resep));

      printf("%d. %s\n", idx, target.name);
      showProcess(target, p);
      printf(" - ");

      for (i; i<nBahan; i++) {
         bahan = getFoodByID(listBahan(resep).bahan[i], l);
         printf("%s", bahan.name);
         if (i<nBahan-1) {
            printf(" - ");
         } else {
            printf("\n");
         };
      }

      idx++;
   }

   fc = FCHD(resep);
   printListResep(fc, p, l);
   printListResep(NSBG(resep), p, l);
}

void printKatalog(BinTree resep, Peta p, ListStatik l) {   // Belum tahu nama proses buy
// Mencetak Katalog

   int i = 0;
   int idx = 1;
   AddressTree fc;
   Makanan target, bahan;

   if (FCHD(resep) != NULL && resep != NULL) {
      target = getFoodByID(INFOTREE(resep), l);
      int nBahan = lengthListBahan(listBahan(resep));

      printf("%d. %s\n", idx, target.name);
      showProcess(target, p);
      printf(" - ");

      for (i; i<nBahan; i++) {
         bahan = getFoodByID(listBahan(resep).bahan[i], l);
         printf("%s", bahan.name);
         if (i<nBahan-1) {
            printf(" - ");
         } else {
            printf("\n");
         };
      }

      idx++;
   }

   fc = FCHD(resep);
   printListResep(fc, p, l);
   printListResep(NSBG(resep), p, l);
}

void showProcess (Makanan target, Peta p) {
// Menunjukkan process dari suatu makanan 

   if (EQ(target.loc, Locate(p, 'B'))) {
      printf("BOIL"); 
   } else if (EQ(target.loc, Locate(p, 'C'))) {
      printf("CHOP"); 
   } else if (EQ(target.loc, Locate(p, 'F'))) {
      printf("FRY"); 
   } else {
      printf("MIX"); 
   }

}