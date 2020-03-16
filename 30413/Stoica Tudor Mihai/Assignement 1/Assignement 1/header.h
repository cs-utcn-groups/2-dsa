typedef struct node
{
    int info;
    struct node *next;
}node;

node *first, *last;
int nrElements,maxLengthInstruction=20;

void init(void);
