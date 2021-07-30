#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define edgecount 13000
#define pointcount  2505
#define inf 1e9
using namespace std;
struct edge
{
	int next;
	int to;
	int w;
};
vector<edge> edges(edgecount);
vector<int> head(pointcount, 0);
vector<int> dist(pointcount, inf);
int cnt = 0;
inline void add(int from, int to, int w)
{
	edges[++cnt].to = to;
	edges[cnt].w = w;
	edges[cnt].next = head[from];
	head[from] = cnt;
}
typedef pair<int, int> Pair;
void dij(int s)
{
	vector<int> vis(pointcount, 0);
	priority_queue<Pair, vector<Pair>, greater<Pair> >Q;
	Q.push(make_pair(0, s));
	dist[s] = 0;
	while(!Q.empty())
	{
		int p = Q.top().second;
		Q.pop();
		if (vis[p])
			continue;
		vis[p] = 1;
		for (int e = head[p]; e != 0; e = edges[e].next)
		{
			int to = edges[e].to;
			dist[to] = min(dist[p] + edges[e].w, dist[to]);
			if (!vis[to])
				Q.push(make_pair(dist[to], to));
		}
	}
}
int main()
{
	int n,m,s,t;
	cin >> n>>m>>s>>t;
	for (int i = 0; i < m; ++i)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	dij(s);
	cout << dist[t] << endl;
	return 0;
}