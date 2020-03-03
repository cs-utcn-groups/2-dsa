//
// Created by bindi on 3/2/2020.
//
#include <stdio.h>
#include <string.h>
#include "list.h"

int readCommand(char *buffer) {
    //We assign a number to each command
    //AF - 1
    //AL - 2
    //DF - 3
    //DL - 4
    //DOOM_THE_LIST - 5
    //DE - 6
    //PRINT_ALL - 7
    //PRINT_F - 8
    //PRINT_L - 9
    if (strstr(buffer, "AF")) {
        return 1;
    }
    if (strstr(buffer, "AL")) {
        return 2;
    }
    if (strstr(buffer, "DF")) {
        return 3;
    }
    if (strstr(buffer, "DL")) {
        return 4;
    }
    if (strstr(buffer, "DOOM_THE_LIST")) {
        return 5;
    }
    if (strstr(buffer, "DE")) {
        return 6;
    }
    if (strstr(buffer, "PRINT_ALL")) {
        return 7;
    }
    if (strstr(buffer, "PRINT_F")) {
        return 8;
    }
    if (strstr(buffer, "PRINT_L")) {
        return 9;
    }
    return 0;///Error
}

void executeCommand(int commandNo, int x) {
    switch (commandNo) {
        case 1:
            addFirst(x);
            break;
        case 2:
            addLast(x);
            break;
        case 3:
            deleteFirst();
            break;
        case 4:
            deleteLast();
            break;
        case 5:
            doomTheList();
            break;
        case 6:
            deleteElement(x);
            break;
        case 7:
            printAll();
            break;
        case 8:
            printFirst(x);
            break;
        case 9:
            printLast(x);
            break;
        default:
            printf("Warning! Erroneous command detected!\n");
    }
}