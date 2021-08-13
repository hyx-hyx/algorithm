/*
Primq求MST
耗费矩阵cost[][],标号从1开始，1~n,相当于存图用的矩阵
返回最小生成树的权值，返回-1表示原图不连通
*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=505;
int cost[MAXN][MAXN];
bool vis[MAXN];
int lowc[MAXN];

int Prim(int n)
{
    int ans=0;
    memset(vis,false,sizeof(vis));
    vis[1]=true;
    for(int i=2;i<=n;i++) lowc[i]=cost[1][i];
    for(int i=2;i<=n;i++)
    {
        int minc=INF,p=-1;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&minc>lowc[j])
            {
                minc=lowc[j];
                p=j;
            }
        }
        if(minc==INF) return -1;//原图不连通
        ans+=minc;
        vis[p]=true;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&lowc[j]>cost[p][j])
                lowc[j]=cost[p][j];
        }
    }
    return ans;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m==0) break;
        memset(cost,INF,sizeof(cost));
        int u,v,w;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            cost[u][v]=min(cost[u][v],w);
            cost[v][u]=min(cost[v][u],w);
        }
        int res=Prim(n);
        if(res==-1) printf("?\n");
        else  printf("%d\n",res);
    }
    return 0;
}