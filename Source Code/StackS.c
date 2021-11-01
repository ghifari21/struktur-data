/* Stack Static */

#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char name[50];
    float nilai;
}nilaiMatkul;

typedef struct
{
    int top;
    nilaiMatkul data[10];
}stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void push(char nim[], char name[], float nilai, stack *S);
void pop(stack *S);
void printStack(stack S);

int main(){
    stack S;
    createEmpty(&S);
    printStack(S);
    printf("====================\n");
    push("13507701", "Nana", 64.75, &S);
    push("13507702", "Rudi", 75.11, &S);
    push("13507703", "Dea", 84.63, &S);
    printStack(S);
    printf("====================\n");
    pop(&S);
    pop(&S);
    printStack(S);
    printf("====================\n");

    return 0;
}

void createEmpty(stack *S){
    (*S).top = -1;
}

int isEmpty(stack S){
    int result = 0;
    if (S.top == -1)
    {
        result = 1;
    }
    return result;
}

int isFull(stack S){
    int result = 0;
    if (S.top == 9)
    {
        result = 1;
    }
    return result;
}

void push(char nim[], char name[], float nilai, stack *S){
    if (isFull(*S) == 1)
    {   // jika stack penuh
        printf("stack penuh\n");
    }else
    {
        if (isEmpty(*S) == 1)
        {   // jika stack kosong
            (*S).top = 0;
            strcpy((*S).data[0].nim, nim);
            strcpy((*S).data[0].name, name);
            (*S).data[0].nilai = nilai;
        }else
        {   // jika stack tidak kosong
            (*S).top++;
            strcpy((*S).data[(*S).top].nim, nim);
            strcpy((*S).data[(*S).top].name, name);
            (*S).data[(*S).top].nilai = nilai;
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

void printStack(stack S){
    if (S.top != -1)
    {   // jika stack tidak kosong
        printf("-----isi stack-----\n");
        for (int i = S.top; i >= 0; i--)
        {
            printf("====================\n");
            printf("element ke: %d\n", i);
            printf("nim: %s\n", S.data[i].nim);
            printf("nama: %s\n", S.data[i].name);
            printf("nilai: %f\n", S.data[i].nilai);
        }
        printf("--------------------\n");
    }else
    {   // jika stack kosong
        printf("stack kosong\n");
    }
}