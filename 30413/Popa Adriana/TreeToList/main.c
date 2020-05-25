#include <stdio.h>
#include <stdlib.h>

typedef struct nodet_type
{
  char id;
  struct nodet_type *left, *right;
} NodeT;//tree

typedef struct nodel_type
{
    char id;
    struct nodel_type *prev, *next;
}NodeL;//list

void fatalError( const char *msg )
{
 printf( msg );
 printf( "\n" );
 exit ( 1 );
}

NodeT *createBinTree()
{
  NodeT *p;
  char c;
  /* read node id */
  scanf("%c", &c);
  if ( c == '*' )
    return NULL; /* empty tree; do nothing */
  else /* else included for clarity */
  { /* build node pointed to by p */
    p = ( NodeT *) malloc( sizeof( NodeT ));
    if ( p == NULL )
      fatalError( "Out of space in createBinTree" );
    /* fill in node */
    p->id = c;
    p->left = createBinTree();
    p->right = createBinTree();
  }
  return p;
}

void preorder(NodeT *tree, NodeL **current)
{
    NodeL *newNode = (NodeL*)malloc(sizeof(NodeL));
    if (tree != NULL)
    {
        newNode->id = tree->id;
    }
    else
    {
        newNode->id = '*';
    }
    newNode->prev = *current;
    (*current)->next = newNode;

    *current = newNode;

    if (tree != NULL)
    {
        preorder(tree->left, current);
        preorder(tree->right, current);
    }
}

NodeL* getListFromTree (NodeT *tree)
{
    NodeL *first = (NodeL*)malloc(sizeof(NodeL));
    first->next = first->prev = NULL;
    first->id = tree->id;
    NodeL *current = first;

    preorder(tree, &current);

    current->next = NULL;

    NodeL *temp = first;
    first = first->next;
    free(temp);

    return first;
}

void traverseList(NodeL* first)
{
    NodeL *node = first;
    while (node!=NULL)
    {
        printf("%c", node->id);
        node = node->next;
    }
    printf("\n");
}

NodeT* createTree(NodeL **list)
{
    NodeT *p;
    *list = (*list)->next;
    if ( (*list)->id == '*' )
    {
        return NULL;
    }
    else
    {
        p = ( NodeT *) malloc( sizeof( NodeT ));
        if ( p == NULL )
        fatalError( "Out of space in createTree" );

        p->id = (*list)->id;
        p->left = createTree(list);
        p->right = createTree(list);
    }
    return p;
}

NodeT* getTreeFromList(NodeL *firstFromList)
{
    NodeL *current = (NodeL*)malloc(sizeof(NodeL));
    current->id = firstFromList->id;
    current->prev = NULL;
    current->next = firstFromList;

    NodeL *temp = current;

    NodeT *tree = createTree(&current);

    free(temp);

    return tree;

}

void prettyPrint(NodeT *tree, int level)
{
    if (tree == NULL)
    {
        return;
    }
    prettyPrint(tree->right, level+1);

    for (int i=0; i<level; i++)
    {
        printf("    ");
    }
    printf("%c\n", tree->id);

    prettyPrint(tree->left, level+1);
}

int main()
{
    NodeT *root = createBinTree();
    NodeL *firstFromList = getListFromTree(root);
    traverseList(firstFromList);
    root = getTreeFromList(firstFromList);
    prettyPrint(root, 0);
    return 0;
}
