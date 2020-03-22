#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>

typedef struct _NODE{
    char *name;
    float price;
    int amount,dateOfManufacturing,dateOfExpiration;
    struct _NODE *left,*right;
}NODE;

NODE * expiredTree=NULL;
NODE * addMedicine(NODE *Medicine,NODE *parent);
NODE * createMedicine(char * name, float price, int amount, int date1,int date2);
NODE * findMedicine(char *name,NODE *Medicine,NODE *parent);
NODE * delete(char *name,NODE *parent);
NODE * getMedicine(char *s);
void createExpiredTree(NODE *root);

int main(int argc, char *argv[]) {
    NODE *root=NULL;

    char * name=malloc(sizeof(char)*256);
    FILE *f=fopen(argv[1],"r");
    char *s=(char*)malloc(sizeof(char)*256);
    while(fgets(s,256,f))
        switch (s[0]){
            case 'i':root=addMedicine(getMedicine(s+1),root);break;
            case 'u':strcpy(s,s+1);
                     int it=0;
                    while(s[it]!=',')
                        name[it]=s[it],++it;
                    name[it]='\0';
                  //  strcpy(s,s+it+1);
                    if(findMedicine(name,getMedicine(s+it+1),root))
                        printf("Medicine found and updated\n");
                    else
                        printf("Medicine not found!\n");
                    break;
            case 'd':s[strlen(s)-1]='\0',delete(s+1,root);
                        break;
             case 'c':createExpiredTree(root);
                    break;
            default:printf("WRONG INPUT COMMAND!\n");break;
        }


    return 0;
}

void preorder(NODE *parent)
{
    if(parent==NULL)
        return;
    if(parent->dateOfExpiration>=20210101) ///expiration date
        expiredTree=addMedicine(createMedicine(parent->name,parent->price,parent->amount,parent->dateOfManufacturing,parent->dateOfExpiration),expiredTree);
    preorder(parent->left);
    preorder(parent->right);
}

void createExpiredTree(NODE *root)
{
    NODE * expiredTree=NULL;
    preorder(root);
 //   return expiredTree;
}

NODE *getMedicine(char *s)
{
  //  strcpy(s,s+1);
    char *p=strtok(s,",\n");
    char *name=(char *)malloc(sizeof(char)*256);
    strcpy(name,p);
    float price;
    int amount,date1,date2;
    p=strtok(NULL,",\n");
    if(!strcmp(p,"~"))
        price=FLT_MIN;
    else
        price=atof(p);
    p=strtok(NULL,",\n");
    if(!strcmp(p,"~"))
        amount=INT_MIN;
    else
        amount=atoi(p);
    p=strtok(NULL,",\n");
    if(!strcmp(p,"~"))
        date1=INT_MIN;
    else
        date1=atoi(p);
    p=strtok(NULL,",\n");
    if(!strcmp("~",p))
        date2=INT_MIN;
    else
        date2=atoi(p);
    return createMedicine(name,price,amount,date1,date2);


}

NODE * findMax(NODE *parent)
{
    if(!parent)
        return  NULL;
    if(parent->right)
        return parent->right;
    return parent;
}

NODE * delete(char *name,NODE *parent)
{
    if(parent==NULL)
        return NULL;
    if(!strcmp(name,parent->name))
    {
        if(!parent->left && !parent->right)
        {
            free(parent);
            return NULL;
        } else
            if((parent->left && !parent->right) || (parent->right && !parent->left))
            {
                NODE *p=parent->left?parent->left:parent->right;
                free(parent);
                return p;
            } else
            {
                NODE *p=findMax(parent->left);
                strcpy(parent->name,p->name);
                parent->dateOfExpiration=p->dateOfExpiration;
                parent->price=p->price;
                parent->amount=p->amount;
                parent->dateOfManufacturing=p->dateOfManufacturing;
                parent->left=delete(p->name,parent->left);
                return parent;
            }
    } else
    {
        if(strcmp(name,parent->name)>0)
            parent->right=delete(name,parent->right);
        else
            parent->left=delete(name,parent->left);
    }
}

NODE * findMedicine(char *name,NODE *Medicine,NODE *parent)
{
    if(parent==NULL)
        return NULL;
    if(!strcmp(parent->name,name))
    {
        if(strcmp(Medicine->name,"~"))
            strcpy(parent->name,Medicine->name);
        if(Medicine->price!=FLT_MIN)
            parent->price=Medicine->price;
        if(Medicine->amount!=INT_MIN)
            parent->amount=Medicine->amount;
        if(Medicine->dateOfManufacturing!=INT_MIN)
            parent->dateOfManufacturing=Medicine->dateOfManufacturing;
        if(Medicine->dateOfExpiration!=INT_MIN)
            parent->dateOfExpiration=Medicine->dateOfExpiration;
        return parent;
    } else{
        return findMedicine(name,Medicine,parent->left)?findMedicine(name,Medicine,parent->left):findMedicine(name,Medicine,parent->right);
    }
}

NODE * createMedicine(char * name, float price, int amount, int date1,int date2)
{
    NODE *p=(NODE*)malloc(sizeof(NODE));
    p->name=(char *)malloc(sizeof(char)*15);
    strcpy(p->name,name);
    p->right=NULL;
    p->left=NULL;
    p->dateOfExpiration=date2;
    p->dateOfManufacturing=date1;
    p->price=price;
    p->amount=amount;
    return p;
}

NODE * addMedicine(NODE *Medicine, NODE *parent)
{
    if(parent==NULL)
        return  Medicine;
    if(strcmp(Medicine->name,parent->name)>0)
        parent->right=addMedicine(Medicine,parent->right);
    else
        parent->left=addMedicine(Medicine,parent->left);
}
