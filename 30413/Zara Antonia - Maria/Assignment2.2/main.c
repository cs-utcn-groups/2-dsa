#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node1
{
    int data;
    struct node1 *next;
} nodeSeconds;

typedef struct node2
{
    char *name;
    int money;
    int seconds;
    struct node2 *next;
} nodeCustomers;

nodeSeconds *firstS, *lastS;
nodeCustomers *firstC,*lastC;
int nrReqSeconds = 0;

int charToInt(char *string)
{
    int number = 0,lastDigit,i;
    int length = strlen(string);

    for(i=0; i<length; i++)
    {
        lastDigit = (int)string[i] - '0';
        number = number*10 + lastDigit;
    }

    return number;
}

void addLastSecond(int data)
{
    if(firstS == NULL)
    {
        firstS = (nodeSeconds*)malloc(sizeof(nodeSeconds));
        firstS->data = data;
        firstS->next = NULL;
        lastS = firstS;
    }
    else
    {
        nodeSeconds * newNode = (nodeSeconds*)malloc(sizeof(nodeSeconds));
        newNode->data = data;
        newNode->next = NULL;
        lastS->next = newNode;
        lastS = newNode;
    }
}

void storeSecondsData(char *strbuf)
{
    char *p;
    for(p = strtok(strbuf," "); p; p = strtok(NULL," \n"))
    {
        int nr = charToInt(p);
        addLastSecond(nr);
        nrReqSeconds++;
    }
}

void addLastCustomer(char *name, int money, int seconds)
{
    if(firstC == NULL)
    {
        firstC = (nodeCustomers*)malloc(sizeof(nodeCustomers));
        firstC->name = name;
        firstC->money = money;
        firstC->seconds = seconds;
        firstC->next = NULL;
        lastC = firstC;
    }
    else
    {
        nodeCustomers * newNode = (nodeCustomers*)malloc(sizeof(nodeCustomers));
        newNode->name = name;
        newNode->money = money;
        newNode->seconds = seconds;
        newNode->next = NULL;
        lastC->next = newNode;
        lastC = newNode;
    }
}

void storeNewCustomer(char *strbuf)
{
    char *name = (char*)malloc(sizeof(char)*20);
    int money,seconds;

    char *p;
    p = strtok(strbuf," ");
    strcpy(name,p);
    p = strtok(NULL," ");
    money = charToInt(p);
    p = strtok(NULL," \n");
    seconds = charToInt(p);

    addLastCustomer(name,money,seconds);

}

void deleteFirstS()
{
    nodeSeconds *currentNode = firstS->next;
    free(firstS);
    firstS = currentNode;
}

void deleteFirstC()
{
    nodeCustomers *currentNode = firstC->next;
    free(firstC);
    firstC = currentNode;
}

int calculateMoney(FILE *g, nodeCustomers *currentCustomer, nodeSeconds *currentSeconds, int money, int secondsFromCustomers)
{
    printf("%d\n",currentSeconds->data);
    if(firstC!=NULL)
    {
        while(firstC!=NULL && secondsFromCustomers + firstC->seconds < currentSeconds->data)
        {
            secondsFromCustomers = secondsFromCustomers + firstC->seconds;
            money = money + firstC->money;
            currentCustomer = currentCustomer->next;
            deleteFirstC();
        }
    }
    return money;
}

int main()
{
    FILE *f = fopen("input.dat","r");
    FILE *g = fopen("output.dat","r+");

    char *strbuf = (char*)malloc(sizeof(char)*50);
    fgets(strbuf,50,f);

    storeSecondsData(strbuf);

    while(fgets(strbuf,50,f))
    {
        storeNewCustomer(strbuf);
    }

    int i,money = 0,secondsFromCustomers = 0;
    nodeSeconds *currentSeconds = firstS;
    nodeCustomers *currentCustomer = firstC;

    for(i=1; i<=nrReqSeconds; i++)
    {
        money = calculateMoney(g,currentCustomer,currentSeconds,money,secondsFromCustomers);

        fprintf(g,"After %d seconds: %d\n",currentSeconds->data,money);

        currentSeconds = currentSeconds->next;
        deleteFirstS();
    }

    return 0;
}
