#include "../time/time.h"
#include "../inventory/inventory.h"
#include "../word-machine/wordmachine.h"
#include "../makanan/makanan.h"
#include "../point/point.h"
#include "../peta/peta.h"
#include "../resep/tree.h"
#include "../liststatik/liststatik.h"
#include <string.h>
#include <stdio.h>

ListStatik katalogByProses(ListStatik katalog, Word proses);
//mereturn katalog makanan dengan proses tertentu
void displayKatalogProses (ListStatik katalogProses);
//menampilkan katalog proses
boolean isIn (Makanan X, Inventory I);
//mereturn true jika makanan X ada di dalam inventory
boolean isCookable (ListIDBahan bahan, Inventory I);
//mereturn true jika semua bahan ada di inventory
ListStatik TidakDimiliki (Inventory I, ListIDBahan bahan);
//mereturn list staik yang berisi bahan yang tidak dimiliki di INventory
void Boil();
//prosedur untuk merebus
void chop();
//prosedur untuk memotong
void fry();
//prosedur untuk menggoreng
void mix();
//prosedur untuk mencampur
