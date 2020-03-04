#include "head.h"
#include <string.h>


int main()
{
    initializeList();
    /*AF(5);
    AF(6);
    AF(21);
    AL(12);
    DF();
    DL();
    DE(3);
    DE(5);
    AF(2);
    AL(200);
    PRINT_ALL();
    AF(1);
    PRINT_ALL();
    PRINT_F(2);
    PRINT_L(3);
    DOOM_THE_LIST();
    DL();
    AF(42);
    AL(24);
    AF(9);
    PRINT_ALL();
    PRINT_L(2);*/

    FILE *f=fopen("input.txt","rw");
    FILE *o=fopen("output.txt","rw");
    char *s1=(char*)malloc(sizeof(char)*100);
    char *s2=(char*)malloc(sizeof(char)*100);
    ///char aux[100];
    while(fscanf(f,"%s",s1)!=EOF)
    {
        int nr=0;
        if(strstr(s1,"AF")!=0)
        {
            for(int i=0; i<strlen(s1); i++)
            {
                if(s1[i]>='0'&&s1[i]<='9')
                {

                    s2[nr]=s1[i];
                    nr++;

                }
            }
            s2[nr]='\0';
            AF(atoi(s2));
            ///PRINT_ALL();
            continue;
        }




        if(strstr(s1,"AddL")!=0)
        {
            for(int i=0; i<strlen(s1); i++)
            {
                if(s1[i]>='0'&&s1[i]<='9')
                {

                    s2[nr]=s1[i];
                    nr++;

                }
            }
            s2[nr]='\0';
            AddL(atoi(s2));
            ///PRINT_ALL();
            continue;
        }





        if(strstr(s1,"DE")!=0)
        {
            for(int i=0; i<strlen(s1); i++)
            {
                if(s1[i]>='0'&&s1[i]<='9')
                {

                    s2[nr]=s1[i];
                    nr++;

                }
            }
            s2[nr]='\0';
            DE(atoi(s2));
            ///PRINT_ALL();
            continue;
        }






        if(strstr(s1,"PRINT_L")!=0)
        {
            for(int i=0; i<strlen(s1); i++)
            {
                if(s1[i]>='0'&&s1[i]<='9')
                {

                    s2[nr]=s1[i];
                    nr++;

                }
            }
            s2[nr]='\0';
            PRINT_L(atoi(s2));
            ///PRINT_ALL();
            continue;
        }




        if(strstr(s1,"PRINT_F")!=0)
        {
            for(int i=0; i<strlen(s1); i++)
            {
                if(s1[i]>='0'&&s1[i]<='9')
                {

                    s2[nr]=s1[i];
                    nr++;

                }
            }
            s2[nr]='\0';
            PRINT_F(atoi(s2));
            ///PRINT_ALL();
            continue;
        }






        if(strstr(s1,"DL")!=0)
        {
            DL();
            ///PRINT_ALL();
            continue;
        }






        if(strstr(s1,"DOOM")!=0)
        {
            DOOM_THE_LIST();
            ///PRINT_ALL();
            ///continue;
        }






        if(strstr(s1,"PRINT_ALL")!=0)
        {
            PRINT_ALL();
           /// continue;
        }


        if(strstr(s1,"DF")!=0)
        {
            DF();
            ///PRINT_ALL();
            continue;
        }




    }
    return 0;
}
