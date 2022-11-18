#include "pengolahan.h"

// extern ListStatik katalog;
// Peta map;
// String cmd;
// BinTree resep;
// Inventory I;
// TIME progTime;
ListStatik katalogByProses(ListStatik katalog, String proses, Peta p){
    ListStatik katalogProses;
    CreateListStatik(&katalogProses);
    String Boil, Chop, Fry, Mix;
    createString("BOIL", 4, &Boil);
    createString("CHOP", 4, &Chop);
    createString("FRY", 3, &Fry);
    createString("MIX", 3, &Mix);
    if(isStringEqual(proses, Boil)){
        for(int i = 0; i<listLength(katalog); i++){
            if(EQ(ActionLoc(Elmt(katalog, i)), Locate(p, 'B'))){
                insertLast(&katalogProses, Elmt(katalog,i));
            }
        }
    }
    else if(isStringEqual(proses, Chop)){
        for(int i = 0; i<listLength(katalog); i++){
            if(EQ(ActionLoc(Elmt(katalog, i)), Locate(p, 'C'))){
                insertLast(&katalogProses,Elmt(katalog,i));
            }
        }
    }
    else if(isStringEqual(proses, Fry)){
        for(int i = 0; i<listLength(katalog); i++){
            if(EQ(ActionLoc(Elmt(katalog, i)), Locate(p, 'F'))){
                insertLast(&katalogProses,Elmt(katalog,i));
            }
        }
    }
    else if(isStringEqual(proses, Mix)){
        for(int i = 0; i<listLength(katalog); i++){
            if(EQ(ActionLoc(Elmt(katalog, i)), Locate(p, 'M'))){
                insertLast(&katalogProses,Elmt(katalog,i));
            }
        }
    }
    return katalogProses;
}

void displayKatalogProses (ListStatik katalogProses){
    printf("List makanan yang bisa dibuat: ");
    for(int i = 0; i<listLength(katalogProses); i++){
        printf("%d. ", (i+1));
        printString(FoodName(Elmt(katalogProses, i)));
        printf("\n");
    }
}

boolean isIn (Makanan X, Inventory I){
    return(indexOfInventory(I, X) != IDX_UNDEF);
} 

boolean isCookable (ListIDBahan bahan, Inventory I, ListStatik katalog){
    boolean bisa = true;
    for(int i = 0; i< lengthListBahan(bahan); i++){
        if(!isIn(getFoodByID(ELMTLB(bahan, i), katalog), I)){
            bisa = false;
            break;
        }
    }
    return bisa;
}

ListStatik TidakDimiliki (Inventory I, ListIDBahan bahan, ListStatik katalog){
    ListStatik unhave;
    int i ;
    CreateListStatik(&unhave);
    for(i = 0; i< lengthListBahan(bahan); i++){
        if(!isIn(getFoodByID(ELMTLB(bahan, i), katalog), I)){
            insertFirst(&unhave, getFoodByID(ELMTLB(bahan, i), katalog));
        }
    }
    return unhave;
}


// void copyListID (listIDBahan  *newList, listIDBahan  List){
//     for(int i =0; i<lengthListBahan; i++){
//         ELMTLB(*newList, i) = ELMTLB(List, i);
//     }
// }


void Boil(ListStatik katalog, String cmd, Peta map, Simulator *s, BinTree resep, TIME currTime, PrioQueueMakanan pesanan){
    ListStatik Rebus;
    Makanan val;
    int target;
    AddressTree p;
    printf("==========================================\n");
    printf("===                  BOIL              ===\n");
    printf("==========================================\n");
    CreateListStatik(&Rebus);
    Rebus = katalogByProses(katalog, cmd, map);
    displayKatalogProses(Rebus);
    printf("kirim 0 untuk exit\n");
    printf("enter comand: ");
    scanf("%d", &target);
    while(target != 0){
        p = searchByID(ID(Elmt(Rebus,(target-1))), resep);
        p = FCHD(p); //hanya diperlukan satu bahan untuk merebus, jadi bahan hanyalah firstchild di tree resep
        if(indexOfInventory(Inv(*s), getFoodByID(INFOTREE(p), katalog)) != IDX_UNDEF){
            deleteAtInventory(&Inv(*s), indexOfInventory(Inv(*s), getFoodByID(INFOTREE(p), katalog)), &val);
            insertInventory(&Inv(*s), Elmt(Rebus, target-1));
            printString(FoodName(Elmt(Rebus, target-1)));
            printf(" berhasil dibuat dan sudah dimasukkan di inventory\n");
            progressTime(s, &pesanan, &currTime);
        }
        else{
            printf("gagal membuat %s karena tidak memiliki bahan berikut : \n", FoodName(Elmt(Rebus, target-1)));
            printf("1. %s\n", FoodName(getFoodByID(INFOTREE(p), katalog)));
        }
        scanf("%d", &target);
    }
}

