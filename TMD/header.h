#include <stdio.h>
#include <string.h>
#include <malloc.h>

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

// n-ary tree
void makeTree(char location[], int infectedCase, tree *T);  // build a tree
void addChild(char location[], int infectedCase, simpul *root); // add a child to parent
simpul* findSimpul(char location[], simpul *root);  // find node
void printTreePreOrder(simpul *root, int space);    // print tree with pre order traversal
int lenLib(int infectedCase);   // library for length of infectedCase
int maxSpacePerLevel(simpul *root);
void calculatinginfectedCases(simpul *root, int infectedCase);
void sortingNode(simpul *root);
void swapNode(simpul *root1, simpul *root2, simpul *parent);