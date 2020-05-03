
typedef struct node
{
    char * content;
    struct node * next;
} nodeT;

typedef struct list
{
    nodeT * head;
    nodeT * tail;
    float size;
} listT;

listT addToList(listT l, char * content);
