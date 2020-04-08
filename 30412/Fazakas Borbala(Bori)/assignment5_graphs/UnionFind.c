//
// Created by Bori on 4/8/2020.
//

#include "UnionFind.h"

/*UnionFind createUnionFind(int noElements)
{
    UnionFind muUf;
    this.noElements=noElements;
    root = new int[noElements+1];
    noChildren = new int[noElements+1];
    for(int i=1; i<=noElements; i++) {
        root[i]=i;
        noChildren[i]=0;
    }
}

void union(int a, int b)
{
int rootA = getRoot(a);
int rootB = getRoot(b);
if(noChildren[rootA]<noChildren[rootB])
{
setRoot(rootA, rootB);
if(noChildren[rootA]+1>noChildren[rootB]) noChildren[rootB]+=noChildren[rootA]+1;
}
else {
setRoot(rootB, rootA);
if(noChildren[rootB]+1>noChildren[rootA]) noChildren[rootA]+=noChildren[rootB]+1;
}
printRootsArray();
}

public boolean connected(int a, int b)
{
    if(getRoot(a)==getRoot(b)) return true;
    return false;
}

private int getRoot(int a)
{
    if(root[a]==a) return a;
    else
    {
        int rootA = getRoot(root[a]);
        root[a]=rootA;
        return rootA;
    }
}

private void setRoot(int a, int newRoot)
{
    root[a]=newRoot;
}

private void printRootsArray()
{
    System.out.println(Arrays.toString(root));
}
 */
