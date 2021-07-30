#define _CRT_SECURE_NO_WARNINGS  
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define maxn 100000000
typedef long long ll;
using namespace std;
ll fa[maxn];
typedef struct node
{
	ll from;
	ll to;
	ll w;
}node;
vector<node> edge(100000000);
bool cmp(node i, node j)
{
	return i.w < j.w;
}
void init(ll n)
{
	for (ll i = 0; i < n; ++i)
		fa[i] = i;
}
ll find(ll x)
{
	return x == fa[x] ? x : find(fa[x]);
}
void merge(ll i, ll j)
{
	fa[find(j)] = find(i);
}
ll GCD(ll a, ll b)
{
	return a % b ? GCD(b, a % b) : b;
}
int main()
{
	ll t;
	cin >> t;
	for (ll i = 0; i < t; ++i)
	{
		ll n,k = 0, total = 0, cnt = 0;
		scanf("%lld", &n);
		for (ll i = 2; i <=n; ++i)
		{
			for (ll j = i+1; j <=n; ++j)
			{
				ll w = j * i/GCD(i,j);
				edge[++cnt].from = i;
				edge[cnt].to = j;
				edge[cnt].w = w;
			}
		}
		init(n);
		sort(edge.begin(), edge.begin() + cnt, cmp);
		for (ll i = 1; i <=cnt; ++i)
		{
			if (k == n - 1) break;
			if (find(edge[i].from) != find(edge[i].to))
			{
				merge(edge[i].from, edge[i].to);
				total += edge[i].w;
				k++;
			}
		}
		printf("%lld\n", total);
	}
	return 0;
}
