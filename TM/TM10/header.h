#include <stdio.h>
#include <malloc.h>

// tipe data terstruktur yang dipakai
typedef struct nd *nodeAddress;
typedef struct pth *pathAddress;

typedef struct nd
{
    char container;
    nodeAddress next;
    pathAddress arc;
}node;

typedef struct pth
{
    int pathContainer;
    pathAddress nextPath;
    node *destination;
}path;

typedef struct
{
    node* first;
}graph;

// prosedur dan fungsi
void createEmpty(graph *G); // buat graf kosong
void addNode(char c, graph *G); // buat node
void addPath(node *first, node *dest, int weight);  // buat jalur
node* findNode(char c, graph G);    // cari node
void delPath(char cDest, node *first);  // hapus jalur
void delAll(node *first);   // hapus semua
void delNode(char c, graph *G); // hapus node
void printGraph(graph G);   // output