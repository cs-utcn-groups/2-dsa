#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * f;

typedef struct node
{
    int data;
    struct node * next;

} NodeT;

NodeT * first, * last;

void initializeSll()
{
    first = NULL;
    last = NULL;
}

void addFirst(int data)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        newElement->next = first;
        newElement->next = first;
        newElement->data = data;
        first = newElement;
    }
}

void addLast(int data)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->next = NULL;
        newElement->data = data;
        last = newElement;
    }
}

void deleteLast()
{
    NodeT * currElement = first;
    if(first == NULL) return;
    while(currElement->next != last)
    {
        currElement = currElement->next;
    }
    free(last);
    last = currElement;
}

void deleteFirst()
{
    NodeT * currentElement = first;
    if(first == NULL) return;
    first = first->next;
    free(currentElement);
}

void removeElement(int data)
{
    NodeT * currentElement = first;
    NodeT * previousElement= first;
    while(currentElement != NULL)
    {
        if(currentElement->data == data)
        {
            if(currentElement == first)
            {
                first = first->next;
            }
            else if(currentElement == last)
            {
                last = previousElement;
                last->next = NULL;
            }
            else
            {
                previousElement->next = currentElement->next;
            }
            previousElement = currentElement;
            currentElement = currentElement->next;
            free(previousElement);
            previousElement = currentElement;
        }
        else
        {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }

    }
}

void removeAll()
{

    NodeT * currentElement = first;

    while(currentElement != NULL)
    {

        if(!first) {
            free(currentElement);
            break;
        }

        first = first->next;
        free(currentElement);
        currentElement = first;

    }

    first = NULL;
    last = NULL;

}

void printAll()
{
    if(first == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        NodeT * currentElement = first;
        while(currentElement != NULL)
        {
            printf("%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        printf("\n");
    }

}

void print_f(int nr)
{
    int i=0;
    if(first == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        NodeT * currentElement = first;
        while(i<nr)
        {
            printf("%d ", currentElement->data);
            currentElement = currentElement->next;
            i++;
        }
        printf("\n");
    }
}

void print_l(int nr)
{
    int i=0,j;
   NodeT * currentElement = first;
   while(currentElement!=NULL)
   {
       currentElement = currentElement->next;
       i++;
   }
   currentElement = first;
   for(j=0;j<i-nr;j++)
   {
       currentElement = currentElement->next;
   }
    while(currentElement!=NULL)
    {
        printf("%d ",currentElement->data);
        currentElement = currentElement->next;
    }
            printf("\n");
}

void verifyInstruction(char * instruction, int nr)
{
    if(strlen(instruction) == 2)
    {
        if(instruction[0]=='A')
        {
            if(instruction[1]=='F')
            {
                addFirst(nr);

            }
            else
            {
                addLast(nr);
            }
        }
        else
        {
            if(instruction[1]=='F')
            {
                deleteFirst();
            }
            else
            {
                if(instruction[1]=='L')
                {
                    deleteLast();
                }
                else
                {
                    removeElement(nr);
                }
            }
        }

    }
    else
    {
        if(strcmp(instruction, "DOOM_THE_LIST\n")==0)
        {
            removeAll();
        }
        else
        {
            if(instruction[6]=='A')
            {
                printAll();
            }
            else
            {
                if(instruction[6]=='F')
                {
                    print_f(nr);
                }
                else
                {
                    print_l(nr);
                }
            }
        }
    }
}

int main()
{
    initializeSll();
    int nr;
    char * instruction = (char*)malloc(sizeof(char)*15);
    char * line = (char*)malloc(sizeof(char)*15);
    char * piece = (char*)malloc(sizeof(char)*15);
    f = fopen("input.txt", "r");
    while((fgets(line, 15, f)!=NULL))
    {
        piece = strtok(line, " ");
        strcpy(instruction, piece);
        piece = strtok(NULL, " ");
        nr = atoi(piece);
        if(instruction[2]=='\n')
        {
            instruction[2]='\0';
        }
        verifyInstruction(instruction,nr);
    }
    return 0;
}
