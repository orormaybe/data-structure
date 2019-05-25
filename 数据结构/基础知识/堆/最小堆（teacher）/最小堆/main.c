//
//  main.c
//  最小堆
//
//  Created by 汪博文 on 2019/5/18.
//  Copyright © 2019 汪博文. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct _node{
    int *data;
    int capacity;
    int size;
}heap;
void pop(heap* myHeap);
int top(heap* myHeap);
bool empty(heap* myHeap);
void percolateDown(heap* myHeap,int i);
void init(heap* myHeap,int n,int* array);
void BuildHeap(heap* myHeap);
void destory(heap* myHeap);
int main(int argc,const char* argv[]){
    printf("Coded By Wang");
    int a[12]={79, 66, 43, 83, 30, 87, 38, 55, 91, 72, 49, 9};
    heap myHeap;
    init(&myHeap,12,a);
    BuildHeap(&myHeap);
    for(int i=0;i<12;i++){
        int x=top(&myHeap);
        printf("%d ",x);
        pop(&myHeap);
    }
    destory(&myHeap);
}
void pop(heap* myHeap){
    int k=myHeap->size--;
    myHeap->data[1]=myHeap->data[k];
    int parent=1;
    int lChild=2*parent;
    int rChild=2*parent+1;
    int child;
    if(2*parent+1>myHeap->size)
        child=lChild;
    else
        child=myHeap->data[lChild]<myHeap->data[rChild]?lChild:rChild;
    while (child<=myHeap->size&&myHeap->data[child]<myHeap->data[parent]) {
        int temp=myHeap->data[child];
        myHeap->data[child]=myHeap->data[parent];
        myHeap->data[parent]=temp;
        parent=child;
        lChild=2*parent;
        rChild=2*parent+1;
        if(rChild>myHeap->size)
            child=lChild;
        else
            child=myHeap->data[lChild]<myHeap->data[rChild]?lChild:rChild;
    }
    
}
int top(heap* myHeap){
    return myHeap->data[1];
}
bool empty(heap* myHeap);
void percolateDown(heap* myHeap,int i){
    int parent,child;
    parent=i;
    while(parent*2<=myHeap->size){
        if(parent*2+1>myHeap->size){
            child=2*parent;
        }
        else
            child=myHeap->data[2*parent]<myHeap->data[2*parent+1]?2*parent:2*parent+1;
        if(myHeap->data[parent]<myHeap->data[child]){
            break;
        }
        else{
            int temp=myHeap->data[child];
            myHeap->data[child]=myHeap->data[parent];
            myHeap->data[parent]=temp;
            parent=child;
        }
    }
    
}
void init(heap* myHeap,int n,int* array){
    myHeap->capacity=n+1;
    myHeap->size=n;
    myHeap->data=(int*)malloc(sizeof(heap)*myHeap->capacity);
    for(int i=0;i<n;i++){
        myHeap->data[i+1]=array[i];
    }
}
void BuildHeap(heap* myHeap){
    int k=myHeap->size/2;
    for (int i=k;i>0;i--) {
        percolateDown(myHeap, i);// 这里传进来的myHeap已经是一个指针了，如果还是&myHeap的话，则变成双指针了。
    }
}
void destory(heap* myHeap){
    free(myHeap->data);
}
