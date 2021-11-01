/* Stack Dynamic */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char nim[10];
    char name[50];
    float nilai;
}nilaiMatkul;

typedef struct elmt *elmtAddress;
typedef struct elmt
{
    nilaiMatkul container;
    elmtAddress next;
}element;

typedef struct
{
    element* top;
}stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
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
    (*S).top = NULL;
}

int isEmpty(stack S){
    int result = 0;
    if (S.top == NULL)
    {
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
        {
            result++;
            ptr = ptr->next;
        }
    }
    return result;
}

void push(char nim[], char name[], float nilai, stack *S){
    element* new = (element *) malloc (sizeof (element));
    strcpy(new->container.nim, nim);
    strcpy(new->container.name, name);
    new->container.nilai = nilai;

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
        {
            (*S).top = NULL;
        }else
        {
            (*S).top = (*S).top->next;
        }
        delete->next = NULL;
        free(delete);
    }else
    {   // jika stack kosong
        printf("stack kosong\n");
    }
}

void printStack(stack S){
    if (S.top != NULL)
    {   // jika stack tidak kosong
        printf("-----isi stack-----\n");
        element* ptr = S.top;
        int i = 1;
        while (ptr != NULL)
        {
            printf("====================\n");
            printf("element ke: %d\n", i);
            printf("nim: %s\n", ptr->container.nim);
            printf("nama: %s\n", ptr->container.name);
            printf("nilai: %f\n", ptr->container.nilai);
            ptr = ptr->next;
            i++;
        }
        printf("--------------------\n");
    }else
    {   // jika stack kosong
        printf("stack kosong\n");
    }
}