#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
using namespace std;
#define edgecount 40010
#define pointcount 20005
const int MAXN = 200005;
struct edge
{
    int to;
    int next;
    int w;
};
vector<edge> edges(edgecount);
vector<int> head(pointcount,0);
int cnt = 0,n;
inline void add(int from,int to,int w)
{
    edges[++cnt].to = to;
    edges[cnt].w = w;
    edges[cnt].next = head[from];
    head[from] = cnt;
}
// 这份代码默认节点编号从 1 开始，即 i ∈ [1,n]
int sizet[MAXN],  // 这个节点的“大小”（所有子树上节点数 + 该节点）
weight[MAXN],  // 这个节点的“重量”
centroid[2];   // 用于记录树的重心（存的是节点编号）
void GetCentroid(int cur,int fa)
{  // cur 表示当前节点 (current)
    sizet[cur] = 1;
    weight[cur] = 0;
    for(int i = head[cur]; i != 0; i = edges[i].next)
    {
        if(edges[i].to != fa)
        {  // e[i].to 表示这条有向边所通向的节点。
            GetCentroid(edges[i].to,cur);
            sizet[cur] += sizet[edges[i].to];
            weight[cur] = max(weight[cur],sizet[edges[i].to]);
        }
    }
    weight[cur] = max(weight[cur],n - sizet[cur]);
    if(weight[cur] <= n / 2)
    {  // 依照树的重心的定义统计
        centroid[centroid[0] != 0] = cur;
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        edges.assign(edgecount,edge{0,0,0});
        head.assign(pointcount,0);
        cnt = 0;
        centroid[0] = centroid[1] = 0;
        cin >> n;
        For(i,0,n - 1)
        {
            int x,y;
            cin >> x >> y;
            add(x,y,0),add(y,x,0);
        }
        GetCentroid(1,0);
        int ans;
        if(centroid[1])
            ans = max(centroid[0],centroid[1]);
        else
            ans = centroid[0];
        cout << ans << " " << weight[ans] << endl;
    }
    return 0;
}