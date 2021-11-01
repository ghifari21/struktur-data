/*  (LTRD121) List Tunggal Representasi Dinamis 2021 C1 (Mesin)

    Saya Hilman Fauzi Herdiana (2000879) mengerjakan Tes Mesin 2 dalam 
    mata kuliah Stuktur Data untuk keberkahanNya maka saya tidak
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include "header.h"

//prosedur membuat list
void createList(list *L)
{
    (*L).first = NULL;
}

//fungsi menghitung elemen
int countElement(list L)
{
    int hasil = 0;

    if (L.first != NULL)
    {
        //list tidak kosong 
        elemen* tunjuk;
        //inisialisasi
        tunjuk = L.first;
        while (tunjuk != NULL)
        {
            //proses
            hasil = hasil + 1;
            //iterasi
            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}

//prosedur add first
void addFirst(char nama[], char rumus[], char konsentrasi[], list *L)
{
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    //memindahkan
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.rumus, rumus);
    strcpy(baru->kontainer.konsentrasi, konsentrasi);

    //jika L.first adalah null
    if ((*L).first == NULL)
    {
        baru->next = NULL;
    } 
    else
    {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

//prosedur add after
void addAfter(elemen* prev, char nama[], char rumus[], char konsentrasi[], list *L)
{
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    //memindahkan
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.rumus, rumus);
    strcpy(baru->kontainer.konsentrasi, konsentrasi);

    if (prev->next == NULL)
    {
        baru->next = NULL;
    } 
    else
    {
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;   
}

//prosedur add last
void addLast(char nama[], char rumus[], char konsentrasi[], list *L)
{
    if ((*L).first == NULL)
    {
        //jika listnya kosong
        addFirst(nama, rumus, konsentrasi, L);
    } 
    else
    {
        //jika list tidak kosong, cari elemen terakhir list
        elemen* prev = (*L).first;
        while (prev->next != NULL)
        {
            //iterasi
            prev = prev->next;
        }
        addAfter(prev, nama, rumus, konsentrasi, L);
    }
}

//prosedur del first
void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        //jika list bukan list kosong
        elemen* hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

//prosedur del after
void delAfter(elemen* prev, list *L)
{
    elemen* hapus = prev->next;

    //jika hapus bukan null
    if (hapus != NULL)
    {
        if (hapus->next == NULL)
        {
            prev->next = NULL;
        }
        else
        {
            prev->next = hapus->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

//prosedur del last
void delLast(list *L)
{
    if ((*L).first != NULL)
    {
        //jika list nya tidak kosong
        if (countElement(*L) == 1)
        {
            //list terdiri dari satu elemen
            delFirst(L);
        }
        else
        {
            //mencari elemen terakhir list
            elemen* last = (*L).first;
            elemen* prev;

            while (last->next != NULL)
            {
                //iterasi
                prev = last;
                last = last->next;
            }
        delAfter(prev, L);
        }   
    }  
}

//prosedur print element
void printElement(list L)
{
    if (L.first != NULL)
    {
        //jika list tidak kosong
        //inisialisasi
        elemen* tunjuk = L.first;
        int i = 1;
        while (tunjuk != NULL)
        {
            //proses menampilkan output
            printf("%s %s %s\n", tunjuk->kontainer.nama, tunjuk->kontainer.rumus, tunjuk->kontainer.konsentrasi);
            //iterasi
            tunjuk = tunjuk->next;
            i = i + 1;

            //jika tunjuk nya ketemu null, print pembatas
            if (tunjuk == NULL)
            {
                printf("======\n");
            }
        }
    }
    else
    {
        //proses jika list kosong print ini
        printf("list kosong\n");
        printf("======\n");
    }
}

//prosedur del all
void delAll(list *L)
{
    if (countElement(*L) != 0)
    {
        int i;
        for (i = countElement(*L); i >= 1; i--)
        {
            //prosed menghapus elemen list
            delLast(L);
        }
    }
}