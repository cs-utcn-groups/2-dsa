//This sounds like it should be illegal
#include "io.h"
#include "files.h"

int main()
{
    int N = _100;
    char ** content = readFromFile(N);
    printContentToConsole(content,N);

    return 0;

}