/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan UTS (lolpkk21)|
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

int main(){
    list L;
    createList(&L); // membuat list
    int i, count;
    scanf("%d", &count);
    restaurant restoData;
    resMenu restoMenu;

    char flag[50];
    eRow* ptr;
    int end = 1;    // penanda looping
    for ( i = 0; i < count; i++)
    {
        scanf("%s", &flag); // start/end
        if (strcmp(flag, "start") == 0) // jika masukan nya start
        {
            scanf("%s", &restoData.name);
            addLastRow(restoData.name, &L);  // memasukan data row
            ptr = searchRow(L); // mencari row yang terakhir kali diinput
            do
            {
                scanf("%s", &restoMenu.name);
                if (strcmp(restoMenu.name, "end") != 0)   // jika inputan bukan end
                {
                    scanf("%d", &restoMenu.price);
                    addLastColumn(restoMenu.name, restoMenu.price, ptr);    // memasukan data column
                    end = 1;
                }else   // jika inputannya end maka akan keluar dari loop
                {
                    end = 0;
                }
            } while (end == 1);
        }
    }

    // input data yang ingin dipindahkan
    swappingTarget dataSwap;
    scanf("%s", &flag);
    end = 1;
    do
    {
        scanf("%s", &dataSwap.originResto);
        if (strcmp(dataSwap.originResto, "end") != 0)    // jika inputannya adalah bukan end
        {
            scanf("%s %s", &dataSwap.menuName, &dataSwap.targetResto);
            moveElementToTarget(dataSwap.originResto, dataSwap.menuName, dataSwap.targetResto, &L);    // menjalankan prosedur memindahkan element
            end = 1;
        }else   // jika inputannya adalah end maka akan keluar dari loop
        {
            end = 0;
        }
    } while (end == 1);
    
    printElement(L);    // output

    return 0;
}