/* Single Linked List Static */

#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char name[50];
    char grade[2];
}grading;

typedef struct
{
    grading container;
    int next;
}element;

typedef struct
{
    int first;
    element data[10];
}list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nim[], char name[], char grade[], list *L);
void addAfter(int prev, char nim[], char name[], char grade[], list *L);
void addLast(char nim[], char name[], char grade[], list *L);
void delFirst(list *L);
void delAfter(int prev, list *L);
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
    (*L).first = -1;
    
    for (int i = 0; i < 10; i++)
    {
        (*L).data[i].next = -2;
    }
}

int countElement(list L){
    int result = 0;
    if (L.first != -1)
    {   // list tidak kosong
        int ptr;
        ptr = L.first;
        while (ptr != -1)
        {
            result++;
            ptr = L.data[ptr].next;
        }
    }
    return result;
}

int emptyElement(list L){
    int result = -1;
    if (countElement(L) < 10)
    {
        int found = 0, i = 0;
        while (found == 0 && i < 10)
        {
            if (L.data[i].next == -2)
            {
                result = i;
                found = 1;
            }else
            {
                i++;
            }
        }
    }
    return result;
}

void addFirst(char nim[], char name[], char grade[], list *L){
    if (countElement(*L) < 10)
    {
        int new = emptyElement(*L);
        strcpy((*L).data[new].container.nim, nim);
        strcpy((*L).data[new].container.name, name);
        strcpy((*L).data[new].container.grade, grade);

        if ((*L).first == -1)
        {   // jika list kosong
            (*L).data[new].next = -1;
        }else
        {   // jika list tidak kosong
            (*L).data[new].next = (*L).first;
        }
        (*L).first = new;
    }else
    {
        printf("list penuh\n");
    }
}

void addAfter(int prev, char nim[], char name[], char grade[], list *L){
    if (countElement(*L) < 10)
    {
        int new = emptyElement(*L);
        strcpy((*L).data[new].container.nim, nim);
        strcpy((*L).data[new].container.name, name);
        strcpy((*L).data[new].container.grade, grade);

        if ((*L).data[prev].next == -1)
        {
            (*L).data[new].next = -1;
        }else
        {   
            (*L).data[new].next = (*L).data[prev].next;
        }
        (*L).data[prev].next = new;
    }else
    {
        printf("list penuh\n");
    }
}
void addLast(char nim[], char name[], char grade[], list *L){
    if ((*L).first == -1)
    {
        addFirst(nim, name, grade, L);
    }else
    {
        if (countElement(*L) < 10)
        {
            int prev = (*L).first;
            while ((*L).data[prev].next != -1)
            {
                prev = (*L).data[prev].next;
            }
            addAfter(prev, nim, name, grade, L);
        }else
        {
            printf("list penuh\n");
        }
    }
}

void delFirst(list *L){
    if ((*L).first != -1)
    {
        int delete = (*L).first;
        if (countElement(*L) < 10)
        {
            (*L).first = -1;
        }else
        {
            (*L).first = (*L).data[delete].next;
        }
        (*L).data[delete].next = -2;
    }else
    {
        printf("list kosong\n");
    }
}

void delAfter(int prev, list *L){
    int delete = (*L).data[prev].next;
    if (delete != -1)
    {
        if ((*L).data[delete].next == -1)
        {
            (*L).data[prev].next = -1;
        }else
        {
            (*L).data[prev].next = (*L).data[delete].next;
        }
        (*L).data[delete].next = -2;
    }
}

void delLast(list *L){
    if ((*L).first != -1)
    {
        if (countElement(*L) == 1)
        {
            delFirst(L);
        }else
        {
            int delete = (*L).first, prev;
            while ((*L).data[delete].next != -1)
            {
                prev = delete;
                delete = (*L).data[delete].next;
            }
            delAfter(prev, L);
        }
    }else
    {
        printf("list kosong\n");
    }
}

void delAll(list *L){
    for (int i = countElement(*L); i > 0; i--)
    {
        delLast(L);
    }
}

void printElement(list L){
    if (L.first != -1)
    {
        int ptr = L.first, i = 1;
        while (ptr != -1)
        {
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", L.data[ptr].container.nim);
            printf("nama : %s\n", L.data[ptr].container.name);
            printf("nilai : %s\n", L.data[ptr].container.grade);
            printf("next : %d\n", L.data[ptr].next);
            printf("------------\n");
            
            i++;
            ptr = L.data[ptr].next;
        }
    }else
    {
        printf("list kosong\n");
    }
}