/* Queue Dynamic */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char name[50];
    float nilai;
}nilaiMatkul;

typedef struct elmt *elmtAddress;
typedef struct elmt
{
    nilaiMatkul container;
    elmtAddress next;
}element;

typedef struct
{
    element *first;
    element *last;
}queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char nim[], char name[], float nilai, queue *Q);
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
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isEmpty(queue Q){
    int result = 0;
    if (Q.first == NULL)
    {
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

void add(char nim[], char name[], float nilai, queue *Q){
    element* new = (element *) malloc (sizeof (element));
    strcpy(new->container.nim, nim);
    strcpy(new->container.name, name);
    new->container.nilai = nilai;

    new->next = NULL;
    if ((*Q).first == NULL)
    {   // jika queue kosong
        (*Q).first = new;
    }else
    {
        (*Q).last->next = new;
    }
    (*Q).last = new;
    new = NULL;
}

void del(queue *Q){
    if ((*Q).first != NULL)
    {   // jika queue tidak kosong
        element *delete = (*Q).first;
        if (countElement(*Q) == 1)
        {
            (*Q).first = NULL;
            (*Q).last = NULL;
        }else
        {
            (*Q).first = (*Q).first->next;
            delete->next = NULL;
        }
        free(delete);
    }
}

void printQueue(queue Q){
    if (Q.first != NULL)
    {   // jika queue tidak kosong
        printf("---isi queue---\n");
        element* ptr = Q.first;
        int i = 1;
        while (ptr != NULL)
        {
            printf("===============\n");
            printf("element ke: %d\n", i);
            printf("nim: %s\n", ptr->container.nim);
            printf("nama: %s\n", ptr->container.name);
            printf("nilai: %f\n", ptr->container.nilai);
            ptr = ptr->next;
            i++;
        }
        printf("---------------\n");
    }else
    {   // jika queue kosong
        printf("queue kosong\n");
    }
}