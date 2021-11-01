/*  (LTRS21) List Tunggal Representasi Statis 2021 C1 (Main)

    Saya Hilman Fauzi Herdiana (2000879) mengerjakan Tes Mesin dalam 
    mata kuliah Stuktur Data untuk keberkahanNya maka saya tidak
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include "header.h"

int main()
{
    int i;
    char brand[6][50], color[6][15], size[6][5]; //array sepatu
    list L;

    //input masukan dari user
    for (i = 0; i < 6; i++)
    {
        scanf("%s", &brand[i]); //merk
        scanf("%s", &color[i]); //warnaA
        scanf("%s", &size[i]);  //ukuran
    }
    
    createList(&L); //membuat list nya
    i = 0; //inisialisasi terlebih dahulu
    addFirst(brand[i], color[i], size[i], &L); //masukan elemen pertama
    i++; //i bertambah
    addFirst(brand[i], color[i], size[i], &L); //masukan elemen baru ke posisi pertama
    i++; //i bertambah
    addLast(brand[i], color[i], size[i], &L); //masukan elemen di akhir
    printElement(L); //tampilkan output listnya
    delLast(&L); //hapus elemen terakhir
    i++; //i bertambah
    addLast(brand[i], color[i], size[i], &L); //masukan elemen di akhir
    i++; //i bertambah
    addAfter(L.first, brand[i], color[i], size[i], &L);  //masukan elemen baru setelah elemen pertama
    delFirst(&L); //hapus elemen pertama
    printElement(L); //tampilkan output listnya
    i++; //i bertambah ;-;
    addAfter(L.data[L.first].next, brand[i], color[i], size[i], &L); //masukan elemen baru setelah elemen kedua
    delAfter(L.first, &L); //hapus elemen setelah elemen pertama
    printElement(L); //tampilkan output listnya

    delAll(&L); //hapus semua list
    printElement(L); //tampilkan output listnya

    return 0;
}