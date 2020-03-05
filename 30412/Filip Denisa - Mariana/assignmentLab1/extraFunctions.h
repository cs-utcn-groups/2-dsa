//
// Created by Denisa on 3/1/2020.
//

#ifndef ASSIGNMENTLAB1_EXTRAFUNCTIONS_H
#define ASSIGNMENTLAB1_EXTRAFUNCTIONS_H

#include <string.h>
#include "head.h"

#define MAX_LINE 100

void parseFromFile(char **nameOfFunction, int *key, char *line);

void callingTheFunction(FILE *input, FILE *output);

#endif //ASSIGNMENTLAB1_EXTRAFUNCTIONS_H
