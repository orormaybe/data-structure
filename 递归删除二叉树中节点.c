//
//  main.c
//  递归删除二叉树中节点
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
} bt;
void PreOrderTraversal(bt* root);
void InOrderTraversal(bt* root);
void PostOrderTraversal(bt* root);
bt* Delete(bt* root,int num);
int main(int argc, const char * argv[]) {
    int x,n,i;
    bt* root=(bt*)malloc(sizeof(bt));
    scanf("%d %d",&n,&x);
    root->data=x;
    root->left=NULL;
    root->right=NULL;
    for(i=1;i<n;i++)
    {
        bt* p=root;
        bt* pre=NULL;
        scanf("%d",&x);
        while(p!=NULL)
        {
            pre=p;
            if(p->data<x)
                p=p->right;
            else
                p=p->left;
        }
        bt* t=(bt*)malloc(sizeof(bt));
        t->data=x;
        t->left=NULL;
        t->right=NULL;
        if(x>pre->data)
            pre->right=t;
        else
            pre->left=t;
    }
    PreOrderTraversal(root);
    printf("\n");
    InOrderTraversal(root);
    printf("\n");
    PostOrderTraversal(root);
    printf("\n");
    int len;
    int num;
    scanf("%d",&len);
    for(i=0;i<len;i++)
    {
        scanf("%d",&num);
        root=Delete(root, num);
    }
    PreOrderTraversal(root);
    printf("\n");
    InOrderTraversal(root);
    printf("\n");
    PostOrderTraversal(root);
    printf("\n");
    return 0;
}
void PreOrderTraversal(bt* root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}
void InOrderTraversal(bt* root)
{
    if (root==NULL)
        return;
    InOrderTraversal(root->left);
    printf("%d ",root->data);
    InOrderTraversal(root->right);
}
void PostOrderTraversal(bt* root)
{
    if(root==NULL)
        return;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    printf("%d ",root->data);
}
bt* Delete(bt* root,int num)
{
    if(num>root->data)
        root->right=Delete(root->right, num);
    else if(num<root->data)
        root->left=Delete(root->left, num);
    else{
        if(root->left&&root->right)
        {
            bt* p=root->left;
            while(p->right!=NULL)
            {
                p=p->right;
            }
            bt* temp=p;
            root->data=temp->data;
            root->left=Delete(root->left,root->data);
        }
        else{
            bt* temp=root;
            if(!root->left)
                root=root->right;
            else
                root=root->left;
            free(temp);
        }
    }
    return root;
}
