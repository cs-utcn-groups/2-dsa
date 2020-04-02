#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int** initializeMatrix() {

    int** matrix = (int**)malloc(sizeof(int*) * 100);
    for(int i = 0; i < 100; i++) {

        matrix[i] = (int*)malloc(sizeof(int) * 100);
        memset(matrix[i], 0, 100);

    }

    return matrix;

}

int verifyIfNodeExists(int* nodes, int node, int ct) {

    for(int i = 0; i < ct; i++)
        if(nodes[i] == node)
            return 1;

    return 0;
}

void printingNewVert(int** matrix, int* nodesFirst, int ctFirst) {

    printf("aaa");
    for(int i = 0; i < ctFirst - 1; i++) {

        for(int j = i + 1; j < ctFirst; j++) {

            if(i == j)
                continue;

            if(matrix[nodesFirst[i]][nodesFirst[j]] == 1)
                printf("(%d %d) ", nodesFirst[i], nodesFirst[j]);

        }
    }
}

void putNodes(char* input, int* ct, int* nodes) {
    puts(input);
    char* tok = (char*)malloc(100);
    tok = strtok(input, " ");
    tok = strtok(NULL, " ");
    tok = strtok(NULL, " ");

    while(tok != NULL) {

        nodes[*ct] = atoi(tok);
        (*ct)++;

        tok = strtok(NULL, " \n\0");

    }
}

void readInput(int** matrix, int* nodes, int* ct, int* nodesFirst, int* ctFirst, FILE* in) {

    char* input = (char*)malloc(100);
    char* tok = (char*)malloc(100);
    int node1, node2;
    fgets(input, 100, in); /// nodes

    putNodes(input, &ct, nodes);

    fgets(input, 100, in);  /// arcs

    tok = strtok(input, " ");
    tok = strtok(NULL, " ");
    tok = strtok(NULL, " ");

    while(tok != NULL) {

        strcpy(tok, tok + 1);
        node1 = atoi(tok);
        tok = strtok(NULL, " \0\n");

        tok[strlen(tok) - 1] = '\0';
        node2 = atoi(tok);
        matrix[node1][node2] = 1;
        matrix[node2][node1] = 1;

        tok = strtok(NULL, " ");

    }

    fgets(input, 100, in); ///V'

    tok = strtok(input, " ");
    tok = strtok(NULL, " ");
    tok = strtok(NULL, " ");

    while(tok != NULL) {

        if(verifyIfNodeExists(nodes, atoi(tok), *ct) == 0) {

            printf("Node %d does not exist.\n", atoi(tok));

        } else {

            nodesFirst[*ctFirst] = atoi(tok);

            (*ctFirst)++;

        }
        tok = strtok(NULL, " \n\0");
    }

    printingNewVert(matrix, nodesFirst, *ctFirst);
}

int main(int argc, char* argv[]) {

    FILE*in = fopen(argv[1], "r");
    int** matrix = initializeMatrix();
    int* nodes = (int*)malloc(sizeof(int) * 100);
    int* nodesFirst = (int*)malloc(sizeof(int) * 100);
    int ct = 0, ctFirst = 0;
    memset(nodes, 0, 100);
    memset(nodesFirst, 0, 100);

    readInput(matrix, nodes, &ct, nodesFirst, &ctFirst, in);

    for(int i = 0; i< ct; i++)
        printf("%d ", nodes[i]);

    printf("\n\n\n");

    for(int i = 0; i < ctFirst; i++)
        printf("%d ", nodesFirst[i]);
    return 0;
}
