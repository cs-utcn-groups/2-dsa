#include "list.h"
#include "io.h"

nodeT * createNode(char * content)
{
    nodeT * n = (nodeT*) malloc(sizeof(nodeT));
    n->content = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

void addToList(listT *l, char * content)
{
    //! add last
    if(l->head==NULL)
    {
        l->head=createNode(content);
        l->head->next=l->tail;
        l->tail=l->head;
        l->size++;

    }
    else
    {
        nodeT *newElement =createNode(content);
        l->tail->next=newElement;
        l->tail=newElement;
        l->size++;
    }

}
void printSllData(listT *l)
{
    if(l->head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        nodeT * currentElement;
        currentElement=l->head;
        while(currentElement!=NULL)
        {
            printf("%s ", currentElement->content);
            currentElement=currentElement->next;
        }
        printf("\n");
    }
}
