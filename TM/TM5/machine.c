/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TM5           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void createList(list *L){
    (*L).first = NULL;
}

int countElementRow(list L){
    int result = 0;
    if (L.first != NULL)
    {   // jika list baris tidak kosong
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
    {   // jika list kolom tidak kosong
        eColumn* ptr = L.col;
        while (ptr != NULL)
        {
            result++;
            ptr = ptr->nextCol;
        }
    }
    return result;
}

void addFirstRow(char name[], int since, list *L){
    eRow* new = (eRow*) malloc (sizeof (eRow));
    strcpy(new->container.name, name);
    new->container.since = since;
    
    new->col = NULL;
    if ((*L).first == NULL)
    {   // jika list baris kosong
        new->next = NULL;
    }else
    {   // jika list baris tidak kosong
        new->next = (*L).first;
    }
    (*L).first = new;
    new = NULL;
}

void addAfterRow(eRow *prev, char name[], int since){
    eRow* new = (eRow*) malloc (sizeof (eRow));
    strcpy(new->container.name, name);
    new->container.since = since;

    new->col = NULL;
    if (prev->next == NULL)
    {   // jika prev adalah element baris terakhir
        new->next = NULL;
    }else
    {   // jika bukan element baris terakhir
        new->next = prev->next;
    }
    prev->next = new;
    new = NULL;
}

void addLastRow(char name[], int since, list *L){
    if ((*L).first == NULL)
    {   // jika list baris kosong
        addFirstRow(name, since, L);
    }else
    {   // jika list baris tidak kosong
        eRow *last = (*L).first;
        // cari element terakhir dari list baris
        while (last->next != NULL)
        {
            last = last->next;
        }
        addAfterRow(last, name, since);
    }
}

void addFirstColumn(char name[], eRow *L){
    eColumn* new = (eColumn*) malloc (sizeof (eColumn));
    strcpy(new->containerCol.name, name);

    if ((*L).col == NULL)
    {   // jika list kolom kosong
        new->nextCol = NULL;
    }else
    {   // jika tidak kosong
        new->nextCol = (*L).col;
    }
    (*L).col = new;
    new = NULL;
}

void addAfterColumn(eColumn *prev, char name[]){
    eColumn* new = (eColumn*) malloc (sizeof (eColumn));
    strcpy(new->containerCol.name, name);

    if (prev->nextCol == NULL)
    {   // jika prev adalah kolom terakhir
        new->nextCol = NULL;
    }else
    {   // jika bukan kolom terakhir
        new->nextCol = prev->nextCol;
    }
    prev->nextCol = new;
    new = NULL;
}

void addLastColumn(char name[], eRow *L){
    if ((*L).col == NULL)
    {   // jika list kolom kosong
        addFirstColumn(name, L);
    }else
    {   // jika tidak kosong
        eColumn *last = (*L).col;
        // mencari kolom terakhir
        while (last->nextCol != NULL)
        {
            last = last->nextCol;
        }
        addAfterColumn(last, name);
    }
}

void delFirstRow(list *L){
    if ((*L).first != NULL)
    {   // jika list baris tidak kosong
        eRow *delete = (*L).first;
        if (delete->col != NULL)
        {   // jika kolomnya ber isi
            delAllColumn(delete); // hapus dulu semuanya
        }
        if (countElementRow(*L) == 1)
        {   // jika hanya berisi 1 baris
            (*L).first = NULL;
        }else
        {   // jika ada banyak
            (*L).first = (*L).first->next;
        }
        delete->next = NULL;
        free(delete);
    }else
    {   //jika list baris kosong
        printf("list kosong\n");
    }
}

void delAfterRow(eRow *prev){
    if (prev != NULL)
    {   // jika prev tidak kosong
        eRow *delete = prev->next;
        if (delete != NULL)
        {   // jika delete tidak kosong
            if (delete->col != NULL)
            {   // jika kolomnya berisi
                delAllColumn(delete); // hapus dulu semuanya
            }
            if (delete->next == NULL)
            {   // jika delete adalah baris terakhir
                prev->next = NULL;
            }else
            {   // jika bukan baris terakhir
                prev->next = delete->next;
            }
            delete->next = NULL;
            free(delete);
        }
    }
}

void delLastRow(list *L){
    if ((*L).first != NULL)
    {   // jika list baris tidak kosong
        if (countElementRow(*L) == 1)
        {   // jika hanya ada satu baris
            delFirstRow(L);
        }else
        {   // jika ada banyak baris
            eRow *ptr = (*L).first;
            eRow *prev;
            // cari baris terakhir
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
    {   // jika list baris tidak kosong
        for (int i = countElementRow(*L); i > 0; i--)
        {
            delLastRow(L);
        }
    }
}

void delFirstColumn(eRow *L){
    if ((*L).col != NULL)
    {   // jika kolom tidak kosong
        eColumn *delete = (*L).col;
        if (countElementColumn(*L) == 1)
        {   // jika kolom hanya 1
            (*L).col = NULL;
        }else
        {   // jika ada banyak kolom
            (*L).col = (*L).col->nextCol;
            delete->nextCol = NULL;
        }
        free(delete);
    }
}

void delAfterColumn(eColumn* prev){
    eColumn* delete = prev->nextCol;
    if (delete != NULL)
    {   // jika delete tidak kosong
        if (delete->nextCol == NULL)
        {   // jika delete adalah kolom terakhir
            prev->nextCol = NULL;
        }else
        {   // jika bukan
            prev->nextCol = delete->nextCol;
            delete->nextCol = NULL;
        }
        free(delete);
    }
}

void delLastColumn(eRow *L){
    if ((*L).col != NULL)
    {   // jika kolom tidak kosong
        if (countElementColumn(*L) == 1)
        {   // jika hanya ada 1 kolom
            delFirstColumn(L);
        }else
        {   // jika ada banyak kolom
            eColumn *ptr = (*L).col;
            eColumn *prev;
            // cari kolom terakhir
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
    {   // jika kolom tidak kosong
        for (int i = countElementColumn(*L); i > 0; i--)
        {
            delLastColumn(L);
        }
    }
}

eRow* findRow(list L, char name[]){
    if (L.first != NULL)
    {   // jika list baris tidak kosong
        eRow* ptr = L.first;
        // mencari pointer dari element yang dimaksud
        while (ptr != NULL && strcmp(ptr->container.name, name) != 0)
        {
            ptr = ptr->next;
        }
        return ptr;
    }
}

void printElement(list L){
    if (L.first != NULL)
    {   // jika list tidak kosong
        eRow* ptrRow = L.first;
        eColumn* ptrCol;
        while (ptrRow != NULL)
        {   // looping baris
            printf("%s %d\n", ptrRow->container.name, ptrRow->container.since);
            ptrCol = ptrRow->col;   // inisialisasi kolom
            while (ptrCol != NULL)
            {   // looping kolom
                printf("- %s\n", ptrCol->containerCol.name);
                ptrCol = ptrCol->nextCol;   // iterator kolom
            }
            printf("==================\n");
            ptrRow = ptrRow->next;  // iterator baris
        }
    }else
    {   // jika list kosong
        printf("list kosong\n");
    }
}