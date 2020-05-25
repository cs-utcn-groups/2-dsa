#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int mark[100];

typedef struct node
{

    int id;
    struct node* next;

} nextT;

nextT* first,* last;

void initialize()
{
    last = first = NULL;
}

int** initializeMatrix()
{
    int** matrix = (int**)malloc(sizeof(int*) * 100);
    int i;
    for(i = 0; i < 100; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int) * 100);
        memset(matrix[i], 0, 400);
    }

    return matrix;
}

void readInput(int** matrix, FILE* in)
{
    char* input = (char*)malloc(100);
    char* tok = (char*)malloc(100);
    int node1, node2;

    fgets(input, 100, in); /// nodes

    fgets(input, 100, in);  /// arcs
    tok = strtok(input, " ");
    tok = strtok(NULL, " ");

    while(tok != NULL)
    {
        tok = strtok(NULL, " ");
        strcpy(tok, tok + 1);
        node1 = atoi(tok);

        tok = strtok(NULL, ")\0\n");
        node2 = atoi(tok);
        matrix[node1][node2] = 1;
        matrix[node2][node1] = 1;

    }
}

void addNode(int id)
{

    if(first == NULL)
    {

        first = (nextT*)malloc(sizeof(nextT));
        first->id = id;
        first->next = last;
        last = first;

    }
    else
    {

        nextT* current = (nextT*)malloc(sizeof(nextT));
        current->id = id;
        current->next = NULL;
        last->next = current;
        last = current;

    }
}

void deleteFirst()
{

    if(first == NULL)
        return;

    if(first->next == NULL)
    {

        free(first);
        initialize();
        return;

    }
    nextT* current = first;
    first = first->next;
    free(current);

}

void deleteLast()
{


    if(first->next == last)
    {

        nextT* current = last;
        last = first;
        first->next = last->next = NULL;
        free(current);
        return;

    }

    if(first->next == NULL)
    {

        free(first);
        initialize();

    }
    if(last == NULL)
        return;

    nextT* current = first;

    while(current->next != last)
        current = current->next;

    last = current;
    current = last->next;
    free(current);
    last->next = NULL;

}

void BFS(int node, int** matrix)
{

    addNode(node);
    mark[node] = 1;
    int i;
    while(first != NULL)
    {
        node = first->id;
        printf("%d ", node);
        deleteFirst();

        for( i = 0; i < 100; i++)
        {
            if(matrix[node][i] == 1)
            {
                if(mark[i] == 0)
                {

                    mark[i] = 1;
                    addNode(i);


                }
            }
        }
    }
}

void DFS(int node, int** matrix)
{

    int find = 0;
    addNode(node);
    int mark[100];
    memset(mark, 0, 100);
    mark[node] = 1;
    printf("%d ", node);
    int i;
    while(first != NULL)
    {

        node = last->id;
        find = 0;

        for(i = 0; i < 100 && !find; i++)
        {

            if(matrix[node][i] == 1)
            {
                if(mark[i] == 0)
                {

                    printf("%d ", i);
                    mark[i] = 1;
                    addNode(i);
                    find = 1;
                }
            }
        }

        if(find == 0)
        {
            deleteLast();
        }
    }
}

int main(int argc, char* argv[])
{

    FILE* in = fopen(argv[1], "r");

    int** matrix = initializeMatrix();
    readInput(matrix, in);

    printf("Breath first search: ");
    BFS(2, matrix);
    printf("\n");

    printf("Depth first search: ");
    DFS(2, matrix);
    return 0;
}
