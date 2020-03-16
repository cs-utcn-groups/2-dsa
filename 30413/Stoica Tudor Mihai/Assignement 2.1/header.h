#define maxLengthInstruction 25

typedef struct listt
{
    struct node * first;
    struct node * last;
    int nrElements;
}listt;

typedef struct node
{
    int info;
    struct node * next;
    struct node * previous;
}node;

listt * list0;

void initList();
void addToEnd(int data);
void addElementAtFront(int data);
void DOOM_THE_LIST ();
void deleteFirst();
void deleteLast();
void PRINT_ALL (FILE *o);
void deleteElement(int data);
void PRINT_F(int nr,FILE *o);
void PRINT_L(int nr,FILE *o);
void readInstructions(FILE *f,FILE *o);
