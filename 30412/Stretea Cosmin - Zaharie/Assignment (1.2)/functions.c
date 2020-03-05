//
// Created by Cosmin on 04-Mar-20.
//
#include "head.h"

void addLastNode(int val, wave **first, wave **last) {

    if ((*last) == NULL) {
        (*last) = (wave *) malloc(sizeof(wave));
        (*last)->damage = val;
        (*last)->next = NULL;
        (*first) = (*last);
    } else {
        wave *newNode = (wave *) malloc(sizeof(wave));
        newNode->damage = val;
        newNode->next = NULL;
        (*last)->next = newNode;
        (*last) = newNode;
    }
}

void deleteFirstNode(wave **first) {
    wave *currentNode = (*first);
    (*first) = (*first)->next;
    free(currentNode);
}
int thereIsAWave(){
    for (int i = 0; i < M; i++) {
        if ((countryList + i)->firstWave)
            return 1;
    }
    return 0;
}
void printAll(){
    for (int i = 0; i < M; i++) {
        printf("%s:", countryList[i].name);
        country currentCountry = countryList[i];
        while (currentCountry.firstWave) {
            printf("%d ", currentCountry.firstWave->damage);
            currentCountry.firstWave = currentCountry.firstWave->next;
        }
        printf("\n");
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", sentinel[i]);
    }
}
void getCountriesAndWaves(){
    fscanf(input, "%d", &M);
    getc(input);
    countryList = (country *) malloc(M * sizeof(country));
    for (int i = 0; i < M; i++) {
        (countryList + i)->totalDamage = 0;
        (countryList + i)->name = (char *) malloc(MAX_NAME * sizeof(char));
        fscanf(input, "%s", (countryList + i)->name);
        getc(input);
        (countryList + i)->firstWave = NULL;
        (countryList + i)->lastWave = NULL;
        int damageCopy, c;
        do{
            fscanf(input, "%d", &damageCopy);
            c = fgetc(input);
            addLastNode(damageCopy, &(countryList + i)->firstWave, &(countryList + i)->lastWave);
        }while(c != '\n' && c != EOF);
    }
}
void getSentinelsShield(){
    fscanf(input, "%d", &N);
    getc(input);
    sentinel = (int *) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        fscanf(input, "%d", &sentinel[i]);
        getc(input);
        JimKongShield += sentinel[i];
    }
}
void findStrongestWeakestLastHit(){
    maxDamage = minDamage = countryList[0].firstWave->damage;
    while (JimKongShield > 0 && thereIsAWave()) {
        for (int i = 0; i < M; i++) {
            if((countryList + i)->firstWave) {
                int damageDealt = (countryList + i)->firstWave->damage;
                JimKongShield -= damageDealt;
                (countryList + i)->totalDamage += damageDealt;
                int currentTotalDamage = (countryList + i)->totalDamage;
                deleteFirstNode(&(countryList + i)->firstWave);

                if (JimKongShield <= 0) {
                    strcpy(lastHit, (countryList + i)->name);
                    break;
                }

                if (currentTotalDamage > maxDamage) {
                    maxDamage = currentTotalDamage;
                    strcpy(strongest, (countryList + i)->name);

                } else if (currentTotalDamage < minDamage) {
                    minDamage = currentTotalDamage;
                    strcpy(weakest, (countryList + i)->name);
                }
            }
        }
    }
}
void verifyStrongestCountry(int copyJimKongShield){
    for (int i = 0; i < M; i++) {
        if ((countryList + i)->totalDamage > copyJimKongShield) {
            killEmAll = 1; //check if there was a country which could have defeated the boss
            break;
        }
    }
    if (killEmAll == 0) {
        fprintf(output, "No country could have defeated all the sentinels.\n");
        int indCurrentSentinel = 0;
        while(maxDamage > 0 && indCurrentSentinel<N){      //if not we find how many sentinels has the strongest country brought down
            if(maxDamage > sentinel[indCurrentSentinel]) {
                maxDamage -= sentinel[indCurrentSentinel];
                indCurrentSentinel++;
            }
            else
                break;
        }
        fprintf(output,"%s could have brought down the first %d sentinels and would have had chipped off %d life points from sentinel %d.", strongest, indCurrentSentinel, maxDamage, indCurrentSentinel+1);
    } else {
        fprintf(output, "The country which could have defeated all the sentinels is: %s\n", strongest); //else we print the strongest
    }
}
void printResultWeakestStrongest(){
    if (JimKongShield <= 0) {
        fprintf(output, "The tyrant was killed!\n");
    } else {
        fprintf(output, "The tyrant was not killed!\n");
    }
    if (JimKongShield <= 0) {
        fprintf(output, "The last hit was done by: %s\n", lastHit);
    }
    fprintf(output, "The strongest country was: %s\n", strongest);
    fprintf(output, "The weakest country was: %s\n", weakest);
}
