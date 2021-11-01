/*  (LGD121) List Ganda Dinamis C1 (Main)

    Saya Hilman Fauzi Herdiana (2000879) mengerjakan Tes Mesin 4 dalam 
    mata kuliah Stuktur Data untuk keberkahanNya maka saya tidak
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include "header.h"

int main()
{
    list L;
    dataMahasiswa arr[6]; //bungkusan array data mahasiswa
    int i;
    //input masukan dari user
    for (i = 0; i < 6; i++)
    {
        scanf("%s", &arr[i].nama);
        scanf("%s", &arr[i].matkul);
        scanf("%s", &arr[i].nilai);
    }

    createList(&L); // buat list nya
    i = 0; //inisialisasi
    addFirst(arr[i].nama, arr[i].matkul, arr[i].nilai, &L);
    i++; // iterasi
    addAfter(L.first, arr[i].nama, arr[i].matkul, arr[i].nilai, &L);
    i++; // iterasi
    addBefore(L.tail, arr[i].nama, arr[i].matkul, arr[i].nilai, &L);
    printElement(L); // print isi list nya

    delAfter(L.first->next->prev, &L);
    i++; // iterasi
    addLast(arr[i].nama, arr[i].matkul, arr[i].nilai, &L);
    printElement(L); // print isi list nya

    delFirst(&L); // hapus data list pertama
    i++; // iterasi
    addLast(arr[i].nama, arr[i].matkul, arr[i].nilai, &L);
    i++; // iterasi
    addAfter(L.first->next, arr[i].nama, arr[i].matkul, arr[i].nilai, &L);
    delLast(&L); // hapus data list terakhir
    printReverse(L); // print isi list nya secara reverse

    delAll(&L); // hapus semua isi list
    printElement(L); // print isi list nya

    return 0;
}