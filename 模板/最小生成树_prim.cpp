#define _CRT_SECURE_NO_WARNINGS 
#include<cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INFINITE 0x3FFFFFFF   
#define VertexData unsigned int  //顶点数据
#define vexCounts 5005  //顶点数量
int n;
struct node
{
    VertexData data;
    unsigned int lowestcost;
}closedge[vexCounts]; //Prim算法中的辅助信息
int Minmum(struct node* closedge)  //返回最小代价边
{
    unsigned int min = INFINITE;
    int index = 0;
    for (int i = 0; i < vexCounts; i++)
    {
        if (closedge[i].lowestcost < min && closedge[i].lowestcost != 0)
        {
            min = closedge[i].lowestcost;
            index = i;
        }
    }
    return index;
}
int MiniSpanTree_Prim(vector<vector<int> > &adjMat, VertexData s)
{
    int sum = 0;
    for (int i = 1; i <=n; i++)
    {
        closedge[i].lowestcost = INFINITE;
    }
    closedge[s].data = s;      //从顶点s开始
    closedge[s].lowestcost = 0;
    for (int i = 1; i <=n; i++)  //初始化辅助数组
    {
        if (i != s)
        {
            closedge[i].data = s;
            closedge[i].lowestcost = adjMat[s][i];
        }
    }
    for (int e = 1; e <n; e++)  //n-1条边时退出
    {
        int k = Minmum(closedge);  //选择最小代价边
        sum += closedge[k].lowestcost;
        closedge[k].lowestcost = 0; //代价置为0
        for (int i = 2; i <=n; i++)  //更新v中顶点最小代价边信息
        {
            if (adjMat[k][i] < closedge[i].lowestcost)
            {
                closedge[i].data = k;
                closedge[i].lowestcost = adjMat[k][i];
            }
        }
    }
    return sum;
}
int main()
{
    vector<vector<int> >adjMat(vexCounts, vector<int>(vexCounts, INFINITE));
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        adjMat[x][y] = z;
        adjMat[y][x] = z;
    }
    int ans = MiniSpanTree_Prim(adjMat, 1); //Prim算法，从顶点1开始.
    if (abs(ans) >= INFINITE)
        cout << "orz" << endl;
    else
        cout << ans << endl;
    return 0;
}