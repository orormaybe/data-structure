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
Stack* createStack(){
    Stack* s=(Stack*)malloc(sizeof(Stack));
    node* head=(node*)malloc(sizeof(node));
    head->link=NULL;
    s->top=head;
    return s;
}
//入栈,向指针myStack所指向的栈中压入元素x
void push(Stack *myStack, ElemType x){
    node* t=(node*)malloc(sizeof(node));
    t->data=x;
    t->link=myStack->top;
    myStack->top=t;
}
//出栈,把myStack指向的栈的栈顶元素弹栈
void pop(Stack *myStack){
    node* t=myStack->top;
    myStack->top=t->link;
    free(t);
}
//返回指针myStack所指向栈的栈顶元素。
ElemType top(Stack *myStack){
    return myStack->top->data;
}
//判断指针myStack指向的栈是否为空。
//栈空返回true，否则返回false。
bool empty(Stack *myStack){
    if(myStack->top->link==NULL)
        return true;
    else
        return false;
}
//销毁指针myStack所指向的栈
bool destroy(Stack *myStack){
    if(myStack->top==NULL)
        free(myStack);
    else{
        node* t=myStack->top->link;
        while(t!=NULL)
        {
            free(myStack->top);
            myStack->top=t;
            t=t->link;
        }
        free(myStack->top);
    }
    return true;
}

int main(void)
{
    Stack *head; //定义指向栈结构的指针
    char c;
    head = createStack(); //创建一个空栈
    c = getchar(); //读入第1个字符
    while (c != '\n')
    {//当读入的字符不是换行符时进入循环
        push(head, c); //字符变量C的值入栈
        c = getchar(); //读取下一个c
    }
    while (!empty(head))
    {//当栈不为空时进入循环
        c = top(head); //获取当前栈顶元素，由变量c得到栈顶元素的值
        printf("%c\n", c); //输出变量c的值到屏幕
        pop(head); //出栈1次
    }
    destroy(head);//销毁栈空间
    return 0;
}
