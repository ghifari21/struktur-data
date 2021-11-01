/*  (LGS221) List Ganda Statis C1 (Header)

    Saya Hilman Fauzi Herdiana (2000879) mengerjakan Tugas Mesin 3 dalam 
    mata kuliah Stuktur Data untuk keberkahanNya maka saya tidak
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include <string.h>

typedef struct
{
    char merk[50];
    char tipe[50];
    char jumlah[5];
}dataHp;

typedef struct
{
    dataHp kontainer;
    int prev;
    int next;
}elemen;

typedef struct
{
    int first;
    int tail;
    elemen data[10];
}list;

//prosedur membuat list
void createList(list *L);
//fungsi menghitung elemen
int countElement(list L);
//fungsi empty elemen
int emptyElement(list L);
//prosedur add first
void addFirst(char merk[], char tipe[], char jumlah[], list *L);
//prosedur add after
void addAfter(int before, char merk[], char tipe[], char jumlah[], list *L);
//prosedur add last
void addLast(char merk[], char tipe[], char jumlah[], list *L);
//prosedur del first
void delFirst(list *L);
//prosedur del after
void delAfter(int before, list *L);
//prosedur del last
void delLast(list *L);
//prosedur print element
void printElement(list L);
//prosedur print element terbalik
void printReverse(list L);
//prosedur del all
void delAll(list *L);