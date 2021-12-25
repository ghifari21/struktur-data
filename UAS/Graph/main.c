/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan UAS           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

int main()
{
    graph G;
    createEmpty(&G);    // membuat graph kosong
    char origin, dest;
    node *check;
    node *begin;
    node *end;
    int flag = 0;

    do  // looping selama input bukan 0
    {
        scanf(" %c", &origin);
        if (origin != '0')
        {   // jika input bukan 0
            scanf(" %c", &dest);
            check = findNode(origin, G);    // mencari node origin
            if (check == NULL)
            {   // jika tidak ditemukan
                addNode(origin, &G);    // add node
            }
            check = findNode(dest, G);  // mencari node destination
            if (check == NULL)
            {   // jika tidak ditemukan
                addNode(dest, &G);  // add node
            }
            
            // membuat jalur
            begin = findNode(origin, G);
            end = findNode(dest, G);
            if (begin != NULL && end != NULL)
            {
                addPath(begin, end, 1);
            }
        }else
        {   // jika inputan adalah 0
            flag = 1;
        }
    } while (flag == 0);
    
    // mencari jalur yang memutar
    flag = 0;
    node *ptr = G.first;
    while (ptr != NULL && flag != 1)
    {
        flag = isCycle(ptr->container, ptr, G);
        ptr = ptr->next;
    }

    if (flag == 1)
    {   // jika ditemukan jalur yang memutar
        printf("ada jalur memutar\n");
    }else
    {   // jika tidak ditemukan
        printf("tidak ada jalur memutar\n");
    }

    return 0;
}
