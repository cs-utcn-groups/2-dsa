//
// Created by Bori on 4/8/2020.
//

#ifndef ASSIGNMENT5_GRAPHS_UNIONFIND_H
#define ASSIGNMENT5_GRAPHS_UNIONFIND_H

#include <stdbool.h>

typedef struct {
    int size;
    int *roots;
} UnionFind;

UnionFind createUnionFind(int noElements);

void union_f(UnionFind *myUF, int a, int b);

bool find(UnionFind *myUf, int a, int b);

#endif //ASSIGNMENT5_GRAPHS_UNIONFIND_H
