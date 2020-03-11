#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"head.h"


int main()
{
   initialize();
   char s[200];
   int nr = 0;
   FILE* f = fopen("input.txt", "r");


   if (f)
   {
      while (fgets(s, 200, f) != NULL)
      {
         char* p = strtok(s, " \n");
         if (strcmp(p, "AF") == 0)
         {
            p = strtok(NULL, " \n");
            nr = strtol(p, NULL, 10);
            addElementi(nr);
            printf("%d ", nr);

         }
         else if (strcmp(p, "AL") == 0)
         {
            p = strtok(NULL, " \n");
            nr = strtol(p, NULL, 10);
            addElementf(nr);
            printf("%d ", nr);

         }
         else if (strcmp(p, "DF") == 0)
         {
            erasei();
         }
         else if (strcmp(p, "DL") == 0)
         {
            erasef();
         }
         else if (strcmp(p, "DOOM_THE_LIST") == 0)
         {
            eraseAll();
         }
         else if (strcmp(p, "DE") == 0)
         {
            p = strtok(NULL, " \n");
            nr = strtol(p, NULL, 10);
            eraseElement(nr);
            printf("%d ", nr);

         }
         else if (strcmp(p, "PRINT_ALL") == 0)
         {
            print();
         }
         else if (strcmp(p, "PRINT_F") == 0)
         {
            p = strtok(NULL, " \n");
            nr = strtol(p, NULL, 10);
            printIx(nr);
            printf("%d ", nr);

         }
         else if (strcmp(p, "PRINT_L") == 0)
         {
            p = strtok(NULL, " \n");
            nr = strtol(p, NULL, 10);
            printFx(nr);
            printf("%d ", nr);
         }
      }
      return 0;
   }
}
