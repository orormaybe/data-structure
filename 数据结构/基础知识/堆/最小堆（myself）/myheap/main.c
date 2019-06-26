//
//  main.c
//  myheap
//
//  Created by 汪博文 on 2019/5/19.
//  Copyright © 2019 汪博文. All rights reserved.
//第一行输入总共输入多少个数，第二行输入要输入的数字，将数字从小到大输出

#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"
typedef struct node{
    int *data;
    int capacity;
    int size;
}heap;
void init(heap* myHeap,int n,int* a);//初始化堆
void insert(heap* myHeap,int x);//插入新元素（需要使用上筛）（本程序不需要使用insert（），本程序在主函数创建一个数组，把值传入数组，再通过init（）函数把值一一赋给myHeap->data)
void delete(heap* myHeap);//删除最小元素
int top(heap* myHeap);//输出最小值
void destory(heap* myHeap);//清空堆中data所申请的空间
void percolateDown(heap* myHeap,int i);//下滤/下筛（把一个已经存在的数组按照y最小堆的方式进行排列（BuiltHeap()函数)/删除最小元素（delete（））会用到）
void BuiltHeap(heap* myHeap);//把一个已经存在的数组按照y最小堆的方式进行排列
bool empty(heap* myHeap);//判断堆是否为空
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Coded By Wang\n");
    int n;
    scanf("%d",&n);
    int a[10000];
    int x;
    heap myHeap;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        a[i]=x;
    }
    init(&myHeap,n,a);
    BuiltHeap(&myHeap);
    while(!empty(&myHeap)){
        int x=top(&myHeap);
        printf("%d ",x);
        delete(&myHeap);
    }
    return 0;
}
void init(heap* myHeap,int n,int* a){
    myHeap->capacity=n+1;
    myHeap->size=n;
    myHeap->data=(int*)malloc(sizeof(int)*myHeap->capacity);
    for(int i=0;i<n;i++){
        myHeap->data[i+1]=a[i];
    }
}
void insert(heap* myHeap,int x){
    int k=++myHeap->size;
    myHeap->data[k]=x;
    int parent=k/2;
    while(parent>0&&myHeap->data[k]<myHeap->data[parent]){
        int temp=myHeap->data[k];
        myHeap->data[k]=myHeap->data[parent];
        myHeap->data[parent]=temp;
        k=parent;
        parent=k/2;
    }
}
//delete()函数是以1为根节点进行下滤
void delete(heap* myHeap){
    int k=myHeap->size--;
    myHeap->data[1]=myHeap->data[k];
    percolateDown(myHeap,1);
}
int top(heap* myHeap){
    return myHeap->data[1];
}
void destory(heap* myHeap){
    free(myHeap->data);
}
void percolateDown(heap* myHeap,int i){
    int parent=i;
    int lChild=2*parent;
    int rChild=2*parent+1;
    int child;
    if(rChild>myHeap->size)
        child = lChild;
    else
        child=myHeap->data[lChild]<myHeap->data[rChild]?lChild:rChild;
    //第一种写法
    /*while(child<=myHeap->size&&myHeap->data[parent]>myHeap->data[child]){
        int temp=myHeap->data[child];
        myHeap->data[child]=myHeap->data[parent];
        myHeap->data[parent]=temp;
        parent=child;
        lChild=2*parent;
        rChild=2*parent+1;
        if(rChild>myHeap->size)
            child = lChild;
        else
            child=myHeap->data[lChild]<myHeap->data[rChild]?lChild:rChild;
    }*/
    //第二种写法
    while(myHeap->size>=child){
        if(myHeap->data[parent]<myHeap->data[child])
            break;
        else{
            int temp=myHeap->data[child];
            myHeap->data[child]=myHeap->data[parent];
            myHeap->data[parent]=temp;
            parent=child;
            lChild=2*parent;
            rChild=2*parent+1;
            if(rChild>myHeap->size)
                child = lChild;
            else
                child=myHeap->data[lChild]<myHeap->data[rChild]?lChild:rChild;
        }
    }
    
    
}
//BuiltHeap每次以myHeap->size/2,myHeap->size-1,myHeap->size-2...为根节点进行下滤
void BuiltHeap(heap* myHeap){
    int k=myHeap->size/2;
    for(int i=k;i>0;i--){
        percolateDown(myHeap, i);//这里percolateDown传入的参数不能是&myHeap，因为BuiltHeap传入的myHeap就是一个地址，&myHeap为指向地址的地址
    }
}
bool empty(heap* myHeap){
    return myHeap->size==0;
}
