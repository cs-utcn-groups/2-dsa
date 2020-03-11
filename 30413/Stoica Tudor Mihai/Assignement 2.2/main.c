#include "header.h"

void initList()
{
    customerFirst=customerLast=NULL;
    first=last=NULL;
}

void readInput(FILE * f, FILE * o)
{
    int a;
    char * s=(char *) malloc(25);

    while(fscanf(f,"%d",&a)==1)
    {
        addElementToEndNode(a);
    }

    while(fgets(s,25,f)!=NULL)
    {
        char * token=strtok(s," \n");
        char * name=(char *) malloc(25);
        strcpy(name,token);
        token=strtok(NULL," \n");
        int money=atoi(token);
        token=strtok(NULL," \n");
        int seconds=atoi(token);

      addElementToEndCustomers(name,money,seconds);
    }
}

void addElementToEndNode(int data)
{
    if(first==NULL)
    {
        first=(node *) malloc(sizeof(node));
        first->info=data;
        first->next=last;
        last=first;
    }

    else
    {
        node * element=(node *) malloc(sizeof(node));
        element->next = NULL;
        element->info = data;
        last->next = element;
        last = element;
    }
}

void addElementToEndCustomers(char * name, int money, int seconds)
{
    if(customerFirst==NULL)
    {
        customerFirst=(customers *) malloc(sizeof(customers));

        customerFirst->money=money;
        customerFirst->seconds=seconds;

        customerFirst->next=customerLast;
        customerLast=customerFirst;
    }

    else
    {
        customers * element=(customers *) malloc(sizeof(customers));

        element->next = NULL;
        element->money=money;
        element->seconds=seconds;

        customerLast->next = element;
        customerLast = element;
    }
}

void computeSum(FILE *o)
{
    node * element=first;

    while(element!=NULL)
    {
        int sum=0,time=element->info,auxTime=time;

        customers * elem=customerFirst;

        while(elem!=NULL)
        {
            if(time>=elem->seconds)
            {
                sum+=elem->money;
                time-=elem->seconds;
            }
            else
            {
                break;
            }
            elem=elem->next;
        }
        fprintf(o,"After %d seconds: %d\n",auxTime,sum);
        element=element->next;
    }
}

int main()
{
    FILE *f=fopen("input.dat","r");
    FILE *o=fopen("output.dat","w+");

    initList();
    readInput(f,o);
    computeSum(o);

//    f.close();
//    o.close();

    return 0;
}

