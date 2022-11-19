#include "pengolahan.h"
#include "../menu/command.h"

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
    printf("List makanan yang bisa dibuat: \n");
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


void Boil(ListStatik katalog, String cmd, Peta map, Simulator *s, BinTree resep, TIME *currTime, PrioQueueMakanan *pesanan){
    ListStatik Rebus;
    Makanan val;
    int target;
    AddressTree p;
    printf("======================\n");
    printf("=        BOIL        =\n");
    printf("======================\n");
    CreateListStatik(&Rebus);
    Rebus = katalogByProses(katalog, cmd, map);
    displayKatalogProses(Rebus);
    printf("\n");
    printf("Kirim 0 untuk exit\n");
    printf("\n");
    inputCommand(&cmd);

    while (!isCommandInteger(cmd)) {
        printf("\n");
        printf("Command tidak valid.\n");
        printf("\n");
        inputCommand(&cmd);
    }

    target = parseToInteger(cmd);
    
    while(target != 0) {
        if(target>=0 && target <=listLength(Rebus)){
            p = searchByID(ID(Elmt(Rebus,(target-1))), resep);
            p = FCHD(p); //hanya diperlukan satu bahan untuk merebus, jadi bahan hanyalah firstchild di tree resep
            if(indexOfInventory(Inv(*s), getFoodByID(INFOTREE(p), katalog)) != IDX_UNDEF){
                deleteAtInventory(&Inv(*s), indexOfInventory(Inv(*s), getFoodByID(INFOTREE(p), katalog)), &val);
                insertInventory(&Inv(*s), Elmt(Rebus, target-1));
                printString(FoodName(Elmt(Rebus, target-1)));
                printf(" berhasil dibuat dan sudah dimasukkan di inventory\n");
                progressTime(s, pesanan, currTime);
            }
            else {
                printf("Gagal membuat ");
                printString(FoodName(Elmt(Rebus, target-1)));
                printf(" karena tidak memiliki bahan berikut : \n");
                printf("1. %s\n", FoodName(getFoodByID(INFOTREE(p), katalog)));
                printf("\n");
            }
        }
        else{
            printf("Target tidak valid!\n");
        }
       
        printf("\n");
        inputCommand(&cmd);
        while (!isCommandInteger(cmd)) {
            printf("\n");
            printf("Command tidak valid.\n");
            printf("\n");
            inputCommand(&cmd);
        }
        target = parseToInteger(cmd);
    }
}

void chop(ListStatik katalog, String cmd, Peta map, Simulator *s, BinTree resep, TIME *currTime, PrioQueueMakanan *pesanan){
    ListStatik Potong;
    Makanan val;
    int target;
    AddressTree p;
    printf("======================\n");
    printf("=        CHOP        =\n");
    printf("======================\n");
    CreateListStatik(&Potong);
    Potong = katalogByProses(katalog, cmd, map);
    displayKatalogProses(Potong);
    printf("\n");
    printf("Kirim 0 untuk exit\n");
    printf("\n");
    inputCommand(&cmd);

    while (!isCommandInteger(cmd)) {
        printf("\n");
        printf("Command tidak valid.\n");
        printf("\n");
        inputCommand(&cmd);
    }

    target = parseToInteger(cmd);
    while(target != 0){
        if(target>=0 && target <=listLength(Potong)){
            p = searchByID(ID(Elmt(Potong,(target-1))), resep);
            p = FCHD(p); //hanya diperlukan satu bahan untuk dipotong, jadi bahan hanyalah firstchild di tree resep
            if(indexOfInventory(Inv(*s), getFoodByID(INFOTREE(p), katalog)) != IDX_UNDEF){
                deleteAtInventory(&Inv(*s), indexOfInventory(Inv(*s), getFoodByID(INFOTREE(p), katalog)), &val);
                insertInventory(&Inv(*s), Elmt(Potong, target-1));
                printString(FoodName(Elmt(Potong, target-1)));
                printf(" berhasil dibuat dan sudah dimasukkan di inventory\n");
                progressTime(s, pesanan, currTime);
            }
            else{
                printf("Gagal membuat ");
                printString(FoodName(Elmt(Potong, target-1)));
                printf(" karena tidak memiliki bahan berikut : \n");
                printf("1. %s\n", FoodName(getFoodByID(INFOTREE(p), katalog)));
            }
        }
        else{
            printf("Target tidak valid!\n");
        }
        
        printf("\n");
        inputCommand(&cmd);
        while (!isCommandInteger(cmd)) {
            printf("\n");
            printf("Command tidak valid.\n");
            printf("\n");
            inputCommand(&cmd);
        }
        target = parseToInteger(cmd);
    }
}

