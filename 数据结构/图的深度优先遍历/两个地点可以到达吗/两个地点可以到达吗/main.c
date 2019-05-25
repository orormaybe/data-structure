#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int visited[101]={0};
int graph[101][101]={0};
int flag=0;
void findWay(int src,int des,int size);
int main()
{
    int num;
    scanf("%d",&num);
    while(num--){
        flag=0;
        int size;
        scanf("%d",&size);
        int src,des;
        scanf("%d%d",&src,&des);
        for(int i=1;i<=size;i++)
        {
            for(int j=1;j<=size;j++)
            {
                scanf("%d",&graph[i][j]);
            }
            
        }
        findWay(src,des,size);
        if(flag==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

void findWay(int src,int des,int size){
    if(visited[src]==1)
        return;
    visited[src]=1;
    if(src==des)
        flag=1;
    for(int w=1;w<=size;w++)
    {
            if(visited[w]==0&&graph[src][w]==1)
                findWay(w, des,size);
    }
}
