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
const int maxn = 3e5+5;
typedef long long ll;
#define edgecount 300005
#define pointcount 300005
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
//======================================
//树链剖分
/*
int fa[maxn]:当前点的父节点
int dep[maxn]:当前点的深度
int son[maxn]:当前点的子节点
int siz[maxn]:当前点的大小(以当前点为根节点的子树的节点数量)
*/
int v[maxn],fa[maxn],dep[maxn],siz[maxn],son[maxn];
void dfs1(int u,int f=0)
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
int tim,dfn[maxn],top[maxn],w[maxn];
void dfs2(int u,int t=0)
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
vector<int> maxv(maxn,-30005);
struct Node
{
    int l,r,f,val;//flag,标记
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
    sgt[k].val = (sgt[ls(k)].val + sgt[rs(k)].val);
    maxv[k] = max(maxv[ls(k)],maxv[rs(k)]);
}
inline void pushdown(int k)
{
    sgt[ls(k)].f += sgt[k].f;
    sgt[rs(k)].f += sgt[k].f;
    sgt[ls(k)].val += (sgt[ls(k)].r - sgt[ls(k)].l + 1) * sgt[k].f;
    sgt[rs(k)].val += (sgt[rs(k)].r - sgt[rs(k)].l + 1) * sgt[k].f;
    maxv[ls(k)]+=sgt[k].f;
    maxv[rs(k)]+=sgt[k].f;
    sgt[k].f = 0;
}

void build(int l,int r,int k = 1)
{
    sgt[k].l = l,sgt[k].r = r;
    if(l == r)
    {
        sgt[k].val = w[l];
        maxv[k] = w[l];
        return;
    }
    int m = (l + r) >> 1;
    build(l,m,ls(k));
    build(m + 1,r,rs(k));
    pushup(k);
}
void modify(int x,int y,int z,int k = 1)  //令[x，y]区间内数值全部加z
{
    int l = sgt[k].l,r = sgt[k].r;
    if(x <= l && y >= r)
    {
        sgt[k].f += z;
        sgt[k].val += (r - l + 1) * z;
        maxv[k] = maxv[k] + z;
        return;
    }
    if(sgt[k].f)
        pushdown(k);
    int m = (l + r) >> 1;
    if(x <= m)
        modify(x,y,z,ls(k));
    if(y>m)
        modify(x,y,z,rs(k));
    pushup(k);
}
int querymax(int x,int y,int k = 1)
{
    int l = sgt[k].l,r = sgt[k].r;
    if(x <= l && y >= r)
        return maxv[k];
    if(y<l || x>r)
        return -30005;
    return max(querymax(x,y,ls(k)),querymax(x,y,rs(k)));
}
int query(int x,int y,int k = 1)      //代表查询[x，y]区间内数值之和
{
    int l = sgt[k].l,r = sgt[k].r;
    if(l > r || l > y || r < x)
        return 0;
    if(x <= l && y >= r)
        return sgt[k].val;
    if(sgt[k].f)
        pushdown(k);
    int sum = 0,m = (l + r) >> 1;
    if(x <= m)
        sum += query(x,y,ls(k));
    if(y > m)
        sum += query(x,y,rs(k));
    return sum;
}
int qchain(int x,int y)          //求树从x到y节点最短路径上所有节点的值之和
{
    int ret = 0;
    while(top[x] != top[y])
    {
        if(dep[top[x]] < dep[top[y]])
            swap(x,y);
        ret += query(dfn[top[x]],dfn[x]);
        x = fa[top[x]];
    }
    if(dep[x] > dep[y])
        swap(x,y);
    ret += query(dfn[x],dfn[y]);
    return ret;
}
int query_max_chain(int x,int y)
{
    int ret = -30005;
    while(top[x] != top[y])
    {
        if(dep[top[x]] < dep[top[y]])
            swap(x,y);
        ret=max(ret,querymax(dfn[top[x]],dfn[x]));
        x = fa[top[x]];
    }
    if(dep[x] > dep[y])
        swap(x,y);
    return max(ret,querymax(dfn[x],dfn[y]));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> v[i];
    for(int i = 1; i < n; ++i)
    {
        int u,v;
        cin >> u >> v,add(u,v,0),add(v,u,0);
    }
    dfs1(1,0);
    dfs2(1,0);
    build(1,n);
	for(int i = 1; i <=q; ++i)
	{
		int a,b,op;
		cin >> op>> a >> b;
        if(op == 0)
            cout << query_max_chain(a,b) << endl;
        if(op == 1)
            cout << qchain(a,b)<< endl;
        if(op == 2)
            modify(dfn[a],dfn[a],b - v[a]),v[a] = b;
	}
	return 0;
}