/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TM7           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void createEmpty(queue *Q){
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isEmpty(queue Q){
    int result = 0;
    if (Q.first == NULL)
    {   // jika first null / queue kosong
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

void add(char name[], char rating[], queue *Q){
    element* new = (element *) malloc (sizeof (element));
    strcpy(new->container.name, name);
    strcpy(new->container.rating, rating);

    new->next = NULL;
    if ((*Q).first == NULL)
    {   // jika queue kosong
        (*Q).first = new;
    }else
    {   // jika queue tidak kosong
        (*Q).last->next = new;
    }
    (*Q).last = new;
    new = NULL;
}

void addPriority(char name[], char rating[], int priority, queue *Q){
    element* new = (element *) malloc (sizeof (element));
    strcpy(new->container.name, name);
    strcpy(new->container.rating, rating);
    new->next = NULL;

    if (isEmpty(*Q) == 1)
    {   // jika queue kosong
        (*Q).first = new;
        (*Q).last = new;
    }else
    {   // jika queue tidak kosong
        if (priority == 1)
        {   // jika prioritas 1
            new->next = (*Q).first;
            (*Q).first = new;
        }
        else if (priority > countElement(*Q))
        {   // jika nilai prioritasnya lebih besar daripada element terakhir
            (*Q).last->next = new;
            (*Q).last = new;
        }
        else
        {   // jika memasukan element prioritas ditengah queue
            element *ptr = (*Q).first;
            for (int i = 1; i < priority-1; i++)
            {
                ptr = ptr->next;
            }
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
        {   // jika banyak element hanya 1
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

void move(queue *Q1, queue *Q2){
    /* masukan element pertama dari queue 1 ke queue 2 */
    element *ptr = (*Q1).first;
    add(ptr->container.name, ptr->container.rating, Q2);
    del(Q1);
}

void printQueue(queue Q){
    if (Q.first != NULL)
    {   // jika queue tidak kosong
        element* ptr = Q.first;
        while (ptr != NULL)
        {
            printf("%s %s\n", ptr->container.name, ptr->container.rating);
            ptr = ptr->next;
        }
    }else
    {   // jika queue kosong
        printf("queue kosong\n");
    }
}