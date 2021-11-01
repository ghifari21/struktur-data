/*  (LGD121) List Ganda Dinamis C1 (Mesin)

    Saya Hilman Fauzi Herdiana (2000879) mengerjakan Tes Mesin 4 dalam 
    mata kuliah Stuktur Data untuk keberkahanNya maka saya tidak
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include "header.h"

//prosedur membuat list
void createList(list *L)
{
    (*L).first = NULL;
    (*L).tail = NULL;
}

//fungsi menghitung elemen
int countElement(list L)
{
    int hasil = 0; // inisialisasi

    if (L.first != NULL) //list tidak kosong 
    {
        elemen* bantu;
        //inisialisasi
        bantu = L.first;
        while (bantu != NULL) // looping selama bantu tidak kosong
        {
            //iterasi
            hasil = hasil + 1;
            bantu = bantu->next;
        }
    }
    return hasil;
}

//prosedur add first
void addFirst(char nama[], char matkul[], char nilai[], list *L)
{
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));

    //pindahkan data
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.matkul, matkul);
    strcpy(baru->kontainer.nilai, nilai);

    if ((*L).first == NULL)
    {
        baru->prev = NULL;
        baru->next = NULL;
        (*L).tail = baru;
    }
    else
    {
        baru->next = (*L).first;
        baru->prev = NULL;
        (*L).first->prev = baru;
    }
    (*L).first = baru;
    baru = NULL;
}

//prosedur add after
void addAfter(elemen* before, char nama[], char matkul[], char nilai[], list *L)
{
    if (before != NULL)
    {
        elemen* baru;
        baru = (elemen*) malloc (sizeof (elemen));

        //pindahkan data
        strcpy(baru->kontainer.nama, nama);
        strcpy(baru->kontainer.matkul, matkul);
        strcpy(baru->kontainer.nilai, nilai);

        if (before->next == NULL)
        {
            baru->next = NULL;
            (*L).tail = baru;
        } 
        else
        {
            baru->next = before->next;
            baru->next->prev = baru;
        }
        baru->prev = before;
        before->next = baru;
        baru = NULL;
    }   
}

//prosedur add last
void addLast(char nama[], char matkul[], char nilai[], list *L)
{
    if ((*L).first == NULL)
    {
        //jika list adalah list kosong
        addFirst(nama, matkul, nilai, L);
    } 
    else
    {
        //jika list tidak kosong
        addAfter((*L).tail, nama, matkul, nilai, L);
    }
}

//prosedur add before
void addBefore(elemen* before, char nama[], char matkul[], char nilai[], list *L)
{
    if (before != NULL)
    {
        elemen* baru;
        baru = (elemen*) malloc (sizeof (elemen));

        // pindahkan data
        strcpy(baru->kontainer.nama, nama);
        strcpy(baru->kontainer.matkul, matkul);
        strcpy(baru->kontainer.nilai, nilai);

        if (before->prev == NULL) //jika before->prev kosong
        {
            baru->prev = NULL;
            (*L).tail = baru;
        } 
        else // jika tidak
        {
            baru->prev = before->prev;
            baru->prev->next = baru;
        }
        baru->next = before;
        before->prev = baru;
        baru = NULL;
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
            (*L).tail = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
             (*L).first->prev = NULL;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

//prosedur del after
void delAfter(elemen* before, list *L)
{
    elemen* hapus = before->next;
    if (hapus != NULL) //jika pointer hapus tidak kosong
    {
        if (hapus->next == NULL) //jika pointer hapus->next tidak kosong
        {
            before->next = NULL;
            (*L).tail = before;
        }
        else
        {
            before->next = hapus->next;
            hapus->next->prev = before;
            hapus->next = NULL;
        }
        hapus->prev = NULL;
        free(hapus);
    }
}

//prosedur del last
void delLast(list *L)
{
    if ((*L).first != NULL)
    {
        //jika list tidak kosong
        if (countElement(*L) == 1)
        {
            //list terdiri dari satu elemen
            delFirst(L);
        }
        else
        {
            //jika banyak elemen
            delAfter((*L).tail->prev, L);
        }   
    }  
}

//prosedur print element
void printElement(list L)
{
    if (L.first != NULL) //jika list tidak kosong
    {
        //inisialisasi
        elemen* bantu = L.first;
        while (bantu != NULL) // looping selama bantu tidak kosong
        {
            printf("%s ",  bantu->kontainer.nama);
            printf("%s ",  bantu->kontainer.matkul);
            printf("%s\n",  bantu->kontainer.nilai);
            bantu = bantu->next; //iterasi
        }
    }
    else // jika list kosong
    {
        printf("List Kosong\n");
    }
    printf("========\n");
}

//prosedur print reverse
void printReverse(list L)
{
    if (L.first != NULL) //jika list tidak kosong
    {
        // inisialisasi
        elemen* bantu = L.tail;
        while (bantu != NULL) // looping selama bantu tidak kosong
        {
            printf("%s ",  bantu->kontainer.nama);
            printf("%s ",  bantu->kontainer.matkul);
            printf("%s\n",  bantu->kontainer.nilai);
            bantu = bantu->prev; //iterasi
        }
    }
    else // jika list kosong
    {
        printf("List Kosong\n");
    }
    printf("========\n");
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