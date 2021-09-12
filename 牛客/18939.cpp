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
const int mod = 1e9 + 7;
typedef long long ll;
#define edgecount 100005
#define pointcount 100005
int v[maxn],fa[maxn],dep[maxn],siz[maxn],son[maxn];
int tim,dfn[maxn],top[maxn],w[maxn];
//===============================================
//图论存图
struct edge
{
	int to;
	int next;
	int w;
};
vector<edge> edges(edgecount);
vector<int> head(pointcount,0);
int cnt = 0;
inline void add(int from,int to,int w)
{
	edges[++cnt].to = to;
	edges[cnt].w = w;
	edges[cnt].next = head[from];
	head[from] = cnt;
}
//===============================================
//线段树
struct Node
{
	ll l,r,f,val,squaresum = 0;
} sgt[maxn * 4];
inline int ls(int k)
{
	return k << 1;
}
inline int rs(int k)
{
	return k << 1 | 1;
}
inline void pushup(int k)
{
	sgt[k].val = (sgt[ls(k)].val + sgt[rs(k)].val) % mod;
	sgt[k].squaresum = (sgt[ls(k)].squaresum + sgt[rs(k)].squaresum) % mod;
}
inline void pushdown(int k)
{
	sgt[ls(k)].squaresum = (sgt[ls(k)].squaresum + ((sgt[ls(k)].r - sgt[ls(k)].l + 1) * sgt[k].f%mod * sgt[k].f%mod + 2 * sgt[k].f%mod * sgt[ls(k)].val%mod)%mod) % mod;
	sgt[rs(k)].squaresum = (sgt[rs(k)].squaresum + ((sgt[rs(k)].r - sgt[rs(k)].l + 1) * sgt[k].f%mod * sgt[k].f%mod + 2 * sgt[k].f%mod * sgt[rs(k)].val%mod)%mod) % mod;
	sgt[ls(k)].f = (sgt[ls(k)].f + sgt[k].f) % mod;
	sgt[rs(k)].f = (sgt[k].f + sgt[rs(k)].f) % mod;
	sgt[ls(k)].val = (sgt[ls(k)].val + (sgt[ls(k)].r - sgt[ls(k)].l + 1) * sgt[k].f%mod) % mod;
	sgt[rs(k)].val = (sgt[rs(k)].val + (sgt[rs(k)].r - sgt[rs(k)].l + 1) * sgt[k].f%mod) % mod;

	sgt[k].f = 0;
}
void build(int l,int r,int k = 1)
{
	sgt[k].l = l,sgt[k].r = r;
	if(l == r)
	{
		sgt[k].val = w[l];
		sgt[k].squaresum = w[l]*w[l]%mod;
		return;
	}
	int m = (l + r) >> 1;
	build(l,m,ls(k));
	build(m + 1,r,rs(k));
	pushup(k);
}
void modify(int x,int y,int z,int k = 1)  //令[x，y]区间内数值全部加z
{
	ll l = sgt[k].l,r = sgt[k].r;
	z %= mod;
	if(x <= l && y >= r)
	{
		sgt[k].squaresum = (sgt[k].squaresum + (r - l + 1) * z * z + 2 * z * sgt[k].val%mod) % mod;
		sgt[k].f = (sgt[k].f + z) % mod;
		sgt[k].val = (sgt[k].val + ((r - l + 1) * z)%mod) % mod;
		return;
	}
	if(sgt[k].f)
		pushdown(k);
	ll m = (l + r) >> 1;
	if(x <= m)
		modify(x,y,z,ls(k));
	if(y > m)
		modify(x,y,z,rs(k));
	pushup(k);
}
ll query(int x,int y,int mode,int k = 1)      //代表查询[x，y]区间内数值之和
{
	ll l = sgt[k].l,r = sgt[k].r;
	if(x <= l && y >= r)
	{
		if(!mode)
			return sgt[k].val;
		else
			return sgt[k].squaresum;
	}
	if(sgt[k].f)
		pushdown(k);
	ll sum = 0,m = (l + r) >> 1;
	if(x <= m)
		sum = (sum + query(x,y,mode,ls(k))%mod) % mod;
	if(y > m)
		sum = (sum + query(x,y,mode,rs(k))%mod) % mod;
	return sum;
}
//======================================
//树链剖分
/*
int fa[maxn]:当前点的父节点
int dep[maxn]:当前点的深度
int son[maxn]:当前点的子节点
int siz[maxn]:当前点的大小(以当前点为根节点的子树的节点数量)
*/
void dfs1(int u,int f)
{
	fa[u] = f;
	dep[u] = dep[f] + 1;
	siz[u] = 1;
	int maxsize = -1;
	for(int i = head[u]; i; i = edges[i].next)
	{
		int v = edges[i].to;
		if(v == f)
			continue;
		dfs1(v,u);
		siz[u] += siz[v];
		if(siz[v] > maxsize)
		{
			maxsize = siz[v];
			son[u] = v;
		}
	}
}
/*
int top[maxn]:当前点的所在重链的顶部
int dfn[maxn]:当前点的时间戳
int w[maxn]:节点权值的dfs序
int tim:时间戳计数器
int v[maxn]:存放所有节点的权值
*/
void dfs2(int u,int t)
{
	dfn[u] = ++tim;
	top[u] = t;
	w[tim] = v[u];
	if(!son[u])
		return;
	dfs2(son[u],t);
	for(int i = head[u]; i; i = edges[i].next)
	{
		int v = edges[i].to;
		if(v == fa[u] || v == son[u])
			continue;
		dfs2(v,v);
	}
}
void mchain(int x,int y,int z)  //树从x到y节点最短路径上所有节点的值加上z
{
	while(top[x] != top[y])
	{
		if(dep[top[x]] < dep[top[y]])
			std::swap(x,y);
		modify(dfn[top[x]],dfn[x],z);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y])
		std::swap(x,y);
	modify(dfn[x],dfn[y],z);
}
inline void mson(int x,int z)   //将以x为根节点的子树内所有节点值都加上z
{
	modify(dfn[x],dfn[x] + siz[x] - 1,z);
}
ll qchain(int x,int y,int mode)          //求树从x到y节点最短路径上所有节点的值之和
{
	ll ret = 0;
	while(top[x] != top[y])
	{
		if(dep[top[x]] < dep[top[y]])
			swap(x,y);
		ret = (ret + query(dfn[top[x]],dfn[x],mode)%mod) % mod;
		x = fa[top[x]];
	}
	if(dep[x] > dep[y])
		swap(x,y);
	ret = (ret + query(dfn[x],dfn[y],mode)%mod) % mod;
	return ret;
}
ll pow(ll a,ll n,ll p)
{
	ll ans = 1;
	while(n)
	{
		if(n & 1) ans = ans * a % p;
		a = a * a % p;
		n >>= 1;
	}
	return ans%p;
}

ll niyuan(ll a,ll p)
{
	return pow(a,p - 2,p);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> v[i];
	for(int i = 0; i < n - 1; ++i)
	{
		int u,v;
		cin >> u >> v;
		add(u,v,0),add(v,u,0);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,n);
	for(int i = 0; i < m; ++i)
	{
		int opt,u,v,val;
		cin >> opt;
		if(opt == 1)
		{
			cin >> u >> val;
			mson(u,val);
		}
		if(opt == 2)
		{
			cin >> u >> v >> val;
			mchain(u,v,val);
		}
		if(opt == 3)
		{
			cin >> u >> v;
			ll sum1,sum2;
			sum1 = qchain(u,v,0);
			sum2 = qchain(u,v,1);
			ll two = niyuan(2,mod);
			cout<<(pow(sum1,2,mod) - sum2)%mod* two%mod<<endl;
		}
	}
	return 0;
}