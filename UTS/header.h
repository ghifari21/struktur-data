/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan UTS (lolpkk21)|
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

// tipe data terstruktur yang dipakai
typedef struct
{
    char name[100];
}restaurant;    // nama restoran untuk data row

typedef struct
{
    char name[100];
    int price;
}resMenu;   // nama menu dan harga untuk data column

typedef struct eclmn *columnAddress;
typedef struct eclmn
{
    resMenu containerCol;
    columnAddress nextCol;
}eColumn;

typedef struct erw *rowAddress;
typedef struct erw
{
    restaurant container;
    eColumn *col;
    rowAddress next;
}eRow;

typedef struct
{
    eRow *first;
}list;

typedef struct
{
    char originResto[100];
    char menuName[100];
    char targetResto[100];
}swappingTarget;    // menampung data pemindahan data

// fungsi dan prosedur yang dipakai
void createList(list *L);   // membuat list
eRow* searchRow(list L);    // mencari row terakhir
void moveElementToTarget(char origin[], char menuName[], char target[], list *L); //memindahkan data column
// menghitung banyak element
int countElementRow(list L);
int countElementColumn(eRow L);
// menambahkan element row
void addFirstRow(char name[], list *L);
void addAfterRow(eRow *prev, char name[]);
void addLastRow(char name[], list *L);
// menambahkan element column
void addFirstColumn(char name[], int price, eRow *L);
void addAfterColumn(eColumn *prev, char name[], int price);
void addLastColumn(char name[], int price, eRow *L);
// output
void printElement(list L);