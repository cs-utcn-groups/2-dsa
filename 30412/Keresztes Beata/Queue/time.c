//
// Created by q on 3/6/2020.
//

#include "time.h"

TimeT * createTime(int sec) {
    TimeT * t = (TimeT *)malloc(sizeof(TimeT));
    if(t) {
        t->sec = sec;
        t->prev = t->next = NULL;
        return t;
    }
    else {
        perror(ERR_MEMORY);
        exit(EXIT_FAILURE);
    }
}

MomentT * createMoment() {
    MomentT * m = (MomentT *)malloc(sizeof(MomentT));
    if(m) {
        m->end = m->begin = NULL;
        return m;
    }
    else {
        perror(ERR_MEMORY);
        exit(EXIT_FAILURE);
    }
}
void freeTime(MomentT * momentPtr) {
    TimeT * t = momentPtr->begin;
    while(t) {
        momentPtr->begin = t->next;
        free(t);
        t = momentPtr->begin;
    }
    free(momentPtr);
}

void addTime(MomentT * momentPtr, int sec) {
    TimeT * newTime = createTime(sec);
    if(momentPtr->begin == NULL) {
        //first element added
        momentPtr->begin = newTime;
    }
    else {
        momentPtr->end->next = newTime;
        newTime->prev = momentPtr->end;
    }
    momentPtr->end = newTime;
}

MomentT * readTime(FILE * fp) {
    MomentT * momentPtr = createMoment();
    int T;
    do{
        fscanf(fp,"%d",&T);
        addTime(momentPtr,T);
    }
    while(fgetc(fp) != '\n');
    return momentPtr;
}

void printSumAtEachMoment(FILE * fp, MomentT * momentPtr, QueueT * queuePtr) {
    TimeT * time = momentPtr->begin;
    CustomerT * currCustomer;
    while(time) {
        currCustomer = findCustomer(queuePtr,time->sec);
        fprintf(fp,"After %d seconds: %d\n",time->sec,currCustomer->rubles);
        time = time->next;
    }
}