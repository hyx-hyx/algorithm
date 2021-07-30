#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#define pointcount 100
#define edgescount 100
#define inf 1e9
using namespace std;
struct edge
{
    int to;
    int w;
    int next;
};
typedef pair<int, int> Pair;
priority_queue<Pair, vector<Pair>, greater<Pair> > Q_dij;
vector<edge> edges(edgescount);
int cnt = 0;
vector<int> head(pointcount, 0);
vector<int> dist(pointcount, inf);
void add(int from,int to,int w)
{
    edges[++cnt].to=to;
    edges[cnt].w = w;
    edges[cnt].next = head[from];
    head[from] = cnt;
}
void SPFA(int s)
{
    vector<int> inqueue(pointcount, 0);
    dist[s] = 0;
    queue<int> Q;
    Q.push(s);
    inqueue[s] = 1;
    while(!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        inqueue[p] = 0;
        for (int e = head[p]; e != 0;e=edges[e].next)
        {
            int to = edges[e].to;
            if (dist[to] > dist[p]+edges[e].w)
            {
                dist[to] = dist[p] + edges[e].w;
                if(!inqueue[to])
                {
                    Q.push(to);
                    inqueue[to] = 1;
                }
            }
        }
    }
}
void dij(int s)
{
    vector<int> vis(pointcount, 0);
    dist[s]=0;
    Q_dij.push( make_pair(0, s));
    while(!Q_dij.empty())
    {
        int p=Q_dij.top().second;
        Q_dij.pop();
        if(vis[p])
            continue;
        vis[p] = 1;
        for (int e = head[p]; e != 0;e=edges[e].next)
        {
            int to = edges[e].to;
            dist[to] = min(dist[to], dist[p] + edges[e].w);
            if(!vis[to])
                Q_dij.push( make_pair(dist[to],to));
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
        if(dist[i]==inf)
        {
            cout << (int)(pow(2,31) - 1) << " ";
        }
        else
        {
            cout << dist[i] << " ";
        }
    }
    return 0;
}