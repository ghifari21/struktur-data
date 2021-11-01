/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TM5           |
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
    char name[50];
    int since;
}FC; // data baris

typedef struct
{
    char name[50];
}player; // data kolom

typedef struct eclmn *columnAddress;
typedef struct eclmn
{
    player containerCol;
    columnAddress nextCol;
}eColumn;

typedef struct erw *rowAddress;
typedef struct erw
{
    FC container;
    eColumn *col;
    rowAddress next;
}eRow;

typedef struct
{
    eRow *first;
}list;

// prosedur dan fungsi yang dipakai
void createList(list *L);   // inisialisasi list
int countElementRow(list L); // hitung element baris
int countElementColumn(eRow L); // hitung element kolom
eRow* findRow(list L, char name[]); // mencari element baris
// menambahkan data pada baris
void addFirstRow(char name[], int since, list *L);
void addAfterRow(eRow *prev, char name[], int since);
void addLastRow(char name[], int since, list *L);
// menambahkan data pada kolom
void addFirstColumn(char name[], eRow *L);
void addAfterColumn(eColumn *prev, char name[]);
void addLastColumn(char name[], eRow *L);
// menghapus data pada kolom
void delFirstColumn(eRow *L);
void delAfterColumn(eColumn* prev);
void delLastColumn(eRow *L);
void delAllColumn(eRow *L);
// menghapus data pada baris
void delFirstRow(list *L);
void delAfterRow(eRow *prev);
void delLastRow(list *L);
void delAllRow(list *L);
// output
void printElement(list L);