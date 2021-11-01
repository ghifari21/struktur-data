#include <stdio.h>
#include <string.h>

typedef struct{
    char nim[10];
    char nama[50];
    char nilai[2];
}nilaiMatkul;

typedef struct{
    nilaiMatkul kontainer;
    int next;
}elemen;

typedef struct{
    int first;
    elemen data[10];
}list;

//CREATE LIST
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

//COUNT ELEMENT
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

//EMPTY ELEMENT
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

//ADD FIRST
void addFirst(char nim[], char nama[], char nilai[], list *L)
{
    if (countElement(*L) < 10)
    {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.nim, nim);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.nilai, nilai);

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

//ADD AFTER
void addAfter(int prev, char nim[], char nama[], char nilai[], list *L)
{
    if (countElement(*L) < 10)
    {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.nim, nim);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.nilai, nilai);

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

//ADD LAST
void addLast(char nim[], char nama[], char nilai[], list *L)
{
    if ((*L).first == -1)
    {
        //proses jika list masih kosong
        addFirst(nim, nama, nilai, L);
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
            addAfter(prev, nama, nim, nilai, L);
        }
        else
        {
            //proses jika array penuh
            printf("sudah tidak dapat ditambah\n");
        }
    }
}

//VOID DEL FIRST
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
        printf("list kosong\n");
    }
}

//DEL AFTER
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

//DEL LAST
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
        printf("list kosong\n");
    }
}

//PRINT ELEMENT
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
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", L.data[tunjuk].kontainer.nim);
            printf("nama : %s\n", L.data[tunjuk].kontainer.nama);
            printf("nilai : %s\n", L.data[tunjuk].kontainer.nilai);
            printf("next : %d\n", L.data[tunjuk].next);
            printf("------------\n");
            //iterasi
            tunjuk = L.data[tunjuk].next;
            i = i + 1;
        }
    }
    else
    {
        //proses jika list kosong
        printf("list kosong\n");
    }
}

//DEL ALL
void delAll(list *L)
{
    int i;
    for (i = countElement(*L); i >= 1; i--)
    {
        //proses menghapus elemen list
        delLast(L);
    }
}

int main()
{
    list L;
    createList(&L);
    printElement(L);

    printf("=================\n");

    addFirst("1", "Orang_1", "A", &L);
    addAfter(L.first, "2", "Orang_2", "A", &L); 
    addLast("3", "Orang_3", "A", &L);
    printElement(L);

    printf("=================\n");

    delLast(&L);
    delAfter(L.first, &L);
    delFirst(&L);
    printElement(L);

    printf("=================\n");
    
    return 0;
}