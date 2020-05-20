#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

typedef struct N
{
    char name[30];
    float price;
    int amount;
    int dateOfManufacturing;
    int dateOfExpiration;
    struct N* pLeft;
    struct N* pRight;
} Product;

Product*  createnode( char *name, float price, int amount, int dateOfManufacturing, int dateOfExpiration)
{
    Product* p=(Product*)malloc(sizeof(Product));
    if(p)
    {
        strcpy(p->name,name);
        p->price=price;
        p->amount=amount;
        p->dateOfManufacturing=dateOfManufacturing;
        p->dateOfExpiration=dateOfExpiration;
        p->pLeft=p->pRight=NULL;
    }
    return p;
}

Product* insertproduct(Product* pTree, char *name, float price, int amount, int dateOfManufacturing, int dateOfExpiration)
{
    if(pTree == NULL)
    {
        pTree=createnode(name,price,amount,dateOfManufacturing,dateOfExpiration);
        /*
        pNode=(Node*)malloc(sizeof(Node));
        pNode->key=key;
        pNode->pLeft=pNode->pRight=NULL;
        return pNode;
        */
    }
    if( stricmp(pTree->name,name) == 0)
        return pTree;
    if( stricmp(pTree->name,name) < 0)
        pTree->pLeft=insertproduct(pTree->pLeft,name,price,amount,dateOfManufacturing,dateOfExpiration);
    else
        pTree->pRight=insertproduct(pTree->pRight,name,price,amount,dateOfManufacturing,dateOfExpiration);
    return pTree;

}

Product* findproduct(Product* pTree, char *name)
{
    if(pTree == NULL) //empty tree
        return NULL;
    else if( stricmp(pTree->name,name) == 0 )
        return pTree;
    else if ( stricmp(pTree->name,name) < 0)
        return findproduct(pTree->pLeft, name);
    else
        return findproduct(pTree->pRight, name);
}

Product* findMax(Product* pTree)
{
    if(pTree == NULL)
        return NULL;
    else
    if(pTree->pRight)
        return findMax(pTree->pRight);
    else
        return pTree;
}

Product* findMin(Product* pTree)
{
    if(pTree == NULL)
        return NULL;
    else if (pTree->pLeft)
        return findMin((pTree->pLeft));
    else
        return pTree;
}

Product* deletenode(Product* pTree, char *name)
{
    if(pTree == NULL)
        printf(" Medicine %s not found \n",name);
    else if( stricmp(pTree->name,name) < 0)
        //it must be in the left subtree
        pTree->pLeft = deletenode(pTree->pLeft,name);
    else if( stricmp(pTree->name,name) > 0)
        //it must be in the right subtree
        pTree->pRight = deletenode(pTree->pRight,name);
    else
    {
        //we found node
        // Now We can delete this node and replace with either
        //minimum element in the right sub tree or
        //maximum element in the left subtree
        if( pTree->pRight && pTree->pLeft )
        {
            Product* temp=findMin(pTree->pRight);
            strcpy(pTree->name,temp->name);
            pTree->pRight=deletenode(pTree->pRight, temp->name);
        }
        else
        {
            // If there is only one or zero children then we can directly
            // remove it from the tree and connect its parent to its child
            Product* temp = pTree;
            if(pTree->pLeft == NULL)
                pTree = pTree->pRight;
            else if(pTree->pRight == NULL)
                pTree = pTree->pLeft;
            free(temp); // temp is no longer required
        }
    }
    return pTree;
}

FILE *fin,*fout;

void preorder ( Product *pTree, int level)
{
    int i;
    for ( i = 0; i <= level; i++ )
        printf(" "); /// for nice listing
    if(pTree != NULL)
    {
        printf("%s %f %d %d %d \n",pTree->name,pTree->price,pTree->amount,pTree->dateOfManufacturing,pTree->dateOfExpiration);
        preorder( pTree->pLeft, level + 1);
        preorder( pTree->pRight, level + 1);
    }
    else
    {
        printf("*\n");
    }
}

int getDate()
{
    // convert local time to string of form "YYYYMMDD"
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[10];

    time ( &rawtime );
    timeinfo = localtime( &rawtime );
    strftime(buffer, sizeof(buffer), "%Y%m%d", timeinfo);
    int currentDate=atoi(buffer);
    return currentDate;
}

int isExpired(int dateOfExpiration) {
    int currentDate = getDate();
    if(dateOfExpiration < currentDate)
        return 1;
    else
        return 0;
}

int main()
{
    FILE *fin=fopen("input.txt","r");
    FILE *fout=fopen("output.txt","w");
    if(fin== NULL)
    {
        perror("not found input");
        exit(-1);
    }

    if(fout== NULL)
    {
        perror("not found");
        exit(-1);
    }
    Product *pBST=NULL;
    Product *pFind=NULL;
    Product *pBSTE=NULL;
    char name[30];
    float price;
    int amount;
    int dateOfManufacturing;
    int dateOfExpiration;
    char c;
    Product ce;
    getDate();
    while( fscanf(fin,"%s %f %d %d %d",name,&price,&amount,&dateOfManufacturing,&dateOfExpiration) != -1 )
    {
        c=name[0];
        strcpy(name,name+1);
        if( c == 'i')
        {
            pBST=insertproduct(pBST,name,price,amount,dateOfManufacturing,dateOfExpiration);
        }

        if(c == 'd')
        {
            pBST=deletenode(pBST,name);
        }

        if(c == 'u')
        {
            pFind = findproduct(pBST,name);
            if ( pFind == NULL)
                printf("\n Medicine %s not found \n", name);
            else
            {
                printf("\n Medicine %s found \n", name);

            }
        }
        if(isExpired(dateOfExpiration) == 1)
            pBSTE=insertproduct(pBSTE,name,price,amount,dateOfManufacturing,dateOfExpiration);

    }
    preorder(pBST,0);
    printf("\n Expired products are: \n");
    preorder(pBSTE,0);
    return 0;
}
