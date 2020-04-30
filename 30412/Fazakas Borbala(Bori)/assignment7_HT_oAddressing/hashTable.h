//
// Created by Bori on 4/29/2020.
//

#ifndef ASSIGNMENT7_HT_OADDRESSING_HASHTABLE_H
#define ASSIGNMENT7_HT_OADDRESSING_HASHTABLE_H

static float INITIAL_HT_SIZE_FACTOR = .25;
static float MAX_FILL_FACTOR = .80;
char ** hashTable;
int size, noInsertedElements, noResizes;
int hashFunctionNr;


int hashFunction(char * content, int i);
void initHashTable(int N, int functionNr);
void resizeHashTable();
int insertElement(char * element);
int noResizesNeeded();

float getFillFactor();
void setInitialSizeFactor(float sizeFactor);
void setMaxFillFactor(float maxFillFactor);

int hashCode0(char *content);
int hashCode1(char *content);
int hashCode2(char *content);
int hashCode3(char *content);
int hashCode4(char *content);


#endif //ASSIGNMENT7_HT_OADDRESSING_HASHTABLE_H
