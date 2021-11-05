/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TP3           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void createEmpty(stack *S){ // membuat stack
    (*S).top = NULL;
}

int isEmpty(stack S){
    int result = 0;
    if (S.top == NULL)
    {   // jika stack kosong
        result = 1;
    }
    return result;   
}

int countElement(stack S){
    int result = 0;
    if (S.top != NULL)
    {   // jika stack tidak kosong
        element* ptr = S.top;
        while (ptr != NULL)
        {   // looping untuk menghitung banyak element
            result++;
            ptr = ptr->next;
        }
    }
    return result;
}

void push(int year, char title[], char bandName[], stack *S){
    // memasukan data ke stack
    element* new = (element *) malloc (sizeof (element));
    new->container.year = year;
    strcpy(new->container.title, title);
    strcpy(new->container.bandName, bandName);

    if ((*S).top == NULL)
    {   // jika stack kosong
        new->next = NULL;
    }else
    {   // jika stack tidak kosong
        new->next = (*S).top;
    }
    (*S).top = new;
    new = NULL;
}

void musicFilter(stack *Stotal, stack *Spop, stack *Srock){
    element *ptr = Stotal->top;
    int count, i;
    while (ptr != NULL)
    {
        // proses menghitung nilai ascii dari string judul lagu
        count = 0;
        for ( i = 0; i < strlen(ptr->container.title); i++)
        {
            count += ptr->container.title[i];
        }

        if (count % 2 == 0)
        {   // jika nilai ascii genap, maka data lagu akan dimasukan ke playlist rock
            push(ptr->container.year, ptr->container.title, ptr->container.bandName, Srock);
        }else
        {   // jika nilai ascii ganjil, maka data lagu akan dimasukan ke playlist pop
            push(ptr->container.year, ptr->container.title, ptr->container.bandName, Spop);
        }
        ptr = ptr->next;
    }
}

void printStack(stack S){
    if (S.top != NULL)
    {   // jika stack tidak kosong
        element* ptr = S.top;
        int i = 1;
        while (ptr != NULL)
        {
            printf("%d. %s\n", i, ptr->container.title);
            ptr = ptr->next;
            i++;
        }
    }
}