#include "header.h"

void makeTree(data input, tree *T){
    // membuat tree
    simpul *node = (simpul *) malloc (sizeof (simpul));
    strcpy(node->container.name, input.name);
    node->container.grade = input.grade;
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(data input, simpul *root){
    if (root != NULL)
    {   /* jika simpul root tidak kosong,
        berarti dapat ditambahkan simpul anak */
        simpul *new = (simpul *) malloc (sizeof (simpul));
        strcpy(new->container.name, input.name);
        new->container.grade = input.grade;
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

void delAll(simpul *root){
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

void delChild(simpul *target, simpul *root){
    if (root != NULL)
    {   // jika simpul root tidak kosong
        simpul *delete = root->child;
        if (delete != NULL)
        {   // jika simpul delete tidak kosong
            if (delete->sibling == NULL)
            {   // jika hanya mempunyai satu anak
                if (strcmp(root->child->container.name, target->container.name) == 0)
                {   // jika target ditemukan
                    delAll(root->child);
                    root->child = NULL;
                }else
                {   // jika target tidak ditemukan
                    printf("tidak ada simpul anak dengan kontainer nama masukan\n");
                }
            }else
            {   // jika memiliki lebih dari satu simpul anak
                simpul *prev = NULL;
                // mencari simpul yang akan dihapus
                int found = 0;
                while (delete->sibling != root->child && found == 0)
                {
                    if (strcmp(delete->container.name, target->container.name) == 0)
                    {   // jika target ditemukan
                        found = 1;
                    }else
                    {   // jika target tidak ditemukan
                        prev = delete;
                        delete = delete->sibling;
                    }
                }
                /* memproses simpul anak terakhir karena
                belum terproses dalam pengulangan */
                if (found == 0 && strcmp(delete->container.name, target->container.name) == 0)
                {
                    found = 1;
                }
                if (found == 1)
                {
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
                    {   // jika simpul yang dihapus bukan anak pertama
                        if (prev == root->child && last->sibling == root->child)
                        {   /* jika hanya ada dua simpul
                            anak dan yang dihapus adalah simpul
                            anak kedua */
                            root->child->sibling = NULL;
                        }else
                        {   /* jika yang dihapus bukan
                            simpul anak pertama dan simpul root
                            memiliki simpul anak lebih dari dua simpul */
                            prev->sibling = delete->sibling;
                            delete->sibling = NULL;
                        }
                    }
                    delAll(delete);
                }else
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
        }
    }
}

simpul* findSimpul(char name[], simpul *root){
    simpul *result = NULL;
    if (root != NULL)
    {   // jika simpul root tidak kosong
        if (strcmp(root->container.name, name) == 0)
        {   // jika target ditemukan
            result = root;
        }else
        {   // jika target tidak ditemukan
            simpul *ptr = root->child;
            if (ptr != NULL)
            {   // jika simpul ptr tidak kosong
                if (ptr->sibling == NULL)
                {   // jika memiliki satu simpul anak
                    if (strcmp(ptr->container.name, name) == 0)
                    {   // jika target ditemukan
                        result = ptr;
                    }else
                    {   // jika target tidak ditemukan
                        result = findSimpul(name, ptr);
                    }
                }else
                {   // jika memiliki banyak simpul anak
                    int found = 0;
                    while (ptr->sibling != root->child && found == 0)
                    {
                        if (strcmp(ptr->container.name, name) == 0)
                        {   // jika target ditemukan
                            result = ptr;
                            found = 1;
                        }else
                        {   // jika target tidak ditemukan
                            result = findSimpul(name, ptr);
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
                        if (strcmp(ptr->container.name, name) == 0)
                        {   // jika target ditemukan
                            result = ptr;
                        }else
                        {   // jika target tidak ditemukan
                            result = findSimpul(name, ptr);
                        }
                    }
                }
            }
        }
    }
    return result;
}

void printTreePreOrder(simpul *root){
    if (root != NULL)
    {   // jika simpul root tidak kosong
        printf("%s %d", root->container.name, root->container.grade);
        simpul *ptr = root->child;
        if (ptr != NULL)
        {   // jika simpul ptr tidak kosong
            if (ptr->sibling == NULL)
            {   // jika memiliki satu simpul anak
                printf("-");
                printTreePreOrder(ptr);
            }else
            {   // jika memiliki banyak simpul anak
                // mencetak simpul anak
                while (ptr->sibling != root->child)
                {
                    printf("-");
                    printTreePreOrder(ptr);
                    ptr = ptr->sibling;
                }
                /* memproses simpul anak terakhir
                karena belum terproses dalam perulangan */
                printf("-");
                printTreePreOrder(ptr);
            }
        }
    }
}

void printTreePostOrder(simpul *root){
    if (root != NULL)
    {   // jika simpul root tidak kosong
        simpul *ptr = root->child;
        if (ptr != NULL)
        {   // jika simpul ptr tidak kosong
            if (ptr->sibling == NULL)
            {   // jika memiliki satu simpul anak
                printTreePostOrder(ptr);
                printf("-");
            }else
            {   // jika memiliki banyak simpul anak
                // mencetak simpul anak
                while (ptr->sibling != root->child)
                {
                    printTreePostOrder(ptr);
                    printf("-");
                    ptr = ptr->sibling;
                }
                /* memproses simpul anak terakhir
                karena belum terproses dalam perulangan */
                printTreePostOrder(ptr);
                printf("-");
            }
        }
        printf("%s %d", root->container.name, root->container.grade);
    }
}

void copyTree(simpul *root1, simpul **root2){
    if (root1 != NULL)
    {   // jika simpul root1 tidak kosong
        (*root2) = (simpul *) malloc (sizeof (simpul));
        (*root2)->container = root1->container;
        if (root1->sibling != NULL)
        {   // jika root1 mempunyai sibling
            (*root2)->sibling = root1->sibling;
        }else
        {   // jika root1 tidak mempunyai sibling
            (*root2)->sibling = NULL;
        }
        if (root1->child != NULL)
        {   // jika root1 mempunyai anak
            (*root2)->child = root1->child;
        }else
        {   // jika root1 tidak mempunyai anak
            (*root2)->child = NULL;
        }

        if (root1->child != NULL)
        {   // jika root1 memiliki anak
            if (root1->child->sibling == NULL)
            {   // jika memiliki satu simpul anak
                copyTree(root1->child, &(*root2)->child);
            }else
            {   // jika memiliki banyak simpul anak
                simpul *ptr1 = root1->child;
                simpul *ptr2 = (*root2)->child;
                while (ptr1->sibling != root1->child)
                {
                    copyTree(ptr1, &ptr2);
                    ptr1 = ptr1->sibling;
                    ptr2 = ptr2->sibling;
                }
                /* memproses simpul anak terakhir karena
                belum terproses dalam pengulangan */
                copyTree(ptr1, &ptr2);
            }
        }
    }
}

int isEqual(simpul *root1, simpul *root2){
    int result = 1;
    if (root1 != NULL && root2 != NULL)
    {   // jika simpul root1 dan root2 tidak kosong
        if (strcmp(root1->container.name, root2->container.name) != 0)
        {   // jika isi dari kedua tree berbeda
            result = 0;
        }else
        {   // jika isi dari kedua tree sama
            if (root1->child != NULL && root2->child != NULL)
            {   // jika simpul root1 dan root2 memiliki anak
                if (root1->child->sibling == NULL)
                {   // jika memiliki satu simpul anak
                    result = isEqual(root1->child, root2->child);
                }else
                {   // jika memiliki banyak simpul anak
                    simpul *ptr1 = root1->child;
                    simpul *ptr2 = root2->child;
                    while (ptr1->sibling != root1->child || ptr2->sibling != root2->child)
                    {
                        if (ptr1 != NULL && ptr2 != NULL)
                        {   // jika simpul ptr1 dan ptr2 tidak kosong
                            result = isEqual(ptr1, ptr2);
                            if (result == 0)
                            {
                                break;
                            }
                            ptr1 = ptr1->sibling;
                            ptr2 = ptr2->sibling;
                        }else
                        {
                            result = 0;
                            break;
                        }
                    }
                    /* memproses simpul anak terakhir
                    karena belum terproses dalam pengulangan */
                    if (result != 0)
                    {
                        result = isEqual(ptr1, ptr2);
                    }
                }
            }else
            {
                result = isEqual(root1->child, root2->child);
            }
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