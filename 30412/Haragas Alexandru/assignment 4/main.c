#include "AVL.h"

int main() {
    NodeT *root=NULL;
    FILE *f=fopen("D:\\DSA\\2-dsa\\30412\\Haragas Alexandru\\assignment 4\\data.in","r");
    //PR - print the tree
    //AD X -add x in the tree
    //DE X -deletes x if exists
    char *s=(char*)malloc(sizeof(char)*3);
    while(feof(f)==0)
    {
        fscanf(f,"%s",s);
        if(strcmp(s,"PR")==0) {
            afisTree(root, 0);
            printf("\n");
        }
        else
        {
            int x,r,l;
            fscanf(f,"%d",&x);
            if(strcmp(s,"AD")==0)
                root=addNode(root,x);
            if(strcmp(s,"DE")==0)
                root=delNode(root,x);
            r=depth(root->right);
            l=depth(root->left);
            if(abs(r-l)>1)
                root=balanceTree(root,r,l);
        }
    }
    fclose(f);
    return 0;
}