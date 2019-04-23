//
//  main.c
//  求二叉树的深度
//
//  Created by 汪博文 on 2019/4/23.
//  Copyright © 2019 汪博文. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} bst;
bst* insert(bst *root,int x);
void PreOrderTraverse(bst* root);
int main(int argc, const char * argv[]) {
    // insert code here...
    int x;
    bst* root=NULL;
    while(scanf("%d",&x)!=EOF){
        root=insert(root,x);
    }
    PreOrderTraverse(root);
    return 0;
}
bst* insert(bst *root,int x)
{
    if (root==NULL)
    {
        root=(bst*)malloc(sizeof(bst));
        root->left=NULL;
        root->right=NULL;
        root->data=x;
        return root;
    }
    if(x!=root->data)
    {
        if(root->data>x)
        {
            root->left=insert(root->left, x);
        }
        if(root->data<x)
        {
            root->right=insert(root->right, x);
        }
    }
    return root;
}
void PreOrderTraverse(bst* root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    PreOrderTraverse(root->left);
    PreOrderTraverse(root->right);
}
