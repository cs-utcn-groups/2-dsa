#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {

    char* op;
    struct tree* left,* right;

} treeT;

void initializeChar(treeT* node) {

    node->op = (char*)malloc(10);
    node->left = NULL;
    node->right = NULL;

}

int verifyArray(char* array) {

    int size = strlen(array);

    for(int i = 0; i < size; i++) {

        if(!((array[i] >= '0' && array[i] <= '9') || array[i] == '*' || array[i] == '/' || array[i] == '+' || array[i] == '-' || array[i] == '.'))
            return 0;

    }

    return 1;
}

treeT* createTree() {

    char* array = (char*)malloc(10);

    if(gets(array) != NULL) {

        if(verifyArray(array) == 1) {

            treeT* current = (treeT*)malloc(sizeof(treeT));
            initializeChar(current);
            strcpy(current->op, array);

            if(strcmp(array, "+") == 0 ||  strcmp(array, "-") == 0 || strcmp(array, "/") == 0 || strcmp(array, "*") == 0 ) {

                current->left = createTree();
                current->right = createTree();

            }

            return current;

        } else {

            printf("Please read a valid input.\n");

        }
    }
    else
        return NULL;

}

void print(treeT* current, int level) {

    if(current == NULL)
        return;

    print(current->right, level + 1);

    for(int i = 0; i < level; i++)
        printf("   ");

    printf("%s\n", current->op);
    print(current->left, level + 1);

}

int main() {

    FILE* in = fopen("input.txt", "r");

    if(in == NULL)
        return -1;

    treeT* root = createTree(in);

    print(root, 0);
    return 0;
}
