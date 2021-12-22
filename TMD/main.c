#include "header.h"

int main()
{
    tree T;
    simpul *node;
    int countElement;
    char parent[100], child[100], query[100], tempInfectedCase[50];
    int infectedCase, i, j, idx;
    scanf("%d", &countElement);
    for ( i = 0; i < countElement; i++)
    {
        scanf("%s", &query);

        j = 0;
        idx = 0;
        while (j < strlen(query) && query[j] != '#')
        {
            parent[idx] = query[j];
            idx++;
            j++;
        }
        parent[idx] = '\0';
        j++;

        idx = 0;
        while (j < strlen(query) && query[j] != '#')
        {
            child[idx] = query[j];
            idx++;
            j++;
        }
        child[idx] = '\0';
        j++;
        
        idx = 0;
        while (j < strlen(query) && query[j] != '#')
        {
            tempInfectedCase[idx] = query[j];
            idx++;
            j++;
        }
        tempInfectedCase[idx] = '\0';
        
        infectedCase = 0;
        if (strcmp(tempInfectedCase, "-1") != 0)
        {
            for ( j = 0; j < strlen(tempInfectedCase); j++)
            {
                infectedCase = infectedCase*10 + tempInfectedCase[j] - '0';
            }
        }
        
        if (strcmp(parent, "null") == 0)
        {
            makeTree(child, infectedCase, &T);
        }else
        {
            node = findSimpul(parent, T.root);
            if (node != NULL)
            {
                addChild(child, infectedCase, node);
            }
        }
    }

    int countSubTree;
    scanf("%d", &countSubTree);
    char subTree[50][100];
    for ( i = 0; i < countSubTree; i++)
    {
        scanf("%s", &subTree[i]);
    }

    calculatinginfectedCases(T.root, T.root->container.infectedCase);
    
    printf("pohon lengkap:\n");
    printTreePreOrder(T.root, 0);
    printf("Sub-pohon:\n");
    for ( i = 0; i < countSubTree; i++)
    {
        node = findSimpul(subTree[i], T.root);
        printTreePreOrder(node, 0);
    }
    // simpul *ptr = findSimpul("Cemengkalang", T.root);
    // simpul *prev = ptr->child;
    // if (prev->sibling != NULL)
    // {
    //     while (prev->sibling != ptr->child)
    //     {
    //         printf("%s\n", prev->container.locationName);
    //         prev = prev->sibling;
    //     }
    //     printf("%s\n", prev->container.locationName);
    // }
    
    
    return 0;
}
