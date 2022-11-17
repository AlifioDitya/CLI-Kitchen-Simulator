/* File : bintree.h */
/* ADT pohon biner */
/* Representasi AddressTree dengan pointer */
/* TreeElType adalah integer */

#ifndef POHONBINER_H
#define POHONBINER_H

#include "../boolean.h"
#include "../liststatik/liststatik.h"

#define CAPACITY 100
#define VAL_UNDEF -1

typedef int TreeElType;
typedef struct treeNode* AddressTree;
typedef struct treeNode { 
     TreeElType infoTree;
     AddressTree firstChild;
     AddressTree nextSibling;
} TreeNode;
typedef struct {
    int bahan[CAPACITY];
} listIDBahan;
#define ELMTLB(l, i) (l).bahan[(i)]

typedef struct {
    int bahan[CAPACITY];
} ListIDBahan;

#define ELMTLB(l, i) (l).bahan[(i)]

/* Selektor */
#define INFOTREE(p) (p)->infoTree
#define NSBG(p) (p)->nextSibling
#define FCHD(p) (p)->firstChild

/* Definisi PohonBiner */
/* pohon Biner kosong p = NULL */

typedef AddressTree BinTree;

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

AddressTree newTreeNode(TreeElType val);
/* Alokasi sebuah addressTree p, bernilai tidak NULL jika berhasil */
/* Mengirimkan addressTree hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka addressTree tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.infoTree=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

ListIDBahan listBahan(AddressTree targetMakanan);
// Memberikan keluaran ListIDBahan dari input addressTree targetMakanan

void readResep(char* filename, BinTree *r);
// I.S sembarang
// F.S r sudah berisi resep berdasarkan input dari file

int lengthListBahan (ListIDBahan listID); 
// Memberi keluaran panjang listID

void copyListBahan(ListIDBahan *listID1, ListIDBahan *listID2);
   // I.S listID1 terdefinisi dan listID2 belum terdefinisi
   // F.S. Menyalin isi listIDBahan listID1 ke listID2

AddressTree searchByID(TreeElType id, BinTree resep);
// Memberi keluaran addressTree dari makanan berdasarkan input id dan resep

void printListResep(BinTree resep, Peta p, ListStatik l);
// Mencetak List Resep 

void printKatalog(BinTree resep, Peta p, ListStatik l);
// Mencetak Katalog

void showProcess (Makanan target, Peta p);
// Mencetak process dari suatu makanan 

#endif
