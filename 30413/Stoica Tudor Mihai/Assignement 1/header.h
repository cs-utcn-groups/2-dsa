typedef struct node
{
    int info;
    struct node *next;
}node;

node *first, *last;
int nrElements;
const int maxLengthInstruction=20;

void init(void);
void addElementAtEnd(int data);
void addElementAtFront(int data);
void DOOM_THE_LIST (void);
void deleteFirst(void);
void deleteLast(void);
void PRINT_ALL (FILE *o);
void deleteElement(int data);
void PRINT_F(int nr,FILE *o);
void PRINT_L(int nr,FILE *o);
void PRINT_ALLL ();
void readInstructions(FILE *f,FILE *o);
