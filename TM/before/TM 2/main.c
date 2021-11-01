/*  (LTRD121) List Tunggal Representasi Dinamis 2021 C1 (Main)

    Saya Hilman Fauzi Herdiana (2000879) mengerjakan Tes Mesin 2 dalam 
    mata kuliah Stuktur Data untuk keberkahanNya maka saya tidak
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include "header.h"

int main()
{
    list L;
    senyawa arr[6]; //bungkusan array senyawa
    int i;
    //input masukan dari user
    for (i = 0; i < 6; i++)
    {
        scanf("%s", &arr[i].nama);
        scanf("%s", &arr[i].rumus);
        scanf("%s", &arr[i].konsentrasi);
    }

    createList(&L); // membuat buat list

    i = 0; //inisialisasi
    addFirst(arr[i].nama, arr[i].rumus, arr[i].konsentrasi, &L);
    i++; //bertambah
    addLast(arr[i].nama, arr[i].rumus, arr[i].konsentrasi, &L);
    i++;//bertambah
    addAfter(L.first->next, arr[i].nama, arr[i].rumus, arr[i].konsentrasi, &L); 
    printf("======\n");
    printElement(L);

    delFirst(&L);
    i++; //bertambah
    addLast(arr[i].nama, arr[i].rumus, arr[i].konsentrasi, &L);
    delAfter(L.first->next, &L);
    printElement(L);

    delLast(&L);
    i++; //bertambah
    addFirst(arr[i].nama, arr[i].rumus, arr[i].konsentrasi, &L);
    printElement(L);

    delAll(&L);
    printElement(L);

    i++; //bertambah
    addLast(arr[i].nama, arr[i].rumus, arr[i].konsentrasi, &L);
    printElement(L);

    return 0;
}