//
// Created by Andreea on 3/2/2020.
//

#ifndef EXTRA_SLL_H
#define EXTRA_SLL_H
#define MAX_NAME 30
#define MAX_LINE 256

typedef struct waveL
{
    int damage;
    struct waveL *next;
}wave;
typedef struct countryL
{
    wave *first, *last;
    char name[MAX_NAME];
    struct countryL *next;
}country;
typedef struct sentinelL
{
    int lifePoints;
    int remainingLifePoints;
    struct sentinelL *next;
}sentinel;
country *firstCountry, *lastCountry;
sentinel *firstSentinel, *lastSentinel;

void initializeSentinel();
void initializeCountry();
void addSentinel(int lifePoints);
void addCountry(char name[]);
void addWave(int damage, country* currentCountry);
void deleteWave(country *currentCountry);

#endif //EXTRA_SLL_H
