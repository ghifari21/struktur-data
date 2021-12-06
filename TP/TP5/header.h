/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TP5           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

// tipe data terstruktur yang dipakai
typedef struct smp *simpulAddress;
typedef struct smp
{
    char container[100];
    simpulAddress sibling;
    simpulAddress child;
}simpul;

typedef struct
{
    simpul *root;
}tree;

// fungsi dan prosedur N-er Tree
void makeTree(char str[], tree *T); // buat tree
void addChild(char str[], simpul *root);    // add child
void delAll(simpul *root);  // delete all root
void delChild(char str[], simpul *root);    // delete child
simpul* findSimpul(char str[], simpul *root);   // find node
void printTreePreOrder(simpul *root, int space);    // print out tree in pre order traversal