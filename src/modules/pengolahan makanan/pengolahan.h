#include "../time/time.h"
#include "../inventory/inventory.h"
#include "../word-machine/wordmachine.h"
#include "../makanan/makanan.h"
#include "../point/point.h"
#include "../peta/peta.h"
#include "../resep/tree.h"
#include "../liststatik/liststatik.h"
#include "../prioqueuemakanan/prioqueuemakanan.h"
#include"../string/string.h"
#include <stdio.h>

ListStatik katalogByProses(ListStatik katalog, String proses, Peta p);
//mereturn katalog makanan yang dapat dihasilkan dengan proses tertentu

void displayKatalogProses (ListStatik katalogProses);
//menampilkan katalog proses, contoh output: 
// 1. Ayam Goreng
// 2. Udang Goreng

boolean isIn (Makanan X, Inventory I);
//mereturn true jika makanan X ada di dalam inventory

boolean isCookable (ListIDBahan bahan, Inventory I, ListStatik katalog);
//mereturn true jika makanan bisa dibuat
//makanan bisa dibuat jika semua bahan ada di Inventory

ListStatik TidakDimiliki (Inventory I, ListIDBahan bahan, ListStatik katalog);
//mereturn list staik yang berisi bahan yang tidak dimiliki di INventory

void Boil(ListStatik katalog, String cmd, Peta map, Simulator *s, BinTree resep, TIME currTime, PrioQueueMakanan pesanan);
//prosedur untuk merebus

void chop(ListStatik katalog, String cmd, Peta map, Simulator *s, BinTree resep, TIME currTime, PrioQueueMakanan pesanan);
//prosedur untuk memotong

void fry(ListStatik katalog, String cmd, Peta map, Simulator *s, BinTree resep, TIME currTime, PrioQueueMakanan pesanan);
//prosedur untuk menggoreng

void mix(ListStatik katalog, String cmd, Peta map, Simulator *s, BinTree resep, TIME currTime, PrioQueueMakanan pesanan);
//prosedur untuk mencampur
