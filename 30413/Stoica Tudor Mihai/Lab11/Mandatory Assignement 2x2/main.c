#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BOARD_SIZE 2
#define MAX_NR_RECORDS 1*2*3*4 + 5  /// aprox 4!

int initialFreePosition;
int contor=0;

int ** read(FILE * f, int ** matrix)
{
    matrix=(int **) malloc(sizeof(int *) * BOARD_SIZE);
    /// initialise
    for(int i=0; i<BOARD_SIZE; i++)
    {
        matrix[i]=(int *) malloc(sizeof(int) * BOARD_SIZE);
    }

    for(int i=0; i<BOARD_SIZE*BOARD_SIZE; i++)
    {
        fscanf(f,"%d",&matrix[i/BOARD_SIZE][i%BOARD_SIZE]);

        if(matrix[i/BOARD_SIZE][i%BOARD_SIZE]==0)
        {
            initialFreePosition=i;
        }
    }

    return matrix;
}

bool valid(int ** matrixToValidate, int *** sequenceMatrix, int nrMatrixesInSequence)
{
    /// first check if we reached the result

    int contor=1;
    bool break0=false;

    for(int i=0; i<BOARD_SIZE && break0==false; i++)
    {
        for(int j=0; j<BOARD_SIZE; j++)
        {
            if(matrixToValidate[i][j]!=contor)
            {
                break0=true;
                break;
            }

            contor++;

            if(contor==BOARD_SIZE*BOARD_SIZE) /// this can only be true if we did not break (we did not find something wrong in the matrix)
            {
                /// we reached the result
                /// we output the number of steps and the matrixes associated with the result
                /// then we exit the program

                printf("%d\n\n",nrMatrixesInSequence);

                for(int i=0; i<nrMatrixesInSequence; i++)
                {
                    for(int j=0; j<BOARD_SIZE; j++)
                    {
                        for(int k=0; k<BOARD_SIZE; k++)
                        {
                            printf("%d ",sequenceMatrix[i][j][k]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                }

                /// additionally, we must output the result (final matrix)

                for(int i=0; i<BOARD_SIZE && break0==false; i++)
                {
                    for(int j=0; j<BOARD_SIZE; j++)
                    {
                        printf("%d ",matrixToValidate[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
                exit(0);
            }
        }
    }

    /// if we did not reach the result, check wether we encountered this matrix so far

    for(int i=0; i<nrMatrixesInSequence; i++)
    {
        break0=false;

        for(int j=0; j<BOARD_SIZE && break0==false; j++)
        {
            for(int k=0; k<BOARD_SIZE; k++)
            {
                ///printf("%d %d\n",matrixToValidate[j][k],sequenceMatrix[i][j][k]);
                if(matrixToValidate[j][k]!=sequenceMatrix[i][j][k])
                {
                    /// we did not encounter this matrix in this case
                    break0=true; /// get out from the second for
                    break; /// get out from this for
                }
            }
        }

        if(break0==false)
        {
            /// then it means that we have had this matrix configuration so far => return valid->false
            return false;
        }
    }

    return true;
}

int ** getModifiedMatrix(int ** initialMatrix,int freePosition, int nextFreePosition)
{

    int rowFreePosition=freePosition/BOARD_SIZE;
    int collumnFreePosition=freePosition%BOARD_SIZE;

    int rowNextPosition=nextFreePosition/BOARD_SIZE;
    int collumnNextPosition=nextFreePosition%BOARD_SIZE;

    int aux=initialMatrix[rowFreePosition][collumnFreePosition];
    initialMatrix[rowFreePosition][collumnFreePosition]=initialMatrix[rowNextPosition][collumnNextPosition];
    initialMatrix[rowNextPosition][collumnNextPosition]=aux;

    return initialMatrix;
}

void back(int freePosition, int ** matrix, int *** sequenceMatrix, int nrMatrixesInSequence)
{

    if(valid(matrix,sequenceMatrix,nrMatrixesInSequence))
    {
        /// if valid == true we do this function
        /// moreover, we must place this matrix into sequenceMatrix

        for(int i=0; i<BOARD_SIZE; i++)
        {
            for(int j=0; j<BOARD_SIZE; j++)
            {
                sequenceMatrix[nrMatrixesInSequence][i][j]=matrix[i][j];
            }
        }
        nrMatrixesInSequence++;
    }

    else
    {
        /// if valid == false we exit this function
        return;
    }

    switch (freePosition)
    {
    case 0:
        back(1,getModifiedMatrix(matrix,freePosition,1),sequenceMatrix,nrMatrixesInSequence);
        matrix=getModifiedMatrix(matrix,freePosition,1);
        back(2,getModifiedMatrix(matrix,freePosition,2),sequenceMatrix,nrMatrixesInSequence);
        matrix=getModifiedMatrix(matrix,freePosition,2);
        break;

    case 1:
        back(0,getModifiedMatrix(matrix,freePosition,0),sequenceMatrix,nrMatrixesInSequence);
        matrix=getModifiedMatrix(matrix,freePosition,0);
        back(3,getModifiedMatrix(matrix,freePosition,3),sequenceMatrix,nrMatrixesInSequence);
        matrix=getModifiedMatrix(matrix,freePosition,3);
        break;

    case 2:
        back(0,getModifiedMatrix(matrix,freePosition,0),sequenceMatrix,nrMatrixesInSequence);
        matrix=getModifiedMatrix(matrix,freePosition,0);
        back(3,getModifiedMatrix(matrix,freePosition,3),sequenceMatrix,nrMatrixesInSequence);
        matrix=getModifiedMatrix(matrix,freePosition,3);
        break;

    case 3:
        back(2,getModifiedMatrix(matrix,freePosition,2),sequenceMatrix,nrMatrixesInSequence);
        matrix=getModifiedMatrix(matrix,freePosition,2);
        back(1,getModifiedMatrix(matrix,freePosition,1),sequenceMatrix,nrMatrixesInSequence);
        matrix=getModifiedMatrix(matrix,freePosition,1);
        break;

    default:
        printf("error freePosition = %d",freePosition);
        break;
    }
}

int main()
{
    FILE * f=fopen("in.txt","r");

    int *** matrixRecords=(int ***) malloc(sizeof(int **) * MAX_NR_RECORDS);

    for(int i=0; i<MAX_NR_RECORDS; i++)
    {
        matrixRecords[i]=(int **) malloc(sizeof(int *) * BOARD_SIZE);

        for(int j=0; j<BOARD_SIZE; j++)
        {
            matrixRecords[i][j]=(int *) malloc(sizeof(int) * BOARD_SIZE);
        }
    }

    int ** matrix=read(f,matrix);

    back(initialFreePosition,matrix,matrixRecords,0);

    return 0;
}
