//
// Created by q on 3/17/2020.
//

#include "queue.h"


NodeT * createNode(char * data) {
 // functions that creates a node
    NodeT * n = (NodeT*)malloc(sizeof(NodeT));
    if(n == NULL) {
        errorMessage();
    }
    else {
        n->data = (char *)malloc(sizeof(char)*MAX_SIZE_DATA);
        strcpy(n->data,data);
        n->right = n->left = NULL;
        return n;
    }
}
NodeT * createSentinel() {
    //function that creates the sentinel for the queue;
    NodeT * s = (NodeT *)malloc(sizeof(NodeT));
    if(s == NULL) {
        errorMessage();
    }
    else {
        s->left = s->right = s;
        return s;
    }
}

void errorMessage() {
    perror(ERR_ALLOC_MEM);
    exit(EXIT_FAILURE);
}

int enQueue(FILE * fp, NodeT * s) {
    /*
     * function that reads the input values from a file and saves them in a queue;
     * --returns : "level", static variable,
     *             which indicates the longest distance from the the root of the tree to one of the leaves;
     *
     */
    static int level;
    if(!feof(fp)) {
        char *data = (char *) malloc(sizeof(char) * 10);
        fscanf(fp, "%s", data);
        append(s,data);
        if(CheckIfNumber(data)) {
            /*
             * every number is a leaf, so it has no children
             * -- symbol "#" indicates that the node has no left/ right child
             */
            append(s,"#");
            append(s,"#");
        }
        else {
            /*
             * ->update level, if an operand was read => the depth of the tree depends on the number of operands;
             * -->another way to determine the depth of the binary tree would be
             *    to count the number of leaves, and use the theorem: depth = log2( noLeaves);
             */
            level++;
        }
        enQueue(fp,s);
        free(data);
    }
    return level;
}

void append(NodeT * s, char * data) {
    /*
 * function that appends the new node to the queue;
 */
    NodeT *new = createNode(data);
    new->left = s->left;
    new->right = s;
    s->left->right = new;
    s->left = new;
}

int CheckIfNumber(char * string) {
    /*
     * function that checks if the string read is an operand (number) or an operator;
     * --returns 1 (true) if it's a number
     */
    if(isdigit(string[0])) {
        return 1;
    }
    else if(isdigit(string[1])) {
        return 1;
    }
    return 0;
}

void deleteFirst(NodeT * s) {
    /*
     * function that deletes the first element of the queue;
     */
    NodeT * temp = s->right;
    s->right = temp->right;
    free(temp);
}