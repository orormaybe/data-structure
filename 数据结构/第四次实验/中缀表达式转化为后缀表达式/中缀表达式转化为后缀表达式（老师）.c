#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node *ptr_to_node;
typedef ptr_to_node Stack;

typedef struct Node_i *ptr_to_node_i;
typedef ptr_to_node_i Stack_i;

struct Node
{
    char Element;
    ptr_to_node Next;
};

struct Node_i
{
    int Element;
    ptr_to_node_i Next;
};

bool is_empty(Stack S);
Stack creat_stack();
void make_empty(Stack S);
void Push(char X, Stack S);
char Top(Stack S);
void Pop(Stack S);

bool is_empty_i(Stack_i S);
Stack_i creat_stack_i();
void make_empty_i(Stack_i S);
void Push_i(int X, Stack_i S);
int Top_i(Stack_i S);
void Pop_i(Stack_i S);

int main()
{
    Stack S1, S2;
    S1 = creat_stack();
    S2 = creat_stack();
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i != n; ++i) {
        char c;
        while ((c = getchar()) != '\n') {
            if (c >= '0' && c <= '9') {
                Push(c, S1);
                continue;
            }
            if (c == ')') {
                while (Top(S2) != '(') {
                    Push(Top(S2), S1);
                    Pop(S2);
                }
                Pop(S2);
                continue;
            }
            while (((c == '+' || c == '-') && Top(S2) != '(' && !is_empty(S2)) || ((c == '*' || c == '/') && (Top(S2) == '*' || Top(S2) == '/'))) {
                Push(Top(S2), S1);
                Pop(S2);
            }
            Push(c, S2);
        }
        while (!is_empty(S2)) {
            Push(Top(S2), S1);
            Pop(S2);
        }
        while (!is_empty(S1)) {
            Push(Top(S1), S2);
            Pop(S1);
        }
        Stack_i S3;
        S3 = creat_stack_i();
        while (!is_empty(S2)) {
            printf("%c", Top(S2));
            int t;
            if (Top(S2) >= '0' && Top(S2) <= '9') {
                t = Top(S2) - '0';
                Push_i(t, S3);
            }
            else {
                int t1 = Top_i(S3);
                Pop_i(S3);
                int t2 = Top_i(S3);
                Pop_i(S3);
                if (Top(S2) == '+')
                    t = t2 + t1;
                if (Top(S2) == '-')
                    t = t2 - t1;
                if (Top(S2) == '*')
                    t = t2 * t1;
                if (Top(S2) == '/')
                    t = t2 / t1;
                Push_i(t, S3);
            }
            Pop(S2);
        }
        printf(" %d\n", Top_i(S3));
        make_empty(S1);
        make_empty(S2);
        make_empty_i(S3);
    }
    return 0;
}
bool is_empty(Stack S)
{
    return S->Next == NULL;
}

bool is_empty_i(Stack_i S)
{
    return S->Next == NULL;
}

Stack creat_stack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct Node));
    S->Next = NULL;
    make_empty(S);
    return S;
}

Stack_i creat_stack_i()
{
    Stack_i S;
    S = (Stack_i)malloc(sizeof(struct Node_i));
    S->Next = NULL;
    make_empty_i(S);
    return S;
}

void make_empty(Stack S)
{
    while (!is_empty(S))
        Pop(S);
}

void make_empty_i(Stack_i S)
{
    while (!is_empty_i(S))
        Pop_i(S);
}

void Push(char X, Stack S)
{
    ptr_to_node T;
    T = (Stack)malloc( sizeof(struct Node));
    T->Element = X;
    T->Next = S->Next;
    S->Next = T;
}

void Push_i(int X, Stack_i S)
{
    ptr_to_node_i T;
    T = (Stack_i)malloc( sizeof(struct Node_i));
    T->Element = X;
    T->Next = S->Next;
    S->Next = T;
}

char Top(Stack S)
{
    if(!is_empty(S)) {
        return S->Next->Element;
    }
}

int Top_i(Stack_i S)
{
    if(!is_empty_i(S)) {
        return S->Next->Element;
    }
}

void Pop(Stack S)
{
    ptr_to_node F;
    if(!is_empty(S)) {
        F = S->Next;
        S->Next = S->Next->Next;
        free(F);
    }
}

void Pop_i(Stack_i S)
{
    ptr_to_node_i F;
    if(!is_empty_i(S)) {
        F = S->Next;
        S->Next = S->Next->Next;
        free(F);
    }
}

