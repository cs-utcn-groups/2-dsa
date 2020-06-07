typedef struct _node
{
    char * content;
    struct _node * next;
} NodeT;

typedef struct _list
{
    NodeT * head;
    NodeT * tail;
    int size;
} ListT;

void addToList(ListT *l, char * content);

void initList(ListT *l);