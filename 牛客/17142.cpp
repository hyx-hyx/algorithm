#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
typedef long long ll;
using namespace std;
//=============================================
const int MAXN = 100005,MAXQ = 100005;
int sq;
int vis[MAXN] = {0};
struct query // 把询问以结构体方式保存
{
    int l,r,id;
    bool operator<(const query& o) const // 重载<运算符，奇偶化排序
    {
        // 这里只需要知道每个元素归属哪个块，而块的大小都是sqrt(n)，所以可以直接用l/sq
        if(l / sq != o.l / sq)
            return l < o.l;
        if(l / sq & 1)
            return r < o.r;
        return r > o.r;
    }
} Q[MAXQ];
int A[MAXN],ans[MAXQ],cur,l,r;
inline void add(int p)
{
    if(vis[A[p]] == 0)
        cur++;
    vis[A[p]]++;
}
inline void del(int p)
{
    vis[A[p]]--;
    if(vis[A[p]] == 0)
        cur--;
}
int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q) != EOF)
    {
        memset(vis,0,sizeof vis);
        cur = 0;
        sq = sqrt(n);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d",&A[i]);
            if(vis[A[i]] == 0)
                cur++;
            vis[A[i]]++;
        }
        for(int i = 0; i < q; ++i)
            scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].id = i; // 把询问离线下来
        sort(Q,Q + q); // 排序
        l = 1,r = 2;
        for(int i = 0; i < q; ++i)
        {
            while(l > Q[i].l)
                del(l--);
            while(r < Q[i].r)
                del(r++);
            while(l < Q[i].l)
                add(++l);
            while(r > Q[i].r)
                add(--r);
            ans[Q[i].id] = cur; // 储存答案
        }
        for(int i = 0; i < q; ++i)
            printf("%d\n",ans[i]); // 按编号顺序输出
    }
    return 0;
}