#include <stdio.h>
#include <stdbool.h>
int matrix[4][4];
int gAllStates[90000000][4][4];
int step=0;

bool IWasHereBefore()
{
    if(!step)
        return false;
    for(int i=0;i<step;++i)
    {
        for(int j=0;j<4;++j)
            for(int k=0;k<4;++k)
            {
                if(matrix[j][k]!=gAllStates[i][j][k])
                {
                    return false;
                }
            }
    }
    return true;
}

void printare()
{

    for(int i=0;i<4;++i,printf("\n"))
        for(int j=0;j<4;++j)
        {
            gAllStates[step][i][j]=matrix[i][j];
            printf("%d ",matrix[i][j]);
        }
    ++step;
    printf("\n");
}

bool IsSol()
{
    for(int i=0;i<4;++i)
        for(int j=0;j<3;++j)
            if(matrix[i][j]!=4*i+j+1)
                return false;
    return true;
}

void swap(int *a,int *b)
{
    int aux=*a;
    *a=*b;
    *b=aux;
}

void BackTracking(int x, int y, int FromX, int FromY)
{
    if(IWasHereBefore())
        return;
    printare();
    if(IsSol())
    {
        exit(0);
    }
    if(x+1<4 && x+1 != FromX )
    {
        swap(&matrix[x][y],&matrix[x+1][y]);
        BackTracking(x+1,y,x,y);
        swap(&matrix[x][y],&matrix[x+1][y]);
    }
    if(y+1<4 && y+1 != FromY)
    {
        swap(&matrix[x][y],&matrix[x][y+1]);
        BackTracking(x,y+1,x,y);
        swap(&matrix[x][y],&matrix[x][y+1]);
    }
    if(x-1>=0 && x-1 != FromX)
    {
        swap(&matrix[x][y],&matrix[x-1][y]);
        BackTracking(x-1,y,x,y);
        swap(&matrix[x][y],&matrix[x-1][y]);
    }
    if(y-1>=0 && y-1 != FromY)
    {
        swap(&matrix[x][y],&matrix[x][y-1]);
        BackTracking(x,y-1,x,y);
        swap(&matrix[x][y],&matrix[x][y-1]);
    }
}

int main()
{
    FILE *f=fopen("input.dat","r");
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            fscanf(f,"%d",&matrix[i][j]);
        }
    }
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
        {
            if(!matrix[i][j])
            {
                BackTracking(i,j,i,j);
                exit(0);
            }
        }
    //printf("Hello, World!\n");
    return 0;
}
