#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {

    char id;
    struct tree* left,* right;

}treeT;

treeT* root;

typedef struct node {

    char id;
    struct node* previous,* next;

}nodeT;

nodeT* first,* last,* node;

void initialize() {

    first = NULL;
    last = NULL;

}

treeT* createBTree() {

    char* c = (char*)malloc(sizeof(char));
    treeT* p;
    scanf("%s", c);

    if(strcmp(c, "*") == 0)
        return NULL;
    else {

        p = (treeT*)malloc(sizeof(treeT));
        strcpy(&(p->id), c);
        p->left = createBTree();
        p->right = createBTree();
        return p;

    }
}

void add(nodeT* node, char id) {

    if(first == NULL) {

        first = (nodeT*)malloc(sizeof(nodeT));
        first->id = id;
        first->next = NULL;
        first->previous = NULL;
        last = first;

    } else {

        nodeT* current = (nodeT*)malloc(sizeof(nodeT));
        current->id = id;
        current->next = NULL;
        current->previous = last;
        last->next = current;
        last = current;

    }
}

void getListFromTree(treeT* tree, nodeT* node) {

    if(tree == NULL)
        add(node, '*');
    else {

        add(node, tree->id);
        getListFromTree(tree->left, node);
        getListFromTree(tree->right, node);

    }
}

treeT* getTreeFromList() {

    char c = node->id;
    node = node->next;

    if(c == '*' || node == NULL) {

        return NULL;

    }
    else {

        treeT* tree = (treeT*)malloc(sizeof(treeT));
        tree->id = c;
        tree->left = getTreeFromList(node);
        tree->right = getTreeFromList(node);
        return tree;

    }
}

void prettyPrint(treeT* node, int level) {

    if(node == NULL)
        return;

    prettyPrint(node->right, level + 1);

    for(int i = 0; i < level; i++)
        printf("   ");

    printf("%c\n", node->id);
    prettyPrint(node->left, level + 1);

}

void transverseList(nodeT* first) {

    nodeT* current = first;

    while(current != NULL) {

        printf("%c ", current->id);
        current = current->next;

    }
}

int main() {

    initialize();

    root = createBTree();
    getListFromTree(root, first);
    transverseList(first);
    node = first;
    root = getTreeFromList();
    printf("\n\n");

    prettyPrint(root, 0);

    return 0;
}
