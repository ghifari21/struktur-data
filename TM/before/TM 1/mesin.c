/*  (LTRS21) List Tunggal Representasi Statis 2021 C1 (Mesin)

    Saya Hilman Fauzi Herdiana (2000879) mengerjakan Tes Mesin dalam 
    mata kuliah Stuktur Data untuk keberkahanNya maka saya tidak
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include "header.h"

//prosedur membuat list
void createList(list *L)
{
    (*L).first = -1;
    int i;

    for (i = 0; i < 10; i++)
    {
        //proses menginisialisasi isi array
        (*L).data[i].next = -2;
    }
}

//fungsi menghitung banyak elemen
int countElement(list L)
{
    int hasil = 0;
    if (L.first != -1)
    {
        // list tidak kosong
        int hitung;
        //inisialisasi
        hitung = L.first;

        while (hitung != -1)
        {
            //proses
            hasil = hasil + 1;
            //iterasi
            hitung = L.data[hitung].next;
        }
    }
    return hasil;
}

//fungsi untuk mengkosongkan elemen
int emptyElement(list L)
{
    int hasil = -1;

    if (countElement(L) < 10)
    {
        int ketemu = 0;
        int i =
         0;
        while ((ketemu == 0) && (i < 10))
        {
            if (L.data[i].next == -2)
            {
                hasil = i;
                ketemu = 1;
            }
            else
            {
                i = i + 1;
            }
        }
    }
    return hasil;
}

//prosedur memasukan elemen pertama
void addFirst(char merk[], char warna[], char ukuran[], list *L)
{
    if (countElement(*L) < 10)
    {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.merk, merk);
        strcpy((*L).data[baru].kontainer.warna, warna);
        strcpy((*L).data[baru].kontainer.ukuran, ukuran);

        if ((*L).first == -1)
        {
            //jika list kosong
            (*L).data[baru].next = -1;
        }
        else
        {
            //jika list tidak kosong 
            (*L).data[baru].next = (*L).first;
        }
        (*L).first = baru;
    }
    else
    {
        //proses jika array penuh
        printf("sudah tidak dapat ditambah\n");
    }
}

//prosedur memasukan elemen setelah elemen pertama
void addAfter(int prev, char merk[], char warna[], char ukuran[], list *L)
{
    if (countElement(*L) < 10)
    {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.merk, merk);
        strcpy((*L).data[baru].kontainer.warna, warna);
        strcpy((*L).data[baru].kontainer.ukuran, ukuran);

        if ((*L).data[prev].next == -1)
        {
            (*L).data[baru].next = -1;
        }
        else
        {
            (*L).data[baru].next = (*L).data[prev].next;
        }
        (*L).data[prev].next = baru;
    }
    else
    {
        //proses jika array penuh
        printf("sudah tidak dapat ditambah\n");
    }
}

//prosedur memasukan elemen di akhir
void addLast(char merk[], char warna[], char ukuran[], list *L)
{
    if ((*L).first == -1)
    {
        //proses jika list masih kosong
        addFirst(merk, warna, ukuran, L);
    }
    else
    {
        //proses jika list telah berisi elemen
        if (countElement(*L) < 10)
        {
            //proses jika array belum penuh
            //proses mencari elemen terakhir
            //inisialisasi
            int prev = (*L).first;

            while ((*L).data[prev].next != -1)
            {
                //iterasi
                prev = (*L).data[prev].next;
            }
            addAfter(prev, merk, warna, ukuran, L);
        }
        else
        {
            //proses jika array penuh
            printf("sudah tidak dapat ditambah\n");
        }
    }
}

//prosedur menghapus elemen pertama
void delFirst(list *L)
{
    if ((*L).first != -1)
    {
        int hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = -1;
        }
        else
        {
            (*L).first = (*L).data[hapus].next;
        }
        //elemen awal sebelumnya dikosongkan
        (*L).data[hapus].next = -2;        
    }
    else
    {
        //proses jika list kosong
        printf("List kosong\n");
    }
}

//prosedur menghapus elemen setelah elemen pertama 
void delAfter(int prev, list *L)
{
    int hapus = (*L).data[prev].next;

    if (hapus != -1)
    {
        if ((*L).data[hapus].next == -1)
        {
            (*L).data[prev].next = -1;
        }
        else
        {
            (*L).data[prev].next = (*L).data[hapus].next;
        }
        //pengosongan elemen
        (*L).data[hapus].next = -2;
    }
}

//prosedur menghapus elemen terakhir
void delLast(list *L)
{
    if ((*L).first != -1)
    {
        if (countElement(*L) == 1)
        {
            //proses jika list hanya berisi satu elemen
            delFirst(L);
        }
        else
        {
            int hapus = (*L).first;
            int prev;

            while ((*L).data[hapus].next != -1)
            {
                //iterasi
                prev = hapus;
                hapus = (*L).data[hapus].next;
            }
            //elemen sebelum elemen terakhir menjadi elemen terakhir
            delAfter(prev, L);
        }
    }
    else
    {
        //proses jika list kosong
        printf("List kosong\n");
    }
}

//prosedur menampilkan output
void printElement(list L)
{
    if (L.first != -1)
    {
        //inisialisasi
        int tunjuk = L.first;
        int i = 1;

        while (tunjuk != -1)
        {
            //proses
            printf("%s %s %s\n", L.data[tunjuk].kontainer.merk, L.data[tunjuk].kontainer.warna, L.data[tunjuk].kontainer.ukuran);
            //iterasi
            tunjuk = L.data[tunjuk].next;
            i = i + 1;

            if (tunjuk == -1)
            {
                printf("========\n");
            }
        }
    }
    else
    {
        //proses jika list kosong
        printf("List kosong\n");
        printf("========\n");
    }
}

//prosedur menghapus semua elemen
void delAll(list *L)
{
    int i;
    for (i = countElement(*L); i >= 1; i--)
    {
        //proses menghapus elemen list
        delLast(L);
    }
}