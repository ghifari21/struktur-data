/* N-er Tree */

#include <stdio.h>
#include <malloc.h>

typedef struct smp *simpulAddress;
typedef struct smp
{
    char container;
    simpulAddress sibling;
    simpulAddress child;
}simpul;

typedef struct
{
    simpul *root;
}tree;

void makeTree(char c, tree *T);
void addChild(char c, simpul *root);
void delAll(simpul *root);
void delChild(char c, simpul *root);
simpul* findsimpul(char c, simpul *root);
void printTreePreOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);

int main(){
    tree T;
    makeTree('A', &T);
    addChild('B', T.root);
    addChild('C', T.root);
    addChild('D', T.root);

    simpul *node = findsimpul('B', T.root);
    if (node != NULL)
    {
        addChild('E', node);
        addChild('F', node);
    }
    
    node = findsimpul('C', T.root);
    if (node != NULL)
    {
        addChild('G', node);
    }
    
    node = findsimpul('D', T.root);
    if (node != NULL)
    {
        addChild('H', node);
        addChild('I', node);
        addChild('J', node);
    }
    
    node = findsimpul('J', T.root);
    if (node != NULL)
    {
        addChild('K', node);
        addChild('L', node);
        addChild('M', node);
    }
    
    // printf("===============\n");
    // printf("preOrder\n");
    // printTreePreOrder(T.root);
    // printf("\n===============\n");
    // printf("postOrder\n");
    // printTreePostOrder(T.root);
    // printf("\n===============\n");

    // tree T2;
    // // copyTree(T.root, &T2.root);
    // makeTree('A', &T2);
    // addChild('B', T2.root);
    // addChild('C', T2.root);
    // addChild('D', T2.root);

    // node = findsimpul('B', T2.root);
    // if (node != NULL)
    // {
    //     addChild('E', node);
    //     addChild('F', node);
    // }
    
    // node = findsimpul('C', T2.root);
    // if (node != NULL)
    // {
    //     addChild('G', node);
    // }
    
    // node = findsimpul('D', T2.root);
    // if (node != NULL)
    // {
    //     addChild('H', node);
    //     addChild('I', node);
    //     addChild('J', node);
    // }
    
    // node = findsimpul('J', T2.root);
    // if (node != NULL)
    // {
    //     addChild('K', node);
    //     addChild('L', node);
    //     addChild('M', node);
    //     addChild('Z', node);
    // }
    // printf("===============\n");
    // printf("preOrder\n");
    // printTreePreOrder(T2.root);
    // printf("\n===============\n");
    // printf("postOrder\n");
    // printTreePostOrder(T2.root);
    // printf("\n===============\n");
    // if (isEqual(T.root, T2.root) == 1)
    // {
    //     printf("pohon sama\n");
    // }else
    // {
    //     printf("pohon tidak sama\n");
    // }
    
    // node = findsimpul('J', T.root);
    // if (node != NULL)
    // {
    //     delChild('K', node);
    //     delChild('L', node);
    //     delChild('M', node);
    // }

    // node = findsimpul('J', T.root);
    // if (node != NULL)
    // {
    //     // addChild('K', node);
    //     // addChild('L', node);
    //     delChild('M', node);
    // }

    delAll(T.root);
    printf("===============\n");
    printf("preOrder setelah dihapus\n");
    printTreePreOrder(T.root);
    printf("\n===============\n");
    printf("postOrder setelah dihapus\n");
    printTreePostOrder(T.root);
    printf("\n===============\n");
    // node = findsimpul('L', T.root);
    // printf("%c\n", node->sibling->container);

    return 0;
}

