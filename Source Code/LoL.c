/* List of List */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char nim[10];
    char name[50];
}student;

typedef struct
{
    char code[10];
    char grade[2];
}subject;

typedef struct eclmn *columnAddress;
typedef struct eclmn
{
    subject containerCol;
    columnAddress nextCol;
}eColumn;

typedef struct erw *rowAddress;
typedef struct erw
{
    student container;
    eColumn *col;
    rowAddress next;
}eRow;

typedef struct
{
    eRow *first;
}list;

void createList(list *L);
int countElementRow(list L);
int countElementColumn(eRow L);
void addFirstRow(char nim[], char name[], list *L);
void addAfterRow(eRow *prev, char nim[], char name[]);
void addLastRow(char nim[], char name[], list *L);
void addFirstColumn(char code[], char grade[], eRow *L);
void addAfterColumn(eColumn *prev, char code[], char grade[]);
void addLastColumn(char code[], char grade[], eRow *L);
void delFirstColumn(eRow *L);
void delAfterColumn(eColumn* prev);
void delLastColumn(eRow *L);
void delAllColumn(eRow *L);
void delFirstRow(list *L);
void delAfterRow(eRow *prev);
void delLastRow(list *L);
void delAllRow(list *L);
void printElement(list L);

int main()
{
    list L;
    createList(&L);
    printElement(L);

    printf("================\n");
    addFirstRow("1", "Orang_1", &L);
    addFirstColumn("IF40K1", "A", L.first);
    addAfterColumn(L.first->col, "IF40Z1", "A");
    addLastColumn("IF40Z2", "A", L.first);
    addAfterRow(L.first, "2", "Orang_2");
    addFirstColumn("TI5141", "A", L.first->next);
    addLastColumn("IF5021", "A", L.first->next);
    addLastRow("3", "Orang", &L);
    addFirstColumn("IF5321", "A", L.first->next->next);
    printElement(L);

    printf("================\n");
    delAllRow(&L);
    printElement(L);
    printf("================\n");

    return 0;
}

void createList(list *L){
    (*L).first = NULL;
}

int countElementRow(list L){
    int result = 0;
    if (L.first != NULL)
    {
        eRow* ptr = L.first;
        while (ptr != NULL)
        {
            result++;
            ptr = ptr->next;
        }
    }
    return result;
}

int countElementColumn(eRow L){
    int result = 0;
    if (L.col != NULL)
    {
        eColumn* ptr = L.col;
        while (ptr != NULL)
        {
            result++;
            ptr = ptr->nextCol;
        }
    }
    return result;
}

