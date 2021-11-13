/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan Kuis          |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

// tipe data terstruktur yang dipakai
typedef struct
{
    char name[50];
    int priority;
    char city[50];
    int bansosNeeded;
}bansosRecord;

typedef struct elmt *elmtAddress;
typedef struct elmt
{
    bansosRecord container;
    elmtAddress next;
}element;

typedef struct
{
    element *first;
    element *last;
}queue;

// prosedur dan fungsi yang dipakai
void createEmpty(queue *Q); // membuat queue
int isEmpty(queue Q);   // memeriksa apakah queue kosong?
int countElement(queue Q);  // menghitung banyaknya element dalam queue
void addPriority(char name[], int priority, char city[], int bansosNeeded, queue *Q);   // menambahkan element berprioritas
void del(queue *Q); // hapus element
void printQueue(queue *Q, int count);   // output