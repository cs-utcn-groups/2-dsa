#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "header.h"

void InitializeTree(TREE **Tree)
{
    TREE* tr = (TREE*)malloc(sizeof(TREE));
    tr->Info = (INFO*)malloc(sizeof(INFO));

//    tr->Info->Name = (char*)malloc(sizeof(char)*100);
//    tr->Info->Price = -1;
//    tr->Info->Amount = -1;
//    tr->Info->DateOfManufacturing = -1;
//    tr->Info->DateOfExpiration = -1;

    tr->Info = NULL;
    tr->Left = NULL;
    tr->Right = NULL;

    *Tree = tr;
}


TREE* NewNode(INFO *info)
{
    TREE* node = (TREE*)malloc(sizeof(TREE));
    node->Info = info;
    node->Left = NULL;
    node->Right = NULL;

    return node;
}

TREE* Insert(TREE* Node, INFO *info)
{
    if (Node == NULL)
    {
        Node = NewNode(info);
        return Node;
    }
    else if (Node->Info == NULL)
    {
        Node->Info = info;
        return Node;
    }
    else
    {
        if (strcmp(info->Name, Node->Info->Name)<0)
        {
            Node->Left = Insert(Node->Left, info);
        }
        else
        {
            Node->Right = Insert(Node->Right, info);
        }

        return Node;
    }
}

INFO* ParseString(char *token)
{
    INFO *info = (INFO*)malloc(sizeof(INFO));
    info->Name = (char*)malloc(sizeof(char)*100);
    strcpy(info->Name, token);

    token = strtok(NULL, ",\n");
    info->Price = (char*)malloc(sizeof(char)*100);
    strcpy(info->Price, token);

    token = strtok(NULL, ",\n");
    info->Amount = (char*)malloc(sizeof(char)*100);
    strcpy(info->Amount, token);

    token = strtok(NULL, ",\n");
    info->DateOfManufacturing = (char*)malloc(sizeof(char)*100);
    strcpy(info->DateOfManufacturing, token);

    token = strtok(NULL, ",\n");
    info->DateOfExpiration = (char*)malloc(sizeof(char)*100);
    strcpy(info->DateOfExpiration, token);

    return info;
}

void InsertTree(TREE *Tree,FILE *f)
{
    char *strBuf = (char*)malloc(sizeof(char)*100);
    fgets(strBuf,100,f);

    char *token = strtok(strBuf, ",\n");

    INFO *info = ParseString(token);

    Tree = Insert(Tree, info);
}

void FreeMemory(INFO *info)
{
    free(info->Amount);
    free(info->DateOfExpiration);
    free(info->DateOfManufacturing);
    free(info->Name);
    free(info->Price);
    free(info);
}

TREE* FindMin(TREE *Node)
{
    TREE *current = Node;
    while (current && current->Left)
    {
        current = current->Left;
    }
    return current;
}

TREE* Delete(TREE* Root, char *Name)
{
    if (NULL == Root)
    {
        return NULL;
    }

    if (strcmp(Name, Root->Info->Name)<0)
    {
        Root->Left = Delete(Root->Left, Name);
    }
    else if (strcmp(Name, Root->Info->Name)>0)
    {
        Root->Right = Delete(Root->Right, Name);
    }
    else
    {
        if (NULL == Root->Left)
        {
            TREE* t = Root->Right;
            FreeMemory(Root->Info);
            free(Root);
            return t;
        }
        else if (NULL == Root->Right)
        {
            TREE* temp = Root->Left;
            FreeMemory(Root->Info);
            free(Root);
            return temp;
        }
            TREE* temp = FindMin(Root->Right);
            Root->Info = temp->Info;
            Root->Right = Delete(Root->Right, temp->Info->Name);

    }
    return Root;
}

void DeleteFromTree(TREE *Tree, FILE *f)
{
    char *Name = (char*)malloc(sizeof(char)*100);
    fgets(Name, 100, f);


    if (Tree->Left == NULL && Tree->Right == NULL)
    {
        if (strcmp(Tree->Info->Name, Name)==0)
        {
            FreeMemory(Tree->Info);
        }
    }
    else
    {
       Tree = Delete(Tree, Name);
       if (Tree == NULL)
       {
           InitializeTree(&Tree);
       }
    }
}

void Replace(TREE **node, INFO *info)
{
    if (strcmp(info->Name, "~")!=0)
    {
        strcpy((*node)->Info->Name, info->Name);
    }
    if (strcmp(info->Price, "~")!=0)
    {
        strcpy((*node)->Info->Price, info->Price);
    }
    if (strcmp(info->Amount, "~")!=0)
    {
        strcpy((*node)->Info->Amount, info->Amount);
    }
    if (strcmp(info->DateOfManufacturing, "~")!=0)
    {
        strcpy((*node)->Info->DateOfManufacturing, info->DateOfManufacturing);
    }
    if (strcmp(info->DateOfExpiration, "~")!=0)
    {
        strcpy((*node)->Info->DateOfExpiration, info->DateOfExpiration);
    }
}

void FindAndReplace(TREE *Tree, FILE *f, FILE *g)
{
    char *strBuf = (char*)malloc(sizeof(char)*100);
    char *Name = (char*)malloc(sizeof(char)*100);
    fgets(strBuf, 100, f);

    char *token = strtok(strBuf, ",\n");
    strcpy(Name, token);
    token = strtok(NULL, ",\n");

    INFO *info = ParseString(token);


    TREE* node = Tree;

    while (NULL != node)
    {
        if (strcmp(Name, node->Info->Name)>0)
        {
            node = node->Right;
        }
        else if (strcmp(Name, node->Info->Name)<0)
        {
            node = node->Left;
        }
        else
        {
            Replace(&node, info);
            return;
        }
    }

    fprintf(g, "Medicine %s not found!\n", info->Name);
}

void Preorder(TREE *Tree, TREE *NewTree, char *Date)
{
    if (Tree == NULL)
    {
        return;
    }

    if (strcmp(Tree->Info->DateOfExpiration, Date)<0)
    {
        Insert(NewTree, Tree->Info);
    }
    Preorder(Tree->Left, NewTree, Date);
    Preorder(Tree->Right, NewTree, Date);
}

char* GetDate()
{
    struct tm *local;
    time_t t = time(NULL);

    local = localtime(&t);

    char *date = (char*)malloc(sizeof(char)*10);

    strftime(date, 10,"%Y%m%d", local);

    return date;
}

void CreateExpired(TREE *NewTree, TREE *Tree, FILE *f)
{
    char *currentDate = GetDate();

    Preorder(Tree, NewTree, currentDate);

    char *strBuf = (char*)malloc(sizeof(char)*10);
    fgets(strBuf, 10,f );

    free(strBuf);
}

void PrintTree(TREE *Tree, FILE *g)
{
    if (Tree == NULL)
    {
        return;
    }

    fprintf(g,"The medicine %s costs %s$, quantity %s\n",Tree->Info->Name,Tree->Info->Price,Tree->Info->Amount);
    PrintTree(Tree->Left, g);
    PrintTree(Tree->Right, g);

}
