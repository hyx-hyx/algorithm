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
	int c,s,e;
}vis[maxn];
int fa[maxn];
void init(int n)
{
	for(int i = 0; i <= n; ++i)
		fa[i] = i;
}
int find(int x)
{
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	int p[maxn] = {0},dep[maxn] = {0};
	p[0] = -1;
	while(cin >> n)
	{
		init(n);
		memset(dep,0,sizeof(dep));
		for(int i = 1; i < n; ++i)
			vis[i].c = 0;
		for(int i = 1; i <= n - 1; ++i)
		{
			cin >> p[i];
			dep[i] = dep[p[i]] + 1;
		}
		int q;
		cin >> q;
		for(int i = 0; i < q; ++i)
		{
			char c;
			int u,v;
			cin >> c;
			if(c == 'R')
			{
				cin >> u >> v;
				if(u > v)
					swap(u,v);
				int utemp = u,vtemp = v;
				while(u != v)
				{
					if(dep[u] < dep[v])
						swap(u,v);
					vis[u].c++;
					if(vis[u].c == 1)
						vis[u].s = utemp,vis[u].e = vtemp;
					else
						fa[u] = p[u];
					u = find(p[u]);
				}
			}
			if(c == 'W')
			{
				cin >> v;
				if(!vis[v].c)
					cout << "Not yet" << endl;
				if(vis[v].c == 1)
					cout << vis[v].s << " " << vis[v].e << endl;
				if(vis[v].c == 2)
					cout << "Many times" << endl;
			}
		}
	}
	return 0;
}