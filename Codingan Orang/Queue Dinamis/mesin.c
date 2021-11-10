/* Deklarasi Library */
#include "tama.h"

/* Prosedur untuk membuat queue kosong */
void createEmpty(queue *Q)
{
    /* NULL kan pointer penunjuk awal dan akhir */
    (*Q).first = NULL;
    (*Q).last = NULL;
}

/* Fungsi untuk mengecek apakah ada data dalam queue */
int isEmpty(queue Q)
{
    /* Inisialisasi untuk mengecek */
    int cekKosong = 0;

    /* Jika pointer first nya itu NULL */
    if (Q.first == NULL)
    {
        /* Maka tidak ada data dalam queue */
        cekKosong = 1;
    }

    /* Kembalikan nilai pengecekan */
    return cekKosong;
}

/* Fungsi untuk mengecek jumlah data dalam queue */
int countElement(queue Q)
{
    /* Inisialisasi untuk mengecek */
    int cekPenuh = 0;

    /* Jika pointer first nya bukan itu NULL */
    if (Q.first != NULL)
    {
        /* Maka tidak ada data dalam queue */
        elemen *help;

        /* inisialisasi */
        help = Q.first;

        /* lakukan perulangan selama help bukan NULL */
        while (help != NULL)
        {
            /* Proses */
            cekPenuh += 1;

            /* itearsi */
            help = help->next;
        }
    }

    /* Mengembalikan nilai penuh */
    return cekPenuh;
}

/* Prosedur untuk memasukan data ke dalam queue */
void addQueue(char nim[], char nama[], float nilai, queue *Q)
{
    elemen *baru;                            /* Membuat elemen baru */
    baru = (elemen *)malloc(sizeof(elemen)); /* Memerintah memori untuk mengalokasikan 1 elemen dan kemudian diacu oleh pointer baru */

    /* Pindahkan data inputan ke dalam queue */
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.nilai = nilai;

    /* NULL-kan next dari pointer baru */
    baru->next = NULL;

    /* Jika pointer first queue itu NULL */
    if ((*Q).first == NULL)
    {
        /* Maka pointer first queue menunjuk elemen baru */
        (*Q).first = baru;
    }
    else /* Jika tidak */
    {
        /* Pointer next last queue menunjuk elemen baru */
        (*Q).last->next = baru;
    }

    /*Pointer last akan menunjuk elemen baru */
    (*Q).last = baru;

    /* Pointer baru akan NULL */
    baru = NULL;
}

/* Prosedur untuk menghapus data dalam queue */
void delQueue(queue *Q)
{

    if ((*Q).first != NULL)
    {
        /* Jika queue itu tidak kosong */

        elemen *hapus = (*Q).first;

        /* Jika hanya ada satu data dalam queue */
        if (countElement(*Q) == 1)
        {
            /* Maka NULL-kan semua pointer queue*/
            (*Q).first = NULL;
            (*Q).last = NULL;
        }
        else /* Jika lebih dari 1 */
        {
            /* Pointer first akan maju ke elemen data selanjutnya */
            (*Q).first = (*Q).first->next;

            /* next dari pointer hapus akan NULL */
            hapus->next = NULL;
        }

        /* Hapus elemen hapus */
        free(hapus);
    }
}

/* Prosedur untuk memasukan data prioritas ke dalam queue */
void addQueuePrioritas(int idx, char nim[], char nama[], float nilai, queue *Q)
{
    elemen *prioritas;                            /* Membuat elemen prioritas */
    prioritas = (elemen *)malloc(sizeof(elemen)); /* Memerintah memori untuk mengalokasikan 1 elemen dan kemudian diacu oleh pointer prioritas */

    /* Pindahkan data prioritas ke dalam queue */
    strcpy(prioritas->kontainer.nim, nim);
    strcpy(prioritas->kontainer.nama, nama);
    prioritas->kontainer.nilai = nilai;

    /* Deklarasi untuk elemen membantu tunjuk */
    elemen *help = (*Q).first;
    elemen *after = help->next;

    /* Jika queue kosong */
    if (isEmpty(*Q) == 1)
    {
        /* NULL-kan next dari pointer prioritas */
        prioritas->next == NULL;

        /* Maka pointer first queue menunjuk elemen prioritas */
        (*Q).first = prioritas;

        /*Pointer last akan menunjuk elemen prioritas */
        (*Q).last = prioritas;
    }
    else if (isEmpty(*Q) != 1) /* Jika queue tidak kosong */
    {
        /* Jika index prioritas ingin di awal queue */
        if (idx == 1)
        {
            /* next dari elemen prioritas akan menunjuk pointer first */
            prioritas->next = (*Q).first;

            /* pointer first akan mundur ke elemen prioritas */
            (*Q).first = prioritas;
        }
        else if ((idx > countElement(*Q))) /* Jika index prioritas ingin di akhir data setelah queue */
        {
            /* NULL-kan next dari pointer prioritas */
            prioritas->next == NULL;

            /* Pointer next last queue menunjuk elemen prioritas */
            (*Q).last->next = prioritas;

            /*Pointer last akan menunjuk elemen prioritas */
            (*Q).last = prioritas;
        }
        else if ((idx < countElement(*Q))) /* Jika index prioritas ingin di tengah-tengah data queue */
        {
            int i; /* iterator */

            /* lakukan perulangan untuk menunjuk elemen */
            for (i = 1; i < idx - 2; i++)
            {
                /* help akan maju ke elemen nextnya */
                help = help->next;

                /* after itu menunjuk next dari help yang sudah maju */
                after = help->next;
            }

            /* next dari help akan menunjuk elemen prioritas */
            help->next = prioritas;
            /* next dari elemen prioritas akan menunjuk after */
            prioritas->next = after;

            /* Pointer untuk membantu akan NULL */
            help = NULL;
            after = NULL;
        }
    }

    /* Pointer prioritas akan NULL */
    prioritas = NULL;
}

/* Prosedur untuk menampilkan data dalam queue */
void printQueue(queue Q)
{
    /* Jika pointer first bukan NULL */
    if (Q.first != NULL)
    {
        /* membuat elemen help */
        elemen *help = Q.first;

        /* inisialisasi iterator */
        int i = 1;

        /* selama help bukan NULL */
        while (help != NULL)
        {
            /* Print data dalam queue */
            printf("\n");
            printf("Elemen  : %d\n", i);
            printf("NIM     : %s\n", help->kontainer.nim);
            printf("Nama    : %s\n", help->kontainer.nama);
            printf("Nilai   : %f\n", help->kontainer.nilai);

            /* increment iterasi */
            help = help->next;
            i = i + 1;
        }
        printf("=============================\n");
    }
    else
    {
        /* Maka queue itu kosong */
        printf("Queue Kosong\n");
    }
}