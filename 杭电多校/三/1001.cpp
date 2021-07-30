#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
#define edgecount 100005
#define pointcount 100005
#define inf 1e9+5
vector<int> pre(pointcount, 0);
struct edge
{
	int to;
	int next;
	int w;
};
vector<edge> edges(edgecount);
vector<int> head(pointcount, 0);
typedef pair<int, int> Pair;
int cnt = 0;
inline void add(int from, int to, int w)
{
	edges[++cnt].to = to;
	edges[cnt].w = w;
	edges[cnt].next = head[from];
	head[from] = cnt;
}
void dij(int s)
{
	vector<int> vis(pointcount, 0);
	vector<int> dist(pointcount, inf);
	pre.assign(pointcount, 0);
	priority_queue<Pair, vector<Pair>, greater<Pair> > Q;
	Q.push(make_pair(0, s));
	dist[s] = 0;
	while (!Q.empty())
	{
		int p = Q.top().second;
		Q.pop();
		if (vis[p])
			continue;
		vis[p] = 1;
		for (int e = head[p]; e != 0; e = edges[e].next)
		{
			int to = edges[e].to;
			if (edges[e].w + dist[p] < dist[to])
			{
				pre[to] = p;
				dist[to] = edges[e].w + dist[p];
				if (!vis[to])
					Q.push(make_pair(dist[to], to));
			}
		}
	}
}
int main()
{
	int n, t,q;
	int a[100] = { 0 };
	cin >> t;
	for (int T = 0; T < t; ++T)
	{
		edges.assign(edgecount, { 0,0,0 });
		head.assign(pointcount, 0);
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i <n-1; ++i)
		{
			int to, from;
			scanf("%d%d", &from, &to);
			add(from, to, 1);
			add(to, from, 1);
		}
		for (int i = 0; i < q; ++i)
		{
			int start, terminal, laststart = 0, money;
			scanf("%d%d%d", &start, &terminal, &money);
			if (laststart != start)
				dij(start);
			int path = terminal;
			vector<int> temp;
			while (path != start && path)
			{
				temp.push_back(path);
				path = pre[path];
			}
			temp.push_back(start);
			for (int i = temp.size() - 1; i >= 0; --i)
			{
				if (a[temp[i]] <= money)
					money -= a[temp[i]];
			}
			printf("%d\n", money);
		}
	}
	return 0;
}
/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#define maxn 105
using namespace std;
int dist[maxn][maxn];
void Floyd(int n)
{
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
int main()
{
	int n, t,q;
	int a[100] = { 0 };
	cin >> t;
	for (int T = 0; T < t; ++T)
	{
		memset(dist, 0, sizeof(dist));
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < n - 1; ++i)
		{
			int to, from;
			scanf("%d%d", &from, &to);
			dist[from][to] = 1;
			dist[to][from]=1;
		}
		Floyd(n);
		for (int i = 0; i < q; ++i)
		{
			int x, y, money = 0;
			scanf("%d%d%d", &x, &y, &money);

		}
	return 0;
}
*/