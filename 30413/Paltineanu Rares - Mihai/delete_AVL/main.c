#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct tree {

    int id;
    int height;
    struct tree* left,*right;

} treeT;

treeT* root;

treeT* initialize(treeT* current) {

    current = (treeT*)malloc(sizeof(treeT));
    current->height = 1;
    current->left = current->right = NULL;
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
        return height(current->left)- height(current->right);

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

    printf("%d\n", id);
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
        current->height = height(current->left) + 1;
    else
        current->height = height(current->right) + 1;

    int balanceValue = balance(current);

    if(balanceValue > 1 && id < current->left->id) {

        return rightRotate(current);

    }

    if(balanceValue > 1 && id > current->left->id) {

        current->left = leftRotate(current->left);
        return rightRotate(current);


    }

    if(balanceValue < -1 && id < current->right->id) {

        current->right = rightRotate(current->right);
        return leftRotate(current);


    }

    if(balanceValue < -1 && id > current->right->id) {

        return leftRotate(current);


    }

    return current;

}

treeT* findSmallest(treeT* current) {

    if(current->left == NULL)
        return current;
    else
        return findSmallest(current->left);


}

treeT* deleteElement(treeT* current, int id) {

    if(current == NULL)
        return NULL;

    if(id > current->id)
        current->right = deleteElement(current->right, id);
    else if(id < current->id)
        current->left = deleteElement(current->left, id);
    else {

        if(current->right == NULL) {

            treeT* node = current->left;
            free(current);
            return node;

        } else if(current->left == NULL) {

            treeT* node = current->right;
            free(current);
            return node;

        } else {

            treeT* node = findSmallest(current->right);
            current->id = node->id;
            current->right = deleteElement(current->right, node->id);

        }
    }

    if(root != NULL)
        if(height(root->left) > height(root->right))
            root->height = 1 + height(root->left);
        else
            root->height = 1 + height(root->right);
    else
        return NULL;

    int balanceValue = balance(root);

    if(balanceValue > 1 && id < current->left->id) {

        return rightRotate(current);

    }

    if(balanceValue > 1 && id > current->left->id) {

        current->left = leftRotate(current->left);
        return rightRotate(current);


    }

    if(balanceValue < -1 && id < current->right->id) {

        current->right = rightRotate(current->right);
        return leftRotate(current);


    }

    if(balanceValue < -1 && id > current->right->id) {

        return leftRotate(current);

    }

    return current;
}

void readCommand(FILE* in) {

    char* command = (char*)malloc(10);

    while(fgets(command, 10, in) != NULL) {

        if(strncmp(command, "i", 1) == 0) {

            root = insert(root, atoi(command + 1));

        } else if(strncmp(command, "d", 1) == 0) {

            root = deleteElement(root, atoi(command + 1));

        }
    }
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

int main(int argc, char* argv[]) {

    FILE* in = fopen(argv[1], "r");
    readCommand(in);
    prettyPrint(root, 0);
    printf("\n\n\n\n");
    prettyPrint(root, 0);

    return 0;
}
