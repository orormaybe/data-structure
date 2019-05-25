//
//  main.c
//  反向输出整数数列
//
//  Created by 汪博文 on 2019/5/4.
//  Copyright © 2019 汪博文. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int ElemType;

typedef struct{
    
    ElemType *base; //存储元素的数组
    
    int top;//栈顶指针
    
    int capacity; //当前分配的存储容量( 以sizeof(ElemType)为单位 )
    
}Stack;
void init(Stack *pStack){
    pStack->top=-1;
    pStack->capacity=10;
    pStack->base=(ElemType*)malloc(sizeof(ElemType)*10);
} //初始化一个空栈。空栈拥有10个元素的空间，栈顶值为 -1

void push(Stack *pStack, ElemType x){
    if(pStack->top==pStack->capacity-1){
        pStack->capacity *= 2;
        ElemType *newPs = (ElemType*)malloc(sizeof(ElemType)*pStack->capacity);
        for(int i=0;i<=pStack->top;i++)
        {
            newPs[i]=pStack->base[i];
        }
        free(pStack->base);
        pStack->base = newPs;
    }
    pStack->base[++(pStack->top)]=x;
}//把 x 入栈


ElemType top(Stack *pStack){
    return(pStack->base[pStack->top]);
}//返回当前栈顶元素的值

void pop(Stack *pStack){
    pStack->top--;
} //当前栈顶元素出栈

bool empty(Stack *pStack){
    if(pStack->top==-1)
        return true;
    else
        return false;
}//如果栈空，则返回 true，否则返回 false

void destroy(Stack *pStack){
    free(pStack->base);
}//清空分配给栈的存储空间



int main(int argc, const char * argv[]) {
    // insert code here...
    Stack s;
    Stack* ps=&s;
    init(ps);
    int num;
    scanf("%d",&num);
    while(num!=-1)
    {
        push(ps, num);
        scanf("%d",&num);
    }
    while(!empty(ps)){
        int x=top(ps);
        printf("%d ",x);
        pop(ps);
    }
    destroy(ps);
    return 0;
}
