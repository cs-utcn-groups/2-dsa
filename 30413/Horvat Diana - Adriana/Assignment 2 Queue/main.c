#include "head.h"

int main()
{
    FILE *f=fopen("input.dat","r");
    FILE *g=fopen("output.dat","w");
    readFile(f);
    cashier_money(g);

    return 0;
}
