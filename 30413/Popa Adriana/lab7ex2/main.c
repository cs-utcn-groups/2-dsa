#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f=fopen("input.txt","r");
    int n=10,m=10,i,j,k;
    int a[n][n],v[n];
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            a[i][j]=0;
    char *strbuf=(char*)malloc(sizeof(char));
    char *p=(char*)malloc(sizeof(char));

    j=0;
    fgets(strbuf,100,f);
    p=strtok(strbuf," ");
    while(p!=NULL)
    {
        i=atoi(p);
        v[j++]=i;
        p=strtok(NULL," ");
    }
    n=j;
    fgets(strbuf,100,f);
    p=strtok(strbuf," ");
    while(p!=NULL)
    {
        if(p[0]=='(')
        {
            i=p[1]-'0';
            for(k=0; k<n; k++)
                if(v[k]==i)
                {
                    i=k;
                }
        }
        else
        {
            j=p[0]-'0';
            for(k=0; k<n; k++)
                if(v[k]==j)
                    j=k;
            a[i][j]=1;
            a[j][i]=1;
        }
        p=strtok(NULL," ");
    }
    j=0;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }


    return 0;
}
