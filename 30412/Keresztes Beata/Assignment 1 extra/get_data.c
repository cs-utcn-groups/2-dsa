//
// Created by q on 3/2/2020.
//

#include "get_data.h"

FILE * openFile(char * name, char * mode) {
    FILE * fp = fopen(name, mode);
    if(fp == NULL) {
        perror(FILE_ERROR_MESS);
        exit(EXIT_FAILURE);
    }
    return fp;
}

void initializeCountry(RebelT * c) {
    c->name = (char *)malloc(30*sizeof(char));
    c->first = NULL;
    c->last = NULL;
}
void addWave(RebelT * country, int x) {
    //create node
    WaveT * newWave = (WaveT *) malloc(sizeof(WaveT));
    newWave->damage = x;
    newWave->nextWave = NULL;
    //ckeck if list is empty
    if(country->first == NULL) {
        country->last = newWave;
        country->first = country->last;
    }
    else { //add new_wave as last element of the list
        country->last->nextWave = newWave;
        country->last = newWave;
    }
}

int * getEnemyData(FILE *fp, int *N, int *resistance) {

    fscanf(fp, "%d", N);
    int * sentinels = (int *) malloc((*N) * sizeof(int));
    (*resistance) = 0;
    for (int i = 0; i < *N; i++) {
        fscanf(fp, "%d", &sentinels[i]);
        (*resistance) += sentinels[i];
    }
    (*resistance)++; // the leader can be killed by 1 damage point
    return sentinels;
}
RebelT * getRebelsData(FILE *fp, int *M) {

    fscanf(fp, "%d", M);
    RebelT * countries = (RebelT *)malloc((*M) * sizeof(RebelT));
    for (int i = 0; i < *M; i++) {
        initializeCountry(&countries[i]);
        fscanf(fp, "%s", countries[i].name);

        while (fgetc(fp) != '\n' && !feof(fp)) {
            int damage;
            fscanf(fp, "%d", &damage);
            addWave(&countries[i], damage);
        }
    }
    return countries;
}
