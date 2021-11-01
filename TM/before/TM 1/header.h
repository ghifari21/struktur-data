/*  (LTRS21) List Tunggal Representasi Statis 2021 C1 (Header)

    Saya Hilman Fauzi Herdiana (2000879) mengerjakan Tes Mesin dalam 
    mata kuliah Stuktur Data untuk keberkahanNya maka saya tidak
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include <string.h>

//bungkusan sepatu
typedef struct{
    char merk[50];
    char warna[15];
    char ukuran[5];
}tipeSepatu;

typedef struct{
    tipeSepatu kontainer;
    int next;
}elemen;

typedef struct{
    int first;
    elemen data[10];
}list;

void createList(list *L); //prosedur membuat list
int countElement(list L); //fungsi menghitung banyak elemen
int emptyElement(list L); //fungsi untuk mengkosongkan elemen
void addFirst(char merk[], char warna[], char ukuran[], list *L); //prosedur memasukan elemen pertama
void addAfter(int prev, char merk[], char warna[], char ukuran[], list *L); //prosedur memasukan elemen setelah elemen pertama
void addLast(char merk[], char warna[], char ukuran[], list *L); //prosedur memasukan elemen di akhir
void delFirst(list *L); //prosedur menghapus elemen pertama
void delAfter(int prev, list *L); //prosedur menghapus elemen setelah elemen pertama 
void delLast(list *L); //prosedur menghapus elemen terakhir
void printElement(list L); //prosedur menampilkan output
void delAll(list *L); //prosedur menghapus semua elemen