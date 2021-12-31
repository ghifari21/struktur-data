/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TMD           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

// tipe data terstruktur yang dipakai
typedef struct
{
    char locationName[100];
    int infectedCase;
}pandemicCase;

typedef struct smp *simpulAddress;
typedef struct smp
{
    pandemicCase container;
    simpulAddress sibling;
    simpulAddress child;
}simpul;

typedef struct
{
    simpul *root;
}tree;

// fungsi dan prosedur yang dipakai
void makeTree(char location[], int infectedCase, tree *T);  // build a tree
void addChild(char location[], int infectedCase, simpul *root); // add a child to parent
simpul* findSimpul(char location[], simpul *root);  // find node
void printTreePreOrder(simpul *root, int currentSpace, int maxSpace[], int currentLevel);    // print tree with pre order traversal
int lenLib(int infectedCase);   // library for length of infectedCase
int spacePerLevel(simpul *root, int currentLevel, int targetLevel);
int deepestLevelOfTree(simpul *root, int currentLevel); // searching for the deepest level of tree
int calculatingInfectedCases(simpul *root); // menjumlahkan kasus positif pada setiap simpul
void calculate(simpul *root);   // rekursif untuk menghitung kasus positif