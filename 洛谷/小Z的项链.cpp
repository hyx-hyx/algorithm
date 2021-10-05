#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
//=============================================
const int MAXN = 30005,MAXQ = 200005;
int sq;
int vis[1000005] = {0};
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
int C(int m,int n)
{
    int cnt = 1;
    for(int i = 0; i <m; ++i)
        cnt *= (n-i),cnt /= (i+1);
    return cnt;
}
int A[MAXN],ans[MAXQ],cur = 0,l,r;
inline void add(int p)
{
    vis[A[p]]++;
    if(vis[A[p]] > 2)
        cur = cur +(C(2,vis[A[p]] - 1) + C(2,vis[A[p]]))*2;
    else
        if(vis[A[p]] == 2)
            cur += 2;
}
inline void del(int p)
{
    vis[A[p]]--;
    if(vis[A[p]] >= 2)
        cur = cur + (C(2,vis[A[p]] - 1) - C(2,vis[A[p]]))*2;
    else
        cur -= 2;
}
int gcd(int a,int b)
{
    return b > 0 ? gcd(b,a % b) : a;
}
int main()
{
    int n,m;     //所有区间总长度
    cin >> n>>m;
    sq = sqrt(n);  //分块大小
    for(int i = 1; i <= n; ++i)
        cin >> A[i],vis[A[i]]++;
    for(int i = 0; i < m; ++i)
        cin >> Q[i].l >> Q[i].r,Q[i].id = i; // 把询问离线下来
    sort(Q,Q + m); // 排序
    l = 1,r = n;
    for(int i = 0; i < m; ++i)
    {
        while(l > Q[i].l)
            add(--l);
        while(r < Q[i].r)
            add(++r);
        while(l < Q[i].l)
            del(l++);
        while(r > Q[i].r)
            del(r--);
        ans[Q[i].id] = cur; // 储存答案
    }
    for(int i = 0; i < m; ++i)
    {
        if(Q[i].l == Q[i].r||!ans[i])
            cout << "0/1" << endl;
        else
        {
            int temp = gcd(ans[i],Q[i].r - Q[i].l + 1);
            if(temp == 1)
                cout << ans[i] << '/' << (Q[i].r - Q[i].l + 1) << endl;
            else
                cout << (ans[i] / temp) << "/" << (Q[i].r - Q[i].l + 1) / temp << endl;
        }
    }
    return 0;
}