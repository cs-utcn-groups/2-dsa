//
// Created by bindi on 3/9/2020.
//

#ifndef ASSIGNMENT_2_2_LIST_H
#define ASSIGNMENT_2_2_LIST_H
typedef struct _timeList {
    ///simple linked list w/ sentinel because we don't need to use any previous elements
    int time;
    struct _timeList *next;
} timeList;
typedef struct _timeListSentinel {
    timeList *first;
    timeList *last;
} timeListSentinel;
typedef struct _cashierList {
    ///double linked list w/ sentinel because we have to go back at times
    int money;
    int time;
    struct _cashierList *next;
    struct _cashierList *prev;
} cashierList;
typedef struct _cashierListSentinel {
    cashierList *first;
    cashierList *last;
} cashierListSentinel;

void initTimeList(void);

void initCashierList(void);

void timeAddLast(int time);

void cashierAddLast(int money, int time);

void printTimeAndMoney(FILE *output);

#endif //ASSIGNMENT_2_2_LIST_H
