#include "santinels.h"

int main() {

    input = fopen("input.dat", "r");
    output = fopen("output.dat", "w");
    inputSentinels();
    inputCountriesWithWaves();
    int JimKongShieldCopy = ++JimKongNuShield; //we add '1' so the code can work :)
    findExtremasLastHit();
    printExtremasResult();
    verifyStrongestCountry(JimKongShieldCopy);
    fclose(input);
    fclose(output);
    return 0;
}