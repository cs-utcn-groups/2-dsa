#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXTIME=300;
const int MAXNAME=100;

typedef struct
{
    int min,money;
} Value;

typedef struct node
{
    Value data;
    struct node *next;
    struct node *previous;
} ListNode;

typedef struct
{
    ListNode *first, *last;
} List;

List initial(List T)
{
    T.first=NULL;
    T.last=NULL;
    return T;
}

void printAll(List T)
{
    if (T.first==NULL)
        printf("The list is empty.\n");
    else
    {
        ListNode *CurrentElement;
        CurrentElement=T.first;
        while(CurrentElement != NULL)
        {
            printf("%d %d\n",CurrentElement->data.money,CurrentElement->data.min);
            CurrentElement=CurrentElement->next;
        }
    }
    printf("\n");
}

List addElement(List T,Value x)
{
    ListNode *Element= (ListNode *) malloc (sizeof (ListNode));
    Element->data=x;
    if(T.first==NULL)
    {
        Element->next=T.first;
        Element->previous=NULL;
        T.first = Element;
        T.last=T.first;
    }
    else
    {
        Element->next=NULL;
        Element->previous=T.last;
        T.last->next=Element;
        T.last=Element;
    }
    return T;
}

void solve(FILE *f,List Customer,FILE *o,List Time)
{
    Value nr;
    ListNode *CurentTime= (ListNode *) malloc (sizeof (ListNode));
    ListNode *CurentCustomer= (ListNode *) malloc (sizeof (ListNode));
    ListNode *Copy= (ListNode *) malloc (sizeof (ListNode));
    char *name=(char *) malloc(sizeof(char)*MAXNAME);
    char *strbuf=(char *) malloc(sizeof(char)*MAXTIME);
    Time=initial(Time);
    char *p;
    Value x;
    fgets(strbuf,MAXTIME,f);
    p=strtok(strbuf," ");
    while(p!=NULL)
    {
        x.min=atoi(p);
        x.money=0;
        Time = addElement(Time,x);
        p=strtok(NULL," ");
    }
    Customer=initial(Customer);
    int sum=0;
    while(fscanf(f,"%s %d %d\n",name,&nr.money,&nr.min)!=EOF)
    {
        Customer=addElement(Customer,nr);
    }
    CurentTime=Time.first;
    CurentCustomer=Customer.first;
    while(CurentTime!=Time.last&&CurentCustomer!=Customer.last)
    {
        if(CurentTime->data.min>=CurentCustomer->data.min)
        {
            sum=sum+CurentCustomer->data.money;
            Copy=CurentCustomer->next;
            Copy->data.min=Copy->data.min+CurentCustomer->data.min;
            CurentCustomer=Copy;
        }
        if(CurentCustomer!=Customer.last)
        {
            fprintf (o,"After %d seconds:%d\n",CurentTime->data.min,sum);
            CurentTime=CurentTime->next;
        }
    }
    sum=sum+CurentCustomer->data.money;
    if(CurentTime!=Time.last)
    {
        while (CurentTime!=NULL)
        {
            fprintf(o, "After %d seconds: %d\n",CurentTime->data.min,sum);
            CurentTime=CurentTime->next;
        }
    }
}

int main()
{

    FILE *f=fopen("input.dat","r");
    FILE *o=fopen("output.dat","w");
    List Time, Customer;
    solve(f,Customer,o,Time);
    fclose(f);
    fclose(o);
    return 0;
}
