#include "../time/time.h"
#include "../inventory/inventory.h"
#include "../word-machine/wordmachine.h"
#include "../makanan/makanan.c"
#include "tree.h"
#include "../point/point.c"
#include "../peta/peta.h"
#include "../resep/tree.c"
#include "../liststatik/liststatik.h"
#include <string.h>
#include <stdio.h>

extern ListStatik katalog;
Peta p;
Word cmd;
BinTree resep;
Inventory I;
TIME progTime;
ListStatik katalogByProses(ListStatik katalog, Word proses){
    ListStatik katalogProses;
    CreateListStatik(&katalogProses);
    if(proses.TabWord == "BOIL"){
        for(int i = 0; i<listLength(katalog); i++){
            if(isPointSame(ActionLoc(Elmt(katalog, i)), Locate(p, 'B'))){
                insertLast(&katalogProses, Elmt(katalog,i));
            }
        }
    }
    else if(proses.TabWord == "CHOP"){
        for(int i = 0; i<listLength(katalog); i++){
            if(isPointSame(ActionLoc(Elmt(katalog, i)), Locate(p, 'C'))){
                insertLast(&katalogProses,Elmt(katalog,i));
            }
        }
    }
    else if(proses.TabWord == "FRY"){
        for(int i = 0; i<listLength(katalog); i++){
            if(isPointSame(ActionLoc(Elmt(katalog, i)), Locate(p, 'F'))){
                insertLast(&katalogProses,Elmt(katalog,i));
            }
        }
    }
    else if(proses.TabWord == "MIX"){
        for(int i = 0; i<listLength(katalog); i++){
            if(isPointSame(ActionLoc(Elmt(katalog, i)), Locate(p, 'M'))){
                insertLast(&katalogProses,Elmt(katalog,i));
            }
        }
    }
    return katalogProses;
}

void displayKatalogProses (ListStatik katalogProses){
    printf("List makanan yang bisa dibuat: ");
    for(int i = 0; i<listLength(katalogProses); i++){
        printf("%d. %s\n", (i+1), FoodName(Elmt(katalogProses, i)));
    }
}

boolean isIn (Makanan X, Inventory I){
    return(invIndexOf(I, X) != IDX_UNDEF);
} 

boolean isCookable (listIDBahan bahan, Inventory I){
    boolean bisa = true;
    for(int i = 0; i< lengthListID(bahan); i++){
        if(!isIn(getFoodByID(ELMTLB(bahan, i), katalog), I)){
            bisa = false;
            break;
        }
    }
    return bisa;
}

ListStatik TidakDimiliki (Inventory I, listIDBahan bahan){
    ListStatik unhave;
    int i ;
    CreateListStatik(&unhave);
    for(i = 0; i< lengthListID(bahan); i++){
        if(!isIn(getFoodByID(ELMTLB(bahan, i), katalog), I)){
            insertFirst(&unhave, getFoodByID(ELMTLB(bahan, i), katalog));
        }
    }
    return unhave;
}

int lengthListBahan (listIDBahan  listID) {
   // Memberi keluaran panjang listID

   return sizeof(listID.bahan)/sizeof(int);
}

void copyListID (listIDBahan  *newList, listIDBahan  List){
    for(int i =0; i<lengthListBahan; i++){
        ELMTLB(*newList, i) = ELMTLB(List, i);
    }
}


void Boil(){
    ListStatik Rebus;
    Makanan val;
    int target;
    Address p;
    CreateListStatik(&Rebus);
    Rebus = katalogByProses(katalog, cmd);
    displayKatalogProses(Rebus);
    printf("kirim 0 untuk exit\n");
    printf("enter comand: ");
    scanf("%d", &target);
    while(target != 0){
        p = searchById(ID(Elmt(Rebus,(target-1))), resep);
        p = FCHD(p);
        if(invIndexOf(I, getFoodByID(Info(p), katalog)) != IDX_UNDEF){
            invdeleteAt(&I, invIndexOf(I, getFoodByID(Info(p), katalog)), &val);
            insert(&I, Elmt(Rebus, target-1));
            printf("%s berhasil dibuat dan sudah dimasukkan di inventory\n", FoodName(Elmt(Rebus, target-1)));
            AdvTime(&progTime);
        }
        else{
            printf("gagal membuat %s karena tidak memiliki bahan berikut : \n", FoodName(Elmt(Rebus, target-1)));
            printf("1. %s\n", FoodName(getFoodByID(Info(p), katalog)));
        }
        scanf("%d", &target);
    }
}

