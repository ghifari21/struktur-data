/* Deklarasi Library */
#include "header.h"

/* Prosedur untuk membuat queue kosong */
void createEmpty(queue *Q)
{
    /* NULL kan pointer penunjuk awal dan akhir */
    (*Q).first = -1;
    (*Q).last = -1;
}

/* Fungsi untuk mengecek apakah ada data dalam queue */
int isEmpty(queue Q)
{
    /* Inisialisasi untuk mengecek */
    int cekKosong = 0;

    /* Jika pointer first nya itu NULL */
    if (Q.first == -1)
    {
        /* Maka tidak ada data dalam queue */
        cekKosong = 1;
    }

    /* Kembalikan nilai pengecekan */
    return cekKosong;
}

/* Fungsi untuk mengecek apakah data sudah penuh dalam queue */
int isFull(queue Q)
{
    /* Inisialisasi untuk mengecek */
    int cekPenuh = 0;

    /* Jika pointer lastnya menunjuk ke data akhir maksimal queue */
    if (Q.last == 9)
    {
        /* Maka data sudah penuh dalam queue */
        cekPenuh = 1;
    }

    /* Kembalikan nilai pengecekan */
    return cekPenuh;
}

/* Prosedur untuk memasukan data ke dalam queue */
void addQueue(char nim[], char nama[], float nilai, queue *Q)
{
    if (isEmpty(*Q) == 1)
    {
        /* Jika queue kosong */

        /* NULL kan pointer penunjuk awal dan akhir */
        (*Q).first = 0;
        (*Q).last = 0;

        /* Pindahkan data input ke dalam queue */
        strcpy((*Q).data[0].nim, nim);
        strcpy((*Q).data[0].nama, nama);
        (*Q).data[0].nilai = nilai;
    }
    else
    {
        /* Jika queue tidak kosong */
        if (isFull(*Q) != 1)
        {
            /* majukan pointer last */
            (*Q).last = (*Q).last + 1;

            /* Pindahkan data input ke dalam queue */
            strcpy((*Q).data[(*Q).last].nim, nim);
            strcpy((*Q).data[(*Q).last].nama, nama);
            (*Q).data[(*Q).last].nilai = nilai;
        }
        else
        {
            /* Maka queue itu penuh */
            printf("Queue Penuh\n");
        }
    }
}

/* Prosedur untuk menghapus data dalam queue */
void delQueue(queue *Q)
{
    /* Jika pointer last menunjuk data queue kosong */
    if ((*Q).last == 0)
    {
        /* NULL kan pointer penunjuk awal dan akhir */
        (*Q).first = -1;
        (*Q).last = -1;
    }
    else
    {
        /* Menggeser elemen ke depan */
        int i;
        for (i = ((*Q).first + 1); i <= ((*Q).last); i++)
        {
            /* Pindahkan data kedepan dalam queue */
            strcpy((*Q).data[i - 1].nim, (*Q).data[i].nim);
            strcpy((*Q).data[i - 1].nama, (*Q).data[i].nama);
            (*Q).data[i - 1].nilai = (*Q).data[i].nilai;
        }

        /* Majukan pointer last */
        (*Q).last = (*Q).last - 1;
    }
}

/* Prosedur untuk memasukan data prioritas ke dalam queue */
void addQueuePrioritas(int idx, char nim[], char nama[], float nilai, queue *Q)
{
    if (isEmpty(*Q) == 1)
    {
        /* Jika queue kosong */

        /* NULL kan pointer penunjuk awal dan akhir */
        (*Q).first = 0;
        (*Q).last = 0;

        /* Pindahkan data prioritas ke dalam queue */
        strcpy((*Q).data[0].nim, nim);
        strcpy((*Q).data[0].nama, nama);
        (*Q).data[0].nilai = nilai;
    }
    else if ((isEmpty(*Q) != 1) && (isFull(*Q) != 1))
    {
        if (idx > (*Q).last)
        {
            /* Jika index tempat prioritas lebih besar dari tempat terakhir queue */

            /*Increment pointer last */
            (*Q).last += 1;

            /* Masukan data prioritas ke last queue */
            strcpy((*Q).data[(*Q).last].nim, nim);
            strcpy((*Q).data[(*Q).last].nama, nama);
            (*Q).data[(*Q).last].nilai = nilai;
        }
        else if ((idx <= (*Q).last))
        {
            /* Jika index tempat prioritas lebih kecil sama dengan dari tempat terakhir queue */

            /*Increment pointer last */
            (*Q).last += 1;

            /* Menggeser elemen mundur */
            int i;
            for (i = ((*Q).last - 1); i >= idx; i--)
            {
                if (i != idx) /* Jika iterator belum mendapatkan tempat sesuai prioritas */
                {
                    /* Mundurkan data dalam queue */
                    strcpy((*Q).data[i + 1].nim, (*Q).data[i].nim);
                    strcpy((*Q).data[i + 1].nama, (*Q).data[i].nama);
                    (*Q).data[i + 1].nilai = (*Q).data[i].nilai;
                }
                else /* Jika sudah menemukan tempat untuk prioritas */
                {
                    /* Mundurkan data dalam queue */
                    strcpy((*Q).data[i + 1].nim, (*Q).data[i].nim);
                    strcpy((*Q).data[i + 1].nama, (*Q).data[i].nama);
                    (*Q).data[i + 1].nilai = (*Q).data[i].nilai;

                    /* Masukan data prioritas ke queue */
                    strcpy((*Q).data[i].nim, nim);
                    strcpy((*Q).data[i].nama, nama);
                    (*Q).data[i].nilai = nilai;
                }
            }
        }
    }
    else if (isFull(*Q) == 1)
    {
        /* Maka queue itu penuh */
        printf("Queue Penuh\n");
    }
}

/* Prosedur untuk menampilkan data dalam queue */
void printQueue(queue Q)
{
    /* jika pointer first bukan NULL */
    if (Q.first != -1)
    {
        /* iterator */
        int i;

        /* lakukan perulangan sebanyak data dalam queue */
        for (i = Q.last; i >= Q.first; i--)
        {
            /* Print hasilnya */
            printf("\n");
            printf("Elemen  : %d\n", i);
            printf("NIM     : %s\n", Q.data[i].nim);
            printf("Nama    : %s\n", Q.data[i].nama);
            printf("Nilai   : %f\n", Q.data[i].nilai);
        }
        printf("=============================\n");
    }
    else
    {
        /* Maka queue itu kosong */
        printf("Queue Kosong\n");
    }
}