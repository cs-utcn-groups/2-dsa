static const float INITIAL_HT_SIZE_FACTOR = .25;
static const float MAX_FILL_FACTOR = .80;

char ** hashTable;
int size;
int cnt;


int hashFunction(char * content);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);



