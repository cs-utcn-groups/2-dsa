//
// Created by Diana on 3/9/2020.
//

#ifndef ASSIGNMENT_2_HEAD_H
#define ASSIGNMENT_2_HEAD_H
char * command;
char * data;
int element;
FILE * fp_input;
FILE * fp_output;
void initialize();
int readElement();
void freeMemory();
#endif //ASSIGNMENT_2_HEAD_H
