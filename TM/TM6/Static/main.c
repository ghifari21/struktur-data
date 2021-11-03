/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TM6 Statis    |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

int main()
{
    stack S1, S2;
    // membuat stack
    createEmpty(&S1);
    createEmpty(&S2);
    int i, count = 6;
    recordMenu data[count];
    // input data
    for ( i = 0; i < count; i++)
    {
        scanf("%s %d", &data[i].name, &data[i].price);
    }
    printf("S1:\n");
    printStack(S1);
    printf("S2:\n");
    printStack(S2);
    printf("==================\n");
    push(data[0].name, data[0].price, &S1);
    push(data[1].name, data[1].price, &S2);
    push(data[2].name, data[2].price, &S2);
    printf("S1:\n");
    printStack(S1);
    printf("S2:\n");
    printStack(S2);
    printf("==================\n");
    pop(&S1);
    popToAnotherStack(&S2, &S1);
    push(data[3].name, data[3].price, &S1);    
    push(data[4].name, data[4].price, &S2);    
    push(data[5].name, data[5].price, &S1);
    pop(&S2);
    popToAnotherStack(&S1, &S2);
    printf("S1:\n");
    printStack(S1);
    printf("S2:\n");
    printStack(S2);
    printf("==================\n");


    return 0;
}
