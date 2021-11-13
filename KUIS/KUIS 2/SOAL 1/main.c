/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan Kuis          |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

int main()
{
    int i, countStack;
    scanf("%d", &countStack);   // banyak stack
    laundryRecord data;
    stack S[countStack];    // stack utama
    stack temp[countStack]; // stack temporary
    for ( i = 0; i < countStack; i++)   // create stack dan input element
    {
        createEmpty(&S[i]);
        createEmpty(&temp[i]);
        scanf("%s", &data.name);
        /* akan meminta input selama input
        yang diberikan bukanlah "0" */
        while (strcmp(data.name, "0") != 0)
        {
            scanf("%s", &data.name);
            if (strcmp(data.name, "0") != 0)
            {
                scanf("%s", &data.material);
                push(data.name, data.material, &S[i]);  // push kedalam stack utama
            }
        }
    }
    int countTake;
    scanf("%d", &countTake);    // banyak nama yang mengambil laundry
    char nameTake[countTake][50];
    for ( i = 0; i < countTake; i++)
    {
        scanf("%s", &nameTake[i]);
    }
    int idx = 1;
    // proses pengambilan & output stack utama
    for ( i = 0; i < countStack; i++)
    {
        moveStack(&S[i], &temp[i], countTake, nameTake);
        printf("stack %d:\n", idx);
        printStack(S[i]);
        printf("\n");
        idx++;
    }
    idx--;

    // output stack temporary
    for ( i = countStack-1; i >= 0; i--)
    {
        printf("batas stack %d\n", idx);
        printTemp(temp[i]);
        idx--;
    }

    return 0;
}
