//
//  main.c
//  非递归创建和遍历二叉树
//
//  Created by 汪博文 on 2019/4/16.
//  Copyright © 2019 汪博文. All rights reserved.
//

#include <stdio.h>
#include"stdlib.h"
int Leaf;
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}bt;
void Preorder(bt* root);
void Inorder(bt* root);
void Postorder(bt* root);
int main(int argc, const char * argv[]) {
    int x,i,n;
    scanf("%d %d",&n,&x);
    bt* root=(bt*)malloc(sizeof(bt));
    root->data=x;
    root->left=root->right=NULL;
    for(i=1;i<n;i++)
    {
        scanf("%d",&x);
        bt *p=root;
        bt* pre=NULL;
        while(p!=NULL)
        {
            pre=p;
            if(p->data>x)
                p=p->left;
            else
                p=p->right;
        }
        bt* t=(bt*)malloc(sizeof(bt));
        t->data=x;
        t->left=t->right=NULL;
        if(x>pre->data)
            pre->right=t;
        else
            pre->left=t;
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
void Preorder(bt* root)
{
    if(root==NULL)
        return;
    if(root->left==NULL&&root->right==NULL)
        Leaf++;
    printf("%d ",root->data);
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
void Postorder(bt* root)
{
    if(root==NULL)
        return ;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}
