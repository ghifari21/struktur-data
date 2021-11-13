/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan Kuis          |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

int main()
{
    queue Q;
    createEmpty(&Q);    // create queue

    bansosRecord data;
    int i, count;
    scanf("%d", &count);    // banyaknya data
    for ( i = 0; i < count; i++)    // input
    {
        scanf("%s %d %s %d", &data.name, &data.priority, &data.city, &data.bansosNeeded);
        addPriority(data.name, data.priority, data.city, data.bansosNeeded, &Q);    // add berprioritas
    }
    int pop;
    scanf("%d", &pop);  // banyaknya element yang menerima bansos
    printQueue(&Q, pop);    // output

    return 0;
}