void chop(ListStatik katalog, String cmd, Peta map, Simulator *s, BinTree resep, TIME currTime, PrioQueueMakanan pesanan){
    ListStatik Potong;
    Makanan val;
    int target;
    AddressTree p;
    printf("==========================================\n");
    printf("===                  CHOP              ===\n");
    printf("==========================================\n");
    CreateListStatik(&Potong);
    Potong = katalogByProses(katalog, cmd, map);
    displayKatalogProses(Potong);
    printf("kirim 0 untuk exit\n");
    printf("enter comand: ");
    scanf("%d", &target);
    while(target != 0){
        printf("im here\n");
        p = searchByID(ID(Elmt(Potong,(target-1))), resep);
        printf("%d\n", INFOTREE(p));
        p = FCHD(p); //hanya diperlukan satu bahan untuk dipotong, jadi bahan hanyalah firstchild di tree resep
        printf("%d\n", INFOTREE(p));
        if(indexOfInventory(Inv(*s), getFoodByID(INFOTREE(p), katalog)) != IDX_UNDEF){
            deleteAtInventory(&Inv(*s), indexOfInventory(Inv(*s), getFoodByID(INFOTREE(p), katalog)), &val);
            insertInventory(&Inv(*s), Elmt(Potong, target-1));
            printString(FoodName(Elmt(Potong, target-1)));
            printf(" berhasil dibuat dan sudah dimasukkan di inventory\n");
            progressTime(s, &pesanan, &currTime);
        }
        else{
            printf("gagal membuat %s karena tidak memiliki bahan berikut : \n", FoodName(Elmt(Potong, target-1)));
            printf("1. %s\n", FoodName(getFoodByID(INFOTREE(p), katalog)));
        }
        scanf("%d", &target);
    }
}

void fry(ListStatik katalog, String cmd, Peta map, Simulator *s, BinTree resep, TIME currTime, PrioQueueMakanan pesanan){
    ListStatik Goreng, unHave;
    ListIDBahan bahan;
    Makanan val;
    int target;
    AddressTree p;
    printf("==========================================\n");
    printf("===                  FRY               ===\n");
    printf("==========================================\n");
    CreateListStatik(&Goreng);
    CreateListBahan(&bahan);
    Goreng = katalogByProses(katalog, cmd, map);
    displayKatalogProses(Goreng);
    printf("kirim 0 untuk exit\n");
    printf("enter comand: ");
    scanf("%d", &target);
    while(target != 0){
        p = searchByID(ID(Elmt(Goreng,(target-1))), resep);
        bahan = listBahan(p);
        printf("%d\n", lengthListBahan (bahan));
        if(isCookable(bahan, Inv(*s), katalog)){
            for(int i = 0; i<lengthListBahan(bahan); i++){
                deleteAtInventory(&Inv(*s), indexOfInventory(Inv(*s), getFoodByID(ELMTLB(bahan,i), katalog)), &val);
            }
            insertInventory(&Inv(*s), Elmt(Goreng, (target-1)));
            printString(FoodName(Elmt(Goreng, target-1)));
            printf(" berhasil dibuat dan sudah dimasukkan di inventory\n");
            progressTime(s, &pesanan, &currTime);
        }
        else{
            CreateListStatik(&unHave);
            unHave = TidakDimiliki(Inv(*s), bahan, katalog);
            printf("gagal membuat %s karena tidak memiliki bahan berikut : \n", FoodName(Elmt(Goreng, target-1)));
            for(int i = 0; i<listLength(unHave); i++){
                printf("%d. ", (i+1));
                printString(FoodName(Elmt(unHave,i)));
                printf("\n");
            }

        }
        scanf("%d", &target);
    }
}
void mix(ListStatik katalog, String cmd, Peta map, Simulator *s, BinTree resep, TIME currTime, PrioQueueMakanan pesanan){
    ListStatik Campur, unHave;
    ListIDBahan bahan;
    Makanan val;
    int target;
    AddressTree p;
    printf("==========================================\n");
    printf("===                  MIX               ===\n");
    printf("==========================================\n");
    CreateListStatik(&Campur);
    CreateListBahan(&bahan);
    Campur = katalogByProses(katalog, cmd, map);
    displayKatalogProses(Campur);
    printf("kirim 0 untuk exit\n");
    printf("enter comand: ");
    scanf("%d", &target);
    while(target != 0){
        p = searchByID(ID(Elmt(Campur,(target-1))), resep);
        bahan = listBahan(p);
        if(isCookable(bahan, Inv(*s), katalog)){
            for(int i = 0; i<lengthListBahan(bahan); i++){
                deleteAtInventory(&Inv(*s), indexOfInventory(Inv(*s), getFoodByID(ELMTLB(bahan,i), katalog)), &val);
            }
            insertInventory(&Inv(*s), Elmt(Campur, (target-1)));
            printString(FoodName(Elmt(Campur, target-1)));
            printf(" berhasil dibuat dan sudah dimasukkan di inventory\n");
            progressTime(s, &pesanan, &currTime);
        }
        else{
            CreateListStatik(&unHave);
            unHave = TidakDimiliki(Inv(*s), bahan, katalog);
            // printf("%d\n", listLength(unHave));
            printf("gagal membuat %s karena tidak memiliki bahan berikut : \n", FoodName(Elmt(Campur, target-1)));
            for(int i = 0; i<listLength(unHave); i++){
                printf("%d. ", (i+1));
                printString(FoodName(Elmt(unHave,i)));
                printf("\n");
            }
        }
        scanf("%d", &target);
    }
}
