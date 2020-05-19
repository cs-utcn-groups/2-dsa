#include <stdio.h>
#include "functions.h"

int main() {
    Init();
    //readMatrix();
    matrixToList();
    listToMatrix();

    bfs(0);
    dfs(0);
}