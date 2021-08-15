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
#define maxn 1005
typedef long long ll;
#define edgecount 200010
#define pointcount 200010
struct edge
{
	int to;
	int next;
	int w;
};
vector<edge> edges(edgecount);
vector<int> head(pointcount,0);
typedef pair<int,int> Pair;
int cnt = 0;
inline void add(int from,int to,int w)
{
	edges[++cnt].to = to;
	edges[cnt].w = w;
	edges[cnt].next = head[from];
	head[from] = cnt;
}
int fa[maxn],ranki[maxn];
void init(int n)
{
	for(int i = 0; i<=n; ++i)
	{
		fa[i] = i;
		ranki[i] = 1;
	}
}
int find(int x)
{
	return fa[x]==x ? fa[x] : ( fa[x] = find(fa[x]) );
}
void merge(int i,int j)
{
	int x = find(i);
	int y = find(j);
	if(ranki[x]>ranki[y])
		fa[x] = y;
	else
		fa[y] = x;
	if(ranki[x]==ranki[y]&&x!=y)
		ranki[y]++;
}
int ans = 0,t[maxn] = {0};
vector<int> vis(maxn,0);
void dfs(int x,int l,int r)
{
	if(t[x]>=l&&t[x]<=r)
		ans++;
	else
		return;
	vis[x] = 1;
	for(int e = head[x]; e!=0; e = edges[e].next)
	{
		int to = edges[e].to;
		if(!vis[to])
		{
			vis[to] = 1;
			dfs(to,l,r);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int u[maxn],v[maxn];
	for(int i = 0; i<n-1; ++i)
		cin>>u[i]>>v[i],add(u[i],v[i],0),add(v[i],u[i],0);
	for(int i = 1; i<=n; ++i)
		cin>>t[i];
	int q;
	cin>>q;
	while(q--)
	{
		int x,l,r;
		cin>>x>>l>>r;
		ans = 0;
		vis.assign(maxn,0);
		dfs(x,l,r);
		cout<<ans<<endl;
	}
	return 0;
}
