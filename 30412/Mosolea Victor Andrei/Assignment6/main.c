#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct edge{
    int startNode, endNode;
    struct edge *next;
    int weight;
}Edge;

typedef struct edgeList{
    Edge *first,*last;
}EdgeList;

int find(int *parent,int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int *parent,int x, int y){
    int xset=find(parent,x);
    int yset=find(parent,y);
    if(xset!=yset)
        parent[xset]=yset;
}

bool hasCycle(EdgeList list,int noOfEdges) {
    int *parent=(int*)malloc(noOfEdges*sizeof(int));
    for(int i=0;i<noOfEdges;i++)
        parent[i]=-1;
    Edge *currentEdge=list.first;
    while(currentEdge!=NULL) {
        int x=find(parent,currentEdge->startNode);
        int y=find(parent,currentEdge->endNode);
        if(x==y)
            return true;
        Union(parent,x,y);
        currentEdge=currentEdge->next;
    }
    return false;
}

void initEdgeList(EdgeList *list){
    list->first=NULL;
    list->last=NULL;
};

void addLastEdge(int startNode, int endNode, int weight, EdgeList *list) {
    Edge *newEdge = (Edge *) malloc(sizeof(Edge));
    newEdge->startNode = startNode;
    newEdge->endNode=endNode;
    newEdge->weight=weight;
    newEdge->next = NULL;
    if (list->first == NULL) {
        list->first = newEdge;
        list->last = list->first;
        list->last->next = NULL;
    } else
        list->last->next = newEdge;
    list->last = newEdge;
}
void deleteLastEdge(EdgeList *list){
    if(list->first==list->last) {
        free(list->first);
        initEdgeList(list);
    }
    else if(list->first!=NULL) {
        Edge *aux = list->first;
        while (aux->next->next != NULL)
            aux = aux->next;
        free(list->last);
        aux->next=NULL;
        list->last=aux;
    }
}

void swapContent(Edge *a,Edge *b){
    int start=a->startNode;
    a->startNode=b->startNode;
    b->startNode=start;
    int weight=a->weight;
    a->weight=b->weight;
    b->weight=weight;
    int end=a->endNode;
    a->endNode=b->endNode;
    b->endNode=end;
}

void sortEdgeList(EdgeList *list){
    Edge *i=list->first;
    while(i!=NULL) {
        Edge *j = i->next;
        while(j!=NULL){
            if(j->weight<i->weight)
                swapContent(i,j);
                 j=j->next;
        }
        i=i->next;
    }
}

void kruskal(EdgeList list,int noOfVertices){
    sortEdgeList(&list);
    EdgeList result;
    initEdgeList(&result);
    Edge *currentEdge=list.first;
    while(currentEdge!=NULL){
        addLastEdge(currentEdge->startNode,currentEdge->endNode,currentEdge->weight,&result);
        if(hasCycle(result,noOfVertices)==true)
            deleteLastEdge(&result);

        currentEdge=currentEdge->next;
    }
    printf("The edges included in the MST are:\n");
    currentEdge=result.first;
    while(currentEdge!=NULL){
        printf("%d---%d\n",currentEdge->startNode,currentEdge->endNode);
        currentEdge=currentEdge->next;
    }
    printf("\n");
}

void bellmanFord(int noOfVertices, int src, EdgeList list){
    int *distance=(int*)malloc(noOfVertices*sizeof(int));
    for(int i=0;i<noOfVertices;i++)
        distance[i]=INT_MAX;
    distance[src]=0;
    for(int i=0;i<noOfVertices-1;i++) {
        Edge *currentEdge = list.first;
        while (currentEdge != NULL) {
            if (distance[currentEdge->startNode] != INT_MAX &&
                distance[currentEdge->endNode] > distance[currentEdge->startNode] + currentEdge->weight)
                distance[currentEdge->endNode] = distance[currentEdge->startNode] + currentEdge->weight;
            currentEdge = currentEdge->next;
        }
    }
    printf("The distance from %d to every vertex is:\n",src);
    for(int i=0;i<noOfVertices;i++)
        printf("%d ",distance[i]);
    printf("\n");
}

int main() {
    int noOfVerticesK;
    FILE *f=fopen("../input.dat","r");
    fscanf(f,"%d",&noOfVerticesK);
    EdgeList edgListK;
    initEdgeList(&edgListK);
    int **adjMatrixK=(int**)malloc(noOfVerticesK*sizeof(int*));
    for(int i=0;i<noOfVerticesK;i++)
        adjMatrixK[i]=(int*)malloc(noOfVerticesK*sizeof(int));
    for(int i=0;i<noOfVerticesK;i++)
        for(int j=0;j<noOfVerticesK;j++)
            fscanf(f,"%d",&adjMatrixK[i][j]);
    for(int i=0;i<noOfVerticesK-1;i++)
        for(int j=i+1;j<noOfVerticesK;j++)
            if(adjMatrixK[i][j]>0)
                addLastEdge(i,j,adjMatrixK[i][j],&edgListK);
            kruskal(edgListK,noOfVerticesK);

    int noOfVerticesBF;
    fscanf(f,"%d",&noOfVerticesBF);
    EdgeList edgListBF;
    initEdgeList(&edgListBF);
    int **adjMatrixBF=(int**)malloc(noOfVerticesBF*sizeof(int*));
    for(int i=0;i<noOfVerticesBF;i++)
        adjMatrixBF[i]=(int*)malloc(noOfVerticesBF*sizeof(int));
    for(int i=0;i<noOfVerticesBF;i++)
        for(int j=0;j<noOfVerticesBF;j++)
            fscanf(f,"%d",&adjMatrixBF[i][j]);
    for(int i=0;i<noOfVerticesBF;i++)
            for(int j=0;j<noOfVerticesBF;j++)
                if(adjMatrixBF[i][j]!=0)
                addLastEdge(i,j,adjMatrixBF[i][j],&edgListBF);
    bellmanFord(noOfVerticesBF,0,edgListBF);

    return 0;
}
