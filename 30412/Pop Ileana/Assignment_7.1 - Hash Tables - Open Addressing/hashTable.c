#include "hashTable.h"

void freeTable();

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    size = INITIAL_HT_SIZE_FACTOR * N;
    hashTable = (char **)malloc(sizeof(char*)*size);
    for(int i=0;i<size;i++)
        *(hashTable+i)=NULL;
    maxNumberOfCollisions=resizes =0;
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;
    int nbOfKeysStored =0;
    for(int i=0; i<size; i++)
        if(*(hashTable+i)!=NULL)
            nbOfKeysStored++;
    fillFactor = (float) nbOfKeysStored/size;
    return fillFactor;
}

void resizeHashTable(int (*hash)(char*,int))
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
    resizes++;
    printf("\nresize\n");
    size = size*2;
    char ** hashTable2;
    hashTable2 = (char **)malloc(size*sizeof(char*));
    if(hashTable2 == NULL)
    {
        perror("Could not allocate memory");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<size;i++)
        *(hashTable2 + i)=NULL;
    for(int i=0;i<size/2;i++)
        if(hashTable[i]!=NULL)
        {
            int j=0,h;
            h=hash(hashTable[i],j);
            while(hashTable2[h]!=NULL)
                h=hash(hashTable[i],++j);
            hashTable2[h]=(char*)malloc(MAX_STRING_LENGTH*sizeof(char));
            strcpy(hashTable2[h],hashTable[i]);
        }
    freeTable();
    hashTable = hashTable2;
    printf("\nresize\n");
}

int insertElement(char * element,int (*hash)(char*,int))
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    int nbOfCollisions,i;

    if(getFillFactor()>MAX_FILL_FACTOR)
        resizeHashTable(hash);

    nbOfCollisions=i=0;

    int h=hash(element,i);

    while(hashTable[h]!=NULL)
    {
        h=hash(element,++i);
        nbOfCollisions++;
    }

    hashTable[h]=(char*)malloc(MAX_STRING_LENGTH*sizeof(char));
    strcpy(hashTable[h],element);

    return nbOfCollisions;
}


int hashFunction1(char * content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum+i) % size;
}

int hashFunction2(char * content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum+i*i)%size;
}
int hashFunction3(char * content, int i)
{
    return (hashFunction1(content,i)+hashFunction2(content,i)+i*i)%size;
}
void freeTable()
{
    for(int i=0;i<size/2;i++)
        free(hashTable[i]);
    free(hashTable);
}
