//
// Created by Bori on 5/6/2020.
//

#ifndef ASSIGNMENT8_SORTING_GENERATEDATA_H
#define ASSIGNMENT8_SORTING_GENERATEDATA_H

#include <stdio.h>

void writeRandomArraysToFile(int noArrays);

void appendSortedArrayToFile_Ascending(int noArrays);

void appendSortedArrayToFile_Descending(int noArrays);

void appendRandomArraysToFile_withConstraint(int noArrays, int maxValue);

void appendSortedArrayToFile_Ascending_withConstraint(int noArrays, int maxValue);

void appendSortedArrayToFile_Descending_withConstraint(int noArrays, int maxValue);


#endif //ASSIGNMENT8_SORTING_GENERATEDATA_H
