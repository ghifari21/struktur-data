/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TM5           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

int main(){
    list L;
    createList(&L);
    int i, j, count, col = 4;

    // input
    scanf("%d", &count);
    FC dataRow[count];
    player dataCol[count][col];
    for ( i = 0; i < count; i++)
    {
        scanf("%s %d", &dataRow[i].name, &dataRow[i].since); // baris
        for ( j = 0; j < col; j++)
        {
            scanf("%s", &dataCol[i][j].name); // kolom
        }
    }
    char tempA[50];
    int tempB;
    int k;
    // sorting berdasarkan tahun (ascending)
    for ( i = 0; i < count - 1; i++)
    {
        for ( j = i; j < count; j++)
        {
            if (dataRow[i].since > dataRow[j].since)
            {
                // baris
                strcpy(tempA, dataRow[i].name);
                strcpy(dataRow[i].name, dataRow[j].name);
                strcpy(dataRow[j].name, tempA);
                tempB = dataRow[i].since;
                dataRow[i].since = dataRow[j].since;
                dataRow[j].since = tempB;
                for ( k = 0; k < col; k++)
                {
                    // kolom
                    strcpy(tempA, dataCol[i][k].name);
                    strcpy(dataCol[i][k].name, dataCol[j][k].name);
                    strcpy(dataCol[j][k].name, tempA);
                }
            }
        }
    }

    // input data to list
    eRow* ptr;
    // row
    addFirstRow(dataRow[0].name, dataRow[0].since, &L);
    for ( i = count - 1; i > 0; i--)
    {
        addAfterRow(L.first, dataRow[i].name, dataRow[i].since);
    }
    // column
    for ( i = 0; i < count; i++)
    {
        ptr = findRow(L, dataRow[i].name); // mencari element yang dimaksud
        addLastColumn(dataCol[i][0].name, ptr);
        addFirstColumn(dataCol[i][1].name, ptr);
        addAfterColumn(ptr->col, dataCol[i][2].name);
        addLastColumn(dataCol[i][3].name, ptr);
    }

    delAfterColumn(L.first->next->col->nextCol);
    delLastRow(&L);
    delFirstColumn(L.first);
    
    printElement(L);    // output

    return 0;
}