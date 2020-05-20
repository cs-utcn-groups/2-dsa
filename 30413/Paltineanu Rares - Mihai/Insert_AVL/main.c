#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {

    int id;
    int height;
    struct tree* left,* right;


} treeT;

treeT* root;

treeT* initialize(treeT* current) {

    current = (treeT*)malloc(sizeof(treeT));
    current->left = current->right = NULL;
    current->height = 1;
    return current;

}

int height(treeT* current) {

    if(current == NULL)
        return 0;
    else
        return current->height;

}

int balance(treeT* current) {

    if(current == NULL)
        return 0;
    else
        return height(current->left) - height(current->right);

}

treeT* leftRotate(treeT* current) {

    treeT* aux1 = current->right;
    treeT* aux2 = aux1->left;

    aux1->left = current;
    current->right = aux2;

    if(height(current->left) > height(current->right))
        current->height = height(current->left) + 1;
    else
        current->height = height(current->right) + 1;

    if(height(aux1->left) > height(aux1->right))
        aux1->height = height(aux1->left) + 1;
    else
        aux1->height = height(aux1->right) + 1;

    return aux1;


}

treeT* rightRotate(treeT* current) {

    treeT* aux1 = current->left;
    treeT* aux2 = aux1->right;

    aux1->right = current;
    current->left = aux2;

    if(height(current->left) > height(current->right))
        current->height = height(current->left) + 1;
    else
        current->height = height(current->right) + 1;

    if(height(aux1->left) > height(aux1->right))
        aux1->height = height(aux1->left) + 1;
    else
        aux1->height = height(aux1->right) + 1;

    return aux1;

}

treeT* insert(treeT* current, int id) {

    if(current == NULL) {

        current = initialize(current);
        current->id = id;

    } else {

        if(id > current->id)
            current->right = insert(current->right, id);
        else if(id < current->id)
            current->left = insert(current->left, id);

    }

    if(height(current->left) > height(current->right))
        current->height = 1 + height(current->left);
    else
        current->height = 1 + height(current->right);

    int balanceValue = balance(current);


    if (balanceValue > 1 && id < current->left->id) {

        return rightRotate(current);

    }

    if (balanceValue > 1 && id > current->left->id) {

        current->left = leftRotate(current->left);
        return rightRotate(current);

    }

    if (balanceValue < -1 && id < current->right->id) {

        current->right = rightRotate(current->right);
        return leftRotate(current);

    }

    if (balanceValue < -1 && id > current->right->id) {

        return leftRotate(current);

    }

    return current;

}

void prettyPrint(treeT* current, int level) {

    if(current == NULL)
        return;

    prettyPrint(current->right, level + 1);

    for(int i = 0; i < level; i++)
        printf("   ");

    printf("%d\n", current->id);

    prettyPrint(current->left, level + 1);

}

void readCommand(FILE* in) {

    char* command = (char*)malloc(10);

    while(fgets(command, 10, in) != NULL) {

        root = insert(root, atoi(command));

    }
}

int main(int agrc, char* argv[]) {

    FILE* in = fopen(argv[1], "r");
    root = NULL;

    readCommand(in);

    prettyPrint(root, 0);

    return 0;
}
