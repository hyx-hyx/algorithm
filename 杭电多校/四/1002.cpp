#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define edgecount 6005
#define pointcount 2005
#define inf 1e9
vector<int>c_vis(pointcount);
vector<int>vis(pointcount);
int c[pointcount], start;
vector<vector<int> >a(pointcount, vector<int>(pointcount));
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
ll fastpower(ll base, ll power, ll mod)
{
	ll res = 1;
	while (power)
	{
		if (power & 1)
			res = (res * base) % mod;
		base = (base * base) % mod;
		power >>= 1;
	}
	return res;
}
void dfs(int s, int count)
{
	vis[s] = 1;
	for (int e = head[s]; e != 0; e = edges[e].next)
	{
		int to = edges[e].to;
		if (!vis[to])
		{
			if (!c_vis[c[to]])
			{
				c_vis[c[to]] = 1;
				count++;
				a[start][to] = count;
				dfs(to, count);
				c_vis[c[to]] = 0;
				count--;
			}
			else
			{
				a[start][to] = count;
				dfs(to, count);
			}
		}
	}
}
int main()
{
	int t;
	ll sum1 = 0;
	ll sum2 = 0;
	ll x = 19560929;
	ll mod1 = 1e9 + 7;
	ll mod2 = 1e9 + 9;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		edges.assign(edgecount,{0,0,0});
		head.assign(pointcount,0);
		for (int i = 2; i <= n; ++i)
		{
			int temp;
			scanf("%d", &temp);
			add(i, temp, 0);
			add(temp, i, 0);
		}
		for (int i = 1; i <= n; ++i)
			scanf("%d", &c[i]);
		for (int i = 1; i <= n; ++i)
		{
			start = i;
			c_vis.assign(n + 5, 0);
			vis.assign(n + 5, 0);
			c_vis[c[start]] = 1;
			a[start][start] = 1;
			dfs(start, 1);
			sum1 = 0;
			sum2 = 0;
			for (int j = 1; j <= n; ++j)
			{
				sum1 = (sum1 + (((ll)a[i][j] * fastpower(x, j - 1, mod1)) % mod1)) % mod1;
				sum2 = (sum2 + (((ll)a[i][j] * fastpower(x, j - 1, mod2)) % mod2)) % mod2;
			}
			printf("%lld %lld\n", sum1, sum2);
		}
	}
	return 0;
}
