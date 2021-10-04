//洛谷P3919
/*
题目背景
这是个非常经典的可持久化权值线段树入门题——静态区间第 k 小。

数据已经过加强，请使用可持久化权值线段树。同时请注意常数优化。

题目描述
如题，给定 n 个整数构成的序列 a，将对于指定的闭区间 [l, r]查询其区间内的第 k 小值。

输入格式
第一行包含两个整数，分别表示序列的长度 n 和查询的个数 m。
第二行包含 n个整数，第 i 个整数表示序列的第 i 个元素 a_i。

接下来 m 行每行包含三个整数 l, r, k表示查询区间 [l, r] 内的第 k 小值。

输出格式
对于每次询问，输出一行一个整数表示答案。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXV =2e5+5,MAXN = 2e5+5;
#define ls(x) tree[x].ls
#define rs(x) tree[x].rs
#define val(x) tree[x].val
#define mark(x) tree[x].mark
struct node
{
    int val,ls,rs;
    int mark;//涉及区间修改时加上，否则可删去
} tree[MAXV<<5];
int A[MAXN],roots[MAXN],n,m,cnt = 1; // roots记录每个历史版本的根节点
// 令A_x加d，p表示原版本的节点，q表示新版本的节点
//单点修改
void update_point(int x,int d,int p,int q,int cl = 1,int cr = n)
{
    if(cl == cr)
        val(q) = val(p) + d; // 给叶子节点赋值
    else
    {
        ls(q) = ls(p),rs(q) = rs(p); // 复制节点
        int mid = (cl + cr) / 2;
        if(x <= mid)
            ls(q) = ++cnt,update_point(x,d,ls(p),ls(q),cl,mid); // 创建新节点作为左儿子，然后往左递归
        else
            rs(q) = ++cnt,update_point(x,d,rs(p),rs(q),mid + 1,cr); // 创建新节点作为右儿子，然后往右递归
        val(q) = val(ls(q)) + val(rs(q)); // 根据子节点给当前节点赋值
    }
}
// 令A_x加d，p表示原版本的节点，q表示新版本的节点
void update_range(int l,int r,int d,int p,int q,int cl = 1,int cr = n) // 区间修改
{
    ls(q) = ls(p),rs(q) = rs(p),mark(q) = mark(p); // 复制节点
    if(cl >= l && cr <= r)
    {
        if(cr > cl)
            mark(q) += d;
    }
    else
    {
        int mid = (cl + cr) / 2;
        if(cl <= r && mid >= l) // 提前进行判断，以免新建不必要的节点
            ls(q) = ++cnt,update_range(l,r,d,ls(p),ls(q),cl,mid);
        if(mid + 1 <= r && cr >= l)
            rs(q) = ++cnt,update_range(l,r,d,rs(p),rs(q),mid + 1,cr);
    }
    val(q) = val(p) + (min(cr,r) - max(cl,l) + 1) * d; // 根据需要更新的区间长度计算当前节点的值
}
int query_point(int l,int r,int p,int cl = 1,int cr = n) // 不带标记区间查询
{
    if(cl > r || cr < l)
        return 0;
    else if(cl >= l && cr <= r)
        return val(p);
    else
    {
        int mid = (cl + cr) / 2;
        return query_point(l,r,ls(p),cl,mid) + query_point(l,r,rs(p),mid + 1,cr);
    }
}
ll query_range(int l,int r,int p,int cl = 1,int cr = n,ll mk = 0) // 区间查询
{
    if(cl > r || cr < l)
        return 0;
    else if(cl >= l && cr <= r)
        return val(p) + mk * (cr - cl + 1); // 加上带的标记
    else
    {
        int mid = (cl + cr) / 2;
        return query_range(l,r,ls(p),cl,mid,mk + mark(p)) + query_range(l,r,rs(p),mid + 1,cr,mk + mark(p)); // 带着标记传递
    }
}
//===========================================================================
void build(int l = 1,int r = n,int p = 1) // 建树
{
    val(p) = 0;
    if(l != r)
    {
        ls(p) = ++cnt,rs(p) = ++cnt;
        int mid = (l + r) / 2;
        build(l,mid,ls(p));
        build(mid + 1,r,rs(p));
    }
}
int C[MAXN],L[MAXN],ori[MAXN];
void discretize(int A[],int n)
{
    memcpy(C,A,sizeof(int) * n);     // 复制
    sort(C,C + n);                    // 排序
    int l = unique(C,C + n) - C;      // 去重
    for(int i = 0; i < n; ++i)
    {
        L[i] = lower_bound(C,C + l,A[i]) - C + 1; // 查找
        ori[L[i]] = A[i]; // 保存离散化后的数对应的原数
    }
}
int kth(int k,int p,int q,int cl = 1,int cr = n) // 求指定排名的数
{
    if(cl == cr)
        return ori[cl];
    int mid = (cl + cr) / 2;
    if(val(ls(q)) - val(ls(p)) >= k)
        return kth(k,ls(p),ls(q),cl,mid); // 往左搜
    else
        return kth(k - (val(ls(q)) - val(ls(p))),rs(p),rs(q),mid + 1,cr); // 往右搜
}
int main()
{ 
    cin >> n >> m;
    build();
    for(int i = 0; i < n; ++i)
        cin >> A[i];
    discretize(A,n);
    //在main函数中把离散化后的数据一个一个地插入可持久化的权值线段树
    for(int i = 0; i < n; ++i)
    {
        roots[i + 1] = ++cnt;
        update_point(L[i],1,roots[i],roots[i + 1]);
    }
    int l,r,k;
    for(int i = 0; i < m; ++i)
    {
        cin >> l >> r >> k;
        cout << kth(k,roots[l-1],roots[r]) << endl;;
    }
    return 0;
}