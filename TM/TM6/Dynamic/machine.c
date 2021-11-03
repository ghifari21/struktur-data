/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TM6 Dinamis   |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void createEmpty(stack *S){ // membuat stack
    (*S).top = NULL;
}

int isEmpty(stack S){
    int result = 0;
    if (S.top == NULL)
    {   // jika stack kosong
        result = 1;
    }
    return result;   
}

int countElement(stack S){
    int result = 0;
    if (S.top != NULL)
    {   // jika stack tidak kosong
        element* ptr = S.top;
        while (ptr != NULL)
        {   // looping untuk menghitung banyak element
            result++;
            ptr = ptr->next;
        }
    }
    return result;
}

void push(char name[], int price, stack *S){
    // memasukan data ke stack
    element* new = (element *) malloc (sizeof (element));
    strcpy(new->container.name, name);
    new->container.price = price;

    if ((*S).top == NULL)
    {   // jika stack kosong
        new->next = NULL;
    }else
    {   // jika stack tidak kosong
        new->next = (*S).top;
    }
    (*S).top = new;
    new = NULL;
}

void pop(stack *S){
    if ((*S).top != NULL)
    {   // jika stack tidak kosong
        element *delete = (*S).top;
        if (countElement(*S) == 1)
        {   // jika stack hanya berisi satu element
            (*S).top = NULL;
        }else
        {   // jika stack berisi lebih dari satu element
            (*S).top = (*S).top->next;
        }
        delete->next = NULL;
        free(delete);
    }else
    {   // jika stack kosong
        printf("Stack Kosong\n");
    }
}

void popToAnotherStack(stack *S1, stack *S2){
    element* ptr1 = (*S1).top;
    /* push element S1 ke S2 kemudian pop S1 */
    push(ptr1->container.name, ptr1->container.price, S2);
    pop(S1);
}

void printStack(stack S){
    if (S.top != NULL)
    {   // jika stack tidak kosong
        element* ptr = S.top;
        int i = 1;
        while (ptr != NULL)
        {
            printf("%d. %s\n", i, ptr->container.name);
            ptr = ptr->next;
            i++;
        }
    }else
    {   // jika stack kosong
        printf("- Stack Kosong\n");
    }
}