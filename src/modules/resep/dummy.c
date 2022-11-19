// #include "time.h"
// // #include "food.h"
// // #include "inventory.h"
// // #include "resep.c"
// #include <string.h>
// #include <stdio.h>

// extern food[] dummy;
// void Boil (){
//     List Rebus;
//     int target;
//     printf("##########BOILLLLLLLLLL##########\n");
//     printf("List Bahan Makanan yang Bisa Dibuat: \n");
    
//     for(int i = 0; i<length(dummy); i++){
//         if(dummy[i].lokasi == 'B'){
//             insertLast(Rebus, dummy[i]);
//         }
//     }
//     for(int i = 0; i<(length(Rebus)); i++){
//         printf("%d. %s\n", (i+1), (Rebus[i]).nama);
//     }
//     printf("Kirim 0 untuk exit\n");
//     printf("enter command: ");
//     scanf("%d", &target);
//     Address p;
//     while(target != 0){
//         p = searchById(resep, (Rebus[target-1]).id);
//         p = firstchild(p);
//         if(IndexOf(inventory, Info(p))!= IDX_UNDEF){
//             deleteAt(inventory,IndexOf(inventory, Info(p) );
//             insert(inventory, Rebus[target-1]);
//             printf("%s berhasil dibuat dan sudah dimasukkan di inventory\n", (Rebus[target-1]).nama);
//         }
//         else{
//             printf("Gagal membuat ayam goreng karena kamu tidak memiliki bahan berikut:\n");
//             printf("1. %s", Info(p).nama);
//         }
//         scanf("%d", &target);
//     }
// }
// void chop(){
//     List Potong;
//     int target;
//     createList(&Potong);
//     printf("##########POTONGGGGGGGGGG##########\n");
//     printf("List Bahan Makanan yang Bisa Dibuat: \n");
    
//     for(int i = 0; i<length(dummy); i++){
//         if(dummy[i].lokasi == 'C'){
//             insertLast(Potong, dummy[i]);
//         }
//     }
//     for(int i = 0; i<(length(Potong)); i++){
//         printf("%d. %s\n", (i+1), (Potong[i]).nama);
//     }
//     printf("Kirim 0 untuk exit\n");
//     printf("enter command: ");
//     scanf("%d", &target);
//     Address p;
//     while(target != 0){
//         p = searchById(resep, (Potong[target-1]).id);
//         p = firstchild(p);
//         if(IndexOf(inventory, Info(p))!= IDX_UNDEF){
//             deleteAt(inventory,IndexOf(inventory, Info(p));
//             insert(inventory, Potong[target-1]);
//             printf("%s berhasil dibuat dan sudah dimasukkan di inventory\n", (Potong[target-1]).nama);
//         }
//         else{
//             printf("Gagal membuat ayam goreng karena kamu tidak memiliki bahan berikut:\n");
//             printf("1. %s", Info(p).nama);
//         }
//         scanf("%d", &target);
//     }
// }

// boolean isIn (Makan X, List Inventory){
//     boolean ada = false;
//     for(int i = 0; i<length(Invetory); i++){
//         if(ELMT(Inventory,i) == X){
//             ada = true;
//         }
//     }
//     return true;
// }
// boolean isCookable (List bahan, List Inventory){
//     boolean bisa = true;
//     for(int i = 0; i< length(bahan); i++){
//         if(!isIn(ELMT(bahan,i), Inventory)){
//             bisa = false;
//             break;
//         }
//     }
//     return bisa;

// }
// void fry(){
//     List Goreng;
//     createList(&Goreng);
//     int target;
//     printf("##########GORENGGGGGGGGGG##########\n");
//     printf("List Bahan Makanan yang Bisa Dibuat: \n");
//     for(int i = 0; i<length(dummy); i++){
//         if(dummy[i].lokasi == 'F'){
//             insertLast(Goreng, dummy[i]);
//         }
//     }
//     for(int i = 0; i<length(Goreng); i++){
//         printf("%d. %s\n", (i+1), Goreng[i].nama);
//     }
//     printf("Kirim 0 untuk exit\n");
//     printf("enter command: ");
//     scanf("%d", &target);
//     Address p;
//     List bahan;
//     while(target != 0){
//         createList(&bahan);
//         p = searchById(resep, (Goreng[target-1]).id);
//         bahan = listBahan(p);
//         if(isCookable(bahan, Inventory)){
//             for(int i = 0; i<length(bahan); i++){
//                 deleteAt(Inventory, IndexOf(Info(ELMT(bahan,i))));
//             }
//             insert(Inventory, Goreng[target-1]);
//         }
//         else{
//             printf("Anda tidak memiliki semua bahan yang dibutuhkan di Inventory :(\n");
//         }
//         printf("enter command: ");
//         scanf("%d", &target);
//     }
// }
// void mix(){
//     List campur;
//     createList(&campur);
//     int target;
//     printf("##########CAMPURRRRRRRRRRR##########\n");
//     printf("List Bahan Makanan yang Bisa Dibuat: \n");
//     for(int i = 0; i<length(dummy); i++){
//         if(dummy[i].lokasi == 'M'){
//             insertLast(campur, dummy[i]);
//         }
//     }
//     for(int i = 0; i<length(campur); i++){
//         printf("%d. %s\n", (i+1), campur[i].nama);
//     }
//     printf("Kirim 0 untuk exit\n");
//     printf("enter command: ");
//     scanf("%d", &target);
//     Address p;
//     List bahan;
//     while(target != 0){
//         createList(&bahan);
//         p = searchById(resep, (Goreng[target-1]).id);
//         bahan = listBahan(p);
//         if(isCookable(bahan, Inventory)){
//             for(int i = 0; i<length(bahan); i++){
//                 deleteAt(Inventory, IndexOf(Info(ELMT(bahan,i))));
//             }
//             insert(Inventory, Goreng[target-1]);
//         }
//         else{
//             printf("Anda tidak memiliki semua bahan yang dibutuhkan di Inventory :(\n");
//         }
//         printf("enter command: ");
//         scanf("%d", &target);
//     }
// }