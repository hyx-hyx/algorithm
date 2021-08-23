a#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
#define maxn 100005
using namespace std;
#define edgecount 100005
#define pointcount 100005
//===============================================
//图论存图
struct edge
{
    int to;
    int next;
    int w;
};
vector<edge> edges(edgecount);
vector<int> head(pointcount, 0);
int cnt=0;
inline void add(int from,int to,int w)
{
    edges[++cnt].to=to;
    edges[cnt].w=w;
    edges[cnt].next = head[from];
    head[from] = cnt;
}
//===============================================
//线段树
struct Node
{
    int l, r, f, val;
} sgt[maxn * 4];
inline int ls(int k) { return k << 1; }
inline int rs(int k) { return k << 1 | 1; }
inline void pushup(int k) { sgt[k].val = (sgt[ls(k)].val + sgt[rs(k)].val); }
inline void pushdown(int k)
{
    sgt[ls(k)].f += sgt[k].f;
    sgt[rs(k)].f += sgt[k].f;
    sgt[ls(k)].val += (sgt[ls(k)].r - sgt[ls(k)].l + 1) * sgt[k].f;
    sgt[rs(k)].val += (sgt[rs(k)].r - sgt[rs(k)].l + 1) * sgt[k].f;
    sgt[k].f = 0;
}
void build(int l, int r, int k = 1)
{
    sgt[k].l = l, sgt[k].r = r;
    if (l == r)
    {
        sgt[k].val = w[l];
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, ls(k));
    build(m + 1, r, rs(k));
    pushup(k);
}
void modify(int x, int y, int z, int k = 1)  //令[x，y]区间内数值全部加z
{
    int l = sgt[k].l, r = sgt[k].r;
    if (x <= l && y >= r)
    {
        sgt[k].f += z;
        sgt[k].val += (r - l + 1) * z;
        return;
    }
    if (sgt[k].f)
        pushdown(k);
    int m = (l + r) >> 1;
    if (x <= m)
        modify(x, y, z, ls(k));
    if (y > m)
        modify(x, y, z, rs(k));
    pushup(k);
}
int query(int x, int y, int k = 1)      //代表查询[x，y]区间内数值之和
{
    int l = sgt[k].l, r = sgt[k].r;
    if (x <= l && y >= r)
        return sgt[k].val;
    if (sgt[k].f)
        pushdown(k);
    int sum = 0, m = (l + r) >> 1;
    if (x <= m)
        sum += query(x, y, ls(k));
    if (y > m)
        sum += query(x, y, rs(k));
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
int v[maxn],fa[maxn], dep[maxn], siz[maxn], son[maxn];
void dfs1(int u, int f)   
{
    fa[u] = f;
    dep[u] = dep[f] + 1;
    siz[u] = 1;
    int maxsize =-1;
    for (int i=head[u];i;i=edges[i].next)
    {
        int v = edges[i].to;
        if (v == f)
            continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[v] > maxsize)
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
int tim, dfn[maxn], top[maxn], w[maxn];
void dfs2(int u, int t)
{
    dfn[u] = ++tim;
    top[u] = t;
    w[tim] = v[u];
    if (!son[u])
        return;
    dfs2(son[u], t);
    for(int i=head[u];i;i=edges[i].to)
    {
        int v = edges[i].to;
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}

void mchain(int x, int y, int z)  //树从x到y节点最短路径上所有节点的值加上z
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            std::swap(x, y);
        modify(dfn[top[x]], dfn[x], z);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        std::swap(x, y);
    modify(dfn[x], dfn[y], z);
}
int qchain(int x, int y)          //求树从x到y节点最短路径上所有节点的值之和
{
    int ret = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            std::swap(x, y);
        ret += query(dfn[top[x]], dfn[x]);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        std::swap(x, y);
    ret += query(dfn[x], dfn[y]);
    return ret;
}
inline void mson(int x, int z)   //将以x为根节点的子树内所有节点值都加上z
{
    modify(dfn[x], dfn[x] + siz[x] - 1, z);
}
inline int qson(int x)          //求以x为根节点的子树内所有节点值之和
{
    return query(dfn[x], dfn[x] + siz[x] - 1);
}
//==============================================
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}