void chop(){
    ListStatik Potong;
    Makanan val;
    int target;
    Address p;
    CreateListStatik(&Potong);
    Potong = katalogByProses(katalog, cmd);
    displayKatalogProses(Potong);
    printf("kirim 0 untuk exit\n");
    printf("enter comand: ");
    scanf("%d", &target);
    while(target != 0){
        p = searchById(ID(Elmt(Potong,(target-1))), resep);
        p = FCHD(p);
        if(invIndexOf(I, getFoodByID(Info(p), katalog)) != IDX_UNDEF){
            invdeleteAt(&I, invIndexOf(I, getFoodByID(Info(p), katalog)), &val);
            insert(&I, Elmt(Potong, target-1));
            printf("%s berhasil dibuat dan sudah dimasukkan di inventory\n", FoodName(Elmt(Potong, target-1)));
            AdvTime(&progTime);
        }
        else{
            printf("gagal membuat %s karena tidak memiliki bahan berikut : \n", FoodName(Elmt(Potong, target-1)));
            printf("1. %s\n", FoodName(getFoodByID(Info(p), katalog)));
        }
        scanf("%d", &target);
    }
}

void fry(){
    ListStatik Goreng, unHave;
    listIDBahan bahan;
    Makanan val;
    int target;
    Address p;
    CreateListStatik(&Goreng);
    CreateList(&bahan);
    Goreng = katalogByProses(katalog, cmd);
    displayKatalogProses(Goreng);
    printf("kirim 0 untuk exit\n");
    printf("enter comand: ");
    scanf("%d", &target);
    while(target != 0){
        p = searchById(ID(Elmt(Goreng,(target-1))), resep);
        bahan = listBahan(p);
        if(isCookable(bahan, I)){
            for(int i = 0; i<lengthListID(bahan); i++){
                invdeleteAt(&I, invIndexOf(I, getFoodByID(ELMTLB(bahan,i), katalog)), &val);
            }
            insert(&I, Elmt(Goreng, (target-1)));
            printf("%s berhasil dibuat dan sudah dimasukkan di inventory\n", FoodName(Elmt(Goreng, target-1)));
            AdvTime(&progTime);
        }
        else{
            CreateListStatik(&unHave);
            unHave = TidakDimiliki(I, bahan);
            printf("gagal membuat %s karena tidak memiliki bahan berikut : \n", FoodName(Elmt(Goreng, target-1)));
            displayKatalogProses(unHave);
        }
        scanf("%d", &target);
    }
}
void mix(){
    ListStatik Campur, unHave;
    listIDBahan bahan;
    Makanan val;
    int target;
    Address p;
    CreateListStatik(&Campur);
    CreateList(&bahan);
    Campur = katalogByProses(katalog, cmd);
    displayKatalogProses(Campur);
    printf("kirim 0 untuk exit\n");
    printf("enter comand: ");
    scanf("%d", &target);
    while(target != 0){
        p = searchById(ID(Elmt(Campur,(target-1))), resep);
        bahan = listBahan(p);
        if(isCookable(bahan, I)){
            for(int i = 0; i<lengthListID(bahan); i++){
                invdeleteAt(&I, invIndexOf(I, getFoodByID(ELMTLB(bahan,i), katalog)), &val);
            }
            insert(&I, Elmt(Campur, (target-1)));
            printf("%s berhasil dibuat dan sudah dimasukkan di inventory\n", FoodName(Elmt(Campur, target-1)));
            AdvTime(&progTime);
        }
        else{
            CreateListStatik(&unHave);
            unHave = TidakDimiliki(I, bahan);
            printf("gagal membuat %s karena tidak memiliki bahan berikut : \n", FoodName(Elmt(Campur, target-1)));
            displayKatalogProses(unHave);
        }
        scanf("%d", &target);
    }
}