void fry(ListStatik katalog, String cmd, Peta map, Simulator *s, BinTree resep, TIME *currTime, PrioQueueMakanan *pesanan){
    ListStatik Goreng, unHave;
    ListIDBahan bahan;
    Makanan val;
    int target;
    AddressTree p;
    printf("======================\n");
    printf("=        FRY         =\n");
    printf("======================\n");
    CreateListStatik(&Goreng);
    CreateListBahan(&bahan);
    Goreng = katalogByProses(katalog, cmd, map);
    displayKatalogProses(Goreng);
    printf("\n");
    printf("Kirim 0 untuk exit\n");
    printf("\n");
    inputCommand(&cmd);

    while (!isCommandInteger(cmd)) {
        printf("\n");
        printf("Command tidak valid.\n");
        printf("\n");
        inputCommand(&cmd);
    }

    target = parseToInteger(cmd);
    while(target != 0){
        if(target >= 0 && target <= listLength(Goreng)){
            p = searchByID(ID(Elmt(Goreng,(target-1))), resep);
            bahan = listBahan(p);
            if(isCookable(bahan, Inv(*s), katalog)){
                for(int i = 0; i<lengthListBahan(bahan); i++){
                    deleteAtInventory(&Inv(*s), indexOfInventory(Inv(*s), getFoodByID(ELMTLB(bahan,i), katalog)), &val);
                }
                insertInventory(&Inv(*s), Elmt(Goreng, (target-1)));
                printString(FoodName(Elmt(Goreng, target-1)));
                printf(" berhasil dibuat dan sudah dimasukkan di inventory\n");
                progressTime(s, pesanan, currTime);
            }
            else{
                CreateListStatik(&unHave);
                unHave = TidakDimiliki(Inv(*s), bahan, katalog);
                printf("Gagal membuat ");
                printString(FoodName(Elmt(Goreng, target-1)));
                printf(" karena tidak memiliki bahan berikut : \n");
                for(int i = 0; i<listLength(unHave); i++){
                    printf("%d. ", (i+1));
                    printString(FoodName(Elmt(unHave,i)));
                    printf("\n");
                }
            }
        }
        else{
            printf("Target tidak valid!\n");
        }
        printf("\n");
        inputCommand(&cmd);
        while (!isCommandInteger(cmd)) {
            printf("\n");
            printf("Command tidak valid.\n");
            printf("\n");
            inputCommand(&cmd);
        }
        target = parseToInteger(cmd);
    }
}
void mix(ListStatik katalog, String cmd, Peta map, Simulator *s, BinTree resep, TIME *currTime, PrioQueueMakanan *pesanan){
    ListStatik Campur, unHave;
    ListIDBahan bahan;
    Makanan val;
    int target;
    AddressTree p;
    printf("======================\n");
    printf("=        MIX         =\n");
    printf("======================\n");
    CreateListStatik(&Campur);
    CreateListBahan(&bahan);
    Campur = katalogByProses(katalog, cmd, map);
    displayKatalogProses(Campur);
    printf("\n");
    printf("Kirim 0 untuk exit\n");
    printf("\n");
    inputCommand(&cmd);

    while (!isCommandInteger(cmd)) {
        printf("\n");
        printf("Command tidak valid.\n");
        printf("\n");
        inputCommand(&cmd);
    }

    target = parseToInteger(cmd);
    while(target != 0){
        if(target >= 0 && target <= listLength(Campur)){
            p = searchByID(ID(Elmt(Campur,(target-1))), resep);
            bahan = listBahan(p);
            if(isCookable(bahan, Inv(*s), katalog)){
                for(int i = 0; i<lengthListBahan(bahan); i++){
                    deleteAtInventory(&Inv(*s), indexOfInventory(Inv(*s), getFoodByID(ELMTLB(bahan,i), katalog)), &val);
                }
                insertInventory(&Inv(*s), Elmt(Campur, (target-1)));
                printString(FoodName(Elmt(Campur, target-1)));
                printf(" berhasil dibuat dan sudah dimasukkan di inventory\n");
                progressTime(s, pesanan, currTime);
            }
            else{
                CreateListStatik(&unHave);
                unHave = TidakDimiliki(Inv(*s), bahan, katalog);
                printf("Gagal membuat ");
                printString(FoodName(Elmt(Campur, target-1)));
                printf(" karena tidak memiliki bahan berikut : \n");
                for(int i = 0; i<listLength(unHave); i++){
                    printf("%d. ", (i+1));
                    printString(FoodName(Elmt(unHave,i)));
                    printf("\n");
                }
            }
        }
        else{
            printf("Target tidak valid!\n");
        }
        
        printf("\n");
        inputCommand(&cmd);
        while (!isCommandInteger(cmd)) {
            printf("\n");
            printf("Command tidak valid.\n");
            printf("\n");
            inputCommand(&cmd);
        }
        target = parseToInteger(cmd);
    }
}
