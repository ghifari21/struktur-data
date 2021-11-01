/* Doubly Linked List Dynamic */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[50];
    char nilai[2];
}nilaiMatkul;

typedef struct elmt *elmtAddress;
typedef struct elmt
{
    nilaiMatkul container;
    elmtAddress prev;
    elmtAddress next;
}element;

typedef struct
{
    element *first;
    element *tail;
}list;

void createList(list *L);
int countElement(list L);
void addFirst(char nim[], char nama[], char nilai[], list *L);
void addAfter(element* before, char nim[], char nama[], char nilai[], list *L);
void addLast(char nim[], char nama[], char nilai[], list *L);
void delFirst(list *L);
void delAfter(element* before, list *L);
void delLast(list *L);
void delAll(list *L);
void printElement(list L);

int main(){
    list L;
    createList(&L);

    printf("============\n");
    addFirst("1", "Orang1", "A", &L);
    addAfter(L.first, "2", "Orang2", "A", &L);
    addLast("3", "Orang3", "A", &L);
    printElement(L);
    printf("============\n");
    delLast(&L);
    delAfter(L.first, &L);
    delFirst(&L);
    printElement(L);
    printf("============\n");

    return 0;
}

void createList(list *L){
    (*L).first = NULL;
    (*L).tail = NULL;
}

int countElement(list L){
    int result = 0;
    if (L.first != NULL)
    {   // jika list tidak kosong
        element* bantu;
        bantu = L.first;
        while (bantu != NULL)
        {
            result++;
            bantu = bantu->next;
        }
    }
    return result;
}

void addFirst(char nim[], char nama[], char nilai[], list *L){
    element* new = (element*) malloc (sizeof(element));

    strcpy(new->container.nim, nim);
    strcpy(new->container.nama, nama);
    strcpy(new->container.nilai, nilai);

    if ((*L).first == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        (*L).tail = new;
    }else
    {
        new->next = (*L).first;
        new->prev = NULL;
        (*L).first->prev = new;
    }
    (*L).first = new;
    new = NULL;
}

void addAfter(element* before, char nim[], char nama[], char nilai[], list *L){
    if (before != NULL)
    {
        element* new = (element*) malloc (sizeof(element));

        strcpy(new->container.nim, nim);
        strcpy(new->container.nama, nama);
        strcpy(new->container.nilai, nilai);

        if (before->next == NULL)
        {
            new->next = NULL;
            (*L).tail = new;
        }else
        {
            new->next = before->next;
            new->next->prev = new;
        }
        new->prev = before;
        before->next = new;
        new = NULL;
    }
}

void addLast(char nim[], char nama[], char nilai[], list *L){
    if ((*L).first == NULL)
    {   //jika list adalah list kosong
        addFirst(nim, nama, nilai, L);
    }else
    {   //jika bukan list kosong
        addAfter((*L).tail, nim, nama, nilai, L);
    }
}

void delFirst(list *L){
    if ((*L).first != NULL)
    {   // jika bukan list kosong
        element* delete = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
            (*L).tail = NULL;
        }else
        {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            delete->next = NULL;
        }
        free(delete);
    }
}

void delAfter(element* before, list *L){
    if (before != NULL)
    {
        element* delele = before->next;
        if (delele != NULL)
        {
            if (delele->next == NULL)
            {
                before->next = NULL;
                (*L).tail = before;
            }else
            {
                before->next = delele->next;
                delele->next->prev = before;
                delele->next = NULL;
            }
            delele->prev = NULL;
            free(delele);
        }
    }
}

void delLast(list *L){
    if ((*L).first != NULL)
    {
        if (countElement(*L) == 1)
        {
            delFirst(L);
        }else
        {
            delAfter((*L).tail->prev, L);
        }
    }
}

void delAll(list *L){
    if (countElement(*L) != 0)
    {
        for (int i = countElement(*L); i >= 1; i--)
        {
            delLast(L);
        }
    }
}

void printElement(list L){
    if (L.first != NULL)
    {
        element* bantu = L.first;
        int i = 1;
        while (bantu != NULL)
        {
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", bantu->container.nim);
            printf("nama : %s\n", bantu->container.nama);
            printf("nilai : %s\n", bantu->container.nilai);
            printf("---------------\n");

            bantu = bantu->next;
            i++;
        }
    }else
    {
        printf("list kosong\n");
    }
}