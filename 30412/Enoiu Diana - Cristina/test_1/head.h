//
// Created by Diana on 3/10/2020.
//

#ifndef TEST_1_HEAD_H
#define TEST_1_HEAD_H
typedef struct _orglist {
    struct _orglist * next;
    int data;
}originalList;
originalList * first, * last;
typedef struct _sublist1 {
    struct _sublist1 * next;
    int data;
}sublist_1;
sublist_1 * first_1, * last_1;
typedef struct _sublist2 {
    struct _sublist2 * next;
    int data;
}sublist_2;
sublist_2 * first_2, * last_2;
void initializeOrgList ();
void initializeSublist1();
void initializeSublist2();
void addFirst (int data);
void printAllOrgList(FILE * out);
void AlternatingSplit(originalList * source);
void printAllSublist1(FILE * out);
void printAllSublist2(FILE * out);
#endif //TEST_1_HEAD_H
