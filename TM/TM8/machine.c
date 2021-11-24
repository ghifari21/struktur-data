#include "header.h"

void makeTree(char c, tree *T){
    simpul *new = (simpul *) malloc (sizeof (simpul));
    new->container = c;
    new->right = NULL;
    new->left = NULL;
    (*T).root = new;
    new = NULL;
}

void addRight(char c, simpul *root){
    if (root->right == NULL)
    {   // jika sub pohon kanan masih kosong
        simpul *new = (simpul *) malloc (sizeof (simpul));
        new->container = c;
        new->left = NULL;
        new->right = NULL;
        root->right = new;
    }else
    {   // jika sub pohon kanan sudah terisi
        printf("sub pohon kanan sudah terisi\n");
    }
}

void addLeft(char c, simpul *root){
    if (root->left == NULL)
    {   // jika sub pohon kiri kosong
        simpul *new = (simpul *) malloc (sizeof (simpul));
        new->container = c;
        new->right = NULL;
        new->left = NULL;
        root->left = new;
    }else
    {   // jika sub pohon kiri sudah terisi
        printf("sub pohon kiri sudah terisi\n");
    }
}

void delAll(simpul *root){
    if (root != NULL)
    {   // jika root tidak null
        delAll(root->left);
        delAll(root->right);
        free(root);
    }
}

void delRight(simpul *root){
    if (root != NULL)
    {   // jika root tidak null
        if (root->right != NULL)
        {   // jika sub pohon kanan tidak null
            delAll(root->right);
            root->right = NULL;
        }
    }
}

void delLeft(simpul *root){
    if (root != NULL)
    {   // jika root tidak null
        if (root->left != NULL)
        {   // jika sub pohon kiri tidak null
            delAll(root->left);
            root->left = NULL;
        }
    }
}

void printTreePreOrder(simpul *root){
    if (root != NULL)
    {   // jika root tidak null
        printf("%c", root->container);
        if (root->left != NULL)
        {   // jika sub pohon kiri tidak null
            printf(" - ");
        }
        printTreePreOrder(root->left);
        if (root->right != NULL)
        {   // jika sub pohon kanan tidak null
            printf(" - ");
        }
        printTreePreOrder(root->right);
    }   
}

void printTreeInOrder(simpul *root){
    if (root != NULL)
    {   // jika root tidak null
        printTreeInOrder(root->left);
        if (root->left != NULL)
        {   // jika sub pohon kiri tidak null
            printf(" - ");
        }
        printf("%c", root->container);
        if (root->right != NULL)
        {   // jika sub pohon kanan tidak null
            printf(" - ");
        }
        printTreeInOrder(root->right);
    }
}

void printTreePostOrder(simpul *root){
    if (root != NULL)
    {   // jika root tidak null
        printTreePostOrder(root->left);
        if (root->left != NULL)
        {   // jika sub pohon kiri tidak null
            printf(" - ");
        }
        printTreePostOrder(root->right);
        if (root->right != NULL)
        {   // jika sub pohon kanan tidak null
            printf(" - ");
        }
        printf("%c", root->container);
    }
}