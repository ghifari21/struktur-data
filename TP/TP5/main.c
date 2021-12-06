/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TP5           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

int main()
{
    // variable
    tree T;
    char query[50][100], parent[50][100], child[50][100];
    int end = 0, idx = 0;
    simpul *node;

    // input
    do
    {
        scanf("%s", &query[idx]);   // query
        if (strcmp(query[idx], "MAKETREE") == 0)
        {   // jika querynya adalah MAKETREE
            scanf("%s", &parent[idx]);
            parent[idx][strlen(parent[idx])-1] = '\0';
            idx++;
        }else if (strcmp(query[idx], "CHILD") == 0)
        {   // jika querynya adalah CHILD
            scanf("%s %s", &child[idx], &parent[idx]);
            parent[idx][strlen(parent[idx])-1] = '\0';
            idx++;
        }else if (strcmp(query[idx], "DELLCHILD") == 0)
        {   // jika querynya adalah DELLCHILD
            scanf("%s %s", &child[idx], &parent[idx]);
            parent[idx][strlen(parent[idx])-1] = '\0';
            idx++;
        }else if (strcmp(query[idx], "PREORDER;") == 0)
        {   // jika querynya adalah PREORDER
            query[idx][strlen(query[idx])-1] = '\0';
            idx++;
        }else
        {   // jika querynya adalah DONE
            end = 1;
        }
    } while (end == 0);

    // proses data
    int index = 1;
    for (int i = 0; i < idx; i++)
    {
        if (strcmp(query[i], "MAKETREE") == 0)
        {   // jika querynya MAKETREE
            makeTree(parent[i], &T);    // buat tree
        }else if (strcmp(query[i], "CHILD") == 0)
        {   // jika querynya CHILD
            node = findSimpul(parent[i], T.root);
            addChild(child[i], node);   // add child
        }else if (strcmp(query[i], "DELLCHILD") == 0)
        {   // jika querynya DELLCHILD
            node = findSimpul(parent[i], T.root);
            delChild(child[i], node);   // delete child
        }else if (strcmp(query[i], "PREORDER") == 0)
        {   // jika querynya PREORDER
            printf("Output %d:\n", index);
            printf("=========\n");
            printTreePreOrder(T.root, 0);   // print tree dengan pre order traversal
            if (i == idx - 1)
            {
                printf("=========\n");
            }
            index++;
        }
    }
    

    return 0;
}