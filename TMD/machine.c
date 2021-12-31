/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TMD           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void makeTree(char location[], int infectedCase, tree *T)
{
    simpul *node = (simpul *) malloc (sizeof (simpul));
    strcpy(node->container.locationName, location);
    node->container.infectedCase = infectedCase;
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(char location[], int infectedCase, simpul *root)
{
    if (root != NULL)
    {   /* jika simpul root tidak kosong,
        berarti dapat ditambahkan simpul anak */
        simpul *new = (simpul *) malloc (sizeof (simpul));
        strcpy(new->container.locationName, location);
        new->container.infectedCase = infectedCase;
        new->child = NULL;
        if (root->child == NULL)
        {   /* jika simpul root belum
            memiliki simpul anak maka simpul baru
            menjadi anak pertama */
            new->sibling = NULL;
            root->child = new;
        }else
        {
            if (root->child->sibling == NULL)
            {   /* jika simpul root memiliki
                anak yang belum memiliki saudara, maka
                simpul baru menjadi anak kedua */
                if (root->child->container.infectedCase < new->container.infectedCase)
                {   /* jika jumlah kasus anak pertama lebih kecil
                    daripada kasus simpul baru */
                    simpul *temp = root->child;
                    temp->sibling = new;
                    new->sibling = temp;
                    root->child = new;
                }else
                {   // jika kasus simpul baru lebih kecil daripada anak pertama
                    new->sibling = root->child;
                    root->child->sibling = new;
                }
            }else
            {   // jika memiliki banyak anak
                simpul *ptr  = root->child;
                int found = 0;
                while (ptr->sibling != root->child && found != 1)
                {   // mencari anak yang memiliki nilai kasus lebih kecil daripada simpul baru
                    if (ptr->container.infectedCase < new->container.infectedCase)
                    {   // jika jumlah kasus simpul ptr lebih kecil daripada simpul baru
                        found = 1;
                    }else
                    {   // jika tidak
                        ptr = ptr->sibling;
                    }
                }
                if (found == 0)
                {   // jika tidak ditemukan simpul yang lebih kecil daripada simpul baru
                    if (ptr->container.infectedCase < new->container.infectedCase)
                    {   // jika simpul ptr lebih kecil daripada simpul baru
                        root->child->sibling = new;
                        new->sibling = ptr;
                        ptr->sibling = root->child;
                    }else
                    {   // jika tidak
                        new->sibling = root->child;
                        ptr->sibling = new;
                    }
                }else
                {   // jika ditemukan simpul yang lebih kecil daripada simpul baru
                    if (ptr == root->child)
                    {   // jika simpul tersebut merupakan anak pertama
                        simpul *temp = root->child;
                        while (temp->sibling != root->child)
                        {
                            temp = temp->sibling;
                        }
                        root->child = new;
                        new->sibling = ptr;
                        temp->sibling = root->child;
                        
                    }else
                    {   // jika simpul tersebut bukan anak pertama
                        new->sibling = ptr->sibling;
                        ptr->sibling = new;
                    }
                }
            }
        }
    }
}

simpul* findSimpul(char location[], simpul *root)
{
    simpul *result = NULL;
    if (root != NULL)
    {   // jika simpul root tidak kosong
        if (strcmp(root->container.locationName, location) == 0)
        {
            result = root;
        }else
        {
            simpul *ptr = root->child;
            if (ptr != NULL)
            {
                if (ptr->sibling == NULL)
                {   // jika memiliki satu simpul anak
                    if (strcmp(ptr->container.locationName, location) == 0)
                    {
                        result = ptr;
                    }else
                    {
                        result = findSimpul(location, ptr);
                    }
                }else
                {   // jika memiliki banyak simpul anak
                    int found = 0;
                    while (ptr->sibling != root->child && found == 0)
                    {
                        if (strcmp(ptr->container.locationName, location) == 0)
                        {
                            result = ptr;
                            found = 1;
                        }else
                        {
                            result = findSimpul(location, ptr);
                            if (result != NULL)
                            {
                                found = 1;
                            }
                            ptr = ptr->sibling;
                        }
                    }
                    /* memproses simpul anak terakhir
                    karena belum terproses dalam perulangan */
                    if (found == 0)
                    {
                        if (strcmp(ptr->container.locationName, location) == 0)
                        {
                            result = ptr;
                        }else
                        {
                            result = findSimpul(location, ptr);
                        }
                    }
                }
            }
        }
    }
    return result;
}

int lenLib(int infectedCase)
{   // library panjang kasus
    if (infectedCase >= 10000000)
    {
        return 8;
    }else if (infectedCase >= 1000000)
    {
        return 7;
    }else if (infectedCase >= 100000)
    {
        return 6;
    }else if (infectedCase >= 10000)
    {
        return 5;
    }else if (infectedCase >= 1000)
    {
        return 4;
    }else if (infectedCase >= 100)
    {
        return 3;
    }else if (infectedCase >= 10)
    {
        return 2;
    }else if (infectedCase >= 0)
    {
        return 1;
    }
}

void printTreePreOrder(simpul *root, int currentSpace, int maxSpace[], int currentLevel)
{
    if (root != NULL)
    {   // jika simpul root tidak kosong
        printf("\n");
        if (currentSpace != 0)
        {   // jika banyak spasi bukan 0
            for (int i = 0; i < currentSpace; i++)
            {
                printf(" ");
            }
        }

        printf("|%s - %d\n", root->container.locationName, root->container.infectedCase);

        currentSpace += maxSpace[currentLevel]; // akses panjang string maksimal disetiap level dan dijumlahkan dengan currentSpace
        currentLevel++;
        simpul *ptr = root->child;
        if (ptr != NULL)
        {
            if (ptr->sibling == NULL)
            {   // jika memiliki satu simpul anak
                printTreePreOrder(ptr, currentSpace, maxSpace, currentLevel);
            }else
            {   // jika memiliki banyak simpul anak
                while (ptr->sibling != root->child)
                {
                    printTreePreOrder(ptr, currentSpace, maxSpace, currentLevel);
                    ptr = ptr->sibling;
                }
                /* memproses simpul anak terakhir
                karena belum terproses dalam perulangan */
                printTreePreOrder(ptr, currentSpace, maxSpace, currentLevel);
            }
        }
    }
}

int spacePerLevel(simpul *root, int currentLevel, int targetLevel)
{
    int space = 0;
    if (root != NULL)
    {   // jika simpul root tidak kosong
        if (currentLevel == targetLevel)
        {   // jika level saat ini sama dengan target
            if (space < strlen(root->container.locationName) + 4 + lenLib(root->container.infectedCase))
            {   // jika space lebih kecil daripada panjang string total
                space = strlen(root->container.locationName) + 4 + lenLib(root->container.infectedCase);
            }
        }else
        {
            currentLevel++;
            simpul *ptr = root->child;
            if (ptr != NULL)
            {   // jika simpul root mempunyai anak
                if (ptr->sibling == NULL)
                {   // jika memiliki satu simpul anak
                    if (space < spacePerLevel(ptr, currentLevel, targetLevel))
                    {
                        space = spacePerLevel(ptr, currentLevel, targetLevel);
                    }
                }else
                {   // jika memiliki banyak simpul anak
                    while (ptr->sibling != root->child)
                    {
                        if (space < spacePerLevel(ptr, currentLevel, targetLevel))
                        {
                            space = spacePerLevel(ptr, currentLevel, targetLevel);
                        }
                        ptr = ptr->sibling;
                    }
                    /* memproses simpul anak terakhir
                    karena belum terproses dalam perulangan */
                    if (space < spacePerLevel(ptr, currentLevel, targetLevel))
                    {
                        space = spacePerLevel(ptr, currentLevel, targetLevel);
                    }
                }
            }
        }
    }
    return space;
}

int deepestLevelOfTree(simpul *root, int currentLevel)
{
    int deepestLevel = 0;
    if (root != NULL)
    {   // jika simpul root tidak kosong
        deepestLevel = currentLevel;
        currentLevel++;
        simpul *ptr = root->child;
        if (ptr != NULL)
        {   // jika simpul root mempunyai anak
            if (ptr->sibling == NULL)
            {   // jika memiliki satu simpul anak
                if (deepestLevel < deepestLevelOfTree(ptr, currentLevel))
                {
                    deepestLevel = deepestLevelOfTree(ptr, currentLevel);
                }
            }else
            {   // jika memiliki banyak simpul anak
                while (ptr->sibling != root->child)
                {
                    if (deepestLevel < deepestLevelOfTree(ptr, currentLevel))
                    {
                        deepestLevel = deepestLevelOfTree(ptr, currentLevel);
                    }
                    ptr = ptr->sibling;
                }
                /* memproses simpul anak terakhir
                karena belum terproses dalam perulangan */
                if (deepestLevel < deepestLevelOfTree(ptr, currentLevel))
                {
                    deepestLevel = deepestLevelOfTree(ptr, currentLevel);
                }
            }
        }
    }
    return deepestLevel;
}

int calculatingInfectedCases(simpul *root)
{
    int infectedCase = 0;
    if (root != NULL)
    {   // jika simpul root tidak kosong
        infectedCase = root->container.infectedCase;
        simpul *ptr = root->child;
        if (ptr != NULL)
        {   // jika simpul root mempunyai anak
            if (ptr->sibling == NULL)
            {   // jika memiliki satu simpul anak
                infectedCase += calculatingInfectedCases(ptr);
            }else
            {   // jika memiliki banyak simpul anak
                while (ptr->sibling != root->child)
                {
                    infectedCase += calculatingInfectedCases(ptr);
                    ptr = ptr->sibling;
                }
                /* memproses simpul anak terakhir
                karena belum terproses dalam perulangan */
                infectedCase += calculatingInfectedCases(ptr);
            }
        }
    }
    return infectedCase;
}

void calculate(simpul *root)
{
    if (root != NULL)
    {   // jika simpul root tidak kosong
        root->container.infectedCase = calculatingInfectedCases(root);  // menghitung jumlah kasus anaknya
        simpul *ptr = root->child;
        if (ptr != NULL)
        {   // jika root mempunyai anak
            if (ptr->sibling == NULL)
            {   // jika memiliki satu simpul anak
                calculate(ptr);
            }else
            {   // jika memiliki banyak simpul anak
                while (ptr->sibling != root->child)
                {
                    calculate(ptr);
                    ptr = ptr->sibling;
                }
                /* memproses simpul anak terakhir
                karena belum terproses dalam perulangan */
                calculate(ptr);
            }
        }
    }
}