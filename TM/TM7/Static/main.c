/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TM7           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

int main()
{
    queue Q1, Q2;
    createEmpty(&Q1);   // queue 1
    createEmpty(&Q2);   // queue 2
    
    // input
    int i, count = 6;
    GOTY data[count];
    for ( i = 0; i < count; i++)
    {
        scanf("%s %s", &data[i].name, &data[i].rating);
    }
    
    // input / output data
    add(data[0].name, data[0].rating, &Q1);
    add(data[1].name, data[1].rating, &Q1);
    addPriority(data[2].name, data[2].rating, 2, &Q1);
    printf("******************\nQueue 1\n");
    printQueue(Q1);
    move(&Q1, &Q2);
    printf("******************\nQueue 1\n");
    printQueue(Q1);
    printf("******************\nQueue 2\n");
    printQueue(Q2);
    addPriority(data[3].name, data[3].rating, 1, &Q1);
    addPriority(data[4].name, data[4].rating, 99, &Q1);
    printf("******************\nQueue 1\n");
    printQueue(Q1);
    move(&Q1, &Q2);
    move(&Q1, &Q2);
    add(data[5].name, data[5].rating, &Q1);
    printf("******************\nQueue 1\n");
    printQueue(Q1);
    printf("******************\nQueue 2\n");
    printQueue(Q2);
    printf("******************\n");
    return 0;
}
