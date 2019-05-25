#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct{
    ElemType *elem; //存储空间基址
    int size; //顺序表当前长度
    int capacity; //当前分配的存储容量( 以sizeof(ElemType)为单位 )
}SqList, *List;
void init(List pList);//初始化指针pList指向的顺序表
void push_back(List pList, ElemType x);//把变量x的值加入顺序表末尾
int main(){
    SqList list;
    List p = &list;
    init(p);
    ElemType num;
    scanf("%d",&num);
    while(num!=-1)
    {
        push_back(p, num);
        if(p->capacity==p->size){
            SqList newList;
            List newP=&newList;
            newP->size=2*p->size;
            newP->capacity=p->capacity;
            newP->elem=(ElemType*)malloc(sizeof(ElemType)*2*(p->size));
            for(int i=0;i<p->capacity;i++)
            {
                newP->elem[i]=p->elem[i];
            }
            List q=p;
            p=newP;
            free(q->elem);
        }
        scanf("%d",&num);
    }
    scanf("%d",&num);
    int index=p->capacity-num;
    printf("%d",p->elem[index]);
    free(p->elem);
    return 0;
    }
void init(List pList){
    pList->size=10;
    pList->capacity=0;
    pList->elem=(ElemType*)malloc(10*sizeof(ElemType));
}
void push_back(List pList, ElemType x){
    pList->elem[pList->capacity]=x;
    pList->capacity++;
}
