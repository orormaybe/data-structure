#include "stdio.h"
#include "stdlib.h"
typedef struct _node{
    int data;
    int power;
    struct _node* next;
}node;
node* createList();
void insertList(node* head,int data,int power);
void mergeList(node* head,node* head1,node* head2);
void deleteList(node* head,node* p);
void freeList(node* head);
void showList(node* head);
void addList(node* head,int data,int power);
node* search(node* head,int power);
int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        int num1,num2;
        node* head1=createList();
        node* head2=createList();
        scanf("%d%d",&num1,&num2);
        while(num2>=0)
        {
            insertList(head1, num1, num2);
            scanf("%d%d",&num1,&num2);
        }
        scanf("%d%d",&num1,&num2);
        while(num2>=0)
        {
            insertList(head2, num1, num2);
            scanf("%d%d",&num1,&num2);
        }
        node* head=createList();
        mergeList(head, head1, head2);
        showList(head);
        freeList(head);
        freeList(head1);
        freeList(head2);
    }
}
node* createList(){
    node* head=(node*)malloc(sizeof(node));
    head->next=NULL;
    return head;
}
void insertList(node* head,int data,int power){
    node* t=search(head, power);
    if(t!=NULL){
        t->data+=data;
        return;
    }
    while(head->next!=NULL)
        head=head->next;
    node* p=createList();
    p->data=data;
    p->power=power;
    p->next=NULL;
    head->next=p;
    return;
}
void mergeList(node* head,node* head1,node* head2){
    node* ptr=head1->next;
    while(ptr!=NULL)
    {
        node* p=search(head2, ptr->power);
        if(p!=NULL)
        {
            int data=p->data+ptr->data;
            deleteList(head2,p);
            if(data==0)
            {
                ptr=ptr->next;
                continue;
            }
            addList(head, data, ptr->power);
        }
        else{
            addList(head, ptr->data, ptr->power);
        }
        ptr=ptr->next;
    }
    node* t=head2->next;
    while(t!=NULL)
    {
        addList(head, t->data, t->power);
        t=t->next;
    }
}
void deleteList(node* head,node* p){
    node* ptr=head->next;
    while(ptr->power!=p->power)
    {
        head=ptr;
        ptr=ptr->next;
    }
    head->next=ptr->next;
    free(p);
}
void freeList(node* head){
    node* ptr=head->next;
    while(head->next!=NULL)
    {
        free(head);
        head=ptr;
        ptr=ptr->next;
    }
    free(head);
}
void showList(node* head){
    node* ptr=head->next;
    while(ptr!=NULL)
    {
        printf("[%d %d]",ptr->data,ptr->power);
        ptr=ptr->next;
    }
    printf("\n");
}
node* search(node* head,int power){
    head=head->next;
    while(head!=NULL){
        if(head->power==power)
            return head;
        head=head->next;
    }
    return NULL;
}
void addList(node* head,int data,int power){
    node* ptr=head->next;
    while(1){
        if(ptr==NULL){
            node* newList=(node*)malloc(sizeof(node));
            newList->data=data;
            newList->power=power;
            newList->next=NULL;
            head->next=newList;
            newList->next=ptr;
            break;
        }
        else if(ptr->power>power&&ptr!=NULL)
        {
            node* newList=(node*)malloc(sizeof(node));
            newList->data=data;
            newList->power=power;
            head->next=newList;
            newList->next=ptr;
            break;
        }
        head=ptr;
        ptr=ptr->next;
    }
}
