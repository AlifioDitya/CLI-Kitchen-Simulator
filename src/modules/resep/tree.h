/* File : bintree.h */
/* ADT pohon biner */
/* Representasi Address dengan pointer */
/* TreeElType adalah integer */

#ifndef POHONBINER_H
#define POHONBINER_H

#include "boolean.h"

/* Selektor */
#define INFO(p) (p)->info
#define NSBG(p) (p)->nextSibling
#define FCHD(p) (p)->firstChild

#define CAPACITY 100
#define VAL_UNDEF -1

typedef int TreeElType;
typedef struct treeNode* Address;
typedef struct treeNode { 
     TreeElType info;
     Address firstChild;
     Address nextSibling;
} TreeNode;

typedef struct {
    int bahan[CAPACITY];
} ListIDBahan;

#define ELMTLB(l, i) (l).bahan[(i)]

/* Definisi PohonBiner */
/* pohon Biner kosong p = NULL */

typedef Address BinTree;

void CreateListBahan(ListIDBahan * List);
/* I.S. Sembarang
   F.S. Menghasilkan sebuah ListIDBahan kosong List

BinTree NewTree (TreeElType root, BinTree left_tree, BinTree right_tree); 
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

void CreateTree (TreeElType root, BinTree left_tree, BinTree right_tree, BinTree *p);
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

Address newTreeNode(TreeElType val);
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

ListIDBahan listBahan(Address targetMakanan);
// Memberikan keluaran ListIDBahan dari input address targetMakanan

int lengthListBahan (ListIDBahan listID); 
// Memberi keluaran panjang listID

void copyListBahan(ListIDBahan *listID1, ListIDBahan *listID2);
   // I.S listID1 terdefinisi dan listID2 belum terdefinisi
   // F.S. Menyalin isi listIDBahan listID1 ke listID2

Address searchByID(TreeElType id, BinTree resep);
// Memberi keluaran address dari makanan berdasarkan input id dan resep

void printListResep(BinTree resep, Peta p, ListStatik l);
// Mencetak List Resep 

void printKatalog(BinTree resep, Peta p, ListStatik l);
// Mencetak Katalog

void showProcess (Makanan target, Peta p);
// Mencetak process dari suatu makanan 

#endif
