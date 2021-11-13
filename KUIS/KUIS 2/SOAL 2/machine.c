/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan Kuis          |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void createEmpty(queue *Q){
    /* set first dan last
    menjadi null */
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isEmpty(queue Q){
    int result = 0;
    if (Q.first == NULL)
    {   // jika first = null maka queue kosong
        result = 1;
    }
    return result;
}

int countElement(queue Q){
    int result = 0;
    if (Q.first != NULL)
    {   // jika queue tidak kosong
        element *ptr = Q.first;
        while (ptr != NULL)
        {
            result++;
            ptr = ptr->next;
        }
    }
    return result;
}

void addPriority(char name[], int priority, char city[], int bansosNeeded, queue *Q){
    element* new = (element *) malloc (sizeof (element));
    strcpy(new->container.name, name);
    new->container.priority = priority;
    strcpy(new->container.city, city);
    new->container.bansosNeeded = bansosNeeded;
    new->next = NULL;

    if (isEmpty(*Q) == 1)
    {   // jika queue kosong
        /* set new menjadi first dan last */
        (*Q).first = new;
        (*Q).last = new;
    }else
    {   // jika queue tidak kosong
        if (priority == 1)
        {   // jika nilai prioritas = 1
            // set element new tersebut menjadi first
            new->next = (*Q).first;
            (*Q).first = new;
        }
        else if (priority > countElement(*Q))
        {   /* jika prioritasnya lebih besar
            daripada element terakhir, maka
            new akan menjadi element terakhir */
            (*Q).last->next = new;
            (*Q).last = new;
        }
        else
        {   /* jika prioritasnya ada ditengah */
            element *ptr = (*Q).first;
            // looping mencari posisi
            for (int i = 1; i < priority-1; i++)
            {
                ptr = ptr->next;
            }
            /* masukan ke dalam urutannya,
            konsepnya mirip dengan addfirst
            pada single linked list */
            new->next = ptr->next;
            ptr->next = new;
        }
    }
    new = NULL;
}

void del(queue *Q){
    if ((*Q).first != NULL)
    {   // jika queue tidak kosong
        element *delete = (*Q).first;
        if (countElement(*Q) == 1)
        {   /* jika banyak element hanya 1
            maka fist dan last di NULL kan */
            (*Q).first = NULL;
            (*Q).last = NULL;
        }else
        {   // jika banyak element lebih dari 1
            (*Q).first = (*Q).first->next;
            delete->next = NULL;
        }
        free(delete);
    }
}

void printQueue(queue *Q, int count){
    if ((*Q).first != NULL)
    {   // jika queue tidak kosong
        element* ptr = (*Q).first;
        int i = 0;
        printf("Bantuan Tersalurkan:\n");
        while (i < count)
        {   // output sebanyak input dari user
            printf("%s %d %s %d\n", ptr->container.name, ptr->container.priority, ptr->container.city, ptr->container.bansosNeeded);
            // iterasi
            ptr = ptr->next;
            i++;
            // kemudian delete element tersebut
            del(Q);
        }
        printf("\nAntrian berisi:\n");
        // output sisanya, yang belum keluar dari queue
        ptr = (*Q).first;
        while (ptr != NULL)
        {
            printf("%s %d %s %d\n", ptr->container.name, ptr->container.priority, ptr->container.city, ptr->container.bansosNeeded);
            ptr = ptr->next;
        }
        
    }else
    {   // jika queue kosong
        printf("queue kosong\n");
    }
}