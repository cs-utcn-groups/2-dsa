
static const float INITIAL_HT_SIZE_FACTOR = .50;
static const float MAX_FILL_FACTOR = .90;

char ** hashTable;
int size, n, m;


int hashFunction(char * content, int i);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable(int N, int i, char** content);
int insertElement(char * element, int N);



