/*  (LTRD121) List Tunggal Representasi Dinamis 2021 C1 (Header)

    Saya Hilman Fauzi Herdiana (2000879) mengerjakan Tes Mesin 2 dalam 
    mata kuliah Stuktur Data untuk keberkahanNya maka saya tidak
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//bungkusan senyawa
typedef struct
{
    char nama[50];
    char rumus[10];
    char konsentrasi[10];
}senyawa;

typedef struct elmt* alamatelmt;
typedef struct elmt
{
    senyawa kontainer;
    alamatelmt next;
}elemen;

typedef struct
{
    elemen* first;
}list;

void createList(list *L); //prosedur membuat list
int countElement(list L); //fungsi menghitung elemen
void addFirst(char nama[], char rumus[], char konsentrasi[], list *L); //prosedur add first
void addAfter(elemen* prev, char nama[], char rumus[], char konsentrasi[], list *L); //prosedur add after
void addLast(char nama[], char rumus[], char konsentrasi[], list *L); //prosedur add last
void delFirst(list *L); //prosedur del first
void delAfter(elemen* prev, list *L); //prosedur del after
void delLast(list *L); //prosedur del last
void printElement(list L); //prosedur print element
void delAll(list *L); //prosedur del all