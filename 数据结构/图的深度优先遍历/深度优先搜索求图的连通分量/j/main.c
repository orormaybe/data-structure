#include <stdio.h>

/*图的邻接矩阵*/
int graph[7][7] = {{0, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 0}};
/*顶点的访问标记，为 visited[i] 等于 0 表示 i 号顶点没有被访问过*/
int visited[7] = {0};

//从v号顶点开始，做深度优先搜索
void dfs(int v);

int main(void)
{
    int k = 0;//连通分量的个数
    for (int v = 0; v < 7; v++)
    {
        if (visited[v] == 0)
        {
            k++;
            dfs(v);
        }
    }
    printf("\n该图共有 %d 个连通分量\n", k);
    return 0;
}

//从v号顶点开始，做深度优先搜索
void dfs(int v)
{
    if (visited[v] == 1)
        return;
    visited[v] = 1;
    //访问v号顶点
    printf("%d ", v);
    //对v的每一个没有访问过的邻接点w，做dfs(w)
    for (int w = 0; w < 7; w++)
    {
        if (graph[v][w] == 1 && visited[w] == 0)
        {
            dfs(w);
        }
    }
}
