/* List of List */

#include <stdio.h> 
#include <malloc.h> 
#include <string.h>

typedef struct{
    char nim[10];
    char nama[50]; 
}mahasiswa;

typedef struct{
    char code[10]; 
    char nilai[2];
}matkul;

typedef struct eclmn *columnAddress;
typedef struct eclmn{
    matkul containerCol;
    columnAddress nextCol;
}eColumn;

typedef struct erw *rowAddress;
typedef struct erw{
    mahasiswa container;
    eColumn *col;
    rowAddress next;
}eRow;

typedef struct
{
    eRow *first;
}list;

// prosedur membuat list
void createList(list *L)
{
    (*L).first = NULL;
}

// fungsi menghitung elemen Row
int countElementB(list L)
{
    int result = 0; // inisialisasi
    if (L.first != NULL) // jika list tidak kosong 
    {
        //inisialisasi
        eRow* ptr;
        ptr = L.first;
        while (ptr != NULL) // selama ptr tidak kosong
        {
            //iterasi
            result = result + 1;
            ptr = ptr->next;
        }
    }
    return result;
}

// fungsi menghitung elemen colom
int countElementK(eRow L)
{
    int result = 0; // inisialisasi
    if (L.col!= NULL) // jika list tidak kosong 
    {
        //inisialisasi
        eColumn* ptr;
        ptr = L.col;
        while (ptr != NULL) // selama ptr tidak kosong
        {
            //iterasi
            result = result + 1;
            ptr = ptr->nextCol;
        }
    }
    return result;
}

// prosedur add first Row
void addFirstB(char nim[], char nama[], list *L)
{
    eRow* new = (eRow *) malloc (sizeof (eRow));

    // memindahkan data
    strcpy(new->container.nim, nim);
    strcpy(new->container.nama, nama);
    new->col = NULL;

    if ((*L).first == NULL) // jika (*L).first kosong
    {
        new->next = NULL; // new->next menjadi kosong
    }
    else // jika tidak kosong
    {
        new->next = (*L).first; // new->next menjadi ke (*L).first
    }
    (*L).first = new; // (*L).first menjadi new
    new = NULL; // new menjadi kosong
}

// prosedur add first colom
void addFirstK(char code[], char nilai[], eRow *L)
{
    eColumn* new = (eColumn *) malloc (sizeof (eColumn));

    // memindahkan data
    strcpy(new->containerCol.code, code);
    strcpy(new->containerCol.nilai, nilai);

    if ((*L).col == NULL) // jika (*L).col kosong
    {
        new->nextCol = NULL; // new->nextCol menjadi kosong
    }
    else // jika tidak kosong
    {
        new->nextCol = (*L).col; // new->nextCol menjadi ke (*L).col
    }
    (*L).col = new; // (*L).col menjadi new
    new = NULL; // new menjadi kosong
}

//prosedur add after Row
void addAfterB(eRow* prev, char nim[], char nama[])
{
    eRow* new = (eRow *) malloc (sizeof(eRow));

    // memindahkan data
    strcpy(new->container.nim, nim);
    strcpy(new->container.nama, nama);
    new->col = NULL;

    if (prev->next == NULL) // jika before->next itu kosong
    {
        new->next = NULL; // new->next menjadi kosong
    } 
    else // jika kosong
    {
        new->next = prev->next;
    }
    prev->next = new;
    new = NULL; // new jadi kosong  
}

//prosedur add after colom
void addAfterK(eColumn* prev, char code[], char nilai[])
{
    eColumn* new = (eColumn *) malloc (sizeof(eColumn));

    // memindahkan data
    strcpy(new->containerCol.code, code);
    strcpy(new->containerCol.nilai, nilai);
    if (prev->nextCol == NULL) // jika before->nextCol kosong
    {
        new->nextCol = NULL; // new->nextCol menjadi kosong
    } 
    else // jika kosong
    {
        new->nextCol = prev->nextCol;
    }
    prev->nextCol = new;
    new = NULL; // new jadi kosong  
}

// prosedur add last Row
void addLastB(char nim[], char nama[], list *L)
{
    if ((*L).first == NULL) //jika list kosong
    {
        addFirstB(nim, nama, L);
    } 
    else //jika list tidak kosong
    {
        eRow *last = (*L).first;
        while (last->next != NULL) // mencari elemen terakhir
        {
            last = last->next; // iterasi
        }
        addAfterB(last, nim, nama);
    }
}

// prosedur add last colom
void addLastK(char code[], char nilai[], eRow *L)
{
    if ((*L).col == NULL) //jika list kosong
    {
        addFirstK(code, nilai, L);
    } 
    else //jika list tidak kosong
    {
        eColumn *last = (*L).col;
        while (last->nextCol != NULL) // mencari elemen terakhir
        {
            last = last->nextCol; // iterasi
        }
        addAfterK(last, code, nilai);
    }
}

