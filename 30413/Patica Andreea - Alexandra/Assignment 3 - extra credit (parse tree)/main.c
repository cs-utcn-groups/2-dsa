#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct nodet_type
{
  char *id;
  struct nodet_type *left, *right;
} NodeT;

typedef struct nodel_type
{
    char *id;
    struct nodel_type *next;
}NodeL;


NodeL* getList()
{
    NodeL* first = NULL;
    NodeL* current = first;
    char *string = (char*)malloc(sizeof(char)*MAX_LENGTH);
    gets(string);
    char *token = strtok(string, " \n");

    while (token != NULL)
    {
        NodeL *newNode = (NodeL*)malloc(sizeof(NodeL));
        newNode->id = (char*)malloc(sizeof(char)*MAX_LENGTH);
        strcpy(newNode->id, token);
        newNode->next = NULL;

        if (current != NULL)
        {
            current->next = newNode;
        }
        current = newNode;
        if (first == NULL)
        {
            first = current;
        }

        token = strtok(NULL, " \n");
    }

    return first;
}

NodeT* createTree(NodeL **list)
{
    NodeT *p;
    *list = (*list)->next;
    if ( *list == NULL)
    {
        return NULL;
    }
    else
    {
        p = ( NodeT *) malloc( sizeof( NodeT ));

        p->id = (char*)malloc(sizeof(char)*MAX_LENGTH);
        strcpy(p->id, (*list)->id);
        p->left = p->right = NULL;

        if ((strpbrk((*list)->id, "0123456789"))==NULL)
        {
            p->left = createTree(list);
            if (*list != NULL)
                p->right = createTree(list);
        }
    }
    return p;
}

NodeT* getTreeFromList(NodeL *firstFromList)
{
    NodeL *current = (NodeL*)malloc(sizeof(NodeL));
    current->id = (char*)malloc(sizeof(char)*MAX_LENGTH);
    strcpy(current->id, firstFromList->id);
    current->next = firstFromList;

    NodeL *temp = current;

    NodeT *tree = createTree(&current);

    free(temp);

    return tree;

}

NodeT* parseTree()
{
    NodeL *firstFromList = getList();
    NodeT *root = getTreeFromList(firstFromList);

    return root;
}

int getHeight(NodeT *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int heightLeft = getHeight(node->left);
    int heightRight = getHeight(node->right);

    if (heightLeft > heightRight)
    {
        return heightLeft + 1;
    }
    else
    {
        return heightRight + 1;
    }
}



void prettyPrint(NodeT *root)
{
    int height = getHeight(root);
    int spaces = height;

    NodeT **queue = (NodeT**)malloc(sizeof(NodeT)*MAX_LENGTH);

    int first = 0;
    int last = 0;
    int size = 1;

    queue[first] = root;

    int smallSpaces = 0;

    while (size != 0)
    {
        int count = size;

        char *string = (char*)malloc(sizeof(char)*MAX_LENGTH);
        memset(string, 0, sizeof(string));

        int i=0;
        if (smallSpaces)
            i=4;
        for (; i<spaces; i++)
        {
                printf("    ");
                strcat(string, "    ");
        }
        printf("   ");

        while (count > 0)
        {
            smallSpaces = 0;
            printf("%s   ", queue[first]->id);
            if (strpbrk(queue[first]->id, "0123456789")==NULL)
            {

                strcat(string, "\/  \\");
            }
            else if (count == size)
            {
                for (int i=0; i<height; i++){
                    strcat(string, "     ");
                    spaces++;
                }
            }

            size--;
            if (queue[first]->left != NULL)
            {
                queue[++last]=queue[first]->left;
                if (strlen(queue[last]->id)>3)
                    smallSpaces = 1;
                size++;
            }

            if (queue[first]->right != NULL)
            {
                queue[++last] = queue[first]->right;
                size++;
            }
            count--;
            first++;
        }

        spaces--;
        height--;
        printf("\n");
        printf("%s", string);
        printf("\n");
        free(string);
    }

    free(queue);
}

int main()
{
    NodeT *root = parseTree();
    prettyPrint(root);

    return 0;
}
