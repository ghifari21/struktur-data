/* Binary Tree */

#include <stdio.h>
#include <malloc.h>

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

void makeTree(char c, tree *T);
void addRight(char c, simpul *root);
void addLeft(char c, simpul *root);
void delAll(simpul *root);
void delRight(simpul *root);
void delLeft(simpul *root);
void printTreePreOrder(simpul *root);
void printTreeInOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);

int main(){
    tree T;
    makeTree('A', &T);
    addLeft('B', T.root);
    addRight('C', T.root);
    addLeft('D', T.root->left);
    addRight('E', T.root->left);
    addRight('F', T.root->right);
    printf("===============\n");
    printf("preOrder\n");
    printTreePreOrder(T.root);
    printf("\n===============\n");
    printf("inOrder\n");
    printTreeInOrder(T.root);
    printf("\n===============\n");
    printf("postOrder\n");
    printTreePostOrder(T.root);
    printf("\n===============\n");
    tree T2;
    copyTree(T.root, &T2.root);
    if (isEqual(T.root, T2.root) == 1)
    {
        printf("pohon sama\n");
    }else
    {
        printf("pohon tidak sama\n");
    }
    delRight(T.root->left);
    delLeft(T.root->left);
    printf("===============\n");
    printf("preOrder setelah dihapus\n");
    printTreePreOrder(T.root);
    printf("\n===============\n");

    return 0;
}

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
    {
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
    {
        printf("sub pohon kiri sudah terisi\n");
    }
}

void delAll(simpul *root){
    if (root != NULL)
    {
        delAll(root->left);
        delAll(root->right);
        free(root);
    }
}

void delRight(simpul *root){
    if (root != NULL)
    {
        if (root->right != NULL)
        {
            delAll(root->right);
            root->right = NULL;
        }
    }
}

void delLeft(simpul *root){
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            delAll(root->left);
            root->left = NULL;
        }
    }
}

void printTreePreOrder(simpul *root){
    if (root != NULL)
    {
        printf(" %c", root->container);
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }   
}

void printTreeInOrder(simpul *root){
    if (root != NULL)
    {
        printTreeInOrder(root->left);
        printf(" %c", root->container);
        printTreeInOrder(root->right);
    }
}

void printTreePostOrder(simpul *root){
    if (root != NULL)
    {
        printTreePostOrder(root->left);
        printTreePostOrder(root->right);
        printf(" %c", root->container);
    }
}

void copyTree(simpul *root1, simpul **root2){
    if (root1 != NULL)
    {
        (*root2) = (simpul *) malloc (sizeof (simpul));
        (*root2)->container = root1->container;
        if (root1->left != NULL)
        {
            copyTree(root1->left, &(*root2)->left);
        }
        if (root1->right != NULL)
        {
            copyTree(root1->right, &(*root2)->right);
        }
    }
}

int isEqual(simpul *root1, simpul *root2){
    int result = 1;
    if (root1 != NULL && root2 != NULL)
    {
        if (root1->container != root2->container)
        {
            result = 0;
        }else
        {
            isEqual(root1->left, root2->left);
            isEqual(root1->right, root2->right);
        }
    }else
    {
        if (root1 != NULL || root2 != NULL)
        {
            result = 0;
        }
    }
    return result;
}