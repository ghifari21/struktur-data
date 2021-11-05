/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TP3           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

int main()
{
    // membuat stack kosong
    stack Stotal, Spop, Srock;
    createEmpty(&Stotal);
    createEmpty(&Spop);
    createEmpty(&Srock);

    /* input data dari user dan masukan
    data ke dalam stack total */
    int count, i;
    scanf("%d", &count);
    recordSong data;
    for ( i = 0; i < count; i++)
    {
        scanf("%d %s %s", &data.year, &data.title, &data.bandName);
        push(data.year, data.title, data.bandName, &Stotal);
    }
    
    /* filter music untuk dimasukan ke dalam playlist mana
    berdasarkan nilai total ascii dari string judul lagu*/
    musicFilter(&Stotal, &Spop, &Srock);

    // output musik rock
    printf("Playlist Musik Rock:\n===================\n");
    if (isEmpty(Srock) == 1)
    {   // jika playlist rock kosong
        printf("BUKAN ANAK ROCK!\n");
    }else
    {   // jika playlist rock tidak kosong
        printStack(Srock);
    }
    // output musik pop
    printf("\nPlaylist Musik Pop:\n===================\n");
    if (isEmpty(Spop) == 1)
    {   // jika playlist pop kosong
        printf("BUKAN ANAK POP!\n");
    }else
    {   // jika playlist pop tidak kosong
        printStack(Spop);
    }
    

    return 0;
}
