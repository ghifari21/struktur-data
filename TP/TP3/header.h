/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TP3           |
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
    int year;
    char bandName[50];
    char title[50];
}recordSong;    // data element

typedef struct elmt *elmtAddress;
typedef struct elmt
{
    recordSong container;
    elmtAddress next;
}element;

typedef struct
{
    element* top;
}stack;

// fungsi dan prosedur yang dipakai
void createEmpty(stack *S); // membuat stack kosong
int isEmpty(stack S);   // memeriksa apakah stack kosong
int countElement(stack S);  // menghitung isi element stack
void push(int year, char title[], char bandName[], stack *S);   // memasukan element ke dalam stack
void musicFilter(stack *Stotal, stack *Spop, stack *Srock); // filter isi stack
void printStack(stack S);   // output