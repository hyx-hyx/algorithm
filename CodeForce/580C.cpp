#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
#define maxn 100005
#define edgecount 200010
#define pointcount 100005
using namespace std;
int n, m, a[maxn],leaf[maxn],vis[maxn];
struct edge
{
	int to;
	int next;
	int w;
};
vector<int> ans;
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
void dfs(int point, int num_cat)
{
	vis[point] = 1;
	if (a[point])
	{
		num_cat++;
		if (num_cat >m)
			return;
	}
	else
		num_cat = 0;
	int node_num = 0;
	for (int e = head[point]; e != 0; e = edges[e].next)
	{
		int to = edges[e].to;
		if (!vis[to])
		{	
			node_num++;
			dfs(to, num_cat);
			vis[to] = 0;
		}
	}
	if(!node_num&&num_cat<=m)
		ans.push_back(point);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; ++i)
	{
		int from, to;
		scanf("%d%d", &from, &to);
		add(from, to, 0);
		add(to,from,0);
	}
	dfs(1, 0);
	printf("%d\n", ans.size());
	return 0;
}
