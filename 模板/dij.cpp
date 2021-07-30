#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <cstdio>
#define edgecount 500005
#define pointcount 10005
#define inf 1e9
using namespace std;
struct edge
{
    int to;
    int next;
    int w;
};
vector<edge> edges(edgecount);
vector<int> head(pointcount, 0);
vector<int> dist(pointcount, inf);
typedef pair<int, int> Pair;
int cnt = 0;
inline void add(int from,int to,int w)
{
    edges[++cnt].to=to;
    edges[cnt].w=w;
    edges[cnt].next = head[from];
    head[from] = cnt;
}
void dij(int s)
{
    vector<int> vis(pointcount,0);
    priority_queue<Pair,vector<Pair>,greater<Pair> > Q;
    Q.push(make_pair(0, s));
    dist[s] = 0;
    while(!Q.empty())
    {
        int p = Q.top().second;
        Q.pop();
        if(vis[p])
            continue;
        vis[p] = 1;
        for (int e = head[p]; e != 0;e=edges[e].next)
        {
            int to = edges[e].to;
            dist[to] = min(dist[to], edges[e].w + dist[p]);
            if(!vis[to])
                Q.push(make_pair(dist[to], to));
        }
    }
} 
int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m;++i)
    {
        int to, w, from;
        cin >> from >> to >> w;
        add(from, to, w);
    }
    dij(s);
    for (int i = 1; i <=n;++i)
    {
        if(dist[i]!=1e9)
            cout << dist[i] << " ";
        else
            printf("%d ",(int)(pow(2,31)-1));
    }
    return 0;
}