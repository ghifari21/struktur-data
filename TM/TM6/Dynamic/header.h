/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TM6 Dinamis   |
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
    int price;
}recordMenu;    // isi element

typedef struct elmt *elmtAddress;
typedef struct elmt
{
    recordMenu container;
    elmtAddress next;
}element;

typedef struct
{
    element* top;
}stack;

// fungsi dan prosedur yang dipakai
void createEmpty(stack *S); // membuat stack
int isEmpty(stack S);   // apakah stack kosong?
int countElement(stack S);  // menghitung element
void push(char name[], int price, stack *S);    // memasukan element ke stack
void pop(stack *S); // mengeluarkan element dari stack
void popToAnotherStack(stack *S1, stack *S2);   // mengeluarkan element dari stack 1 dan memasukannya ke stack 2
void printStack(stack S);   // output