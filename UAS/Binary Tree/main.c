/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan UAS           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

int main()
{
    // variabel yang akan dipakai
    tree T;
    int left, right;
    space = 0;

    scanf("%d %d", &left, &right);  // input
    makeTree(left, right, &T);  // buat tree
    recAdd(left, right, T.root);    // add child secara rekursif

    printTree(T.root);  // output
    printf("\n");

    return 0;
}