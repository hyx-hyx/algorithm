#define _CRT_SECURE_NO_WARNINGS   //洛谷  P3366
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define maxn 5005
using namespace std;
int fa[maxn];
typedef struct node
{
	int from;
	int to;
	int w;
}node;
vector<node> edge(200005);
bool cmp(node i, node j)
{
	return i.w < j.w;
}
void init(int n)
{
	for (int i = 0; i < n; ++i)
		fa[i] = i;
}
int find(int x)
{
	return x == fa[x] ? x : find(fa[x]);
}
void merge(int i, int j)
{
	fa[find(j)] = find(i);
}
int main()
{
	int n, m,k=0,total=0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)2
		scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].w);
	init(n);
	sort(edge.begin(), edge.begin()+m, cmp);
	for (int i = 0; i <= m; ++i)
	{
		if (k == n - 1) break;
		if (find(edge[i].from) != find(edge[i].to))
		{
			merge(edge[i].from, edge[i].to);
			total += edge[i].w;
			k++;
		}
	}
	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (fa[i] == i)
			count++;
	}
	if (count > 1)
		cout << "orz" << endl;
	else
		cout << total << endl;
	return 0;
}