void makeTree(char c, tree *T){
    simpul *node = (simpul *) malloc (sizeof (simpul));
    node->container = c;
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(char c, simpul *root){
    if (root != NULL)
    {   /* jika simpul root tidak kosong,
        berarti dapat ditambahkan simpul anak */
        simpul *new = (simpul *) malloc (sizeof (simpul));
        new->container = c;
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
            {
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

void delChild(char c, simpul *root){
    if (root != NULL)
    {
        simpul *delete = root->child;
        if (delete != NULL)
        {   
            if (delete->sibling == NULL)
            {   // jika hanya mempunyai satu anak
                if (root->child->container == c)
                {
                    delAll(root->child);
                    root->child = NULL;
                }else
                {
                    printf("tidak ada simpul anak dengan kontainer nama masukan\n");
                }
            }else
            {   // jika memiliki lebih dari satu simpul anak
                simpul *prev = NULL;
                // mencari simpul yang akan dihapus
                int found = 0;
                while (delete->sibling != root->child && found == 0)
                {
                    if (delete->container == c)
                    {
                        found = 1;
                    }else
                    {
                        prev = delete;
                        delete = delete->sibling;
                    }
                }
                /* memproses simpul anak terakhir karena
                belum terproses dalam pengulangan */
                if (found == 0 && delete->container == c)
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
                    {
                        if (prev == root->child && last->sibling == root->child)
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
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
        }
    }
}

simpul* findsimpul(char c, simpul *root){
    simpul *result = NULL;
    if (root != NULL)
    {
        if (root->container == c)
        {
            result = root;
        }else
        {
            simpul *ptr = root->child;
            if (ptr != NULL)
            {
                if (ptr->sibling == NULL)
                {   // jika memiliki satu simpul anak
                    if (ptr->container == c)
                    {
                        result = ptr;
                    }else
                    {
                        result = findsimpul(c, ptr);
                    }
                }else
                {   // jika memiliki banyak simpul anak
                    int found = 0;
                    while (ptr->sibling != root->child && found == 0)
                    {
                        if (ptr->container == c)
                        {
                            result = ptr;
                            found = 1;
                        }else
                        {
                            result = findsimpul(c, ptr);
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
                        if (ptr->container == c)
                        {
                            result = ptr;
                        }else
                        {
                            result = findsimpul(c, ptr);
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
    {
        printf(" %c", root->container);
        simpul *ptr = root->child;
        if (ptr != NULL)
        {
            if (ptr->sibling == NULL)
            {   // jika memiliki satu simpul anak
                printTreePreOrder(ptr);
            }else
            {   // jika memiliki banyak simpul anak
                // mencetak simpul anak
                while (ptr->sibling != root->child)
                {
                    printTreePreOrder(ptr);
                    ptr = ptr->sibling;
                }
                /* memproses simpul anak terakhir
                karena belum terproses dalam perulangan */
                printTreePreOrder(ptr);
            }
        }
    }
}

void printTreePostOrder(simpul *root){
    if (root != NULL)
    {
        simpul *ptr = root->child;
        if (ptr != NULL)
        {
            if (ptr->sibling == NULL)
            {   // jika memiliki satu simpul anak
                printTreePostOrder(ptr);
            }else
            {   // jika memiliki banyak simpul anak
                // mencetak simpul anak
                while (ptr->sibling != root->child)
                {
                    printTreePostOrder(ptr);
                    ptr = ptr->sibling;
                }
                /* memproses simpul anak terakhir
                karena belum terproses dalam perulangan */
                printTreePostOrder(ptr);
            }
        }
        printf(" %c", root->container);
    }
}

void copyTree(simpul *root1, simpul **root2){
    if (root1 != NULL)
    {
        (*root2) = (simpul *) malloc (sizeof (simpul));
        (*root2)->container = root1->container;
        if (root1->sibling != NULL)
        {
            (*root2)->sibling = root1->sibling;
        }else
        {
            (*root2)->sibling = NULL;
        }
        if (root1->child != NULL)
        {
            (*root2)->child = root1->child;
        }else
        {
            (*root2)->child = NULL;
        }

        if (root1->child != NULL)
        {
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
    {
        if (root1->container != root2->container)
        {
            result = 0;
        }else
        {
            if (root1->child != NULL && root2->child != NULL)
            {
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
                        {
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