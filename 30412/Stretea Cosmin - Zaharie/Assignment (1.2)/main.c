#include "head.h"
int main() {

    input = fopen("input.dat", "r");
    output = fopen("output.dat", "w");
    getSentinelsShield();
    getCountriesAndWaves();
    int copyJimKongShield = ++JimKongShield; //we add '1' life point from 'mister'
    findStrongestWeakestLastHit();
    printResultWeakestStrongest();
    verifyStrongestCountry(copyJimKongShield);
    fclose(input);
    fclose(output);
    return 0;
}

