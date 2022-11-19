#include <stdio.h>
#include "../prioqueuemakanan/prioqueuemakanan.c"
#include "../point/point.c"
#include "../time/time.c" 
#include "../string/string.c"
#include "../inventory/inventory.c" 
#include "../word-machine/charmachine.c"
#include "../makanan/makanan.c"
#include "../word-machine/wordmachine.c"
#include "../simulator/simulator.c"

int main () {
    Simulator s;  
    PrioQueueMakanan q ;
    Makanan m , m1 , m2 ; 
    String c , c1 ,c2 ,name;
    TIME delivery,delivery1,delivery2;
    TIME Expired,expired1,expired2 ;
    Point loc , loc1 ,loc2 ; 
    
    MakeEmptyQueue(&q,3) ; 
    if(IsEmptyQueue(q)){
        printf("true\n") ; 
    }
    else { 
        printf("false\n"); 
    }
    
    createString("lele",4,&c) ;
    CreateTime(&delivery,1,2,3);
    CreateTime(&Expired,2,3,4); 
    CreatePoint(&loc,0,0) ;
    CreateMakanan(&m,1,c,Expired,loc,delivery) ;
    createString("bebek",5,&c1) ;
    CreateTime(&delivery1,3,6,2);
    CreateTime(&expired1,1,8,7); 
    CreatePoint(&loc,8,6) ;
    CreateMakanan(&m1,45,c1,expired1,loc1,delivery1) ;    
    createString("kambing gulai",13,&c2) ;
    CreateTime(&delivery2,5,6,8);
    CreateTime(&expired2,9,7,6); 
    CreatePoint(&loc2,6,1) ;
    CreateMakanan(&m2,35,c2,expired2,loc2,delivery2) ;    
    Enqueue(&q,m); 
    int l1 = NBElmtQueue(q) ;
    printf("%d\n" , l1) ;
    Enqueue(&q,m1); 
    int l = NBElmtQueue(q) ;
    printf("%d\n" , l) ;   
    Enqueue(&q,m2); 
    int l2 = NBElmtQueue(q) ; 
    printf("%d\n" , l2) ; 
    if(IsFullQueue(q)){
        printf("true\n") ; 
    }
    else { 
        printf("false\n"); 
    }
    createString("sim",3,&name) ;
    CreateSimulation(&s,name,0,0) ; 

    while(NBElmtQueue(q)!=1) { 
        DecDeliveryTimeQueue(&q) ; 
        DequeueZeroToInventory(&q,&s); 
    }
    DealokasiQueue(&q);
    PrintPrioQueueMakanan(q); 
    // while(!IsEmptyQueue(q) ) { 
    //     DecDeliveryTimeQueue(&q) ; 
    //     DequeueZeroToInventory(&q,&s) ;
    // }
    
    // PrintPrioQueueMakanan(q); 

    return 0; 
}