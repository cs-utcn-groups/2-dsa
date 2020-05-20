#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <float.h>

typedef struct _NODE{
    float operand;
    char operator;
    struct _NODE *left,*right;
}NODE;

NODE *root=NULL;
char *p;

bool isFloat(char *s)
{
    if(s[0]!='-'&&s[0]!='+'&&s[0]!='*'&&*s!='/')
        return  true;
    if((s[0]=='-'|| s[0]=='+')&&strlen(s)>1)
        return true;
    return false;

}

NODE * CreateTree()
{
    NODE *NewNode=(NODE *)malloc(sizeof(NODE));
    if(isFloat(p=strtok(NULL," \n")))
    {
        sscanf(p,"%f",&NewNode->operand);
        NewNode->right=NULL;
        NewNode->left=NULL;
        NewNode->operator='\0';
    } else
    {
        NewNode->operand=FLT_MIN;
        NewNode->operator=*p;
        NewNode->left=CreateTree();
        NewNode->right=CreateTree();
    }
    return NewNode;
}

void printTree(NODE *Node,int level)
{
    if(Node == NULL)
        return;
    if(Node->operand==FLT_MIN)
    {
        printf("At the Level %d, the operator %c is parent for: ",level,Node->operator);
        if(Node->left->operand==FLT_MIN)
            printf("The operator %c AND ",Node->left->operator);
        else
            printf("the operand %.1f AND ",Node->left->operand );
        if(Node->right->operand==FLT_MIN)
            printf("the operator %c.",Node->right->operator);
        else
            printf("the operand %.1f.",Node->right->operand );
        printf("\n");
        printTree(Node->left,level+1);
        printTree(Node->right,level+1);
    }

}

int main() {
    char *s=(char *)malloc(sizeof(char));
    gets(s);
    char *p=strtok(s," \n");
    if(!p) return 0;
    if(isFloat(p))//if there is only a number we do not need to create a tree in the
    {             //memory, is enough just to print it because it is the root and the only
        printf("%s",p);    //element existing in the tree
        return 0;
    }
    else
    {
        root=(NODE*)malloc(sizeof(NODE));
        root->operator=*p;
        root->operand=FLT_MIN;
        root->left=CreateTree();
        root->right=CreateTree();
    }
    printTree(root,0);

    return 0;
}
