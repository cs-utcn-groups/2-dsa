//
// Created by q on 4/9/2020.
//

#include "edge.h"

EdgeT * createEdges(int N) {
    // create array of edges
    EdgeT * e = (EdgeT *)malloc(N*sizeof(EdgeT));
    if(e == NULL) {
     errMessage();
    }
    return e;
}

void printEdges(int N, EdgeT * e) {
    // print array of edges
    for(int i=0; i<N; i++) {
        printf(" (%c->%c) ",e[i].src+'A', e[i].dest+'A');
    }
    new_line;
}