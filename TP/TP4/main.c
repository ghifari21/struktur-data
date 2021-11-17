/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TP4           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

int main()
{
    queue Q;
    createEmpty(&Q);
    int stop = 0;
    memberRecord data;
    // input selama inputan nama bukanlah stop
    do
    {
        scanf("%s", &data.name);
        if (strcmp(data.name, "stop") != 0)
        {   // jika inputan nama bukanlah stop
            scanf("%s %d", &data.membership, &data.time);
            if (strcmp(data.membership, "nonmember") == 0)
            {   // jika inputan membership adalah nonmember
                addNonMembership(data.name, data.membership, data.time, &Q);    // jalankan add untuk nonmember
            }else
            {   // jika inputan membership adalah platinum/gold/silver
                addMembership(data.name, data.membership, data.time, &Q);   // jalankan add untuk member
            }
        }else
        {   // jika inputan nama adalah stop
            stop = 1;
        }
    } while (stop == 0);
    processingQueue(&Q);    // proses queue
    printQueue(Q);  // output

    return 0;
}
