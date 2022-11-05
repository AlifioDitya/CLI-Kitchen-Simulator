#include "../time/time.h"
#include "../word-machine/wordmachine.h"
#include "../makanan/makanan.h"
#include "tree.h"
#include "../point/point.c"
#include "../peta/peta.h"
#include "../liststatik/liststatik.h"
#include <string.h>
#include <stdio.h>

extern ListStatik katalog;
Peta p;
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

boolean isIn (Makanan X, List Inventory){
    boolean ada = false;
    for(int i = 0; i<length(Invetory); i++){
        if(ELMT(Inventory,i) == X){
            ada = true;
        }
    }
    return true;
}

boolean isCookable (List bahan, List Inventory){
    boolean bisa = true;
    for(int i = 0; i< length(bahan); i++){
        if(!isIn(ELMT(bahan,i), Inventory)){
            bisa = false;
            break;
        }
    }
    return bisa;

}

void Boil (){
    List Rebus;
    int target;
    printf("##########BOILLLLLLLLLL##########\n");
    printf("List Bahan Makanan yang Bisa Dibuat: \n");
    
    for(int i = 0; i<length(dummy); i++){
        if(dummy[i].lokasi == 'B'){
            insertLast(Rebus, dummy[i]);
        }
    }
    for(int i = 0; i<(length(Rebus)); i++){
        printf("%d. %s\n", (i+1), (Rebus[i]).nama);
    }
    printf("Kirim 0 untuk exit\n");
    printf("enter command: ");
    scanf("%d", &target);
    Address p;
    while(target != 0){
        p = searchById(resep, (Rebus[target-1]).id);
        p = firstchild(p);
        if(IndexOf(inventory, Info(p))!= IDX_UNDEF){
            deleteAt(inventory,IndexOf(inventory, Info(p) );
            insert(inventory, Rebus[target-1]);
            printf("%s berhasil dibuat dan sudah dimasukkan di inventory\n", (Rebus[target-1]).nama);
        }
        else{
            printf("Gagal membuat ayam goreng karena kamu tidak memiliki bahan berikut:\n");
            printf("1. %s", Info(p).nama);
        }
        scanf("%d", &target);
    }
}
void chop(){
    List Potong;
    int target;
    createList(&Potong);
    printf("##########POTONGGGGGGGGGG##########\n");
    printf("List Bahan Makanan yang Bisa Dibuat: \n");
    
    for(int i = 0; i<length(dummy); i++){
        if(dummy[i].lokasi == 'C'){
            insertLast(Potong, dummy[i]);
        }
    }
    for(int i = 0; i<(length(Potong)); i++){
        printf("%d. %s\n", (i+1), (Potong[i]).nama);
    }
    printf("Kirim 0 untuk exit\n");
    printf("enter command: ");
    scanf("%d", &target);
    Address p;
    while(target != 0){
        p = searchById(resep, (Potong[target-1]).id);
        p = firstchild(p);
        if(IndexOf(inventory, Info(p))!= IDX_UNDEF){
            deleteAt(inventory,IndexOf(inventory, Info(p));
            insert(inventory, Potong[target-1]);
            printf("%s berhasil dibuat dan sudah dimasukkan di inventory\n", (Potong[target-1]).nama);
        }
        else{
            printf("Gagal membuat ayam goreng karena kamu tidak memiliki bahan berikut:\n");
            printf("1. %s", Info(p).nama);
        }
        scanf("%d", &target);
    }
}

void fry(){
    List Goreng;
    createList(&Goreng);
    int target;
    printf("##########GORENGGGGGGGGGG##########\n");
    printf("List Bahan Makanan yang Bisa Dibuat: \n");
    for(int i = 0; i<length(dummy); i++){
        if(dummy[i].lokasi == 'F'){
            insertLast(Goreng, dummy[i]);
        }
    }
    for(int i = 0; i<length(Goreng); i++){
        printf("%d. %s\n", (i+1), Goreng[i].nama);
    }
    printf("Kirim 0 untuk exit\n");
    printf("enter command: ");
    scanf("%d", &target);
    Address p;
    List bahan;
    while(target != 0){
        createList(&bahan);
        p = searchById(resep, (Goreng[target-1]).id);
        bahan = listBahan(p);
        if(isCookable(bahan, Inventory)){
            for(int i = 0; i<length(bahan); i++){
                deleteAt(Inventory, IndexOf(Info(ELMT(bahan,i))));
            }
            insert(Inventory, Goreng[target-1]);
        }
        else{
            printf("Anda tidak memiliki semua bahan yang dibutuhkan di Inventory :(\n");
        }
        printf("enter command: ");
        scanf("%d", &target);
    }
}
void mix(){
    List campur;
    createList(&campur);
    int target;
    printf("##########CAMPURRRRRRRRRRR##########\n");
    printf("List Bahan Makanan yang Bisa Dibuat: \n");
    for(int i = 0; i<length(dummy); i++){
        if(dummy[i].lokasi == 'M'){
            insertLast(campur, dummy[i]);
        }
    }
    for(int i = 0; i<length(campur); i++){
        printf("%d. %s\n", (i+1), campur[i].nama);
    }
    printf("Kirim 0 untuk exit\n");
    printf("enter command: ");
    scanf("%d", &target);
    Address p;
    List bahan;
    while(target != 0){
        createList(&bahan);
        p = searchById(resep, (Goreng[target-1]).id);
        bahan = listBahan(p);
        if(isCookable(bahan, Inventory)){
            for(int i = 0; i<length(bahan); i++){
                deleteAt(Inventory, IndexOf(Info(ELMT(bahan,i))));
            }
            insert(Inventory, Goreng[target-1]);
        }
        else{
            printf("Anda tidak memiliki semua bahan yang dibutuhkan di Inventory :(\n");
        }
        printf("enter command: ");
        scanf("%d", &target);
    }
}
