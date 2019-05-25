//
//  main.c
//  v1,v2遍历
//
//  Created by 汪博文 on 2019/5/25.
//  Copyright © 2019 汪博文. All rights reserved.
/*图的深度优先搜索（邻接矩阵存储）
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 32767kB
描述
输入一个用邻接矩阵存储的图，输出从某个顶点开始的深度优先遍历得到的顶点序列。我们约定，当一个顶点有多个邻接点时，先访问编号小的邻接点。该图有8个顶点，如下图所示：



输入
输入分为3个部分。
第一行是8个以空格隔开的字符串，分别是8个顶点的名称。
从第二行开始是8行8列的邻接矩阵。
最后一行是一个顶点的名称，表示从该顶点出发开始深度优先遍历。
输出
深度优先遍历得到的顶点序列。每个顶点名称之间以空格隔开。
样例输入
V1 V2 V3 V4 V5 V6 V7 V8
0 1 1 0 0 0 0 0
1 0 0 1 1 0 0 0
1 0 0 0 0 1 1 0
0 1 0 0 0 0 0 1
0 1 0 0 0 0 0 1
0 0 1 0 0 0 1 0
0 0 1 0 0 1 0 0
0 0 0 1 1 0 0 0
V1
样例输出
V1 V2 V4 V8 V5 V3 V6 V7*/
//

#include <stdio.h>
#include <stdlib.h>
int graph[9][9];
int visited[9]={0};
void des(int v);
int main(int argc, const char * argv[]) {
    // insert code here...
    int num;
    char a;
    for(int i=1;i<=8;i++){
        scanf("%c%d ",&a,&num);//%c%d后面要加上空格，因为scanf()以Space、Enter、Tab结束一次输入如果不加空格，当scanf读完v1后会读到v1后面的空格，那么v2，v3就会读到graph中。
    }
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    getchar();/*必须加上getchar()，使用getchar()函数的两种情况：
               1:前面有scanf，后面要用ch=get()接收字符时，中间要用一个空的getchar（）吃回车；
               2:2个接收字符的ch=getchar()中间需要一个空的getchar（）吃回车。
               对于scanf函数,需求%s类型时,\n是不会影响scanf内容的，也不需要使用getchar()函数
               对于需求%c类型时,\n也是字符,自然会有影响.*/
    

    scanf("%c%d",&a,&num);
    des(num);
    return 0;
}
void des(int v){
    if(visited[v]==1)
        return;
    visited[v]=1;
    printf("V%d ",v);
    for(int w=1;w<=8;w++){
        if(visited[w]==0&&graph[v][w]==1)
            des(w);
    }
}
