
static const float INITIAL_HT_SIZE_FACTOR = .25;
static const float MAX_FILL_FACTOR = .85;

char ** hashTable;
int sizeTable;
int nrOfResizes;
int nrOfCollisions;

int hashFunction(int i);

int H2(int i, char * content);

int H3(int i, char * content);

void initHashTable(int N);

float getFillFactor();

void resizeHashTable(int index, char * element);

int insertElement(int index, char * element);




