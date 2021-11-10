/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TM7           |
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
    char rating[50];
}GOTY;

typedef struct elmt *elmtAddress;
typedef struct elmt
{
    GOTY container;
    elmtAddress next;
}element;

typedef struct
{
    element *first;
    element *last;
}queue;

// fungsi dan prosedur yang dipakai
void createEmpty(queue *Q); // membuat queue
int isEmpty(queue Q);   // memeriksa apakah queue kosong?
int countElement(queue Q);  // menghitung banyak element queue
void add(char name[], char rating[], queue *Q); // add
void addPriority(char name[], char rating[], int priority, queue *Q);   // priority add
void del(queue *Q); // delete
void move(queue *Q1, queue *Q2);    // move from queue 1 to queue 2
void printQueue(queue Q);   // output