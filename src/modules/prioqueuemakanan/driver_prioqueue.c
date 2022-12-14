#include <stdio.h>
#include "../prioqueuemakanan/prioqueuemakanan.h"

int main () {
    Simulator s;  
    PrioQueueMakanan q;
    Makanan m , m1 , m2; 
    String c , c1 ,c2 ,name;
    TIME delivery,delivery1,delivery2;
    TIME Expired,expired1,expired2;
    Point loc , loc1 ,loc2; 
    
    MakeEmptyQueue(&q,3) ; 
    printf("Empty queue succesfully made?\n");

    IsEmptyQueue(q) ? printf("True\n") : printf("False\n");

    printf("\n");

    createString("Lele",4,&c) ;
    CreateTime(&delivery,1,2,3);
    CreateTime(&Expired,2,3,4); 
    CreatePoint(&loc,0,0) ;
    CreateMakanan(&m,1,c,Expired,loc,delivery);

    createString("Bebek",5,&c1) ;
    CreateTime(&delivery1,3,6,2);
    CreateTime(&expired1,1,8,7); 
    CreatePoint(&loc,8,6) ;
    CreateMakanan(&m1,45,c1,expired1,loc1,delivery1);

    createString("Kambing gulai",13,&c2) ;
    CreateTime(&delivery2,5,6,8);
    CreateTime(&expired2,9,7,6); 
    CreatePoint(&loc2,6,1) ;
    CreateMakanan(&m2,35,c2,expired2,loc2,delivery2);

    printf("Enqueue first food:\n");
    Enqueue(&q,m);
    PrintPrioQueueMakanan(q);
    printf("\n");
    
    
    printf("Enqueue second food:\n");
    Enqueue(&q,m1); 
    PrintPrioQueueMakanan(q);
    printf("\n");

    printf("Enqueue third food:\n");
    Enqueue(&q,m2); 
    PrintPrioQueueMakanan(q);
    printf("\n");

    printf("Is Queue full? ");
    IsFullQueue(q) ? printf("True\n") : printf("False\n");

    createString("Name",4, &name);
    CreateSimulation(&s,name,0,0); 

    while(!IsEmptyQueue(q)!=1) { 
        DecDeliveryTimeQueue(&q) ; 
        DequeueZeroToInventory(&q,&s); 
    }

    PrintPrioQueueMakanan(q);
    displayInventory(Inv(s));

    return 0; 
}