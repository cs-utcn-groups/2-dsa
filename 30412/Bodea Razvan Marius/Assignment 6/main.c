#include <stdio.h>
#include "graphRepresentation.h"
#include "Kruskal.h"
#include "BellmanFord.h"
#include "Cover.h"

int main() {

    FILE * f = fopen("..//matrix","r");
    readFromAdjMatrix(f);
    FILE *foutKruskal=fopen("..//outKruskal","w");
    kruskal(foutKruskal);
    FILE *foutBellmanFord=fopen("..//outBellmanFord","w");
    BellmanFord(0,foutBellmanFord);
    printf("%d",vCover(0));
    return 0;
}