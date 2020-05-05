#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int min(int x,int y,int z)
{
    if(x<=y && x<=z)
    {
        return x;
    }
    else if(y<=x && y<=z)
    {
        return y;
    }
    else return z;
}
int minOps(char *str1,char *str2)
{
    int len1=strlen(str1);
    int len2=strlen(str2);
    int opr[len1+1][len2+1];
    for(int i=0;i<len1;i++)
    {
        opr[i][0]=i;
    }
    for(int j=0;j<len2;j++)
    {
        opr[0][j]=j;
    }
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                opr[i][j]=opr[i-1][j-1];
            }
            else
            {
               opr[i][j]=min(opr[i-1][j]+1,opr[i][j-1]+1,opr[i-1][j-1]+1);
            }
        }
    }
    return opr[len1][len2];
}

int main()
{
   int t;
   printf("Enter test cases: ");
   scanf("%d",&t);
   for(int i=0;i<t;i++)
   {
        char *str1=(char*)malloc(sizeof(char)*2000);
        char *str2=(char*)malloc(sizeof(char)*2000);
        printf("Enter strings: \n");
        scanf("%s",str1);
        scanf("%s",str2);
        int NrOp = minOps(str1,str2);
        printf("\n%d\n",NrOp);

   }
    return 0;
}
