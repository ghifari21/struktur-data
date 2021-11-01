/*  (LGS221) List Ganda Statis C1 (Main)

    Saya Hilman Fauzi Herdiana (2000879) mengerjakan Tugas Mesin 3 dalam 
    mata kuliah Stuktur Data untuk keberkahanNya maka saya tidak
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include "header.h"

int main()
{
    list L;
    dataHp arr[6]; //bungkusan array data hp
    int i;
    //input masukan dari user
    for (i = 0; i < 6; i++)
    {
        scanf("%s", &arr[i].merk);
        scanf("%s", &arr[i].tipe);
        scanf("%s", &arr[i].jumlah);
    }

    createList(&L);
    i = 0; //inisialisasi
    addFirst(arr[i].merk, arr[i].tipe, arr[i].jumlah, &L);
    i++; //bertambah
    addLast(arr[i].merk, arr[i].tipe, arr[i].jumlah, &L);
    i++;//bertambah
    addAfter(L.first, arr[i].merk, arr[i].tipe, arr[i].jumlah, &L); 
    printElement(L);
    
    delAfter(L.data[L.first].next, &L);
    printElement(L);

    i++;//bertambah
    addAfter(L.data[L.first].next, arr[i].merk, arr[i].tipe, arr[i].jumlah, &L);
    i++; //bertambah
    addLast(arr[i].merk, arr[i].tipe, arr[i].jumlah, &L);
    delFirst(&L);
    printElement(L);

    i++; //bertambah ;-;
    addFirst(arr[i].merk, arr[i].tipe, arr[i].jumlah, &L);
    delAfter(L.first, &L);
    printReverse(L);

    delAll(&L);
    printElement(L);

    return 0;
}