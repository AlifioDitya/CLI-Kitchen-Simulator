/* File : tree.c */
/* ADT pohon N-Ary */
/* Representasi Address dengan pointer */
/* ElType adalah integer */

#include "../boolean.h"
#include <stdio.h>
#include "tree.h"
#include "../word-machine/wordmachine.c"
#include "../word-machine/charmachine.c"
#include "../makanan/makanan.c"
#include "../peta/peta.c"


/* Selektor */
#define CAPACITY 100
#define VAL_UNDEF -1
typedef struct treeNode* Address;
typedef struct treeNode { 
     ElType info;
     Address firstChild;
     Address nextSibling;
} TreeNode;

typedef struct {
    int bahan[CAPACITY];
} listIDBahan;

#define ELMT(l, i) (l).bahan[(i)]


/* Definisi PohonBiner */
/* pohon Biner kosong p = NULL */

typedef Address BinTree;

void CreateList(listIDBahan * List) {
    int i = 0;

    for (i; i<CAPACITY; i++) {
        ELMT(*List,i) = VAL_UNDEF;
    }
}

BinTree NewTree (ElType info, BinTree fc, BinTree nsb) {
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

void CreateTree (ElType info, BinTree fc, BinTree nsb, BinTree *p) {
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */
   
   *p = NewTree(info, fc, nsb);

}

Address newTreeNode(ElType val) {
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


Address searchByID(ElType id, BinTree resep) {

   ElType root = INFO(resep);
   Address fc = FCHD(resep);  

   if (root == id) {
      return resep;
   } 

   if (fc != NULL) {
      searchByID(id, fc);
   }
   
   if (NSBG(resep) != NULL) { 
      searchByID(id, NSBG(resep));
   }
}

void printListResep(BinTree resep, Peta p) {   // Masih nunggu adt makanan
   int i = 0;
   int idx = 1;
   Address fc;
   Makanan target, bahan;

   if (FCHD(resep) != NULL && resep != NULL) {
      target = getFoodByID(INFO(resep));
      int nBahan = length(listBahan(resep).bahan);


      printf("%d. %s\n", idx, target.name);
      showProcess(target, p);
      printf(" - ");

      for (i; i<nBahan; i++) {
         bahan = getFoodByID(listBahan(resep).bahan[i]);
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
   printListResep(fc);
   printListResep(NSBG(resep));
}

void showProcess (Makanan target, Peta p) {

   if (isPointSame(target.loc, Locate(Peta p, "B")) {
      printf("BOIL"); 
   } else if (isPointSame(target.loc, Locate(Peta p, "C")) {
      printf("CHOP"); 
   } else if (isPointSame(target.loc, Locate(Peta p, "F")) {
      printf("FRY"); 
   } else {
      printf("MIX"); 
   }

}


listIDBahan listBahan(Address targetMakanan) {

   Address fc = FCHD(targetMakanan);
   listIDBahan listID;
   int i = 0;

   CreateList(&listID);

   while (fc != NULL) {
      ELMT(listID,i) = INFO(fc);
      fc = NSBG(fc);
   } 

   return listID;
}

// File parser
// BinTree readFromFile(Word pathname) { 

//    FILE *fp = fopen(pathname + ".txt", "r");



//    fclose(fp);

// }
