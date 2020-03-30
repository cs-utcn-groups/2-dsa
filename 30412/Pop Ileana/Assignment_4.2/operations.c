//
// Created by ileana on 3/30/2020.
//


#include "operations.h"

NodeT * insert(NodeT * root, int key)
{
    if(root==NULL)
        return createNode(key);
    if(key < root->key)
        root->left = insert(root->left, key);
    else
    if(key > root->key)
        root->right=insert(root->right,key);
    else
        return root;

    root->height=1+getMax(height(root->left),height(root->right));

    int balance = getBalance(root);

    if(balance>1 || balance<-1)
        printf("Node %d is unbalanced %d \n",root->key,balance);

    if(balance>1 && key < root->left->key)   //Left Left Case
        return rightRotate(root);
    if(balance>1 && key > root->left->key)    //Left Right Case
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 && key > root->right->key)      //Right Right Case
        return leftRotate(root);
    if(balance<-1 && key < root->right->key)      //Right Left Case
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

NodeT * delete(NodeT * root, int key)
{
    if(root==NULL)
        return NULL;
    if(key<root->key)
        root->left=delete(root->left,key);
    else
    if(key>root->key)
        root->right = delete(root->right,key);
    else
    {
        if(root->left==NULL || root->right == NULL)
        {
            NodeT * aux;
            if(root->left==NULL)
                aux=root->left;
            else
                aux=root->right;
            if(aux==NULL)
            {
                aux=root;
                root=NULL;
            }
            else
                *root=*aux;
            free(aux);
        }
        else    //root->left != NULL , root->right !=NULL
        {
            NodeT * aux = minValue(root->right);
            root->key = aux->key;
            root->right = delete(root->right,aux->key);
        }

    }

    if(root==NULL)
        return root;

    root->height = 1+ getMax(height(root->left),height(root->right));

    int balance = getBalance(root);
    if(balance>1 || balance<-1)
        printf("Node %d is unbalanced %d \n",root->key,balance);


    if (balance > 1 && getBalance(root->left) >= 0)  // Left Left Case, left heavy tree, left heavy subtree
        return rightRotate(root);                       //single right rotation

    if (balance > 1 && getBalance(root->left) < 0)    // Left Right Case, left heavy, right heavy subtree
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)  //Right Right Case, right heavy, right heavy subtree
        return leftRotate(root);                        //single left rotation

    if (balance < -1 && getBalance(root->right) > 0)    // Right Left Case, right heavy, left heavy subtree
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}