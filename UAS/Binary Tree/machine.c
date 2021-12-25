/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan UAS           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void makeTree(int left, int right, tree *T)
{
    /* membuat tree dengan parent inputan
        dan child kosong */
    simpul *new = (simpul *) malloc (sizeof (simpul));
    new->leftContainer = left;
    new->rightContainer = right;
    new->right = NULL;
    new->left = NULL;
    (*T).root = new;
    new = NULL;
}

void addRight(int left, int right, simpul *root)
{
    if (root->right == NULL)
    {   // jika sub pohon kanan masih kosong
        simpul *new = (simpul *) malloc (sizeof (simpul));
        new->leftContainer = left;
        new->rightContainer = right;
        new->left = NULL;
        new->right = NULL;
        root->right = new;
    }
}

void addLeft(int left, int right, simpul *root)
{
    if (root->left == NULL)
    {   // jika sub pohon kiri kosong
        simpul *new = (simpul *) malloc (sizeof (simpul));
        new->leftContainer = left;
        new->rightContainer = right;
        new->right = NULL;
        new->left = NULL;
        root->left = new;
    }
}

void printTree(simpul *root)
{
    if (root != NULL)
    {   // jika simpul root tidak kosong
        if (root->left == NULL && root->right == NULL)
        {   // jika simpul root kanan dan kiri kosong
            if (space != 0)
            {   // jika spasi sama dengan 0 alias yang pertama kali di print
                printf(" ");
            }
            space = 1;  // space = 1 menandakan bahwa sudah ada yang di print sebelumnya
            printf("%d %d", root->leftContainer, root->rightContainer);
        }
        printTree(root->left);
        printTree(root->right);
    }
}

void recAdd(int left, int right, simpul *root)
{
    if (left > 1 && right > 1)
    {   // jika left dan right bernilai lebih dari 1
        addLeft(left/2, right, root);   // add left
        addRight(left, right/2, root);  // add right
        if (root->left->leftContainer != 1 && root->right->rightContainer != 1)
        {   // jika isi leftcontainer dari left child dan isi dari rightcontainer dari right child bukan 1
            recAdd(root->left->leftContainer, root->left->rightContainer, root->left);
            recAdd(root->right->leftContainer, root->right->rightContainer, root->right);
        }
    }
}