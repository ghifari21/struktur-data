/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan UAS           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include <stdio.h>
#include <malloc.h>

// tipe data yang dipakai
typedef struct smp *simpulAddress;
typedef struct smp
{
    int leftContainer;
    int rightContainer;
    simpulAddress right;
    simpulAddress left;
}simpul;

typedef struct
{
    simpul* root;
}tree;

// variabel global untuk penanda spasi
int space;

// prosedur yang dipakai
void makeTree(int left, int right, tree *T);    // buat tree
void addRight(int left, int right, simpul *root);   // tambah anak pada node kanan
void addLeft(int left, int right, simpul *root);    // tambah anak pada node kiri
void printTree(simpul *root);   // output
void recAdd(int left, int right, simpul *root); // menambahkan anak dengan rekursif