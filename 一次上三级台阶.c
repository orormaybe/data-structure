//
//  main.c
//  一次上三级台阶
//
//  Created by 汪博文 on 2019/4/16.
//  Copyright © 2019 汪博文. All rights reserved.
//

#include <stdio.h>
int sum(int n);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int n;
    scanf("%d",&n);
    printf("%d\n",sum(n));
    return 0;
}
int sum(int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(n==3)
        return 3;
    return sum(n-1)+sum(n-2)+sum(n-3);
}
//不能使用递归，不能使用类似上1，2级台阶使用sum(n-1)+sum(n-2)+sum(n-3);
