/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TMD           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

int main()
{
    // deklarasi variabel
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
        // proses memisahkan string parent dari string utama
        while (j < strlen(query) && query[j] != '#')
        {
            parent[idx] = query[j];
            idx++;
            j++;
        }
        parent[idx] = '\0';
        j++;

        idx = 0;
        // proses memisahkan string child dari string utama
        while (j < strlen(query) && query[j] != '#')
        {
            child[idx] = query[j];
            idx++;
            j++;
        }
        child[idx] = '\0';
        j++;
        
        idx = 0;
        // proses memisahkan banyak kasus dari string utama
        while (j < strlen(query))
        {
            tempInfectedCase[idx] = query[j];
            idx++;
            j++;
        }
        tempInfectedCase[idx] = '\0';
        
        infectedCase = 0;
        if (strcmp(tempInfectedCase, "-1") != 0)
        {   // jika jumlah kasus bukan -1
            // proses konversi jumlah kasus dari char menjadi integer
            for ( j = 0; j < strlen(tempInfectedCase); j++)
            {
                infectedCase = infectedCase*10 + tempInfectedCase[j] - '0';
            }
        }
        
        if (strcmp(parent, "null") == 0)
        {   // jika parentnya null maka akan membuat tree baru
            makeTree(child, infectedCase, &T);
        }else
        {   // jika parentnya tidak null
            // mencari simpul parent
            node = findSimpul(parent, T.root);
            if (node != NULL)
            {   // jika simpul parent tidak kosong
                addChild(child, infectedCase, node);
            }
        }
    }

    // input sub tree
    int countSubTree;
    scanf("%d", &countSubTree);
    char subTree[50][100];
    for ( i = 0; i < countSubTree; i++)
    {
        scanf("%s", &subTree[i]);
    }

    // menghitung jumlah kasus
    calculate(T.root);

    // mencari level tree terdalam
    int deepestLevel = deepestLevelOfTree(T.root, 1);

    // mencari panjang string maksimal pada setiap levelnya
    int longestSpacePerLevel[100];
    for ( i = 1; i <= deepestLevel; i++)
    {
        longestSpacePerLevel[i] = spacePerLevel(T.root, 1, i);
    }
    // output pohon lengkap
    printf("pohon lengkap:\n");
    printTreePreOrder(T.root, 0, longestSpacePerLevel, 1);
    
    // output sub pohon
    printf("\nSub-pohon:\n");
    for ( i = 0; i < countSubTree; i++)
    {
        // mencari simpul yang dimaksud
        node = findSimpul(subTree[i], T.root);
        // mencari level terdalam pada simpul yang dimaksud
        deepestLevel = deepestLevelOfTree(node, 1);
        // menghitung panjang string maksimal pada setiap levelnya
        for ( j = 1; j <= deepestLevel; j++)
        {
            longestSpacePerLevel[j] = spacePerLevel(node, 1, j);
        }
        printTreePreOrder(node, 0, longestSpacePerLevel, 1);
    }
    
    return 0;
}
