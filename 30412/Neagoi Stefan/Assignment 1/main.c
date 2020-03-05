#include <stdio.h>
#include "sll.h"


int main() {

    int ct;
    initializeList();
    AF(5);
    AF(6);
    AF(21);
    DF();
    DL();
    DE(3);
    DE(6);
    AF(2);
    AL(200);
    PRINT_ALL();
    PRINT_F(3);
    ct=getListLength();
    PRINT_L(3,ct);
    DOOM_LIST();
    AF(42);
    AL(24);
    AF(9);
    PRINT_ALL();
    PRINT_L(2,ct);


    return 0;
}
