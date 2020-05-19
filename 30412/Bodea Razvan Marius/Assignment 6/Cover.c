#include "Cover.h"

int vCover(NodeT *root)
{
    createListFromMatrix(nrOfVertexes);
    // The size of minimum vertex cover is zero if tree is empty or there is only one node
    if (root == NULL)
        return 0;
    if (root->prev == NULL && root->next == NULL)
        return 0;

    // Calculate size of vertex cover when root is part of it
    int size_incl = 1 + vCover(root->prev) + vCover(root->next);

    // Calculate size of vertex cover when root is not part of it
    int size_excl = 0;
    if (root->prev)
        size_excl += 1 + vCover(root->prev->prev) + vCover(root->prev->next);
    if (root->next)
        size_excl += 1 + vCover(root->next->prev) + vCover(root->next->next);

    // Return the minimum of two sizes
    return min(size_incl, size_excl);
}

int min(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

NodeT *createListFromMatrix(int noOfVertices) {
    NodeT *adjList = (NodeT *) malloc(noOfVertices * sizeof(NodeT));
    for (int i = 0; i < noOfVertices; i++)
        for (int j = 0; j < noOfVertices; j++)
            if (adjMatrix[i][j] > 0)
                enqueue(j);
    return adjList;
}