/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TM6 Statis    |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include <stdio.h>
#include <string.h>

// tipe data terstruktur yang dipakai
typedef struct
{
    char name[50];
    int price;
}recordMenu;    // isi element

typedef struct
{
    int top;
    recordMenu data[10];
}stack;

// prosedur dan fungsi yang dipakai
void createEmpty(stack *S); // membuat stack
int isEmpty(stack S);   // apakah stack kosong?
int isFull(stack S);    // apakah stack penuh?
void push(char name[], int price, stack *S);    // memasukan element ke stack
void pop(stack *S); // mengeluarkan element dari stack
void popToAnotherStack(stack *S1, stack *S2);   // mengeluarkan element dari stack 1 dan memasukannya ke stack 2
void printStack(stack S);   // output