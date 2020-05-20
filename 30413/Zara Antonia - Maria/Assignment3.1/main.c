#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;
///am facut citirea codului initial fara spatii intre ca nu mi-am dat seama ca in word aveau spatii
///sa stiti ca e mai greu asa ca trebuie sa am un index global
///doua ore m-am uitat la cod ca sa descopar ca sunt spatii intre caractere

typedef struct node1
{
    char id;
    struct node1 *left,*right;
} nodeT;

typedef struct node2
{
    char id;
    struct node2 *next,*previous;
} nodeL;

nodeL *first,*last,*globalCurrent;
///tot un nod global care ma va ajuta la getTreeFromList

nodeT *addCharacterInTree(char *code,int length)
{
    if(code[i] == '*' || i>=length)
    {
        i++;
        return NULL;
    }
    else
    {
        nodeT *currentNode = (nodeT*)malloc(sizeof(nodeT));
        currentNode->id = code[i++];
        currentNode->left = addCharacterInTree(code,length);
        currentNode->right = addCharacterInTree(code,length);
        return currentNode;
    }
}

nodeT *createBinaryTree()
{
    nodeT *root = (nodeT*)malloc(sizeof(nodeT));

    printf("Input the sequence describing the future tree: ");
    char *code = (char*)malloc(sizeof(char));
    gets(code);
    int length = strlen(code);

    i=0;
    root = addCharacterInTree(code,length);
    return root;
}

void initializeDLL()
{
    first=NULL;
    last=NULL;
}

void addElement(char c)
{
    if(last == NULL)
    {
        first = (nodeL*)malloc(sizeof(nodeL));
        first->id = c;
        first->next = NULL;
        first->previous = NULL;
        last = first;
    }
    else
    {
        nodeL *newNode = (nodeL*)malloc(sizeof(nodeL));
        last->next = newNode;
        newNode->id = c;
        newNode->previous = last;
        newNode->next = NULL;
        last = newNode;
    }
}

void createList(nodeT *currentNode)
{
    if(currentNode != NULL)
    {
        addElement(currentNode->id);
        createList(currentNode->left);
        createList(currentNode->right);
    }
    else
    {
        addElement('*');
    }
}

nodeL *getListFromTree(nodeT *root)
{
    initializeDLL();
    createList(root);

    return first;
}

void traverseList(nodeL *first)
{
    nodeL *newNode = first;
    printf("\nThe list made from that sequence is: ");
    while(newNode!=NULL)
    {
        printf("%c",newNode->id);
        newNode = newNode->next;
    }
    printf("\n\n");
    globalCurrent = first;
}

nodeT *getTreeFromList()
{
    if(globalCurrent->id == '*' || globalCurrent == NULL)
    {
        globalCurrent = globalCurrent->next;
        return NULL;
    }
    else
    {
        nodeT *newNode = (nodeT*)malloc(sizeof(nodeT));
        newNode->id = globalCurrent->id;
        globalCurrent = globalCurrent->next;
        newNode->left = getTreeFromList();
        newNode->right = getTreeFromList();
        return newNode;
    }
}

void prettyPrint( nodeT *p, int level )
{
    int i;
    if ( p != NULL )
    {
        prettyPrint( p->left, level + 1 );
        for (i = 0; i <= level; i++ )
        {
            printf( "   " );
        }
        printf( "%c\n", p->id );
        prettyPrint( p->right, level + 1 );
    }
}

int main()
{
    nodeT *root = createBinaryTree();
    nodeL *firstFromList = getListFromTree(root);
    traverseList(firstFromList);
    root = getTreeFromList(firstFromList);
    prettyPrint(root,0);
    return 0;
}
