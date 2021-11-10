/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TM7           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void createEmpty(queue *Q){ // create queue
    (*Q).first = -1;
    (*Q).last = -1;
}

int isEmpty(queue Q){
    int result = 0;
    if (Q.first == -1)
    {   // jika queue kosong
        result = 1;
    }
    return result;
}

int isFull(queue Q){
    int result = 0;
    if (Q.last == 9)
    {   // jika queue penuh
        result = 1;
    }
    return result;
}

void add(char name[], char rating[], queue *Q){
    if (isEmpty(*Q) == 1)
    {   // jika queue kosong
        (*Q).first = 0;
        (*Q).last = 0;
        strcpy((*Q).data[0].name, name);
        strcpy((*Q).data[0].rating, rating);
    }else
    {   // jika queue tidak kosong
        if (isFull(*Q) != 1)
        {   // jika queue tidak penuh
            (*Q).last++;
            strcpy((*Q).data[(*Q).last].name, name);
            strcpy((*Q).data[(*Q).last].rating, rating);
        }else
        {   // jika queue penuh
            printf("queue penuh\n");
        }
    }
}

void addPriority(char name[], char rating[], int priority, queue *Q){
    if (isEmpty(*Q) == 1)
    {   // jika queue kosong
        (*Q).first = 0;
        (*Q).last = 0;
        strcpy((*Q).data[0].name, name);
        strcpy((*Q).data[0].rating, rating);
    }else
    {
        if (isFull(*Q) != 1)
        {   // jika queue tidak penuh
            if (priority - 1 > (*Q).last)
            {   // jika prioritas new lebih besar daripada element terakhir
                (*Q).last++;
                strcpy((*Q).data[(*Q).last].name, name);
                strcpy((*Q).data[(*Q).last].rating, rating);
            }else
            {   // jika ingin memasukan element new di depan atau ditengah queue
                /* cara kerjanya menggeser element sebelum prioritas kemudian
                    masukan element prioritas di tempat yang sudah dibikin */
                int i;
                for (i = (*Q).last; i >= priority - 1; i--) // looping untuk memundurkan queue
                {
                    strcpy((*Q).data[i+1].name, (*Q).data[i].name);
                    strcpy((*Q).data[i+1].rating, (*Q).data[i].rating);
                }
                (*Q).last++;
                strcpy((*Q).data[priority - 1].name, name);
                strcpy((*Q).data[priority - 1].rating, rating);
            }
        }else
        {   // jika queue penuh
            printf("queue penuh\n");
        }
    }
}

void del(queue *Q){
    if ((*Q).last == 0)
    {   // jika isi queue hanya satu
        (*Q).first = -1;
        (*Q).last = -1;
    }else
    {   // jika isi queue lebih dari satu
        // menggeser element ke depan
        for (int i = (*Q).first + 1; i <= (*Q).last; i++)
        {
            strcpy((*Q).data[i-1].name, (*Q).data[i].name);
            strcpy((*Q).data[i-1].rating, (*Q).data[i].rating);
        }
        (*Q).last--;
    }
}

void move(queue *Q1, queue *Q2){
    /* masukan element pertama dari queue 1 ke queue 2 */
    add((*Q1).data[(*Q1).first].name, (*Q1).data[(*Q1).first].rating, Q2);
    del(Q1);
}

void printQueue(queue Q){
    if (Q.first != -1)
    {   // jika queue tidak kosong
        for (int i = Q.first; i <= Q.last; i++)
        {
            printf("%s %s\n", Q.data[i].name, Q.data[i].rating);
        }
    }else
    {   // jika queue kosong
        printf("queue kosong\n");
    }
}