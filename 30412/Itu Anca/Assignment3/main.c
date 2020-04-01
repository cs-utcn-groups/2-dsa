#include "head.h"
#include "functions.c"

int main() {
   fin = fopen("D:\\Facultate\\SEM2\\DSA\\Assignment3\\input.txt", "r");
   if(fin == NULL){
       printf("File could not be opened");
       exit(1);
   }

   NodeT *root;
   root = createBinaryTree();

   NodeL * firstFromList = getListFromTree(root);
   printf("\nThe extracted list:\n");
   traverseList(firstFromList);

   root = getTreeFromList(&firstFromList);
   printf("\nThe tree reconstructed from the list:\n");
   prettyPrint(root, 0);
   return 0;
}