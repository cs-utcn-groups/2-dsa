#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH_WORD 2005

typedef struct inTemplate
{
    char * string0;
    char * string1;

} inTemplate;

int nrTests;

int mini(int a, int b)
{
    if(a<b)
    {
        return a;
    }

    return b;
}

int min(int x, int y, int z)
{
    return mini(mini(x, y), z);
}

int editDistDP(char * str0, char * str1, int lenStr0, int lenStr1)
{

    int temp[lenStr0+5][lenStr1+5];
    memset(temp,0,sizeof(temp));

    for (int i = 0; i <= lenStr0; i++)
    {
        for (int j = 0; j <= lenStr1; j++)
        {

//            for (int i = 0; i <= lenStr0; i++)
//            {
//                for (int j = 0; j <= lenStr1; j++)
//                {
//                    printf("%d ",temp[i][j]);
//                }
//                printf("\n");
//            }
//
//            printf("\n\n");
/// I have just outputed the matrix, do not mind this

            if (i == 0)
            {
                temp[i][j] = j;
            }

            else if (j == 0)
            {
                temp[i][j] = i;
            }

            else if (str0[i - 1] == str1[j - 1])
            {
                temp[i][j] = temp[i - 1][j - 1];
            }

            else
            {
                temp[i][j] = 1 + min(temp[i][j - 1], temp[i - 1][j], temp[i - 1][j - 1]);
            }
        }
    }

    return temp[lenStr0][lenStr1];
}

inTemplate * read(FILE * f, inTemplate * in)
{
    fscanf(f,"%d",&nrTests);
    int a;
    fscanf(f,"%d",&a);
    in=(inTemplate *) malloc(sizeof(inTemplate) * nrTests);

    for(int i=0; i<nrTests; i++)
    {
        in[i].string0=(char *) malloc(MAX_LENGTH_WORD);
        in[i].string1=(char *) malloc(MAX_LENGTH_WORD);

        fgets(in[i].string0,MAX_LENGTH_WORD,f);
        in[i].string0[strlen(in[i].string0)-1]='\0';

        fgets(in[i].string1,MAX_LENGTH_WORD,f);
        in[i].string1[strlen(in[i].string1)-1]='\0';
    }
    return in;
}

int main()
{
    FILE * f=fopen("in.txt","r");

    inTemplate * input=NULL;
    input=read(f,input);

    for(int i=0; i<nrTests; i++)
    {
        printf("%d\n",editDistDP(input[i].string0, input[i].string1, strlen(input[i].string0), strlen(input[i].string1)));
    }

    free(input);
    fclose(f);

    return 0;
}
