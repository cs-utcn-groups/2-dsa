#include "head.h"
MAX_LENGTH=200;

void readFile(FILE *f)
{
    char *s=(char*)malloc(sizeof(char)*MAX_LENGTH);
    char *token=(char*)malloc(sizeof(char)*MAX_LENGTH);
    int k=0,data;
    initialize_cus();
    initialize_sec();
    while(fgets(s,MAX_LENGTH,f))
    {
        s[strlen(s)-1]='\0';
        if(k==0)
        {
            token=strtok(s," ");
            data=atoi(token);
            addLast(data);

            while(token!=NULL)
            {
                token=strtok(NULL," ");
                if(token!=NULL)
                {
                    data=atoi(token);
                    addLast(data);
                }

                k=1;
            }
        }
        else
        {
            char *name=(char*)malloc(sizeof(char)*MAX_LENGTH);
            int money,sec;

            token=strtok(s," ");
            strcpy(name,token);

            token=strtok(NULL," ");
            money=atoi(token);

            token=strtok(NULL," ");
            sec=atoi(token);

            addLastDLL(name,money,sec);
        }

    }



}

void initialize_sec()
{
    first_sec=NULL;
    last_sec=NULL;
}

void initialize_cus()
{
    first_cus=NULL;
    last_cus=NULL;
}

void addLast(int data)
{
    if(first_sec==NULL)
    {
        first_sec=(Sec*)malloc(sizeof(Sec));
        first_sec->next=NULL;
        first_sec->data=data;
        last_sec=first_sec;
    }
    else
    {

        Sec *newElement=(Sec*)malloc(sizeof(Sec));
        last_sec->next=newElement;
        newElement->next=NULL;
        newElement->data=data;
        last_sec=newElement;
    }
}

void addLastDLL(char *name,int money,int sec)
{
    if(first_cus==NULL)
    {
        first_cus=(Node*)malloc(sizeof(Node));
        first_cus->prev=NULL;
        first_cus->next=NULL;
        first_cus->name=name;
        first_cus->money=money;
        first_cus->sec=sec;
        last_cus=first_cus;
    }
    else
    {

        Node *newCus=(Node *)malloc(sizeof(Node));
        newCus->next=NULL;
        newCus->prev=last_cus;
        newCus->name=name;
        newCus->money=money;
        newCus->sec=sec;
        last_cus->next=newCus;
        last_cus=newCus;
    }
}

void cashier_money(FILE *g)
{
    Sec *currentEl=first_sec;
    while(currentEl!=NULL)
    {
        fprintf(g,"After %d seconds: ",currentEl->data);
        int sum_sec=0,sum_money=0;
        Node *currentDLL=first_cus;
        while(currentDLL!=NULL && sum_sec<currentEl->data)
        {
            sum_sec=sum_sec+currentDLL->sec;
            sum_money=sum_money+currentDLL->money;
            currentDLL=currentDLL->next;
        }
        if(sum_sec>currentEl->data)
        {
            currentDLL=currentDLL->prev;
            sum_sec=sum_sec-currentDLL->next->sec;
            sum_money=sum_money-currentDLL->money;


        }
        fprintf(g,"%d\n",sum_money);
        currentEl=currentEl->next;
    }

}
