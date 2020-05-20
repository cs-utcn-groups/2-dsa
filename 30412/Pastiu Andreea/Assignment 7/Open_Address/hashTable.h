#include <stdlib.h>
#include <string.h>

#define INITIAL_HT_SIZE_FACTOR 0.50
#define MAX_FILL_FACTOR 0.90

char ** hashTable;
int size;

int existingElementsNo;
int maxCollisions;
char **content;


int hashFunction(char * content, int i);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);



