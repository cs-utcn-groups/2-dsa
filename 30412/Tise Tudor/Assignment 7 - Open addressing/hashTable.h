#include <stdlib.h>
#include "string.h"

static const int MAX_WORD_LENGTH = 64;

static const float INITIAL_HT_SIZE_FACTOR = .50;
static const float MAX_FILL_FACTOR = .90;

char ** hashTable;
int size, collisions, resizes;


int hash1(char * content, int i);
int hash2(char * content, int i);
int hash3(char * content, int i);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);
