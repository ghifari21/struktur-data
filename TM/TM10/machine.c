#include "header.h"

void createEmpty(graph *G)
{
    (*G).first = NULL;
}

void addNode(char c, graph *G)
{
    node *new = (node*)malloc(sizeof(node));
    new->container = c;
    new->next = NULL;
    new->arc = NULL;

    if ((*G).first == NULL)
    {   // jika graph kosong
        (*G).first = new;
    }else
    {   /* jika graf tidak kosong
        maka akan menambahkan node
        baru pada akhir graph */
        node *last = (*G).first;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new;
    }
}

void addPath(node *first, node *dest, int weight)
{
    path *new = (path*)malloc(sizeof(path));
    new->pathContainer = weight;
    new->nextPath = NULL;
    new->destination = dest;

    if (first->arc == NULL)
    {   // jika list jalur kosong
        first->arc = new;
    }else
    {   /* jika list jalur tidak kosong
        maka akan menambahkan jalur baru
        pada akhir list jalur */
        path *last = first->arc;
        while (last->nextPath != NULL)
        {
            last = last->nextPath;
        }
        last->nextPath = new;
    }
}

node* findNode(char c, graph G)
{
    node *result = NULL;
    node *ptr = G.first;
    
    int found = 0;
    while (ptr != NULL && found == 0)
    {   // looping sampai menemukan c atau list sudah habis
        if (ptr->container == c)
        {   // jika ketemu c
            result = ptr;
            found = 1;
        }else
        {   // jika tidak ketemu c
            ptr = ptr->next;
        }
    }
    return result;
}

void delPath(char cDest, node *first)
{
    path *delete = first->arc;
    if (delete != NULL)
    {   // jika delete tidak kosong
        path *prev = NULL;

        // mencari jalur yang akan dihapus
        int found = 0;
        while (delete != NULL && found == 0)
        {
            if (delete->destination->container == cDest)
            {   // jika ketemu
                found = 1;
            }else
            {
                prev = delete;
                delete = delete->nextPath;
            }
        }
        if (found == 1)
        {   // jika ketemu
            if (prev == NULL)
            {
                first->arc = delete->nextPath;
                delete->nextPath = NULL;
            }else
            {
                if (delete->nextPath == NULL)
                {
                    prev->nextPath = NULL;
                }else
                {
                    prev->nextPath = delete->nextPath;
                    delete->nextPath = NULL;
                }
            }
            free(delete);
        }
    }
}

void delAll(node *first)
{
    path *ptr = first->arc;
    path *delete;
    while (ptr != NULL)
    {
        delete = ptr;
        ptr = ptr->nextPath;
        first->arc = ptr;
        delete->nextPath = NULL;
        free(delete);
    }
}

void delNode(char c, graph *G)
{
    node *delete = (*G).first;
    if (delete != NULL)
    {
        node *prev = NULL;
        /* mencari simpul yang akan dihapus */
        int found = 0;
        while (delete != NULL && found == 0)
        {
            if (delete->container == c)
            {
                found = 1;
            }else
            {
                prev = delete;
                delete = delete->next;
            }
        }
        if (found == 1)
        {
            /* jika simpul yang akan dihapus ada */
            /* hapus semua jalur dari simpul lain
            yang mengarah pada simpul yang dihapus */
            node *ptr = (*G).first;

            /* memeriksa semua simpul dalam graf */
            while (ptr != NULL)
            {   /* jika simpul yang ditelusuri tidak
                sama dengan yang dihapus */
                if (ptr != delete)
                {   /* hapus semua jalur yang mengarah
                    pada simpul yang dihapus */
                    delPath(delete->container, ptr);
                }
                ptr = ptr->next;
            }
            /* hapus semua jalur */
            delAll(delete);

            if (prev == NULL)
            {   /* hapus simpul pertama */
                (*G).first = delete->next;
                delete->next = NULL;
            }else
            {
                if (delete->next == NULL)
                {   /* hapus simpul terakhir */
                    prev->next = NULL;
                }else
                {   /* hapus simpul di tengah */
                    prev->next = delete->next;
                    delete->next = NULL;
                }
                free(delete);
            }
        }
    }
}

void printGraph(graph G)
{
    node *ptr = G.first;

    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
            printf("Node %c\n", ptr->container);
            path *ptrPath = ptr->arc;
            while (ptrPath != NULL)
            {
                printf("Jalur %c ke %c\n", ptr->container, ptrPath->destination->container);
                ptrPath = ptrPath->nextPath;
            }
            ptr = ptr->next;
        }
    }else
    {
        printf("graf kosong\n");
    }
}