//
//  main.c
//  中缀表达式转化
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
}stack;
stack* createStack();
void pop(stack* myStack);
void push(stack* myStack,char data);
void destory(stack* myStack);
bool empty(stack* myStaack);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    stack* s1;
    stack* s2;
    int num;
    scanf("%d",&num);
    getchar();
    for(int i=0;i<num;i++)
    {
        int flag=0;
        char c;
        s1=createStack();
        while((c=getchar())!='\n')
        {
            if(c>='0'&&c<='9')
                printf("%c",c);
            if(c=='(')
            {
                push(s1,c);
                flag=1;
            }
            if((c=='+')||(c=='-'))
            {
                if((s1->top->data=='/')||(s1->top->data=='*'))
                {
                    if(flag==1){
                        while(s1->top->data!='(')
                        {
                            printf("%c",s1->top->data);
                            pop(s1);
                        }
                        push(s1, c);
                    }
                    else
                    {
                        while(!empty(s1)){
                            printf("%c",s1->top->data);
                            pop(s1);
                        }
                        push(s1, c);
                    }
                }
                else
                    push(s1, c);
            }
            if(c==')')
            {
                while(s1->top->data!='(')
                {
                    printf("%c",s1->top->data);
                    pop(s1);
                }
                pop(s1);
            }
            if((c=='*')||(c=='/'))
                push(s1, c);
        }
        while(!(empty(s1))){
            
            printf("%c",s1->top->data);
            pop(s1);
            
        }
        printf("\n");
        destory(s1);
        
    }
    return 0;
}
stack* createStack(){
    node* head=(node*)malloc(sizeof(node));
    stack* myStack=(stack*)malloc(sizeof(stack));
    head->next=NULL;
    myStack->top=head;
    return myStack;
}
void pop(stack* myStack){
    node* t=myStack->top;
    myStack->top=t->next;
    free(t);
}
void push(stack* myStack,char data){
    node *t=(node*)malloc(sizeof(node));
    t->data=data;
    t->next=myStack->top;
    myStack->top=t;
}
void destory(stack* myStack){
    node* t=myStack->top->next;
    while (t!=NULL) {
         free(myStack->top);
        myStack->top=t;
        t=t->next;
    }
    free(myStack);
}
bool empty(stack* myStack){
    return ((myStack->top->next)==NULL);
}
