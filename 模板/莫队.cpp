#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
//=============================================
const int MAXN = 30005, MAXQ = 200005;
int sq;
struct query // 把询问以结构体方式保存
{
    int l, r, id;
    bool operator<(const query &o) const // 重载<运算符，奇偶化排序
    {
        // 这里只需要知道每个元素归属哪个块，而块的大小都是sqrt(n)，所以可以直接用l/sq
        if (l / sq != o.l / sq) 
            return l < o.l;
        if (l / sq & 1)
            return r < o.r;
        return r > o.r;
    }
} Q[MAXQ];
int A[MAXN], ans[MAXQ], cur, l = 1, r = 0;
inline void add(int p)
{
   
}
inline void del(int p)
{
   
}
int main()
{
    int n;     //所有区间总长度
    cin>>n;
    sq = sqrt(n);  //分块大小
    for (int i = 1; i <= n; ++i)
        cin>>A[i];  //存储每个值
    int q;   //查询个数
    cin>>q;
    for (int i = 0; i < q; ++i)
        cin>>Q[i].l>>Q[i].r,Q[i].id=i; // 把询问离线下来
    sort(Q, Q + q); // 排序
    for (int i = 0; i < q; ++i)
    {
        while (l > Q[i].l)
            add(--l);
        while (r < Q[i].r)
            add(++r);
        while (l < Q[i].l)
            del(l++);
        while (r > Q[i].r)
            del(r--);
        ans[Q[i].id] = cur; // 储存答案
    }
    for (int i = 0; i < q; ++i)
        printf("%d\n", ans[i]); // 按编号顺序输出
    return 0;
}