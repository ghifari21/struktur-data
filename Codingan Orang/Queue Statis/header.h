/* Deklarasi Library */
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[50];
    float nilai;
} nilaiMatkul; /* Nama struct */

typedef struct queue
{
    int first;            /* pointer menunjuk data pertama queue */
    int last;             /* pointer menunjuk data akhir queue */
    nilaiMatkul data[10]; /* variabel struct untuk menampung max banyak data */
} queue;

/* Prosedur dan fungsi Queue */
void createEmpty(queue *Q);                                                      /* Prosedur untuk membuat queue kosong */
int isEmpty(queue Q);                                                            /* Fungsi untuk mengecek apakah ada data dalam queue */
int isFull(queue Q);                                                             /* Fungsi untuk mengecek apakah data sudah penuh dalam queue */
void addQueue(char nim[], char nama[], float nilai, queue *Q);                   /* Prosedur untuk memasukan data ke dalam queue */
void addQueuePrioritas(int idx, char nim[], char nama[], float nilai, queue *Q); /* Prosedur untuk memasukan data prioritas ke dalam queue */
void delQueue(queue *Q);                                                         /* Prosedur untuk menghapus data dalam queue */
void printQueue(queue Q);                                                        /* Prosedur untuk menampilkan data dalam queue */