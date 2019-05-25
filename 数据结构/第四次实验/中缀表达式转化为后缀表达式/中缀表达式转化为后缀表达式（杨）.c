//
//  main.c
//  中缀表达式转化为后缀表达式（杨）
//
//  Created by 汪博文 on 2019/5/5.
//  Copyright © 2019 汪博文. All rights reserved.
//

#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>



typedef char ElemType;



//数据结点类型

typedef struct node

{
    
    ElemType data;//结点中存储的数据
    
    struct node *link;//指向下一个结点的指针
    
}node;



//栈的头结点类型

typedef struct _Stack

{
    
    node *top; //指向栈顶的指针，当栈空时此指针为NULL
    
}Stack;



//创建栈，返回指向头结点的指针

Stack* createStack();

//入栈,向指针myStack所指向的栈中压入元素x

void push(Stack *myStack, ElemType x);

//出栈,把myStack指向的栈的栈顶元素弹栈

void pop(Stack *myStack);

//返回指针myStack所指向栈的栈顶元素。

ElemType top(Stack *myStack);

//判断指针myStack指向的栈是否为空。

//栈空返回true，否则返回false。

bool empty(Stack *myStack);

//销毁指针myStack所指向的栈

bool destroy(Stack *myStack);

int opt(char symbol)

{
    
    switch(symbol)
    
    {
            
        case'*':return 2;break;
            
        case'/':return 2;break;
            
        case'+':return 1;break;
            
        case'-':return 1;break;
            
        default:return 0;break;
            
    }
    
}





bool IsOper(char ch)

{
    
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')')
        
    {
        
        return true;
        
    }
    
    return false;
    
}

int sum(char *ch)

{
    bool flag = true;
    int a, b;
    int num[100];
    int k = 0;
    int summay = (int)(ch[0]-'0');
    Stack *s;
    s = createStack();
    for(int i = 0;ch[i] != '\0';i++)
    {
        if(ch[i] >= '0' && ch[i] <= '9')
            push(s,ch[i]);
        else
        {
            if(flag == true){
                b = (int)(top(s)-'0');
                pop(s);
                a = (int)(top(s)-'0');
                pop(s);
            }
            else{
                if(top(s) == '#')
                {
                    b = num[--k];
                    pop(s);
                }
                else
                {
                    b = (int)(top(s)-'0');
                    pop(s);
                }
                if(top(s) == '#')
                {
                    a = num[--k];
                    pop(s);
                }
                else
                {
                    a = (int)(top(s)-'0');
                    pop(s);
                }
            }
            switch(ch[i])
            {
                    
                case'*':summay = a*b;break;
                    
                case'/':summay = a/b;break;
                    
                case'+':summay = a+b;break;
                    
                case'-':summay = a-b;break;
                    
            }
            num[k++] = summay;
            push(s,'#');
            flag = false;
            
        }
    }
    destroy(s);
    return summay;
    
}



int main(void)

{
    
    int a;
    
    scanf("%d",&a);
    
    char b;
    
    scanf("%c",&b);
    
    for(int i = 0;i < a;i++)
        
    {
        
        Stack *s;
        
        int index = 0;
        
        char s2[100];
        
        s = createStack();
        
        //s1 = createStack();
        
        char symbol[100];
        
        gets(symbol);
        
        for(int j = 0;symbol[j] != '\0';j++)
            
        {
            
            if(!IsOper(symbol[j]))
                
                s2[index++] = symbol[j];
            
            else{
                
                if(empty(s))
                    
                    push(s,symbol[j]);
                
                else
                    
                {
                    
                    if(opt(symbol[j])>opt(top(s))||symbol[j] == '(')
                        
                        push(s,symbol[j]);
                    
                    else
                        
                    {
                        
                        if(symbol[j] == ')')
                            
                        {
                            
                            while(top(s)!='(')
                                
                            {
                                
                                s2[index++] = top(s);
                                
                                pop(s);
                                
                            }
                            
                            pop(s);
                            
                        }
                        
                        else
                            
                        {
                            
                            s2[index++] = top(s);
                            
                            pop(s);
                            
                            push(s,symbol[j]);
                            
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
        while(!empty(s))
            
        {
            
            s2[index++] = top(s);
            
            pop(s);
            
        }
        
        s2[index] = '\0';
        
        printf("%s",s2);
        
        int summ = sum(s2);
        
        printf(" %d\n",summ);
        
        
        
    }
    
    
    
}

//Todo:请写出6个函数的定义

//创建栈，返回指向头结点的指针

Stack*createStack()

{
    
    node *head;
    
    head = NULL;
    
    head = (node*)malloc(sizeof(node));
    
    head->link = NULL;
    
    Stack *myStack;
    
    myStack = (Stack*)malloc(sizeof(Stack));
    
    myStack->top = head;
    
    return myStack;
    
}

//入栈,向指针myStack所指向的栈中压入元素x

void push(Stack *myStack, ElemType x)

{
    
    node *newStack;
    
    newStack = (node*)malloc(sizeof(node));
    
    newStack->data = x;
    
    newStack->link = myStack->top;
    
    myStack->top = newStack;
    
    
    
}



//出栈,把myStack指向的栈的栈顶元素弹栈

void pop(Stack *myStack)

{
    
    node *prt;
    
    prt = myStack->top;
    
    myStack->top = prt->link;
    
    free(prt);
    
}

//返回指针myStack所指向栈的栈顶元素。

ElemType top(Stack *myStack)

{
    
    return myStack->top->data;
    
}

//判断指针myStack指向的栈是否为空。

//栈空返回true，否则返回false。

bool empty(Stack *myStack)

{
    
    if(myStack->top->link == NULL)
        
        return true;
    
    else
        
        return false;
    
}

//销毁指针myStack所指向的栈

bool destroy(Stack *myStack)

{
    
    if(myStack->top == NULL)
        
        free(myStack->top);
    
    else
        
    {
        
        node *prt;
        
        prt = myStack->top->link;
        
        while(prt != NULL)
            
        {
            
            free(myStack->top);
            
            myStack->top = prt;
            
            prt = prt->link;
            
        }
        
        free(myStack->top);
        
    }
    
    free(myStack);
    
    return true;
    
}

