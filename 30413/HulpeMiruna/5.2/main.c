#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXLENGHT=200;
typedef struct nodeT
{
    char label;
    struct nodeT *left, *right;
} NodeT;

NodeT *insert (char c,NodeT *tree)
{
    if(tree==NULL)
    {
        NodeT *p=(NodeT *) malloc (sizeof(NodeT));
        p->label=c;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
    else
    {
        if(tree->label<c)
        {
            tree->right=insert (c,tree->right);
        }
        else
            tree->left=insert (c,tree->left);
        return tree;
    }
}
void  find (char c, NodeT *T,FILE *g)
{
    if(T!=NULL)
    {
        if (T->label==c)
            fprintf(g,"The node %c is in the tree\n",c);
        if(c>T->label)
            return  find (c,T->right,g);
        else if(c<T->label)
            return  find (c,T->left,g);
    }
    else
        fprintf(g,"The node %c is not in the tree\n",c);
}


NodeT * FindMin(NodeT *T)
{
    while(T->left!=NULL)
    {
        T=T->left;
    }
    return T;
}
NodeT * FindMax(NodeT *T)
{
    while(T->right!=NULL)
    {
        T=T->right;
    }
    return T;
}
void preorder(NodeT *T,int level,FILE *g)
{
    if(T!=NULL)
    {
        int i;
        for ( i = 0; i <= level; i++ )
            fprintf(g, " " );
        fprintf(g,"%c\n",T->label);
        preorder( T->left, level + 1,g);
        preorder( T->right, level + 1,g);
    }
}
NodeT *deletee(char c,NodeT *T)
{
    if(T!=NULL)
    {
        if(c<T->label)
            T->left=deletee(c,T->left);
        else if(c>T->label)
            T->right=deletee(c,T->right);
        else if(T->label==c)
        {
            if(T->right==NULL&&T->left==NULL)
                T=NULL;
            else if(T->right!=NULL&&T->left==NULL)
                T=T->right;
            else if(T->right==NULL&&T->left!=NULL)
                T=T->left;
            else
                T= FindMax(T->left);
        }
    }
    return T;
}
void inorder(NodeT *T,int level,FILE *g)
{
    if(T!=NULL)
    {
        inorder( T->left, level + 1,g);
        int i;
        for ( i = 0; i <= level; i++ )
            fprintf(g, " " );
        fprintf(g,"%c\n",T->label);
        inorder( T->right, level + 1,g );
    }
}
void postorder(NodeT *T,int level,FILE *g)
{
    if(T!=NULL)
    {

        postorder( T->left, level + 1,g);
        postorder( T->right, level + 1,g );
        int i;
        for ( i = 0; i <= level; i++ )
            fprintf( g," " );
        fprintf(g,"%c\n",T->label);
    }
}
void readInstructions(FILE *f,FILE *g,NodeT *tree)
{
    char *Strbuf=(char *) malloc (sizeof(char )*MAXLENGHT);
    while (fscanf(f,"%s\n",Strbuf)!=EOF)
    {
        if(Strbuf[0]=='i')
        {
            tree=insert(Strbuf[1],tree);
        }
        else if(Strbuf[0]=='t')
        {
            if(Strbuf[1]=='p')
                preorder(tree,0,g);
            else if(Strbuf[1]=='P')
                postorder(tree,0,g);
            else if(Strbuf[1]=='i')
            {
                inorder(tree,0,g);
            }
        }
        else if(Strbuf[0]=='g')
        {
            NodeT *p=(NodeT *) malloc (sizeof(NodeT));
            if(Strbuf[1]=='m')
                p=FindMin(tree);
            else if(Strbuf[1]=='M')
                p=FindMax(tree);
            fprintf(g,"%c \n",p->label);
        }
        else if(Strbuf[0]=='d')
            tree=deletee(Strbuf[1],tree);
        else if(Strbuf[0]=='f')
            find(Strbuf[1],tree,g);
    }
}



int main(int argc, int **argv)
{
    FILE *f=fopen (argv[1],"r+");
    FILE *g=fopen (argv[2],"r+");
    NodeT *tree;
    tree=NULL;
    readInstructions(f,g,tree);
    return 0;
}
