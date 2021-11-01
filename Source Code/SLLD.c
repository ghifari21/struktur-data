/* Single Linked List Dynamic */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char name[50];
    char grade[2];
}grading;

typedef struct elmt* elmtAddress;
typedef struct elmt
{
    grading container;
    elmtAddress next;
}element;

typedef struct
{
    element* first;
}list;

void createList(list *L);
int countElement(list L);
void addFirst(char nim[], char name[], char grade[], list *L);
void addAfter(element* prev, char nim[], char name[], char grade[], list *L);
void addLast(char nim[], char name[], char grade[], list *L);
void delFirst(list *L);
void delAfter(element* prev, list *L);
void delLast(list *L);
void delAll(list *L);
void printElement(list L);

int main(){
    list L;
    createList(&L);
    printElement(L);

    printf("=================\n");

    addFirst("1", "Orang_1", "A", &L);
    addAfter(L.first, "2", "Orang_2", "A", &L); 
    addLast("3", "Orang_3", "A", &L);
    printElement(L);

    printf("=================\n");

    delLast(&L);
    delAfter(L.first, &L);
    delFirst(&L);
    printElement(L);

    printf("=================\n");

    return 0;
}

void createList(list *L){
    (*L).first = NULL;
}

int countElement(list L){
    int result = 0;
    if (L.first != NULL)
    {   // jika list tidak kosong
        element* ptr;
        ptr = L.first;
        while (ptr != NULL)
        {
            result++;
            ptr = ptr->next;
        }
    }
    return result;
}

void addFirst(char nim[], char name[], char grade[], list *L){
    element* new = (element*) malloc (sizeof (element));
    strcpy(new->container.nim, nim);
    strcpy(new->container.name, name);
    strcpy(new->container.grade, grade);

    if ((*L).first == NULL)
    {
        new->next = NULL;
    }else
    {
        new->next = (*L).first;
    }
    (*L).first = new;
    new = NULL;
}

void addAfter(element* prev, char nim[], char name[], char grade[], list *L){
    element* new = (element*) malloc (sizeof (element));
    strcpy(new->container.nim, nim);
    strcpy(new->container.name, name);
    strcpy(new->container.grade, grade);

    if (prev->next == NULL)
    {
        new->next = NULL;
    }else
    {
        new->next = prev->next;
    }
    prev->next = new;
    new = NULL;
}

void addLast(char nim[], char name[], char grade[], list *L){
    if ((*L).first == NULL)
    {
        addFirst(nim, name, grade, L);
    }else
    {
        element* prev = (*L).first;
        while (prev->next != NULL)
        {
            prev = prev->next;
        }
        addAfter(prev, nim, name, grade, L);
    }
}

void delFirst(list *L){
    if ((*L).first != NULL)
    {
        element* delete = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
        }else
        {
            (*L).first = (*L).first->next;
            delete->next = NULL;
        }
        free(delete);
    }
}

void delAfter(element* prev, list *L){
    element* delete = prev->next;
    if (delete != NULL)
    {
        if (delete->next == NULL)
        {
            prev->next = NULL;
        }else
        {
            prev->next = delete->next;
            delete->next = NULL;
        }
        free(delete);
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
            element* last = (*L).first;
            element* prev;
            while (last->next != NULL)
            {
                prev = last;
                last = last->next;
            }
            delAfter(prev, L);
        }
    }
}

void delAll(list *L){
    if (countElement(*L) != 0)
    {
        for (int i = countElement(*L); i > 0; i--)
        {
            delLast(L);
        }
    }
}

void printElement(list L){
    if (L.first != NULL)
    {
        element* ptr = L.first;
        int i = 1;
        while (ptr != NULL)
        {
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", ptr->container.nim);
            printf("nama : %s\n", ptr->container.name);
            printf("nilai : %s\n", ptr->container.grade);
            printf("------------\n");
            
            i++;
            ptr = ptr->next;
        }
    }else
    {
        printf("list kosong\n");
    }
}