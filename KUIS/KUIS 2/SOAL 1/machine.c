/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan Kuis          |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void createEmpty(stack *S){
    (*S).top = -1;  // set top menjadi null
}

int isEmpty(stack S){
    int result = 0;
    if (S.top == -1)
    {   // jika top = null, maka stack kosong
        result = 1;
    }
    return result;
}

int isFull(stack S){
    int result = 0;
    if (S.top == 50)
    {   // jika top = 50 maka stack penuh
        result = 1;
    }
    return result;
}

void push(char name[], char material[], stack *S){
    if (isFull(*S) == 1)
    {   // jika stack penuh
        printf("stack penuh\n");
    }else
    {
        if (isEmpty(*S) == 1)
        {   // jika stack kosong
            (*S).top = 0;
            strcpy((*S).data[0].name, name);
            strcpy((*S).data[0].material, material);
        }else
        {   // jika stack tidak kosong
            (*S).top++;
            strcpy((*S).data[(*S).top].name, name);
            strcpy((*S).data[(*S).top].material, material);
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

void moveStack(stack *S, stack *temp, int countTake, char nameTake[][50]){
    int i, j, total = 0;
    /* menghitung ada berapa nama yang
    akan dikeluarkan didalam stack */
    for ( i = (*S).top; i >= 0; i--)
    {
        for ( j = 0; j < countTake; j++)
        {
            if (strcmp((*S).data[i].name, nameTake[j]) == 0)
            {
                total++;
            }
        }
    }

    /* akan mengeluarkan element yang dipilih,
    dan memasukan element yang ada diatas nama
    yang dipilih kedalam stack temporary */
    int flag, found = 0;
    i = (*S).top;
    while (found != total)
    {
        flag = 0;
        for ( j = 0; j < countTake; j++)
        {
            if (strcmp((*S).data[i].name, nameTake[j]) == 0)
            {
                pop(S);
                flag = 0;
                found++;
                break;
            }else
            {
                flag = 1;
            }
        }
        /* jika element dalam stack bukanlah
        nama yang dipilih, maka element tersebut
        akan dipindahkan ke stack temporary */
        if (flag == 1)
        {
            push((*S).data[i].name, (*S).data[i].material, temp);   // push element stack utama ke stack temporary
            pop(S); // delete top
        }
        i--;
    }
}

void printStack(stack S){
    if (S.top != -1)
    {   // jika stack tidak kosong
        for (int i = S.top; i >= 0; i--)
        {
            printf("%s %s\n", S.data[i].name, S.data[i].material);
        }
    }else
    {   // jika stack kosong
        printf("kosong\n");
    }
}

void printTemp(stack S){
    if (S.top != -1)
    {   // jika stack tidak kosong
        for (int i = S.top; i >= 0; i--)
        {
            printf("%s %s\n", S.data[i].name, S.data[i].material);
        }
    }
}