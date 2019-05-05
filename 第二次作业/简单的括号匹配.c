//
//  main.c
//  匹配括号
//
//  Created by 汪博文 on 2019/5/4.
//  Copyright © 2019 汪博文. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct node{
    char data;
    struct node* next;
}node;
typedef struct{
    node* top;
}stack;
stack* createStack();
void push(stack* myStack,char data);
void pop(stack* myStack);
bool empty(stack* myStack);
void destory(stack* myStack);
int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        stack* myStack=createStack();
        char c[101];
        scanf("%s",c);
        int flag=0;
        for(int i=0;c[i]!='\0';i++)
        {
            if(c[0]==')')
            {
                break;
            }
            else{
                if(c[i]==')'&&!(empty(myStack)))
                    pop(myStack);
                else
                    push(myStack, c[i]);
                flag=1;
            }
        }
        if(empty(myStack)&&flag==1)
            printf("YES\n");
        else
            printf("NO\n");
        }
    return 0;
}
stack* createStack(){
               stack* myStack=(stack*)malloc(sizeof(stack));
               node* head=(node*)malloc(sizeof(node));
               myStack->top=head;
               head->next=NULL;
               return myStack;
           }
void push(stack* myStack,char data){
               node* p=(node*)malloc(sizeof(node));
               p->data=data;
               p->next=myStack->top;
               myStack->top=p;
           }
void pop(stack* myStack){
               node* t=myStack->top;
               myStack->top=t->next;
               free(t);
           }
bool empty(stack* myStack){
        if(myStack->top->next==NULL)
            return true;
        else
            return false;
    }
void destory(stack* myStack){
    while(myStack->top!=NULL)
    {
        pop(myStack);
    }
    free(myStack);
}
