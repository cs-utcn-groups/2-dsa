//
// Created by acer on 3/3/2020.
//

#include "santinels.h"

void addLastNode(int val, Wave **first, Wave **last) {

    if ((*last) == NULL) {
        (*last) = (Wave *) malloc(sizeof(Wave));
        (*last)->damage = val;
        (*last)->next = NULL;
        (*first) = (*last);
    } else {
        Wave *newNode = (Wave *) malloc(sizeof(Wave));
        newNode->damage = val;
        newNode->next = NULL;
        (*last)->next = newNode;
        (*last) = newNode;
    }
}

void deleteFirstNode(Wave **first) {
    Wave *currentNode = (*first);
    (*first) = (*first)->next;
    free(currentNode);
}

int waveExists(){
    for (int i = 0; i < M; i++)
        if (listOfCountries[i].first)
            return 1;
    return 0;
}

void inputCountriesWithWaves(){
    fscanf(input, "%d", &M);
    getc(input);
    listOfCountries = (Country *) malloc(M * sizeof(Country));
    for (int i = 0; i < M; i++) {
        listOfCountries[i].allDamage = 0;
        listOfCountries[i].name = (char *) malloc(MAX_NAME_LIST * sizeof(char));

        fscanf(input, "%s", listOfCountries[i].name);
        getc(input);

        listOfCountries[i].first = NULL;
        listOfCountries[i].last = NULL;
        int damageCopy, c;
        do{
            fscanf(input, "%d", &damageCopy);
            c = fgetc(input);
            addLastNode(damageCopy, &listOfCountries[i].first, &listOfCountries[i].last);
        }while(c != '\n' && c != EOF);
    }
}
void inputSentinels(){
    fscanf(input, "%d", &N);
    getc(input);
    santinel = (int *) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        fscanf(input, "%d", &santinel[i]);
        getc(input);
        JimKongNuShield += santinel[i];
    }
}
void findExtremasLastHit(){
    maxDamage = minDamage = listOfCountries[0].first->damage;
    while (JimKongNuShield > 0 && waveExists()) {
        for (int i = 0; i < M; i++) {
            if(listOfCountries[i].first) {
                int damageDealt = listOfCountries[i].first->damage;
                JimKongNuShield -= damageDealt;
                listOfCountries[i].allDamage += damageDealt;
                int currentTotalDamage = listOfCountries[i].allDamage;
                deleteFirstNode(&listOfCountries[i].first);

                if (JimKongNuShield <= 0) {
                    strcpy(lastHit, listOfCountries[i].name);
                    break;
                }

                if (currentTotalDamage > maxDamage) {
                    maxDamage = currentTotalDamage;
                    strcpy(strongest, listOfCountries[i].name);

                } else if (currentTotalDamage < minDamage) {
                    minDamage = currentTotalDamage;
                    strcpy(weakest, listOfCountries[i].name);
                }
            }
        }
    }
}
void verifyStrongestCountry(int copyJimKongShield){
    for (int i = 0; i < M; i++) {
        if (listOfCountries[i].allDamage > copyJimKongShield) {
            allDie = 1;
            break;
        }
    }
    if (allDie == 0) {
        fprintf(output, "No country could have defeated all the sentinels.\n");
        int indCurrentSentinel = 0;
        while(maxDamage > 0 && indCurrentSentinel<N){
            if(maxDamage > santinel[indCurrentSentinel]) {
                maxDamage -= santinel[indCurrentSentinel];
                indCurrentSentinel++;
            }
            else
                break;
        }
        fprintf(output,"%s could have brought down the first %d sentinels and would have had chipped off %d life points from santinel %d.", strongest, indCurrentSentinel, maxDamage, indCurrentSentinel+1);
    } else {
        fprintf(output, "The country which could have defeated all the sentinels is: %s\n", strongest);
    }
}
void printExtremasResult(){
    if (JimKongNuShield <= 0) {
        fprintf(output, "The tyrant was killed!\n");
    } else {
        fprintf(output, "The tyrant was not killed!\n");
    }
    if (JimKongNuShield <= 0) {
        fprintf(output, "The last hit was done by: %s\n", lastHit);
    }
    fprintf(output, "The strongest country was: %s\n", strongest);
    fprintf(output, "The weakest country was: %s\n", weakest);
}