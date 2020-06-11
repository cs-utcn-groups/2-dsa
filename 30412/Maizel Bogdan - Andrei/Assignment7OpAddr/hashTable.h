
static const float INITIAL_HT_SIZE_FACTOR = .50;
static const float MAX_FILL_FACTOR = .90;

char **hT;
int size;


int hashFunction(char *content, int i);

void initializeHT(int N);

float getFillFactor();

void resizeHT();

int insert(char *element);



