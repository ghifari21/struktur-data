/* Graph */

#include <stdio.h>
#include <malloc.h>

typedef struct nd *nodeAddress;
typedef struct pth *pathAddress;

typedef struct nd
{
    char container;
    nodeAddress next;
    pathAddress arc;
}node;

typedef struct pth
{
    int pathContainer;
    pathAddress nextPath;
    node *destination;
}path;

typedef struct
{
    node* first;
}graph;

void createEmpty(graph *G);
void addNode(char c, graph *G);
void addPath(node *first, node *dest, int weight);
node* findNode(char c, graph G);
void delPath(char cDest, node *first);
void delAll(node *first);
void delNode(char c, graph *G);
void printGraph(graph G);

int main(int argc, char const *argv[])
{
    graph G;
    createEmpty(&G);
    addNode('A', &G);
    addNode('B', &G);
    addNode('C', &G);
    addNode('D', &G);
    addNode('E', &G);
    addNode('F', &G);

    node *begin = findNode('A', G);
    node *end = findNode('B', G);    
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 3);
    }

    begin = findNode('B', G);
    end = findNode('D', G);
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 3);
    }

    end = findNode('E', G);
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 7);
    }

    begin = findNode('C', G);
    end = findNode('A', G);
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 3);
    }

    begin = findNode('D', G);
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 8);
    }

    end = findNode('C', G);
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 3);
    }

    begin = findNode('E', G);
    end = findNode('D', G);
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 4);
    }

    end = findNode('F', G);
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 4);
    }

    begin = findNode('F', G);
    end = findNode('D', G);
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 2);
    }

    printf("=================\n");
    printGraph(G);
    printf("\n=================\n");

    begin = findNode('A', G);
    if (begin != NULL)
    {
        delPath('B', begin);
    }
    
    printf("=================\n");
    printf("setelah dihapus\n");
    printGraph(G);
    printf("\n=================\n");

    return 0;
}

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
        maka akan menambahkan simpul
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
            {
                found = 1;
            }else
            {
                prev = delete;
                delete = delete->nextPath;
            }
        }
        if (found == 1)
        {
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
        }else
        {
            printf("tidak ada jalur dengan simpul tujuan\n");
        }
    }else
    {
        printf("tidak ada jalur dengan simpul tujuan\n");
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
                if (delete->next = NULL)
                {   /* hapus simpul terakhir */
                    prev->next = NULL;
                }else
                {   /* hapus simpul di tengah */
                    prev->next = delete->next;
                    delete->next = NULL;
                }
                free(delete);
            }
        }else
        {
            printf("tidak ada simpul dengan info karakter masukan\n");
        }
    }else
    {
        printf("tidak ada simpul dengan info karakter masukan\n");
    }
}

void printGraph(graph G)
{
    node *ptr = G.first;

    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
            printf("simpul : %c\n", ptr->container);
            path *ptrPath = ptr->arc;
            while (ptrPath != NULL)
            {
                printf(" - ada jalur ke simpul : %c dengan beban : %d\n", ptrPath->destination->container, ptrPath->pathContainer);
                ptrPath = ptrPath->nextPath;
            }
            ptr = ptr->next;
        }
    }else
    {
        printf("graf kosong\n");
    }
}