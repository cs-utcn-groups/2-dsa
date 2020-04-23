//
// Created by csatl on 4/8/2020.
//

#include <stdbool.h>

#ifndef A6_EDGE_H

typedef struct edge {
    int source;
    int destination;
    int weight;
    bool added;
} edgeT;
#define A6_EDGE_H

#endif //A6_EDGE_H
