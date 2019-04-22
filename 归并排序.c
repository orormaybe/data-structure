//
//  main.c
//  归并排序
//
//  Created by 汪博文 on 2019/4/17.
//  Copyright © 2019 汪博文. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
void Sort(int *a,int low,int high);
void Merge(int *a,int low,int high,int mid);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int a[100];
    int n,num;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        a[i]=num;
    }
    Sort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
    
    
}
void Sort(int *a,int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(high+low)/2;
        Sort(a, low, mid);
        Sort(a, mid+1, high);
        Merge(a, low, high, mid);
    }
}
void Merge(int *a,int low,int high,int mid)
{
    int *temp;
    int left_low=low;
    int left_high=mid;
    int right_low=mid+1;
    int right_high=high;
    int i;
    temp=(int*)malloc(sizeof(int)*(high-low+1));
    int k=0;
    for(k=0;right_low<=right_high&&left_low<=left_high;k++)
    {
        if(a[right_low]<a[left_low])
            temp[k]=a[right_low++];
        else
            temp[k]=a[left_low++];
    }
    if(right_low<=right_high)
    {
        for(i=right_low;i<=right_high;i++)
        {
            temp[k++]=a[i];
        }
    }
    if(left_low<=left_high)
    {
        for(i=left_low;i<=left_high;i++)
        {
            temp[k++]=a[i];
        }
    }
    for(i=0;i<high-low+1;i++)
        a[low+i]=temp[i];
    free(temp);
}
