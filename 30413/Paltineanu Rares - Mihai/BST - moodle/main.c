#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {

    char id;
    struct tree*left,* right;

} treeT;

treeT* root;

treeT* initializeNode(treeT* current, char id) {

    current = (treeT*)malloc(sizeof(treeT));
    current->left = current->right = NULL;
    current->id = id;
    return current;

}

void preOrder(treeT* current, int level) {

    if(current != NULL) {

        for(int i = 0; i < level; i++)
            printf("   ");

        printf("%c\n", current->id);
        preOrder(current->left, level + 1);
        preOrder(current->right, level + 1);

    }
}

void inOrder(treeT* current, int level) {

    if(current != NULL) {

        inOrder(current->left, level + 1);

        for(int i = 0; i < level; i++)
            printf("   ");

        printf("%c\n", current->id);
        inOrder(current->right, level + 1);

    }
}

void postOrder(treeT* current, int level) {

    if(current != NULL) {

        postOrder(current->left, level + 1);
        postOrder(current->right, level + 1);

        for(int i = 0; i < level; i++)
            printf("   ");

        printf("%c\n", current->id);

    }
}

treeT* insertElement(treeT* current, char id) {

    if(current == NULL) {

        current = initializeNode(current, id);
        return current;

    } else if(id < current->id) {

        current->left = insertElement(current->left, id);

    } else if(id > current->id) {

        current->right = insertElement(current->right, id);

    } else
        printf("Element %c already exists.\n", id);

    return current;
}

treeT* findNode(treeT* current, char id) {

    if(id < current->id)
        return findNode(current->left, id);
    else if(id > current->id)
        return findNode(current->right, id);
    else
        return current;

    return NULL;

}

treeT* smallestNode(treeT* current) {

    if(current->left == NULL)
        return current;
    else
        return smallestNode(current->left);

}

treeT* biggestNode(treeT* current) {

    if(current->right == NULL)
        return current;
    else
        return biggestNode(current->right);


}

treeT* deleteElement(treeT* current, char id) {

    if(current == NULL)
        return NULL;

    if(id < current->id)
        current->left = deleteElement(current->left, id);
    else if(id > current->id)
        current->right = deleteElement(current->right, id);
    else {

        if(current->left == NULL) {

            treeT* node = current->right;
            free(current);
            return node;

        } else if(current->right == NULL) {

            treeT* node = current->left;
            free(current);
            return node;

        } else {

            treeT* node = smallestNode(current->right);
            current->id = node->id;
            current->right = deleteElement(current->right, node->id);

        }
    }
    return current;
}

int main(int argc, char* argv[]) {

    FILE* in = fopen("input.txt", "r");
    char* array = (char*)malloc(4);
    treeT* root = NULL;

    while(fgets(array, 4, in) != NULL) {

        if(array[0] == 'i')
            root = insertElement(root, array[1]);
        else if(array[0] == 'd') {

            if(root->id == array[1])
                root = deleteElement(root, array[1]);
            else
                deleteElement(root, array[1]);

        } else if(array[0] == 'f')
            findNode(root, array[1]);
        else if(array[0] == 't' && array[1] == 'p') {

            preOrder(root, 0);
            printf("\n\n");

        } else if(array[0] == 't' && array[1] == 'P') {

            postOrder(root, 0);
            printf("\n\n");

        } else if(array[0] == 't' && array[1] == 'i') {

            inOrder(root, 0);
            printf("\n\n");

        } else if(array[0] == 'g' && array[1] == 'm')
            printf("%c\n", smallestNode(root)->id);
        else if(array[0] == 'g' && array[1] == 'M')
            printf("%c\n", biggestNode(root)->id);
        else
            printf("Invalid command.\n");
    }

    return 0;
}
