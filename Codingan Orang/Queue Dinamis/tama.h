/* Deklarasi Library */
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[50];
    float nilai;
} nilaiMatkul; /* Nama struct */

/* Deklarasi pointer tipe sembarang untuk nama awal (elmt)
sehingga elemenkolom bisa dipanggil sebagai pointer next */
typedef struct elm *alamatelmt;

typedef struct elm
{
    nilaiMatkul kontainer; /* Variabel untuk menampung data dari struct matkul */
    alamatelmt next;       /* pointer next queue */
} elemen;

typedef struct
{
    elemen *first; /* pointer menunjuk data pertama queue */
    elemen *last;  /* pointer menunjuk data akhir queue */
} queue;

/* Prosedur dan fungsi Queue */
void createEmpty(queue *Q);                                                      /* Prosedur untuk membuat queue kosong */
int isEmpty(queue Q);                                                            /* Fungsi untuk mengecek apakah ada data dalam queue */
int countElement(queue Q);                                                       /* Fungsi untuk mengecek jumlah data dalam queue */
void addQueue(char nim[], char nama[], float nilai, queue *Q);                   /* Prosedur untuk memasukan data ke dalam queue */
void addQueuePrioritas(int idx, char nim[], char nama[], float nilai, queue *Q); /* Prosedur untuk memasukan data prioritas ke dalam queue */
void delQueue(queue *Q);                                                         /* Prosedur untuk menghapus data dalam queue */
void printQueue(queue Q);                                                        /* Prosedur untuk menampilkan data dalam queue */