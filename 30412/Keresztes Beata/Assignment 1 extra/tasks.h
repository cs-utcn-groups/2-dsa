//
// Created by q on 3/2/2020.
//

#ifndef ASSIGNMENT_1_EXTRA_TASKS_H
#define ASSIGNMENT_1_EXTRA_TASKS_H

#endif //ASSIGNMENT_1_EXTRA_TASKS_H

#include "get_data.h"
#include "limits.h"
/*
 * the rebellion of the other countries
 */
void rebellion(FILE * fp, int M, RebelT * countries, int resistance);
/*
 * first find the max no of waves = max length of the battle
 * then allocate memory to the waves of attack
 */
int findMaxNoOfWaves( int M, RebelT * countries);
WaveT ** prepareAttacks(int M, RebelT * countries);
/*
 * after the actual attack took place, return the index of the country which dealt the last blow (if any),
 * and draw the conclusion about the result of the rebellion,
 * also clean the battle field
 */
int attackingEnemy(int M, WaveT ** attacks, int resistance);
void resultOfAttack(FILE * fp, RebelT * countries, int finalBlowIndex);
void cleanBattleField(int M, WaveT ** attacks);
/*
 * analyze the strength/ weakness of each country
 */
int findWeakest(int M, RebelT * countries);
int findStrongest(int M, RebelT * countries, int * maxPower);
/*
 * determine whether individual victory would have been possible
 */
int noSentinelsDefeatedByOne(int N, int * sentinels, int * power);
void defeatAlone(FILE * fp, int N, int * sentinels, int resistance, RebelT strongestCountry, int maxPower);