#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
#define maxn 500005
typedef long long ll;
using namespace std;
#define edgecount 1000005
#define pointcount 500005
struct edge
{
	int to;
	int next;
	int w;
};
vector<edge> edges(edgecount);
vector<int> head(pointcount, 0);
int cnt = 0;
inline void add(int from, int to, int w)    //图论存图
{
	edges[++cnt].to = to;
	edges[cnt].w = w;
	edges[cnt].next = head[from];
	head[from] = cnt;
}
int dep[maxn], fa[maxn][25];
void dfs(int x, int pre)     //dfs求每个点的深度和祖先
{
	dep[x] = dep[pre] + 1;
	fa[x][0] = pre;
	for (int e = head[x]; e != 0; e = edges[e].next)
		if (edges[e].to != pre)
			dfs(edges[e].to, x);
}
int getlca(int x, int y)    //求两点的lca(默认x的深度大于y)
{
	if (dep[x] < dep[y])
		swap(x, y);
	while (dep[x] > dep[y])
		x = fa[x][(int)log2((double)( dep[x] - dep[y] ))];
	if (x == y)
		return y;
	for (int j = 20; j >= 0; --j)
		if (fa[x][j] != fa[y][j])
			x = fa[x][j], y = fa[y][j];
	return fa[x][0];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, s;
	cin >> n >> m >> s;
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;
		add(x, y, 0);
		add(y, x, 0);
	}
	dfs(s, 0);   //s为根节点
	for (int j = 1; j <= 20; ++j)
		for (int i = 1; i <= n; ++i)
			fa[i][j] = fa[fa[i][j - 1]][j - 1];   //初始化fa数组
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		cout << getlca(a, b) << endl;
	}
	return 0;
}