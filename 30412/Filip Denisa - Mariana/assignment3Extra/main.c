#include "tree.h"

#define INPUT_FILE_PATH "../input.dat"
#define ERROR_MESSAGE "Sorry, the file could not be found"

int main() {
    FILE *input = fopen(INPUT_FILE_PATH, "r");
    if (input == NULL) {
        perror(ERROR_MESSAGE);
        exit(EXIT_FAILURE);
    }
    Queue myQueue = parseMathematicalExpression(input, &myQueue);
    NodeT *root = createBinTree(&myQueue);
    printTree(root, 0);
    fclose(input);
    return 0;
}