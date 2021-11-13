/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan Kuis          |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include <stdio.h>
#include <string.h>

//  tipe data terstruktur yang dipakai
typedef struct
{
    char name[50];
    char material[50];
}laundryRecord;

typedef struct
{
    int top;
    laundryRecord data[50];
}stack;

// prosedur dan fungsi yang dipakai
void createEmpty(stack *S); // membuat stack
int isEmpty(stack S);   // memeriksa apakah stack kosong?
int isFull(stack S);    // memeriksa apakah stack penuh?
void push(char name[], char material[], stack *S);  // masukan element kedalam stack
void pop(stack *S); // mengeluarkan element dari stack
void moveStack(stack *S, stack *temp, int countTake, char nameTake[][50]);  // memindahkan element dari suatu stack ke stack yang lain
void printStack(stack S);   // output stack utama
void printTemp(stack S);    // output stack temporary