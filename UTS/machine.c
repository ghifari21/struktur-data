/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan UTS (lolpkk21)|
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void createList(list *L){   // membuat list
    (*L).first = NULL;
}

eRow* searchRow(list L){    // mencari row terakhir
    eRow* last = L.first;
    while (last->next != NULL)
    {   // looping untuk mencari row terakhir
        last = last->next;
    }
    return last;
}

int countElementRow(list L){    // menghitung element row
    int result = 0;
    if (L.first != NULL)
    {   // jika list tidak kosong
        eRow* ptr = L.first;
        while (ptr != NULL)
        {
            result++;
            ptr = ptr->next;
        }
    }
    return result;
}

int countElementColumn(eRow L){ // menghitung element column
    int result = 0;
    if (L.col != NULL)
    {   // jika list tidak kosong
        eColumn* ptr = L.col;
        while (ptr != NULL)
        {
            result++;
            ptr = ptr->nextCol;
        }
    }
    return result;
}

void addFirstRow(char name[], list *L){ // menambahkan data pertama row
    eRow* new = (eRow*) malloc (sizeof (eRow));
    strcpy(new->container.name, name);
    
    new->col = NULL;
    if ((*L).first == NULL)
    {   // jika list kosong
        new->next = NULL;
    }else
    {   // jika list tidak kosong
        new->next = (*L).first;
    }
    (*L).first = new;
    new = NULL;
}

void addAfterRow(eRow *prev, char name[]){  // menambahkan data setelah row tertentu
    eRow* new = (eRow*) malloc (sizeof (eRow));
    strcpy(new->container.name, name);

    new->col = NULL;
    if (prev->next == NULL)
    {   // jika prev adalah element baris terakhir
        new->next = NULL;
    }else
    {   // jika prev bukan element baris terakhir
        new->next = prev->next;
    }
    prev->next = new;
    new = NULL;
}

void addLastRow(char name[], list *L){  // menambahkan data sebagai row terakhir
    if ((*L).first == NULL)
    {   // jika list kosong
        addFirstRow(name, L);
    }else
    {   // jika list tidak kosong
        eRow *last = (*L).first;
        while (last->next != NULL)
        {   // mencari row terakhir
            last = last->next;
        }
        addAfterRow(last, name);
    }
}

void addFirstColumn(char name[], int price, eRow *L){   // menambahkan data column pertama
    eColumn* new = (eColumn*) malloc (sizeof (eColumn));
    strcpy(new->containerCol.name, name);
    new->containerCol.price = price;

    if ((*L).col == NULL)
    {   // jika list kosong
        new->nextCol = NULL;
    }else
    {   // jika list tidak kosong
        new->nextCol = (*L).col;
    }
    (*L).col = new;
    new = NULL;
}

void addAfterColumn(eColumn *prev, char name[], int price){ // menambahkan data setelah column tertentu
    eColumn* new = (eColumn*) malloc (sizeof (eColumn));
    strcpy(new->containerCol.name, name);
    new->containerCol.price = price;

    if (prev->nextCol == NULL)
    {   // jika prev adalah column terakhir
        new->nextCol = NULL;
    }else
    {   // jika bukan column terakhir
        new->nextCol = prev->nextCol;
    }
    prev->nextCol = new;
    new = NULL;
}

void addLastColumn(char name[], int price, eRow *L){    // menambahkan data sebagai column terakhir
    if ((*L).col == NULL)
    {   // jika list kosong
        addFirstColumn(name, price, L);
    }else
    {   // jika list tidak kosong
        eColumn *last = (*L).col;
        while (last->nextCol != NULL)
        {   // cari column terakhir
            last = last->nextCol;
        }
        addAfterColumn(last, name, price);
    }
}

void moveElementToTarget(char origin[], char menuName[], char target[], list *L){   // memindahkan element
    // mencari pointer origin
    eRow* ptr = (*L).first;
    while (ptr != NULL && strcmp(ptr->container.name, origin) != 0)
    {
        ptr = ptr->next;
    }
    eRow* ptrOrigin = ptr;
    // mencari pointer target
    ptr = (*L).first;
    while (ptr != NULL && strcmp(ptr->container.name, target) != 0)
    {
        ptr = ptr->next;
    }
    eRow* ptrTarget = ptr;

    // mencari pointer column menu yang ingin dipindahkan pada column origin
    eColumn* colOrigin = ptrOrigin->col;
    eColumn* colOriginPrev = NULL;
    while (colOrigin != NULL && strcmp(colOrigin->containerCol.name, menuName) != 0)
    {
        colOriginPrev = colOrigin;
        colOrigin = colOrigin->nextCol;
    }
    // mencari column terakhir target
    eColumn* lastColTarget = ptrTarget->col;
    while (lastColTarget->nextCol != NULL)
    {
        lastColTarget = lastColTarget->nextCol;
    }

    // jika column origin adalah column pertama
    if (colOriginPrev == NULL)
    {
        // next dari column target menjadi ptrOrigin->col
        lastColTarget->nextCol = ptrOrigin->col;
        // ptrOrigin->col menjadi next dari origin  
        ptrOrigin->col = colOrigin->nextCol;
    }else
    {   // jika bukan column pertama
        // next dari column target menjadi next dari prev Origin
        lastColTarget->nextCol = colOriginPrev->nextCol;
        // next dari prev origin menjadi next dari origin
        colOriginPrev->nextCol = colOrigin->nextCol;
    }
    // next origin menjadi null karena origin menjadi element terakhir
    colOrigin->nextCol = NULL;
}

void printElement(list L){  // output
    if (L.first != NULL)
    {   // jika list tidak kosong
        eRow *ptrRow = L.first;
        eColumn *ptrColumn;
        while (ptrRow != NULL)  // looping sampai list habis
        {
            printf("%s:\n", ptrRow->container.name);
            ptrColumn = ptrRow->col;
            while (ptrColumn != NULL)   // looping sampai list habis
            {
                printf("- %s %d\n", ptrColumn->containerCol.name, ptrColumn->containerCol.price);
                ptrColumn = ptrColumn->nextCol; // iterasi
            }
            if (ptrRow->next != NULL)   // jika bukan element terakhir
            {
                printf("\n");
            }
            ptrRow = ptrRow->next;  // iterasi
        }
    }
}