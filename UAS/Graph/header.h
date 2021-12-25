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

// fungsi dan prosedur yang dipakai
void createEmpty(graph *G); // buat graph kosong
void addNode(char c, graph *G); // menambahkan node
void addPath(node *first, node *dest, int weight);  // menambahkan jalur
node* findNode(char c, graph G);    // mencari node
int isCycle(char start, node *ptr, graph G);    // apakah memiliki jalur yang memutar