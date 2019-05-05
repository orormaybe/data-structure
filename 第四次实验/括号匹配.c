//
//  main.c
//  括号匹配
//
//  Created by 汪博文 on 2019/5/5.
//  Copyright © 2019 汪博文. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
    char data;
    struct node* next;
}node;
typedef struct{
    node* top;
} stack;
void push(stack* myStack,char data);
void pop(stack* myStack);
stack* createStack();
void destory(stack* myStack);
bool empty(stack* myStack);
int main(int argc, const char * argv[]) {
    // insert code here...
    stack* myStack=createStack();
    char c[101];
    scanf("%s",c);
    for(int i=0;c[i]!='\0';i++)
    {
        if((c[i]=='(')||(c[i]=='{')||(c[i]=='['))
            push(myStack, c[i]);
        else{
            if(empty(myStack))
            {
                printf("Extra right brackets\n");
                return 0;
            }
            else if((myStack->top->data=='('&&c[i]==')')||(myStack->top->data=='{'&&c[i]=='}')||(myStack->top->data=='['&&c[i]==']'))
                pop(myStack);
            else
            {
                printf("Brackets not match\n");
                return 0;
            }
        }
    }
    if(empty(myStack))
        printf("Brackets match\n");
    else
        printf("Extra left brackets\n");
   
    return 0;
}
void push(stack* myStack,char data){
    node* t=(node*)malloc(sizeof(node));
    t->data=data;
    t->next=myStack->top;
    myStack->top=t;
}
void pop(stack* myStack){
    node* t=myStack->top;
    myStack->top=t->next;
    free(t);
}
stack* createStack(){
    stack* myStack=(stack*)malloc(sizeof(stack));
    node* head=(node*)malloc(sizeof(node));
    head->next=NULL;
    myStack->top=head;
    return myStack;
}
void destory(stack* myStack){
    while(myStack->top!=NULL)
        free(myStack->top);
    free(myStack);
}
bool empty(stack* myStack){
    if (myStack->top->next==NULL) {
        return true;
    }
    else
        return false;
}

