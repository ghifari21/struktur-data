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
                new->sibling = root->child;
                root->child->sibling = new;
            }else
            {
                simpul *last  = root->child;
                /* mencari simpul anak terakhir
                karena akan dikaitkan dengan simpul
                baru sebagai simpul anak terakhir yang
                baru, simpul anak terakhir adalah yang
                memiliki sibling simpul anak pertama,
                maka selama belum samapi pada simpul
                anak terakhir, penunjuk last akan
                berjalan ke simpul anak berikutnya */
                while (last->sibling != root->child)
                {
                    last = last->sibling;
                }
                new->sibling = root->child;
                last->sibling = new;
            }
        }
    }
}

simpul* findSimpul(char location[], simpul *root)
{
    simpul *result = NULL;
    if (root != NULL)
    {
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
{
    if (infectedCase >= 10000)
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

void printTreePreOrder(simpul *root, int space)
{
    if (root != NULL)
    {
        if (space != 0)
        {
            for (int i = 0; i < space; i++)
            {
                printf(" ");
            }
        }
        printf("|%s - %d - %d\n", root->container.locationName, root->container.infectedCase, space);
        
        //printf("%d", space);
        simpul *ptr = root->child;
        space += maxSpacePerLevel(root);
        if (ptr != NULL)
        {
            //space += strlen(root->container.locationName) + 4 + lenLib(root->container.infectedCase);
            if (ptr->sibling == NULL)
            {   // jika memiliki satu simpul anak
                //space += strlen(root->container.locationName) + 4 + lenLib(root->container.infectedCase);
                printTreePreOrder(ptr, space);
            }else
            {   // jika memiliki banyak simpul anak
                //space += strlen(root->container.locationName) + 4 + lenLib(root->container.infectedCase);
                while (ptr->sibling != root->child)
                {
                    printTreePreOrder(ptr, space);
                    ptr = ptr->sibling;
                }
                /* memproses simpul anak terakhir
                karena belum terproses dalam perulangan */
                printTreePreOrder(ptr, space);
            }
        }
    }
}

int maxSpacePerLevel(simpul *root)
{
    int maxSpace = 0;
    if (root != NULL)
    {
        simpul *ptr = root;
        if (ptr->sibling != NULL)
        {
            while (ptr->sibling != root)
            {
                if (maxSpace < strlen(ptr->container.locationName) + 4 + lenLib(ptr->container.infectedCase))
                {
                    maxSpace = strlen(ptr->container.locationName) + 4 + lenLib(ptr->container.infectedCase);
                }
                // printf("%s", root->container.locationName);
                ptr = ptr->sibling;
            }
        }
        if (maxSpace < strlen(ptr->container.locationName) + 4 + lenLib(ptr->container.infectedCase))
        {
            maxSpace = strlen(ptr->container.locationName) + 4 + lenLib(ptr->container.infectedCase);
        }
    }
    return maxSpace;
}

void calculatinginfectedCases(simpul *root, int infectedCase)
{
    if (root != NULL)
    {
        simpul *ptr = root->child;
        if (ptr != NULL)
        {
            if (ptr->sibling == NULL)
            {   // jika memiliki satu simpul anak
                calculatinginfectedCases(ptr, infectedCase);
                //infectedCase += ptr->container.infectedCase;
            }else
            {   // jika memiliki banyak simpul anak
                // mencetak simpul anak
                while (ptr->sibling != root->child)
                {
                    calculatinginfectedCases(ptr, ptr->container.infectedCase);
                    infectedCase += ptr->container.infectedCase;
                    ptr = ptr->sibling;
                }
                /* memproses simpul anak terakhir
                karena belum terproses dalam perulangan */
                calculatinginfectedCases(ptr, ptr->container.infectedCase);
                //infectedCase += ptr->container.infectedCase;
            }
            infectedCase += ptr->container.infectedCase;
        }
        root->container.infectedCase = infectedCase;
    }
}

void sortingNode(simpul *root)
{
    if (root != NULL)
    {
        simpul *ptr = root->child;
        if (ptr != NULL)
        {
            if (ptr->sibling == NULL)
            {   // jika memiliki satu simpul anak
                sortingNode(ptr);
            }else
            {   // jika memiliki banyak simpul anak
                while (ptr->sibling != root->child)
                {
                    if (ptr->container.infectedCase < ptr->sibling->container.infectedCase)
                    {
                        swapNode(ptr, ptr->sibling, root);
                    }
                    sortingNode(ptr);
                    ptr = ptr->sibling;
                }
                /* memproses simpul anak terakhir
                karena belum terproses dalam perulangan */
                sortingNode(ptr);
            }
        }
    }
}

void swapNode(simpul *root1, simpul *root2, simpul *parent)
{
    simpul *ptr1 = parent->child;
    simpul *prev1 = NULL;
    int found = 0;
    while (found == 1)
    {
        if (ptr1->sibling != parent->child && ptr1 == root1)
        {
            prev1 = ptr1;
            ptr1 = ptr1->sibling;
            found == 1;
        }else
        {
            if (ptr1 == root1)
            {
                found == 1;
            }
        }
    }
    
}