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

void readResep(char* filename, BinTree *r) {
   int n, i, j, k;
   int id, nChild, idChild, MM;
   AddressTree p, q, fc;
   TIME expire, delivery;
   Makanan currMakanan;

   STARTWORDFILE(filename);  
   n = 0;
   for (i=0; i<currentWord.Length; i++) {  // Baca jumlah resep
      n = n*10 + ((int) currentWord.TabWord[i]-'0');
   }
   
   ADVWORDFILE();
   *r = NULL;

   for (i=0; i<n; i++) {   // Pengulangan sebanyak jumlah resep
      
      id = 0;
      for (j=0; j<currentWord.Length; j++) {
         id = id*10 + ((int) currentWord.TabWord[j]-'0');
      }

      p = searchByID(id,*r); 
      if (p == NULL) { 
         p = newTreeNode(id);
      }

      ADVWORDFILE();

      nChild = 0;
      for (k=0; k<currentWord.Length; k++) {    // Baca jumlah bahan yang diperlukan untuk suatu resep
         nChild = nChild*10 + ((int) currentWord.TabWord[k]-48);
      }

      ADVWORDFILE();

      idChild = 0;   
      for (k=0; k<currentWord.Length; k++) {    // Baca bahan pertama untuk resep 1
         idChild = idChild*10 + ((int) currentWord.TabWord[k]-48);
      } 

      q = searchByID(idChild,*r);
      if (q == NULL) {  // Cek apakah sudah pernah dibuat node atau belum
         q = newTreeNode(idChild);
      }
      
      if (q != NULL) {
         FCHD(p) = q;
         fc = q;
      }
       
      ADVWORDFILE();
   
      for (j=1; j<nChild; j++) {    // Ulangi pembacaan id bahan sebanyak nChild jika nChild > 1

         idChild = 0;
         for (k=0; k<currentWord.Length; k++) {
            idChild = idChild*10 + ((int) currentWord.TabWord[k]-48);
         }

         q = searchByID(idChild,*r);
         
         if (q == NULL) {  // Cek apakah sudah pernah dibuat node atau belum
            q = newTreeNode(idChild);
         }

         if (q != NULL) {
            NSBG(fc) = q;
            fc = q;
         }
         
         ADVWORDFILE();
         if (EOP) {
            break;
         }
      }

      *r = p;

      if (EOP) {
         break;
      }
   }
   
   endWord = true;
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
      i++;
   } 

   return listID;
}

int lengthListBahan (ListIDBahan listID) {
   // Memberi keluaran panjang listID

   int i = 0;

   while (ELMTLB(listID,i) != VAL_UNDEF) {
      i++;
   }

   return i;
}

void printListBahan (ListIDBahan listID) {
   // Mencetak list bahan

   int i = 0;
   while (listID.bahan[i] != VAL_UNDEF) {
      printf("%d ", listID.bahan[i]);
      i++;
   } 
   printf("\n");
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
// Memberi keluaran AddressTree dari makanan berdasarkan input id dan resep

   TreeElType root;
   if (resep == NULL) {
      return (NULL);
   } else {
      root = INFOTREE(resep);
      AddressTree fc = FCHD(resep);
      AddressTree p = NULL;

      if (root == id) {
         p = resep;
      } 

      if (fc != NULL && p == NULL) {
         return searchByID(id, fc);
      }
      
      if (NSBG(resep) != NULL && p == NULL) { 
         return searchByID(id, NSBG(resep));
      }

      if (NSBG(resep) == NULL && fc == NULL && p == NULL) { 
         return NULL;
      }

      return p;
   }
}

void printListResep(Peta p, ListStatik l) {
   int n, i, j, k;
   int id, nChild, idChild;
   Makanan target, bahan;

   STARTWORDFILE("src/data/Recipe.txt");  
   
   n = 0;
   for (i=0; i<currentWord.Length; i++) {  // Baca jumlah resep
      n = n*10 + ((int) currentWord.TabWord[i]-'0');
   }
   
   ADVWORDFILE();

   for (i=0; i<n; i++) {   // Pengulangan sebanyak jumlah resep
      printf("%d. ", i+1);
      
      id = 0;
      for (j=0; j<currentWord.Length; j++) {
         id = id*10 + ((int) currentWord.TabWord[j]-'0');
      }

      target = getFoodByID(id, l);

      printString(target.name);
      printf("\n");
      showProcess(target, p);
      printf(" - ");

      ADVWORDFILE();

      nChild = 0;
      for (k=0; k<currentWord.Length; k++) {    // Baca jumlah bahan yang diperlukan untuk suatu resep
         nChild = nChild*10 + ((int) currentWord.TabWord[k]-48);
      }
       
      ADVWORDFILE();
   
      for (j=0; j<nChild; j++) {    // Ulangi pembacaan id bahan sebanyak nChild jika nChild > 1

         idChild = 0;
         for (k=0; k<currentWord.Length; k++) {
            idChild = idChild*10 + ((int) currentWord.TabWord[k]-48);
         }

         bahan = getFoodByID(idChild, l);
         printString(bahan.name);
         if (j+1<nChild) {
            printf(" - ");
         } else {
            printf("\n");
         };
         
         ADVWORDFILE();
         if (EOP) {
            break;
         }
      }

      if (EOP) {
         break;
      }
   }

}

void showProcess (Makanan target, Peta p) {
// Menunjukkan process dari suatu makanan 

   if (EQ(target.loc, Locate(p, 'B'))) {
      printf("BOIL"); 
   } else if (EQ(target.loc, Locate(p, 'C'))) {
      printf("CHOP"); 
   } else if (EQ(target.loc, Locate(p, 'F'))) {
      printf("FRY"); 
   } else if (EQ(target.loc, Locate(p, 'M'))) {
      printf("MIX"); 
   } else {
      printf("undefined");
   }

}