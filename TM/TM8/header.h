#include <stdio.h>
#include <malloc.h>

// tipe data terstruktur yang dipakai
typedef struct smp *simpulAddress;
typedef struct smp
{
    char container;
    simpulAddress right;
    simpulAddress left;
}simpul;

typedef struct
{
    simpul* root;
}tree;

// fungsi dan prosedur yang dipakai
void makeTree(char c, tree *T); // membuat tree
void addRight(char c, simpul *root); // menambahkan ke kanan root
void addLeft(char c, simpul *root); // menambahkan ke kiri root
void delAll(simpul *root);  // delete semua element root
void delRight(simpul *root);    // delete bagian kanan root
void delLeft(simpul *root);     // delete bagian kiri root
void printTreePreOrder(simpul *root);   // pre order
void printTreeInOrder(simpul *root);    // in order
void printTreePostOrder(simpul *root);  // post order