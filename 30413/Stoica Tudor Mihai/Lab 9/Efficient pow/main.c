#include <stdio.h>
#include <stdlib.h>

int power(int base, int exp)
{

    if(exp==0)
    {
        return 1;
    }

    if(exp%2==1) /// if n odd
    {
        return base*power(base,exp/2)*power(base,exp/2);
    }

    /// if n even
    return power(base,exp/2)*power(base,exp/2);
}

int main()
{
    int base,exp;
    printf("base: ");
    scanf("%d", &base);
    printf("\n");
    printf("exponent: ");
    scanf("%d", &exp);
    printf("\n");

    printf("%li",power(base,exp));

    return 0;
}
