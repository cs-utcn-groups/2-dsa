#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100000;

    char ** content = readFromFile(N);
    printContentToConsole(content,N);

    return 0;
}