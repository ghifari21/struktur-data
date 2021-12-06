/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TP5           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void makeTree(char str[], tree *T)
{
    simpul *node = (simpul *) malloc (sizeof (simpul));
    strcpy(node->container, str);
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(char str[], simpul *root)
{
    if (root != NULL)
    {   /* jika simpul root tidak kosong,
        berarti dapat ditambahkan simpul anak */
        simpul *new = (simpul *) malloc (sizeof (simpul));
        strcpy(new->container, str);
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

void delAll(simpul *root)
{
    if (root != NULL)
    {   // jika simpul root tidak kosong
        if (root->child != NULL)
        {
            if (root->child->sibling == NULL)
            {   // jika hanya memiliki satu simpul anak
                delAll(root->child);
                free(root);
            }else
            {   // jika memiliki lebih dari satu simpul anak
                simpul *ptr = root->child;
                simpul *process;
                while (ptr->sibling != root->child)
                {
                    process = ptr;
                    ptr = ptr->sibling;
                    delAll(process);
                }
                delAll(ptr);
            }
            free(root);
        }else
        {
            free(root);
        }
    }
}

void delChild(char str[], simpul *root)
{
    if (root != NULL)
    {   // jika simpul root tidak kosong
        simpul *delete = root->child;
        if (delete != NULL)
        {   // jika simpul delete tidak kosong
            if (delete->sibling == NULL)
            {   // jika hanya mempunyai satu anak
                if (strcmp(root->child->container, str) == 0)
                {   // jika ketemu
                    delAll(root->child);
                    root->child = NULL;
                }else
                {   // jika tidak ketemu
                    printf("tidak ada simpul anak dengan kontainer nama masukan\n");
                }
            }else
            {   // jika memiliki lebih dari satu simpul anak
                simpul *prev = NULL;
                // mencari simpul yang akan dihapus
                int found = 0;
                while (delete->sibling != root->child && found == 0)
                {
                    if (strcmp(delete->container, str) == 0)
                    {   // jika ketemu
                        found = 1;
                    }else
                    {   // jika tidak ketemu
                        prev = delete;
                        delete = delete->sibling;
                    }
                }
                /* memproses simpul anak terakhir karena
                belum terproses dalam pengulangan */
                if (found == 0 && strcmp(delete->container, str) == 0)
                {   /* jika status ketemu masih false dan simpul
                    anak terakhir merupakan element yang ingin
                    dihapus */
                    found = 1;
                }
                if (found == 1)
                {   // jika ketemu element yang ingin dihapus
                    simpul *last = root->child;
                    /* mencari simpul anak terakhir untuk
                    membantu proses atau pemeriksaan jika yang
                    dihapus nantinya anak terahir */
                    while (last->sibling != root->child)
                    {
                        last = last->sibling;
                    }
                    if (prev == NULL)
                    {   // jika simpul yang dihapus anak pertama
                        if (delete->sibling == last && last->sibling == root->child)
                        {   // jika hanya ada dua anak
                            root->child = last;
                            last->sibling = NULL;
                        }else
                        {   // jika memiliki simpul anak lebih dari dua simpul
                            root->child = delete->sibling;
                            last->sibling = root->child;
                        }
                    }else
                    {
                        if (prev == root->child && last == delete)
                        {   /* jika hanya ada dua simpul
                            anak dan yang dihapus adalah simpul
                            anak kedua */
                            root->child->sibling = NULL;
                        }else
                        {   /* jika yang dihapus bukan
                            simpul anak pertama dan simpul root
                            memiliki simpul anak lebih dari dua simpul*/
                            prev->sibling = delete->sibling;
                            delete->sibling = NULL;
                        }
                    }
                    delAll(delete);
                }else
                {   // jika element yang ingin dihapus tidak ditemukan
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
        }
    }
}

simpul* findSimpul(char str[], simpul *root)
{
    simpul *result = NULL;
    if (root != NULL)
    {   // jika simpul root tidak kosong
        if (strcmp(root->container, str) == 0)
        {   // jika ketemu
            result = root;
        }else
        {   // jika tidak ketemu
            simpul *ptr = root->child;
            if (ptr != NULL)
            {   // jika simpul ptr tidak kosong
                if (ptr->sibling == NULL)
                {   // jika memiliki satu simpul anak
                    if (strcmp(ptr->container, str) == 0)
                    {   // jika ketemu
                        result = ptr;
                    }else
                    {   // jika tidak ketemu
                        result = findSimpul(str, ptr);
                    }
                }else
                {   // jika memiliki banyak simpul anak
                    int found = 0;
                    while (ptr->sibling != root->child && found == 0)
                    {
                        if (strcmp(ptr->container, str) == 0)
                        {   // jika ketemu
                            result = ptr;
                            found = 1;
                        }else
                        {   // jika tidak ketemu
                            result = findSimpul(str, ptr);
                            if (result != NULL)
                            {   // jika ketemu
                                found = 1;
                            }
                            ptr = ptr->sibling;
                        }
                    }
                    /* memproses simpul anak terakhir
                    karena belum terproses dalam perulangan */
                    if (found == 0)
                    {   // jika tidak ketemu
                        if (strcmp(ptr->container, str) == 0)
                        {   // jika simpul anak terakhir adalah simpul anak yang dicari
                            result = ptr;
                        }else
                        {   // jika bukan
                            result = findSimpul(str, ptr);
                        }
                    }
                }
            }
        }
    }
    return result;
}

void printTreePreOrder(simpul *root, int space)
{
    if (root != NULL)
    {   // jika simpul root tidak kosong
        if (space != 0)
        {   // jika space tidak 0
            for (int i = 0; i < space; i++)
            {
                printf("->");
            }
        }
        printf("%s\n", root->container);
        
        simpul *ptr = root->child;
        if (ptr != NULL)
        {   // jika simpul ptr tidak kosong
            if (ptr->sibling == NULL)
            {   // jika memiliki satu simpul anak
                space += 1;
                printTreePreOrder(ptr, space);
            }else
            {   // jika memiliki banyak simpul anak
                // mencetak simpul anak
                space += 1;
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