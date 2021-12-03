#include "header.h"

int main()
{
    tree T;
    int count = 9;
    data input[9];
    // input
    for (int i = 0; i < count; i++)
    {
        scanf("%s %d", &input[i].name, &input[i].grade);
    }
    
    // step 1
    printf("Step 1:\n================\n");
    makeTree(input[0], &T);
    addChild(input[1], T.root);
    addChild(input[2], T.root);
    addChild(input[3], T.root);
    addChild(input[4], T.root->child);
    addChild(input[5], T.root->child);
    printTreePreOrder(T.root);
    printf("\n");
    delChild(T.root->child->child->sibling, T.root->child);
    printTreePreOrder(T.root);
    printf("\n");
    addChild(input[6], T.root->child->sibling);
    addChild(input[7], T.root->child->sibling);
    addChild(input[8], T.root->child->sibling->sibling);
    printTreePreOrder(T.root);

    // step 2
    printf("\nStep 2:\n================\n");
    tree T2;
    copyTree(T.root, &T2.root);
    if (isEqual(T.root, T2.root) == 1)
    {   // jika tree 1 dan 2 sama
        printf("Sama\n");
    }else
    {   // jika tree 1 dan 2 beda
        printf("Belum Sama\n");
    }

    // step 3
    printf("Step 3:\n================\n");
    simpul *node = findSimpul(input[7].name, T.root->child->child);
    if (node == NULL)
    {   // jika gian tidak ditemukan
        printf("%s tidak ditemukan\n", input[7].name);
    }else
    {   // jika gian ditemukan
        printf("%s ditemukan\n", input[7].name);
    }
    
    node = findSimpul(input[7].name, T.root->child->sibling);
    if (node == NULL)
    {   // jika gian tidak ditemukan
        printf("%s tidak ditemukan\n", input[7].name);
    }else
    {   // jika gian ditemukan
        printf("%s ditemukan\n", input[7].name);
    }
    
    node = findSimpul(input[7].name, T.root);
    if (node == NULL)
    {   // jika gian tidak ditemukan
        printf("%s tidak ditemukan\n", input[7].name);
    }else
    {   // jika gian ditemukan
        printf("%s ditemukan\n", input[7].name);
    }


    return 0;
}
