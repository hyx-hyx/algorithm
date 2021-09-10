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
typedef long long ll;
#define edgecount 8010
#define pointcount 4005
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const ll x = 19560929;
struct edge
{
	int to;
	int next;
	int w;
};
vector<edge> edges(edgecount);
vector<int> head(pointcount,0);
int cnt = 0,c[pointcount];
vector<int> a(pointcount);
inline void add(int from,int to,int w)
{
	edges[++cnt].to = to;
	edges[cnt].w = w;
	edges[cnt].next = head[from];
	head[from] = cnt;
}
int vis[pointcount] = {0},c_vis[pointcount] = {0};
void dfs(int s)
{
	for(int e = head[s]; e; e = edges[e].next)
	{
		int to = edges[e].to;
		if(!vis[to])
		{
			if(!c_vis[c[to]])
				a[to] = a[s]+1;
			else
				a[to] = a[s];
			c_vis[c[to]]++;
			vis[to] = 1;
			dfs(to);
			c_vis[c[to]]--;
		}
	}
}
ll fastpower(ll base,ll power,ll mod)
{
	ll res = 1;
	while(power)
	{
		if(power & 1)
			res = (res * base) % mod;
		base = (base * base) % mod;
		power >>= 1;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	ll exp1[pointcount] = {0};
	ll exp2[pointcount] = {0};
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i = 1; i <= n; ++i)
			exp1[i] = fastpower(x,i - 1,mod1) % mod1,exp2[i] = fastpower(x,i - 1,mod2) % mod2;
		for(int i = 2; i <= n; ++i)
		{
			int temp;
			cin >> temp;
			add(temp,i,0);
			add(i,temp,0);
		}
		for(int i = 1; i <= n; ++i)
			cin >> c[i];
		for(int i = 1; i <= n; ++i)
		{
			a.assign(pointcount,1);
			memset(c_vis,0,sizeof(c_vis));
			memset(vis,0,sizeof(vis));
			c_vis[c[i]] = 1;
			vis[i] = 1;
			dfs(i);
			ll ans1 = 0,ans2 = 0;
			for(int j = 1; j <= n; ++j)
			{
				c_vis[c[j]] = 1;
				ans1 = (ans1 + ((ll)a[j]*exp1[j] % mod1)) % mod1;
				ans2 = (ans2 + ((ll)a[j]*exp2[j] % mod2)) % mod2;
			}
			cout << ans1 << " " << ans2 << endl;
		}
	}
	return 0;
}