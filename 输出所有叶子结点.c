//
//  main.c
//  输出所有叶子结点
//
//  Created by 汪博文 on 2019/4/16.
//  Copyright © 2019 汪博文. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}bt;
bt* insert(bt* root,int x);
void printleaf(bt* root);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int x,n,i;
    scanf("%d",&n);
    bt* root=NULL;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }
    printleaf(root);
    printf("\n");
    return 0;
}
bt* insert(bt* root,int x)
{
    if(root==NULL)
    {
        root=(bt*)malloc(sizeof(bt));
        root->data=x;
        root->left=root->right=NULL;
        return root;
    }
    if(root->data<x)
        root->right=insert(root->right, x);
    else
        root->left=insert(root->left, x);
    return root;
}
void printleaf(bt* root)
{
    if(root){
    if(root->left==NULL&&root->right==NULL)
        printf("%d ",root->data);
    printleaf(root->left);
    printleaf(root->right);
    }
}
