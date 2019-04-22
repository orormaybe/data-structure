//
//  main.c
//  二叉树的建立与遍历
//
//  Created by 汪博文 on 2019/4/16.
//  Copyright © 2019 汪博文. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} bt;
int Leaf;
bt* insert(bt* root,int x);
void Preorder(bt* root);
void Inorder(bt* root);
void Postorder(bt* root);
int main(int argc, const char * argv[]) {
    int i;
    int n,x;
    scanf("%d",&n);
    bt* root=NULL;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }
    printf("preorder:");
    Preorder(root);
    printf("\n");
    printf("inorder:");
    Inorder(root);
    printf("\n");
    printf("postorder:");
    Postorder(root);
    printf("\n");
    printf("leaf:%d\n",Leaf);
    return 0;
}
bt* insert(bt* root,int x)
{
    if(root==NULL)
    {
        root=(bt*)malloc(sizeof(bt));
        root->data=x;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    
    if(root->data>x)
    {
        root->left=insert(root->left,x);
    }
    else{
        root->right=insert(root->right, x);
    }
    return root;
}
void Preorder(bt* root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    if(root->left==NULL&&root->right==NULL)
        Leaf++;
    Preorder(root->left);
    Preorder(root->right);
    
}
void Inorder(bt* root)
{
    if(root==NULL)
        return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}
void Postorder(bt* root){
    if(root==NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}

