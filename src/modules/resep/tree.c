/* File : tree.c */
/* ADT pohon N-Ary */
/* Representasi Address dengan pointer */
/* TreeElType adalah integer */

#include "../boolean.h"
#include <stdio.h>
#include "tree.h"
#include "../word-machine/wordmachine.c"
#include "../word-machine/charmachine.c"
#include "../makanan/makanan.c"
#include "../peta/peta.c"
#include "../liststatik/liststatik.c"

/* Definisi PohonBiner */
/* pohon Biner kosong p = NULL */

typedef Address BinTree;

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
      INFO(p) = info;
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

Address newTreeNode(TreeElType val) {
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

   Address p;
   p = (Address) malloc(sizeof(TreeNode));
   if (p != NULL) {
      INFO(p) = val;
      FCHD(p) = NULL;
      NSBG(p) = NULL;
   }

   return p;
}

ListIDBahan listBahan(Address targetMakanan) {

   Address fc = FCHD(targetMakanan);
   ListIDBahan listID;
   int i = 0;

   CreateList(&listID);

   while (fc != NULL) {
      ELMTLB(listID,i) = INFO(fc);
      fc = NSBG(fc);
   } 

   return listID;
}


Address searchByID(TreeElType id, BinTree resep) {

   TreeElType root = INFO(resep);
   Address fc = FCHD(resep);
   Address p;  

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

void printListResep(BinTree resep, Peta p, ListStatik l) {   // Masih nunggu adt makanan
   int i = 0;
   int idx = 1;
   Address fc;
   Makanan target, bahan;

   if (FCHD(resep) != NULL && resep != NULL) {
      target = getFoodByID(INFO(resep), l);
      int nBahan = length(listBahan(resep).bahan);


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

   if (isPointSame(target.loc, Locate(p, "B"))) {
      printf("BOIL"); 
   } else if (isPointSame(target.loc, Locate(p, "C"))) {
      printf("CHOP"); 
   } else if (isPointSame(target.loc, Locate(p, "F"))) {
      printf("FRY"); 
   } else {
      printf("MIX"); 
   }

}