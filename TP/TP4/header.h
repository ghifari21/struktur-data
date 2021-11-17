/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TP4           |
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
    char membership[50];
    int time;
}memberRecord;

typedef struct elmt *elmtAddress;
typedef struct elmt
{
    memberRecord container;
    elmtAddress next;
}element;

typedef struct
{
    element *first;
    element *last;
}queue;

// prosedur dan fungsi yang dipakai
void createEmpty(queue *Q); // membuat queue
int isEmpty(queue Q);   // memeriksa apakah queue kosong
int countElement(queue Q);  // menghitung banyak element dalam queue
void addNonMembership(char name[], char membership[], int time, queue *Q);  // add untuk non-member
void addMembership(char name[], char membership[], int time, queue *Q); // add untuk member
void processingQueue(queue *Q); // memproses queue
void del(queue *Q); // delete
void printQueue(queue Q);   // output