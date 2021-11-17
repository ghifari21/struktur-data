/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TP4           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void createEmpty(queue *Q){
   // first dan last dibuat null
   (*Q).first = NULL;
   (*Q).last = NULL;
}

int isEmpty(queue Q){
   int result = 0;
   if (Q.first == NULL)
   {  // jika first null, maka queue kosong
      result = 1;
   }
   return result;
}

int countElement(queue Q){
   int result = 0;
   if (isEmpty(Q) != 1)
   {   // jika queue tidak kosong
      element *ptr = Q.first;
      while (ptr != NULL)
      {
         result++;
         ptr = ptr->next;
      }
   }
   return result;
}

void addNonMembership(char name[], char membership[], int time, queue *Q){
   element* new = (element *) malloc (sizeof (element));
   strcpy(new->container.name, name);
   strcpy(new->container.membership, membership);
   new->container.time = time;

   new->next = NULL;
   if (isEmpty(*Q) == 1)
   {   // jika queue kosong
      (*Q).first = new;
   }else
   {  // jika queue tidak kosong
      (*Q).last->next = new;
   }
   (*Q).last = new;
   new = NULL;
}

void addMembership(char name[], char membership[], int time, queue *Q){
   element* new = (element *) malloc (sizeof (element));
   strcpy(new->container.name, name);
   strcpy(new->container.membership, membership);
   new->container.time = time;
   new->next = NULL;

   if (isEmpty(*Q) == 1)
   {  // jika queue kosong
      (*Q).first = new;
      (*Q).last = new;
   }else
   {  // jika queue tidak kosong
      if (strcmp(new->container.membership, "platinum") == 0)
      {  // jika membershipnya adalah platinum
         if (strcmp((*Q).first->container.membership, "platinum") != 0)
         {  // jika firstnya bukan platinum, maka new akan menjadi first
            new->next = (*Q).first;
            (*Q).first = new;
         }else
         {  /* jika firstnya memiliki membership platinum,
            maka akan looping ujung dari barisan platinum,
            kemudian new ditaruh dibelakang platinum terakhir */
            element *ptr = (*Q).first;
            element *prev = NULL;
            while (ptr != NULL && strcmp(ptr->container.membership, "platinum") == 0)
            {
               prev = ptr;
               ptr = ptr->next;
            }
            new->next = prev->next;
            prev->next = new;
         }
      }else if (strcmp(new->container.membership, "gold") == 0)
      {  // jika membershipnya adalah gold
         if (strcmp((*Q).first->container.membership, "platinum") != 0 && strcmp((*Q).first->container.membership, "gold") != 0)
         {  // jika firstnya bukan platinum dan gold, maka new akan menjadi first
            new->next = (*Q).first;
            (*Q).first = new;
         }else
         {  /* jika first adalah platinum atau gold, maka akan looping dari
            sampai ujung platinum atau gold */
            element *ptr = (*Q).first;
            element *prev = NULL;
            if (strcmp(ptr->container.membership, "platinum") == 0)
            {  // jika ptr adalah platinum, maka akan looping sampai akhir barisan platinum
               while (ptr != NULL && strcmp(ptr->container.membership, "platinum") == 0)
               {
                  prev = ptr;
                  ptr = ptr->next;
               }
            }
            if (strcmp(ptr->container.membership, "gold") == 0)
            {  // jika ptr adalah gold, maka akan looping sampai akhir barisan gold
               while (ptr != NULL && strcmp(ptr->container.membership, "gold") == 0)
               {
                  prev = ptr;
                  ptr = ptr->next;
               }
            }
            new->next = prev->next;
            prev->next = new;
         }
      }else
      {  // jika membershipnya adalah silver
         if (strcmp((*Q).first->container.membership, "platinum") != 0 && strcmp((*Q).first->container.membership, "gold") != 0
            && strcmp((*Q).first->container.membership, "silver") != 0)
         {  // jika firstnya bukan platinum dan gold dan silver, maka new akan menjadi first
            new->next = (*Q).first;
            (*Q).first = new;
         }else
         {  /* jika first adalah platinum atau gold atau silver, maka akan looping dari
            sampai ujung platinum atau gold atau silver */
            element *ptr = (*Q).first;
            element *prev = NULL;
            if (strcmp(ptr->container.membership, "platinum") == 0)
            {  // jika ptr adalah platinum, maka akan looping sampai akhir barisan platinum
               while (ptr != NULL && strcmp(ptr->container.membership, "platinum") == 0)
               {
                  prev = ptr;
                  ptr = ptr->next;
               }
            }
            if (strcmp(ptr->container.membership, "gold") == 0)
            {  // jika ptr adalah gold, maka akan looping sampai akhir barisan gold
               while (ptr != NULL && strcmp(ptr->container.membership, "gold") == 0)
               {
                  prev = ptr;
                  ptr = ptr->next;
               }
            }
            if (strcmp(ptr->container.membership, "silver") == 0)
            {  // jika ptr adalah silver, maka akan looping sampai akhir barisan silver
               while (ptr != NULL && strcmp(ptr->container.membership, "silver") == 0)
               {
                  prev = ptr;
                  ptr = ptr->next;
               }
            }
            new->next = prev->next;
            prev->next = new;
         }
      }
   }
   new = NULL;
}

void processingQueue(queue *Q){
   element *ptr = (*Q).first;
   int timeTotal = 0;
   /* looping untuk menghitung waktu total kemudian di delete,
   batasnya adalah sampai barisan kosong atau waktu total 6 jam/360 menit */
   while (ptr != NULL && timeTotal <= 360)
   {
      timeTotal += ptr->container.time;
      if (timeTotal <= 360)
      {  // jika waktu total masih dibawah 6 jam/360 menit
         ptr = ptr->next;
         del(Q);
      }
   }
}

void del(queue *Q){
   if (isEmpty(*Q) != 1)
   {   // jika queue tidak kosong
      element *delete = (*Q).first;
      if (countElement(*Q) == 1)
      {  // jika banyaknya element hanya 1
         (*Q).first = NULL;
         (*Q).last = NULL;
      }else
      {  // jika queue memiliki lebih dari 1 element
         (*Q).first = (*Q).first->next;
         delete->next = NULL;
      }
      free(delete);
   }
}

void printQueue(queue Q){
   if (Q.first != NULL)
   {   // jika queue tidak kosong
      element* ptr = Q.first;
      while (ptr != NULL)
      {
         printf("%s\n", ptr->container.name);
         ptr = ptr->next;
      }
   }else
   {   // jika queue kosong
      printf("Antrian kosong.\n");
   }
}