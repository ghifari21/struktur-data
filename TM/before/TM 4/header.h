/*  (LGD121) List Ganda Dinamis C1 (Header)

    Saya Hilman Fauzi Herdiana (2000879) mengerjakan Tes Mesin 4 dalam 
    mata kuliah Stuktur Data untuk keberkahanNya maka saya tidak
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//bungkusan
typedef struct
{
    char nama[100];
    char matkul[50];
    char nilai[5];
}dataMahasiswa;

typedef struct elmt* alamatelmt;
typedef struct elmt
{
    dataMahasiswa kontainer;
    alamatelmt prev;
    alamatelmt next;
}elemen;

typedef struct
{
    elemen *first;
    elemen *tail;
}list;

//prosedur membuat list
void createList(list *L);
//fungsi menghitung elemen
int countElement(list L);
//prosedur add first
void addFirst(char nama[], char matkul[], char nilai[], list *L);
//prosedur add after
void addAfter(elemen* before, char nama[], char matkul[], char nilai[], list *L);
//prosedur add last
void addLast(char nama[], char matkul[], char nilai[], list *L);
//prosedur add before
void addBefore(elemen* before, char nama[], char matkul[], char nilai[], list *L);
//prosedur del first
void delFirst(list *L);
//prosedur del after
void delAfter(elemen* before, list *L);
//prosedur del last
void delLast(list *L);
//prosedur print element
void printElement(list L);
//prosedur print reverse
void printReverse(list L);
//prosedur del all
void delAll(list *L);