// prosedur del first colom
void delFirstK(eRow *L)
{
    if ((*L).col != NULL) // jika list tidak kosong
    {
        eColumn* delete = (*L).col;
        if (countElementK(*L) == 1)
        {
            (*L).col = NULL;
        }
        else
        {
            (*L).col = (*L).col->nextCol;
            delete = delete->nextCol = NULL;
        }
        free(delete);
    }
}

// prosedur del after colom
void delAfterK(eColumn* prev)
{
    eColumn* delete = prev->nextCol;
    if (delete != NULL) // jika list tidak kosong
    {
        if (delete->nextCol == NULL)
        {
            prev->nextCol = NULL;
        }
        else 
        {
            prev->nextCol = delete->nextCol;
            delete->nextCol = NULL;
        }
        free(delete);
    }
}

// prosedur del last colom
void delLastK(eRow *L)
{
    if ((*L).col != NULL) // jika list tidak kosong
    {
        if (countElementK(*L) == 1) // jika isi list 1 elemen
        {
            delFirstK(L);
        }
        else // mecari element terakhir list
        {
            eColumn *last = (*L).col;
            eColumn *beforeLast;

            while (last->nextCol != NULL)
            {
                beforeLast = last;
                last = last->nextCol;
            }
            delAfterK(beforeLast);
        }
    }
}

// proesdur mengdelete semua data di list colom
void delALllK(eRow *L)
{
    if (countElementK(*L) != 0) // jika banyak elemen tidak 0
    {
        int i;
        // looping sebanyak i lebih dari atau sama dengan 1
        for (i = countElementK(*L); i >= 1; i--)
        {
            delLastK(L);
        }
    }
}

// prosedur del first Row
void delFirstB(list *L)
{
    if ((*L).first != NULL) // jika list tidak kosong
    {
        eRow* delete = (*L).first;
        if (delete->col != NULL)
        {
            // mengdelete semua elemen colom jika ada
            delALllK(delete);
        }
        if (countElementB(*L) == 1)
        {
            (*L).first = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
        }
        delete->next = NULL;
        free(delete);
    }
    else // jika list kosong
    {
        printf("list kosong\n");
    }
    
}

// prosedur del after Row
void delAfterB(eRow* prev)
{
    if (prev != NULL)
    {
        eRow* delete = prev->next;
        if (delete != NULL) // jika list tidak kosong
        {
            if (delete->col != NULL)
            {
                // mengdelete semua elemen colom jika ada
                delALllK(delete);
            }
            if (delete->next == NULL)
            {
                prev->next = NULL;
            }
            else 
            {
                prev->next = delete->next;
            }
            delete->next = NULL;
            free(delete);
        }
    }
}

// prosedur del last Row
void delLastB(list *L)
{
    if ((*L).first != NULL) // jika list tidak kosong
    {
        if (countElementB(*L) == 1) // jika isi list 1 elemen
        {
            delFirstB(L);
        }
        else // mecari element terakhir list
        {
            eRow *last = (*L).first;
            eRow *beforeLast;

            while (last->next != NULL)
            {
                beforeLast = last;
                last = last->next;
            }
            delAfterB(beforeLast);
        }
    }
}

// proesdur mengdelete semua data di list Row
void delAllB(list *L)
{
    if (countElementB(*L) != 0) // jika banyak elemen tidak 0
    {
        int i;
        // looping sebanyak i lebih dari atau sama dengan 1
        for (i = countElementB(*L); i >= 1; i--)
        {
            delLastB(L);
        }
    }
}

// prosedur menampilkan output list
void printElement(list L)
{
    if (L.first != NULL) // jika list tidak kosong
    {
        // inisialisasi
        eRow* ptr = L.first;
        int i = 1;
        while (ptr != NULL)
        {
            // proses
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", ptr->container.nim);
            printf("nama : %s\n", ptr->container.nama);

            eColumn* eCol = ptr->col;
            while (eCol != NULL)
            {
                printf("code kuliah : %s\n", eCol->containerCol.code);
                printf("nilai : %s\n", eCol->containerCol.nilai);
                eCol = eCol->nextCol;
            }
            printf("------------\n");
            ptr = ptr->next;
        }
    }
    else // jika list kosong
    {
        printf("list kosong\n");
    }
}

int main()
{
    list L;
    createList(&L);
    printElement(L);

    printf("================\n");
    addFirstB("1", "Orang_1", &L);
    addFirstK("IF40K1", "A", L.first);
    addAfterK(L.first->col, "IF40Z1", "A");
    addLastK("IF40Z2", "A", L.first);
    addAfterB(L.first, "2", "Orang_2");
    addFirstK("TI5141", "A", L.first->next);
    addLastK("IF5021", "A", L.first->next);
    addLastB("3", "Orang", &L);
    addFirstK("IF5321", "A", L.first->next->next);
    printElement(L);

    printf("================\n");
    delAllB(&L);
    printElement(L);
    printf("================\n");

    return 0;
}