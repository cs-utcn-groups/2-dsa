#include <stdio.h>
#include "header.h"
int main() {
    NodeT *root=NULL;
    root= insert(root, 10);
    root=insert(root, 9);
    root=insert(root, 7);
    root=insert(root, 0);
    root= insert(root, 11);
    root=insert(root, 13);
    root=insert(root, 12);
    root=insert(root, 4);
    root=insert(root, 5);
    prettyPrint(root, 0);
    root=delete(root, 9);
    root=delete(root, 13);
    prettyPrint(root, 0);
  return 0;
}