#define FREE 0

static const double SIZE_FACTORS[] = {
        .25,
        .20,
        .20,
        .25,
        .25,
        .50
};
 double INITIAL_HT_SIZE_FACTOR;
static const double FILL_FACTORS[] = {
        .60,
        .75,
        .80,
        .83,
        .85,
        .90
};
 double MAX_FILL_FACTOR;

char **hashTable;
int size;
int initialSize;

int hashFunction1(char *content, int i);

int hashFunction2(char *content, int i);

int hashFunction3(char *content, int i);

void initHashTable(int N);

double getFillFactor();

void resizeHashTable(int t);

int insertElement(char *element, int t);



