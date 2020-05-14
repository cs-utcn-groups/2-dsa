#include <stdio.h>
#include <stdlib.h>
#define N 4
int matrice[N][N];
int matrix[1000000][N][N];
int contor=0;
int verficare()
{

    for(int i=0;i<N;++i)
        for(int j=0;j<N-1;++j)
            if(matrice[i][j]!=4*i+j)
                return 0;


     return 1;
}

int ok()
{
    int calcul=0;
    for(int k=0;k<contor;++k)
    {
        for(int i=0;i<N;++i)
            for(int j=0;j<N-1;++j)
                if(matrice[i][j]==matrix[k][i][j])
                    calcul++;
    }
    if(calcul==16)
        return 0;
    return 1;
}

void print()
{
    for(int i=0;i<N;++i,printf("\n"))
        for(int j=0;j<N;++j)
            printf("%d ",matrice[i][j]);
    printf("\n");
}


void backtraking(int x,int y,int fromX,int fromY)
{
    if(!ok)
        return;
    //print();

    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            matrix[contor++][i][j]=matrice[i][j];
    if(verficare())
    {
        print();
        exit(0);
    }
    if(x+1<=3&&x+1!=fromX&&y!=fromY)
    {

        int aux=matrice[x+1][y];
        matrice[x+1][y]=matrice[x][y];
        matrice[x][y]=aux;
        backtraking(x+1,y,x,y);

    }
    if(x-1>=0&&x-1!=fromX&&y!=fromY)
    {
        int aux=matrice[x-1][y];
        matrice[x-1][y]=matrice[x][y];
        matrice[x][y]=aux;
        backtraking(x-1,y,x,y);
    }
    if(y+1<=3&&y+1!=fromY&&x!=fromX)
    {
        int aux=matrice[x][y+1];
        matrice[x][y+1]=matrice[x][y];
        matrice[x][y]=aux;
        backtraking(x,y+1,x,y);

    }
    if(y-1>=0&&y-1!=fromY&&x!=fromX)
    {
        int aux=matrice[x][y-1];
        matrice[x][y-1]=matrice[x][y];
        matrice[x][y]=aux;
        backtraking(x,y-1,x,y);
    }

}

int main() {

    FILE *f=fopen("input.dat","r");
    int index=0;
    while(fscanf(f,"%d%d%d%d",&matrice[index][0],&matrice[index][1],&matrice[index][2],&matrice[index][3])!=EOF)++index;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
        {
            if(!matrice[i][j])
            {
                backtraking(i,j,-1,-1);
                return 0;
            }

        }

    return 0;
}
