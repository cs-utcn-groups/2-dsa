//
// Created by q on 3/2/2020.
//

#include "tasks.h"

void rebellion(FILE * fp, int M, RebelT * countries, int resistance) {

    WaveT ** attacks = prepareAttacks(M, countries);
    int maxNoOfWaves = findMaxNoOfWaves(M, countries);
    int finalBlowIndex = -1;
    for (int k = 0; k < maxNoOfWaves; k++) {
        finalBlowIndex = attackingEnemy(M, attacks, resistance);
        if(finalBlowIndex > -1) {
            break;
        }
    }
    resultOfAttack(fp, countries, finalBlowIndex);
    cleanBattleField(M, attacks);
}

int findMaxNoOfWaves(int M, RebelT * countries) {

    int Max=0;
    for(int i=0;i<M;i++) {
        int max=0;
        WaveT * temp=countries[i].first;
        while(temp) {
            max++;
            temp=temp->nextWave;
        }
        if(max>Max) {
            Max=max;
        }
    }
    return Max;
}
WaveT ** prepareAttacks(int M, RebelT * countries) {

    WaveT ** attacks = (WaveT **) malloc(M * sizeof(WaveT *));
    if(attacks) {
        for (int i = 0; i < M; i++) {
            attacks[i] = (WaveT *) malloc(sizeof(WaveT));
            attacks[i] = countries[i].first;
        }
        return attacks;
    }
    else {
        perror(MEM_ALLOC_ERROR);
        exit(EXIT_FAILURE);
    }
}

int attackingEnemy(int M, WaveT ** attacks, int resistance) {

   static int amountOfDamage = 0;

    for (int index = 0; index < M; index++) {
        if (attacks[index]) {
            amountOfDamage += attacks[index]->damage;
            attacks[index] = attacks[index]->nextWave;

            if (amountOfDamage >= resistance) {
                return index;
            }
        }
    }
    return -1;
}

void resultOfAttack(FILE * fp, RebelT * countries, int finalBlowIndex) {
    if (finalBlowIndex > -1) {
        fprintf(fp,"The tyrant was killed!\n");
        fprintf(fp,"The last hit was done by: %s\n", countries[finalBlowIndex].name);
    } else {
        fprintf(fp,"The tyrant could not be killed!\n");
        fprintf(fp,"No country had the hitting blow.\n");
    }
}
void cleanBattleField(int M, WaveT ** attacks) {
    for (int i = 0; i < M; i++) {
        free(attacks[i]);
    }
    free(attacks);
}

int findWeakest(int M, RebelT * countries) {

    int weakestIndex = -1, minPower = INT_MAX;
    for (int i = 0; i < M; i++) {
        int power = 0;
        WaveT *temp = countries[i].first;
        while (temp != NULL) {
            power += temp->damage;
            temp = temp->nextWave;
        }
        if (power < minPower) {
            minPower = power;
            weakestIndex = i;
        }
    }
    return weakestIndex;
}
int findStrongest(int M, RebelT * countries, int * maxPower) {

    int strongestIndex = -1; * maxPower = 0;
    for (int i = 0; i < M; i++) {
        int power = 0;
        WaveT * temp = countries[i].first;
        while (temp != NULL) {
            power += temp->damage;
            temp = temp->nextWave;
        }
        if (power > (* maxPower)) {
            * maxPower = power;
            strongestIndex = i;
        }
    }
    return strongestIndex;
}

int noSentinelsDefeatedByOne(int N, int * sentinels, int * power) {

    for(int i=0; i<N; i++) {
        if(*power >= sentinels[i]) {
            *power -= sentinels[i];
        }
        else {
            return i;
        }
    }
    return -1;
}

void defeatAlone(FILE *fp, int N, int * sentinels, int resistance, RebelT strongestCountry, int maxPower) {

    if (maxPower >= resistance) {
        fprintf(fp, "%s could have won alone\n", strongestCountry.name);
    } else {
        fprintf(fp, "No countries could have defeated all the sentinels.\n");
        int remainingPower = maxPower;
        int lastDefeated = noSentinelsDefeatedByOne(N, sentinels, &remainingPower);
        if (lastDefeated > -1) {
            fprintf(fp, "%s could have brought down the first %d sentinels and would"
                        " have had chipped off %d life points from sentinels %d.\n",
                    strongestCountry.name, lastDefeated, remainingPower, lastDefeated + 1);
        }
    }
}