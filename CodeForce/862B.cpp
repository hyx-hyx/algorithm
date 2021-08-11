/*
题目大意：
给出一个有n个点的二分图和n-1条边，问现在最多可以添加多少条边使得这个图中不存在自环，重边，并且此图还是一个二分图。
解题分析：
此题不难想到，假设二分图点集数量分别为x,y,添加最多的边数，无非就是x*y-(n-1)，于是，我们利用dfs对所有点进行染色，进而将其划分为两个集合。
关于x*y-(n-1):从x表示的集合中选取一个点，连接y中的所有点。有x个点。所以二分图在不存在自环和重边的前提下边的总数为x*y.再减去题目已给出的n-1个点。
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
typedef long long ll;
#define edgecount 200005
#define pointcount 200005
struct edge
{
	int to;
	int next;
	int w;
};
vector<edge> edges(edgecount);
vector<int> head(pointcount, 0);
int cnt = 0;
inline void add(int from, int to, int w)
{
	edges[++cnt].to = to;
	edges[cnt].w = w;
	edges[cnt].next = head[from];
	head[from] = cnt;
}
ll x = 0, y = 0;
int vis[pointcount] = {0};
void dfs(int s, int flag)
{
	if (!flag)
		x++;
	else
		y++;
	vis[s] = 1;
	flag = flag & 1 ^ 1;                 //flag千万不能写在循环里，写在循环里是每次循环改变染的颜色就会导致错误
	for (int e = head[s]; e; e = edges[e].next)
		if (!vis[edges[e].to])
			dfs(edges[e].to, flag);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		add(u, v, 0);
		add(v, u, 0);
	}
	dfs(1, 0);
	cout <<x * y - n + 1 << endl;
	return 0;
}