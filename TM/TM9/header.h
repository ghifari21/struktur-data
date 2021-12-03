#include <stdio.h>
#include <malloc.h>
#include <string.h>

// tipe data terstruktur yang dipakai
typedef struct
{
    char name[50];
    int grade;
}data;

typedef struct smp *simpulAddress;
typedef struct smp
{
    data container;
    simpulAddress sibling;
    simpulAddress child;
}simpul;

typedef struct
{
    simpul *root;
}tree;

// prosedur dan fungsi yang dipakai
void makeTree(data input, tree *T); // membuat tree
void addChild(data input, simpul *root);    // menambahkan anak
void delAll(simpul *root);  // delete all node
void delChild(simpul *target, simpul *root);    // delete child node
simpul* findSimpul(char name[], simpul *root);  // mencari simpul
void printTreePreOrder(simpul *root);   // output pre order
void printTreePostOrder(simpul *root);  // output post order
void copyTree(simpul *root1, simpul **root2);   // copy
int isEqual(simpul *root1, simpul *root2);  // untuk mencari tahu apakah tree 1 dan 2 sama