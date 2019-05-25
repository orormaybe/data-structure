//
//  main.c
//  哈夫曼树
//
//  Created by 汪博文 on 2019/5/18.
//  Copyright © 2019 汪博文. All rights reserved.
/*构造一个具有n个外部节点的扩充二叉树，每个外部节点Ki有一个Wi对应，作为该外部节点的权。使得这个扩充二叉树的叶节点带权外部路径长度总和最小：
Min( W1 * L1 + W2 * L2 + W3 * L3 + … + Wn * Ln)
Wi:每个节点的权值。
Li:根节点到第i个外部叶子节点的距离。
编程计算最小外部路径长度总和。
输入
第一行输入一个整数t，代表测试数据的组数。
对于每组测试数据，第一行输入一个整数n，外部节点的个数。第二行输入n个整数，代表各个外部节点的权值。
2<=N<=100
输出
输出最小外部路径长度总和。
样例输入
2
3
1 2 3
4
1 1 3 5
样例输出
9
17*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
    int weight;
    struct node* left;
    struct node* right;
} *huffmanTree;
typedef struct _heap{
    huffmanTree* buf;
    int size;
    int capacity;
}heap;
int wpl=0;
void init(heap* myHeap,int n,int* w);
void BuiltHeap(heap* myHeap);
void pop(heap* myHeap);
huffmanTree top(heap *myHeap);
void destory(heap *myHeap);
void insert(heap* myHeap,huffmanTree h);
void percolateDown(heap* myHeap,int i);
void visit(huffmanTree root);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Coded By Wang!");
    int num;//共有num组数据输入
    scanf("%d",&num);
    while(num--){
        int n;
        scanf("%d",&n);//每一组有n个数据
        int w[n];
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);//可以改为scanf("%d",&w[i])
            w[i]=x;
        }
        heap myHeap;
        init(&myHeap, n, w);
        BuiltHeap(&myHeap);
        while(myHeap.size!=1){
            huffmanTree h1=top(&myHeap);
            pop(&myHeap);
            huffmanTree h2=top(&myHeap);
            pop(&myHeap);
            huffmanTree h3=(huffmanTree)malloc(sizeof(struct node));
            h3->weight=h1->weight+h2->weight;
            h3->left=h1;
            h3->right=h2;
            insert(&myHeap,h3);
        }
        huffmanTree root=top(&myHeap);
        pop(&myHeap);
        wpl=0;
        visit(root);
        printf("%d\n",wpl);
        destory(&myHeap);
    }
    return 0;
}
void init(heap* myHeap,int n,int* w){
    myHeap->capacity=2*n-1;
    myHeap->size=n;
    //用malloc申请空间存储huffmanTree,即node的地址
    myHeap->buf=(huffmanTree*)malloc(sizeof(huffmanTree)*myHeap->capacity);
    for(int i=0;i<n;i++){
        myHeap->buf[i+1]=(huffmanTree)malloc(sizeof(struct node));
        myHeap->buf[i+1]->weight=w[i];
        myHeap->buf[i+1]->left=NULL;
        myHeap->buf[i+1]->right=NULL;
    }
}
void BuiltHeap(heap* myHeap){
    int k=myHeap->size/2;
    for(int i=k;i>0;i--){
        percolateDown(myHeap, i);
    }
}
void pop(heap* myHeap){
    int k=myHeap->size--;
    myHeap->buf[1]=myHeap->buf[k];
    percolateDown(myHeap, 1);
}
huffmanTree top(heap *myHeap){
    return myHeap->buf[1];
}
void destory(heap *myHeap){
    free(myHeap->buf);
}
void insert(heap* myHeap,huffmanTree h){
    myHeap->buf[++myHeap->size]=h;
    int k=myHeap->size;
    int parent=k/2;
    while(parent!=0&&myHeap->buf[parent]->weight>myHeap->buf[k]->weight){
         huffmanTree temp=myHeap->buf[parent];
        myHeap->buf[parent]=myHeap->buf[k];
        myHeap->buf[k]=temp;
        k=parent;
        parent=k/2;
    }
}
void visit(huffmanTree h){
    if(h==NULL)
        return;
    if(h->left!=NULL&&h->right!=NULL) {
        wpl+=h->weight;
        visit(h->left);
        visit(h->right);
    }
}
void percolateDown(heap* myHeap,int i){
    int parent=i;
    int lChild=2*parent;
    int rChild=2*parent+1;
    int child;
    if(rChild>myHeap->size){
        child=lChild;
    }
    else
        child=myHeap->buf[lChild]->weight<myHeap->buf[rChild]->weight?lChild:rChild;
    while(child<=myHeap->size){
        if(myHeap->buf[child]->weight>myHeap->buf[parent]->weight){
            break;
        }
        else
        {
            //必须交换huffmanTree而不是交换huffmenTree->weight
            huffmanTree temp=myHeap->buf[parent];
            myHeap->buf[parent]=myHeap->buf[child];
            myHeap->buf[child]=temp;
            parent=child;
            lChild=2*parent;
            rChild=2*parent+1;
            if(rChild>myHeap->size){
                child=lChild;
            }
            else
                child=myHeap->buf[lChild]->weight<myHeap->buf[rChild]->weight?lChild:rChild;
            
        }
    }
        
}
