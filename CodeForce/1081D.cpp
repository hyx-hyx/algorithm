#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
typedef long long ll;
#define maxn 100050
using namespace std;
int fa[maxn];
typedef struct node
{
	int from;
	int to;
	int w;
}node;
vector<node> edge(200300);
bool cmp(node i, node j)
{
	return i.w < j.w;
}
void init(int n)
{
	for (int i = 0; i <= n; ++i)
		fa[i] = i;
}
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int i, int j)
{
	fa[find(j)] = find(i);
}
int main()
{
	int flag[maxn] = { 0 }, temp;
	int n, m, k;
	int ans = 0;
	scanf("%d%d%d", &n, &m, &k);
	init(n);
	for (int i = 0; i < k; ++i)
		scanf("%d", &temp), flag[temp] = 1;
	for (int i = 0; i < m; ++i)
		scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].w);
	sort(edge.begin(), edge.begin() + m, cmp);
	for (int i = 0; i < m; ++i)
	{
		int fa_from = find(edge[i].from);
		int fa_to = find(edge[i].to);
		if (fa_from!=fa_to)
		{
			merge(fa_from,fa_to);
			if (flag[fa_from] && flag[fa_to])
				ans = max(ans, edge[i].w);
			else
			{
				if (flag[fa_from] || flag[fa_to])
					flag[fa_from] = flag[fa_to] = 1;
			}
		}
	}
	for (int i = 0; i < k; ++i)
		printf("%d%c", ans, i == k - 1 ? '\n' : ' ');
	return 0;
}
