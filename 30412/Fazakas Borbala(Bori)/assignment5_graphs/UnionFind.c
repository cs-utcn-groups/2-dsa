//
// Created by Bori on 4/8/2020.
//

#include "UnionFind.h"
#include <stdlib.h>

UnionFind createUnionFind(int noElements)
{
    UnionFind myUf;
    myUf.size = noElements;
    myUf.roots = (int*) malloc(sizeof(int)*(noElements+1));
    for(int i=1; i<=noElements; i++){
        myUf.roots[i]=i;
    }
    return myUf;
}

static int getRoot(UnionFind* myUf, int a) //path compression
{
    if(myUf->roots[a]==a) return a;
    else
    {
        int rootA = getRoot(myUf, myUf->roots[a]);
        myUf->roots[a]=rootA;
        return rootA;
    }
}

void setRoot(UnionFind* myUf, int a, int newRoot)
{
    myUf->roots[a]=newRoot;
}

void union_f(UnionFind* myUf, int a, int b)
{
    int rootA = getRoot(myUf, a);
    int rootB = getRoot(myUf, b);
    setRoot(myUf, rootA, rootB);
}

bool find(UnionFind* myUf, int a, int b)
{
    if(getRoot(myUf, a)==getRoot(myUf, b)) return true;
    return false;
}

