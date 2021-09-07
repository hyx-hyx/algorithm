#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
struct edge
{
	int u,v,w;
}edges[500005];
bool cmp(edge i,edge j)
{
	return i.w < j.w;
}
int fa[maxn],ranki[maxn];
void init(int n)
{
	for(int i = 0; i <= n; ++i)
	{
		fa[i] = i;
		ranki[i] = 1;
	}
}
int find(int x)
{
	return fa[x] == x ? fa[x] : (fa[x] = find(fa[x]));
}
int  merge(int i,int j)
{
	int x = find(i);
	int y = find(j);
	if(x == y)
		return 0;
	if(ranki[x] > ranki[y])
		fa[x] = y;
	else
		fa[y] = x;
	if(ranki[x] == ranki[y] && x != y)
		ranki[y]++;
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int cnt;
		int n,m,k;
		cin >> n >> m >> k;
		cnt = n;
		init(n);
		for(int i = 0; i < m; ++i)
			cin >> edges[i].u >> edges[i].v >> edges[i].w;
		sort(edges,edges + m,cmp);
		int flag = 0;
		if(n == k)
		{
			cout << 0 << endl;
			continue;
		}
		for(int i = 0; i < m - 1; ++i)
		{
			cnt -= merge(edges[i].u,edges[i].v);
			if(edges[i].w != edges[i + 1].w)
				if(cnt == k)
				{
					cout << edges[i].w << endl;
					flag = 1;
					break;
				}
		}
		if(!flag)
			cout << -1 << endl;
	}
	return 0;
}