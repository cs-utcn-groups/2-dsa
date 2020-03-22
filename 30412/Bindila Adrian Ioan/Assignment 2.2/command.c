//
// Created by bindi on 3/9/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void readTime(char *buffer) {
    buffer = strtok(buffer, " \n");
    char *ptr;
    int time = strtol(buffer, &ptr, 10);
    timeAddLast(time);
    while (buffer != NULL) {
        buffer = strtok(NULL, " ");
        time = strtol(buffer, &ptr, 10);
        timeAddLast(time);
    }
}