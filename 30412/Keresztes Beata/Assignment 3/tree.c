//
// Created by q on 3/11/2020.
//

#include "tree.h"

void errorMessage() {
    perror(ERR_MEM_ALLOC);
    exit(EXIT_FAILURE);
}

NodeT * createNode(char * id) {
    NodeT * newNode = (NodeT *)malloc(sizeof(NodeT));
    if(newNode == NULL) {
        errorMessage();
    }
    else {
    newNode->id = (char *) malloc(sizeof(char) * MAX_SIZE);
    strcpy(newNode->id,id);
    newNode->left = newNode->right = NULL;
    return newNode;
    }
}

NodeT * createBinTree(FILE * fp) {
    /*
 * function that creates the binary tree
 * -- returns : pointer to the root
 */
    if(!feof(fp)) {
        char * s = (char *) malloc(sizeof(char) * MAX_SIZE);
        fscanf(fp, "%s", s);
        if (strcmp(s, "*") == 0) {
            free(s);
            return NULL;
        }
        NodeT * node = createNode(s);
        free(s);
        node->left = createBinTree(fp);
        node->right = createBinTree(fp);
        return node;
    }
}

void printPretty(NodeT * root, int level) {
    /*
 * function that prints the tree, by inOrder traversal
 */
    if( root ) {
        printPretty(root->right,level+1);
        for(int i=0; i <= level; i++) {
            printf("  ");
        }
        printf("%s\n", root->id);
        printPretty(root->left,level+1);
    }
}

/*
 * tree -> doubly linked list with sentinel
 */

NodeT * getListFromTree(NodeT * root) {
    /*
     * function that converts the tree back to a list
     * -- returns: pointer to the sentinel of the list
     */
    NodeT * sentinel = createSentinel();
    createList(sentinel,root);
    return sentinel;
}

NodeT *  createSentinel() {
    NodeT * s = (NodeT *)malloc(sizeof(NodeT));
    if(s == NULL) {
        errorMessage();
    }
    else {
        s->right = s->left = s;
        return s;
    }
}
void createList(NodeT * sentinel, NodeT * root) {
    /*
     * function that fills the list with elements
     */
    if(root) {
        addLast(sentinel,root->id);
        if (root->left == NULL) {
           addLast(sentinel,"*");
        }
        if (root->right == NULL) {
            addLast(sentinel,"*");
        }
        createList(sentinel,root->left);
        createList(sentinel,root->right);
    }
}

void addLast(NodeT * sentinel, char * id) {
    /*
     * function that appends a new node to the list
     */
    NodeT * new = createNode(id);
    sentinel->left->right = new;
    new->left = sentinel->left;
    new->right = sentinel;
    sentinel->left = new;
}

void traverseList(NodeT * sentinel) {
    /*
     * function that traverses and prints the list
     */
    if(sentinel == sentinel->right) {
        printf("empty list\n");
    }
    newLine;
    NodeT * temp = sentinel->right;
    while(temp != sentinel) {
        printf("%s ",temp->id);
        temp = temp->right;
    }
    newLine;
}

/*
 * list -> tree
 */

NodeT * getTreeFromList(NodeT * sentinel) {
    /*
     * function that converts the list to a tree
     * -- returns: pointer to the root
     */
    NodeT * first = sentinel->right;
    if(first!= sentinel) {
        if (strcmp(first->id, "*") == 0) {
            return NULL;
        }
        NodeT * node = createNode(first->id);
        deleteFirst(sentinel);
        node->left = getTreeFromList(sentinel);
        deleteFirst(sentinel);
        node->right = getTreeFromList(sentinel);
        return node;
    }
}
void deleteFirst(NodeT * sentinel) {
    /*
     * function that deletes the first element of the list
     */
    NodeT * temp = sentinel->right;
    if(temp != sentinel) {
        //if the list is empty, this function does nothing
        sentinel->right = temp->right;
        temp->right->left = sentinel;
        free(temp);
    }
}
