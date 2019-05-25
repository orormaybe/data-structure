//
//  main.c
//  中缀表达式
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
int change(char sigh)
{
    switch (sigh) {
        case '+':
            return 1;
            break;
        case '-': return 1;break;
        case '*':return 2;break;
        case '/':return 2;break;
        default:return 0;
            break;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int num;
    scanf("%d",&num);
    getchar();
    for(int i=0;i<num;i++)
    {
        stack* s=createStack();
        char c;
        int flag=0;
        while((c=getchar())!='\n'){
            if((c>='0')&&(c<='9'))
                printf("%c",c);
            else{
                while((change(c)<change(s->top->data))&&(c!=')')){
                    printf("%c",c);
                    pop(s);
                    flag=1;
                }
             if((  change(c)>change(s->top->data))||flag==1){
                                    push(s, c);
                }
                if(c==')')
                {
                    while (s->top->data!='(') {
                        printf("%c",c);
                        pop(s);
                    }
                    pop(s);
                }
            }
            
            
        }
        while(!empty(s))
        {
            printf("%c",s->top->data);
            pop(s);
        }
        printf("\n");
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

