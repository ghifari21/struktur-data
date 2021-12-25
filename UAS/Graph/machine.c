/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan UAS           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void createEmpty(graph *G)
{
    (*G).first = NULL;
}

void addNode(char c, graph *G)
{
    node *new = (node*)malloc(sizeof(node));
    new->container = c;
    new->next = NULL;
    new->arc = NULL;

    if ((*G).first == NULL)
    {   // jika graph kosong
        (*G).first = new;
    }else
    {   /* jika graf tidak kosong
        maka akan menambahkan simpul
        baru pada akhir graph */
        node *last = (*G).first;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new;
    }
}

void addPath(node *first, node *dest, int weight)
{
    path *new = (path*)malloc(sizeof(path));
    new->pathContainer = weight;
    new->nextPath = NULL;
    new->destination = dest;

    if (first->arc == NULL)
    {   // jika list jalur kosong
        first->arc = new;
    }else
    {   /* jika list jalur tidak kosong
        maka akan menambahkan jalur baru
        pada akhir list jalur */
        path *last = first->arc;
        while (last->nextPath != NULL)
        {
            last = last->nextPath;
        }
        last->nextPath = new;
    }
}

node* findNode(char c, graph G)
{
    node *result = NULL;
    node *ptr = G.first;
    
    int found = 0;
    while (ptr != NULL && found == 0)
    {   // looping sampai menemukan c atau list sudah habis
        if (ptr->container == c)
        {   // jika ketemu c
            result = ptr;
            found = 1;
        }else
        {   // jika tidak ketemu c
            ptr = ptr->next;
        }
    }
    return result;
}

int isCycle(char start, node *ptr, graph G)
{
    int flag = 0;

    if (ptr != NULL && ptr->arc->destination != NULL)
    {   // jika ptr dan destinasi tidak kosong
        path *ptrPath = ptr->arc;
        node *search;
        while (ptrPath != NULL && flag != 1)
        {   // looping selama jalur tidak kosong dan jalur memutar belu ditemukan
            if (start == ptrPath->destination->container)
            {   // jika jalur memutar ditemukan
                flag = 1;
            }else
            {   // jika tidak ditemukan
                search = findNode(ptrPath->destination->container, G);
                if (search != NULL)
                {
                    flag = isCycle(start, search, G);
                }
                ptrPath = ptrPath->nextPath;
            }
        }
    }

    return flag;
}