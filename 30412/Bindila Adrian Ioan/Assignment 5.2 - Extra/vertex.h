//
// Created by bindi on 4/6/2020.
//

#ifndef ASSIGNMENT_5_2___EXTRA_VERTEX_H
#define ASSIGNMENT_5_2___EXTRA_VERTEX_H
typedef struct _vertex {
    int id;
    int noOfNeighbors;
    int visited;
    struct _vertex **neighbors;
} vertex;

#endif //ASSIGNMENT_5_2___EXTRA_VERTEX_H