void addFirstRow(char nim[], char name[], list *L){
    eRow* new = (eRow*) malloc (sizeof (eRow));
    strcpy(new->container.nim, nim);
    strcpy(new->container.name, name);
    
    new->col = NULL;
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

void addAfterRow(eRow *prev, char nim[], char name[]){
    eRow* new = (eRow*) malloc (sizeof (eRow));
    strcpy(new->container.nim, nim);
    strcpy(new->container.name, name);

    new->col = NULL;
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

void addLastRow(char nim[], char name[], list *L){
    if ((*L).first == NULL)
    {
        addFirstRow(nim, name, L);
    }else
    {
        eRow *last = (*L).first;
        while (last->next != NULL)
        {
            last = last->next;
        }
        addAfterRow(last, nim, name);
    }
}

void addFirstColumn(char code[], char grade[], eRow *L){
    eColumn* new = (eColumn*) malloc (sizeof (eColumn));
    strcpy(new->containerCol.code, code);
    strcpy(new->containerCol.grade, grade);

    if ((*L).col == NULL)
    {
        new->nextCol = NULL;
    }else
    {
        new->nextCol = (*L).col;
    }
    (*L).col = new;
    new = NULL;
}

void addAfterColumn(eColumn *prev, char code[], char grade[]){
    eColumn* new = (eColumn*) malloc (sizeof (eColumn));
    strcpy(new->containerCol.code, code);
    strcpy(new->containerCol.grade, grade);

    if (prev->nextCol == NULL)
    {
        new->nextCol = NULL;
    }else
    {
        new->nextCol = prev->nextCol;
    }
    prev->nextCol = new;
    new = NULL;
}

void addLastColumn(char code[], char grade[], eRow *L){
    if ((*L).col == NULL)
    {
        addFirstColumn(code, grade, L);
    }else
    {
        eColumn *last = (*L).col;
        while (last->nextCol != NULL)
        {
            last = last->nextCol;
        }
        addAfterColumn(last, code, grade);
    }
}

void delFirstRow(list *L){
    if ((*L).first != NULL)
    {
        eRow *delete = (*L).first;
        if (delete->col != NULL)
        {
            delAllColumn(delete);
        }
        if (countElementRow(*L) == 1)
        {
            (*L).first = NULL;
        }else
        {
            (*L).first = (*L).first->next;
        }
        delete->next = NULL;
        free(delete);
    }else
    {
        printf("list kosong\n");
    }
}

void delAfterRow(eRow *prev){
    if (prev != NULL)
    {
        eRow *delete = prev->next;
        if (delete != NULL)
        {
            if (delete->col != NULL)
            {
                delAllColumn(delete);
            }
            if (delete->next == NULL)
            {
                prev->next = NULL;
            }else
            {
                prev->next = delete->next;
            }
            delete->next = NULL;
            free(delete);
        }
    }
}

void delLastRow(list *L){
    if ((*L).first != NULL)
    {
        if (countElementRow(*L) == 1)
        {
            delFirstRow(L);
        }else
        {
            eRow *ptr = (*L).first;
            eRow *prev;
            while (ptr->next != NULL)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            delAfterRow(prev);
        }
    }
}

void delAllRow(list *L){
    if (countElementRow(*L) != 0)
    {
        for (int i = countElementRow(*L); i > 0; i--)
        {
            delLastRow(L);
        }
    }
}

void delFirstColumn(eRow *L){
    if ((*L).col != NULL)
    {
        eColumn *delete = (*L).col;
        if (countElementColumn(*L) == 1)
        {
            (*L).col = NULL;
        }else
        {
            (*L).col = (*L).col->nextCol;
            delete->nextCol = NULL;
        }
        free(delete);
    }
}

void delAfterColumn(eColumn* prev){
    eColumn* delete = prev->nextCol;
    if (delete != NULL)
    {
        if (delete->nextCol == NULL)
        {
            prev->nextCol = NULL;
        }else
        {
            prev->nextCol = delete->nextCol;
            delete->nextCol = NULL;
        }
        free(delete);
    }
}

void delLastColumn(eRow *L){
    if ((*L).col != NULL)
    {
        if (countElementColumn(*L) == 1)
        {
            delFirstColumn(L);
        }else
        {
            eColumn *ptr = (*L).col;
            eColumn *prev;
            while (ptr->nextCol != NULL)
            {
                prev = ptr;
                ptr = ptr->nextCol;
            }
            delAfterColumn(prev);
        }
    }
}

void delAllColumn(eRow *L){
    if (countElementColumn(*L) != 0)
    {
        for (int i = countElementColumn(*L); i > 0; i--)
        {
            delLastColumn(L);
        }
    }
}

void printElement(list L){
    if (L.first != NULL)
    {
        eRow *ptrRow = L.first;
        eColumn *ptrColumn;
        int i = 1;
        while (ptrRow != NULL)
        {
            printf("element ke: %d\n", i);
            printf("nim: %s\n", ptrRow->container.nim);
            printf("nama: %d\n", ptrRow->container.name);
            ptrColumn = ptrRow->col;
            while (ptrColumn != NULL)
            {
                printf("kode kuliah: %s\n", ptrColumn->containerCol.code);
                printf("nilai: %s\n", ptrColumn->containerCol.grade);
                ptrColumn = ptrColumn->nextCol;
            }
            printf("------------\n");
            ptrRow = ptrRow->next;
            i++;
        }
    }else
    {
        printf("list kosong\n");
    }
}