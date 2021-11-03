/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TM6 Statis    |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void createEmpty(stack *S){ // membuat stack
    (*S).top = -1;
}

int isEmpty(stack S){   
    int result = 0;
    if (S.top == -1)
    {   // jika S.top null
        result = 1;
    }
    return result;
}

int isFull(stack S){
    int result = 0;
    if (S.top == 9)
    {   // jika stack penuh
        result = 1;
    }
    return result;
}

void push(char name[], int price, stack *S){
    if (isFull(*S) == 1)
    {   // jika stack penuh
        printf("stack penuh\n");
    }else
    {
        if (isEmpty(*S) == 1)
        {   // jika stack kosong
            (*S).top = 0;
            strcpy((*S).data[0].name, name);
            (*S).data[0].price = price;
        }else
        {   // jika stack tidak kosong
            (*S).top++;
            strcpy((*S).data[(*S).top].name, name);
            (*S).data[(*S).top].price = price;
        }
    }
}

void pop(stack *S){
    if ((*S).top == 0)
    {   // jika stack berisi satu element
        (*S).top = -1;
    }else
    {
        if ((*S).top != -1)
        {   // jika stack tidak kosong
            (*S).top--;
        }
    }
}

void popToAnotherStack(stack *S1, stack *S2){
    /* push element S1 ke S2 kemudian pop S1 */
    push((*S1).data[(*S1).top].name, (*S1).data[(*S1).top].price, S2);
    pop(S1);
}

void printStack(stack S){
    if (S.top != -1)
    {   // jika stack tidak kosong
        int idx = 1;
        for (int i = S.top; i >= 0; i--)
        {
            printf("%d. %s\n", idx, S.data[i].name);
            idx++;
        }
    }else
    {   // jika stack kosong
        printf("- Stack Kosong\n");
    }
}