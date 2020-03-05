#include "head.h"


int main()
{
    pushStack(2);
    pushStack(3);
    pushStack(1);
    printSllData();
    popStack();
    printSllData();
    topStack();
    deleteStack();
    printSllData();



    return 0;
}
