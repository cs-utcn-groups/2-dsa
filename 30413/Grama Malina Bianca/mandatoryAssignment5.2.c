/*
 * Develop a modular program which demonstrates the BST operations in a tree which contains as keys the uppercase
letters of the Roman alphabet. The operations are:
• insert, coded in input as i<letter> (e.g. iD) attempts to insert letter D;
• delete, coded in input as d<letter> (e.g. dF) attempts to delete node with key F;
• find, coded in input as f<letter> (e.g. fG) attempts to find node with key G;
• traversals (pre, in, post-order), coded in input as t<letter> (e.g. tp attempts to list nodes in preorder, tP
attempts to list nodes in postorder, ti) attempts to list nodes in inorder;
• getting the minimum and maximum specified in input as gm (minimum), gM (maximum);
 * */
#include <stdio.h>
#include <stdlib.h>

typedef struct node_type {
    char key;
    struct node_type *left, *right;
} BSTNodeT;

BSTNodeT *createNode(char givenKey) {
    BSTNodeT *p = (BSTNodeT *) malloc(sizeof(BSTNodeT));
    if (p) {
        p->key = givenKey;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

BSTNodeT *insertNode(BSTNodeT *root, char key) {
    if (root == NULL) {
        root = createNode(key);
    } else {
        if (key < root->key) {
            root->left = insertNode(root->left, key);
        } else if (key > root->key) {
            root->right = insertNode(root->right, key);
        } else {
            printf("\nNode with key %c already exists\n", key);
        }
    }
    return root;
}

BSTNodeT *find(BSTNodeT *root, char givenKey) {
    if (root == NULL) {
        return NULL;
    }
    for (BSTNodeT *p = root; p != NULL;) {
        if (givenKey == p->key) {
            return p;
        } else if (givenKey < p->key) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return NULL;
}

BSTNodeT *getMini(BSTNodeT *node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->left) {
        return getMini(node->left);
    } else {
        return node;
    }
}

BSTNodeT *getMaxi(BSTNodeT *node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->right) {
        return getMaxi(node->right);
    } else {
        return node;
    }
}

BSTNodeT *deleteNode(BSTNodeT *node, char key) {
    if (node == NULL) {
        printf("Element not found");
    } else if (key < node->key) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->key) {
        node->right = deleteNode(node->right, key);
    } else {
        if (node->right && node->left) {
            BSTNodeT *aux = getMini(node->right);
            node->key = aux->key;
            node->right = deleteNode(node->right, aux->key);
        } else {
            BSTNodeT *aux = node;
            if (node->left == NULL) {
                node = node->right;
            } else if (node->right == NULL) {
                node = node->left;
            }
            free(aux);
        }
    }
    return node;
}

void deleteTree(BSTNodeT *root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

void preorder(BSTNodeT *p, int level) {
    if (p != NULL) {
        for (int i = 0; i <= level; i++) {
            printf("    ");
        }
        printf("%c\n", p->key);
        preorder(p->left, level + 1);
        preorder(p->right, level + 1);
    }
}

void inorder(BSTNodeT *p, int level) {
    if (p != NULL) {
        inorder(p->left, level + 1);
        for (int i = 0; i <= level; i++) {
            printf("    ");
        }
        printf("%c\n", p->key);
        inorder(p->right, level + 1);
    }
}

void postorder(BSTNodeT *p, int level) {
    if (p != NULL) {
        postorder(p->left, level + 1);
        postorder(p->right, level + 1);
        for (int i = 0; i <= level; i++) {
            printf("    ");
        }
        printf("%c\n", p->key);
    }
}

void prettyPrint(BSTNodeT *tree, int level) {
    if (tree == NULL) {
        return;
    }
    prettyPrint(tree->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("     ");
    }
    printf("%c\n", tree->key);
    prettyPrint(tree->left, level + 1);
}

void readFile(FILE *f) {

    char *strbuf = (char *) malloc(sizeof(char) * 20);
    BSTNodeT *root = NULL;
    while (fgets(strbuf, 20, f) != NULL) {
        if (strbuf[0] == 'i') {
            root = insertNode(root, strbuf[1]);
        }
        if (strbuf[0] == 'd') {
            root = deleteNode(root, strbuf[1]);
        }
        if (strbuf[0] == 'f') {
            BSTNodeT *p = find(root, strbuf[1]);
        }
        if (strbuf[0] == 't') {
            if (strbuf[1] == 'p') {
                preorder(root, 0);
            }
            if (strbuf[1] == 'i') {
                inorder(root, 0);
            }
            if (strbuf[1] == 'P') {
                postorder(root, 0);
            }
        }
        if (strbuf[0] == 'g') {
            if (strbuf[1] == 'm') {
                BSTNodeT *mini = getMini(root);
                printf("\nMinimum in tree is %c", mini->key);
            }
            if (strbuf[1] == 'M') {
                BSTNodeT *maxi = getMaxi(root);
                printf("\nMaximum in tree is %c", maxi->key);
            }
        }
    }
}

int main() {
    FILE *f;
    f = fopen("input.txt", "r");
    readFile(f);
    fclose(f);
    return 0;
}