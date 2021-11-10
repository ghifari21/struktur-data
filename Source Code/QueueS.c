/* Queue Static */

#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char name[50];
    float nilai;
}nilaiMatkul;

typedef struct
{
    int first;
    int last;
    nilaiMatkul data[10];
}queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int isFull(queue Q);
void add(char nim[], char name[], float nilai, queue *Q);
void addPriority(char nim[], char name[], float nilai, int priority, queue *Q);
void del(queue *Q);
void printQueue(queue Q);

int main(){
    queue Q;
    createEmpty(&Q);
    printQueue(Q);
    printf("===============\n");
    add("13507701", "Nana", 64.75, &Q);
    add("13507702", "Rudi", 75.11, &Q);
    add("13507703", "Dea", 84.63, &Q);
    printQueue(Q);
    printf("===============\n");
    del(&Q);
    del(&Q);
    printQueue(Q);
    printf("===============\n");

    return 0;
}

void createEmpty(queue *Q){
    (*Q).first = -1;
    (*Q).last = -1;
}

int isEmpty(queue Q){
    int result = 0;
    if (Q.first == -1)
    {
        result = 1;
    }
    return result;
}

int isFull(queue Q){
    int result = 0;
    if (Q.last == 9)
    {
        result = 1;
    }
    return result;
}

void add(char nim[], char name[], float nilai, queue *Q){
    if (isEmpty(*Q) == 1)
    {   // jika queue kosong
        (*Q).first = 0;
        (*Q).last = 0;
        strcpy((*Q).data[0].nim, nim);
        strcpy((*Q).data[0].name, name);
        (*Q).data[0].nilai = nilai;
    }else
    {   // jika queue tidak kosong
        if (isFull(*Q) != 1)
        {   // jika queue tidak penuh
            (*Q).last++;
            strcpy((*Q).data[(*Q).last].nim, nim);
            strcpy((*Q).data[(*Q).last].name, name);
            (*Q).data[(*Q).last].nilai = nilai;
        }else
        {   // jika queue penuh
            printf("queue penuh\n");
        }
    }
}

void addPriority(char nim[], char name[], float nilai, int priority, queue *Q){
    if (isEmpty(*Q) == 1)
    {
        (*Q).first = 0;
        (*Q).last = 0;
        strcpy((*Q).data[0].nim, nim);
        strcpy((*Q).data[0].name, name);
        (*Q).data[0].nilai = nilai;
    }else
    {
        if (isFull(*Q) != 1)
        {
            if (priority > (*Q).last)
            {
                (*Q).last++;
                strcpy((*Q).data[(*Q).last].nim, nim);
                strcpy((*Q).data[(*Q).last].name, name);
                (*Q).data[(*Q).last].nilai = nilai;
            }else
            {
                for (int i = (*Q).last - 1; i >= priority; i--)
                {
                    strcpy((*Q).data[i+1].nim, (*Q).data[i].nim);
                    strcpy((*Q).data[i+1].name, (*Q).data[i].name);
                    (*Q).data[i+1].nilai = (*Q).data[i].nilai;
                    if (i == priority)
                    {
                        strcpy((*Q).data[i].nim, nim);
                        strcpy((*Q).data[i].name, name);
                        (*Q).data[i].nilai = nilai;
                    }
                }
            }
        }else
        {
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
            strcpy((*Q).data[i-1].nim, (*Q).data[i].nim);
            strcpy((*Q).data[i-1].name, (*Q).data[i].name);
            (*Q).data[i-1].nilai = (*Q).data[i].nilai;
        }
        (*Q).last--;
    }
}

void printQueue(queue Q){
    if (Q.first != -1)
    {   // jika queue tidak kosong
        printf("-----isi stack-----\n");
        for (int i = Q.last; i >= Q.first; i--)
        {
            printf("===============\n");
            printf("element ke: %d\n", i);
            printf("nim: %s\n", Q.data[i].nim);
            printf("nama: %s\n", Q.data[i].name);
            printf("nilai: %f\n", Q.data[i].nilai);
        }
        printf("--------------------\n");
    }else
    {   // jika queue kosong
        printf("queue kosong\n");
    }
}