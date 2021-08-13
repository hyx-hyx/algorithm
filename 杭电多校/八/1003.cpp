/*
分析
一道简单的最小生成树题，题面可以转化成在一个完全图上求最小生成树，直接使用Prim解决，复杂度$O(n^2)$。
常数较好的kruskal也可以通过，但是如果是二分答案然后搜索做，复杂度$O(n^2logn)$的可能过不了。
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 5005
typedef long long ll;
const ll INF = 9*1e18;  //注意本题这里无穷大应取ll，9*1e8
const int MAXN = 5005;
ll cost[MAXN][MAXN];
bool vis[MAXN];
ll lowc[MAXN];
ll res = 0;       //本题数据较大，取long long
int Prim(int n)
{
    int ans = 0;
    memset(vis, false, sizeof(vis));
    vis[1] = true;
    for (int i = 2; i <= n; i++) lowc[i] = cost[1][i];
    for (int i = 2; i <= n; i++)
    {
        ll minc = INF, p = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && minc > lowc[j])
            {
                minc = lowc[j];
                p = j;
            }
        }
        res = max(res, minc);   //输出的答案，树上两点间最短距离的最大值
        if (minc == INF) return -1;//原图不连通
        ans += minc;
        vis[p] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll x[maxn], y[maxn];  //long long
        for (int i = 1; i <= n; ++i)
            cin >> x[i] >> y[i];
        for (int i = 1; i <= n; ++i)
        {
            cost[i][i] = 0;
            for (int j = i+1; j <= n; ++j)
            {
                cost[i][j] = ( x[i] - x[j] ) * ( x[i] - x[j] ) + ( y[i] - y[j] ) * ( y[i] - y[j] );
                cost[j][i] = cost[i][j];
            }
        }
        res = 0;
        Prim(n);
        printf("%lld\n", res);
    }
    return 0;
}