#include <stdio.h>
#include "graphRepresentation.h"
#include "graphTraversals.h"

int main() {

    FILE *f = fopen("list.txt", "r");
    //readFromAdjMatrix(f);
    readFromList(f);
    //printAdjMatrix();
    bfs('A' - 'A');
    dfs('A' - 'A');
    dfsRecurs('A' - 'A');
    return 0;
}
/*!
 * the list.txt has first line the number of vertices (n) and
 * then n lines with number of neighbours
 *      @ the vertices starts counting from 1 @
 */