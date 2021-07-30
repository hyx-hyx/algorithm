#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#define MAXN 50000
#define lowbit(x) (x)&(-x)
#define ll long long ;
int tree[MAXN + 1];
int n;
using namespace std;
void update(int index, int val)
{
    for (int i = index; i <= MAXN; i += lowbit(i))
        tree[i] += val;
}
int query(int n)
{
    int ans = 0;
    for (int i = n; i; i -= lowbit(i))
        ans += tree[i];
    return ans;
}
int query(int a, int b)
{
    return query(b) - query(a - 1);
}
int main()
{
    int cnt, rank[50000];
    long long  a[50000],c[50000];
    while (cin >> n && n != 0)
    {
        int ans = 0;
        memset(tree, 0, sizeof(tree));
        tree[0] = -1;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        memcpy(c, a, sizeof(a));
        sort(c, c + n);
        cnt = unique(c, c + n) - c;
        for (int i = 0; i < n; ++i)
        {
            rank[i] = lower_bound(c, c + cnt, a[i]) - c + 1;
        }
        for (int i = 0; i < n; ++i)
        {
            update(rank[i], 1);
            int qtemp = query(rank[i]-1);
            ans += (i - qtemp);
        }
        cout << ans << endl;
    }
    return 0;
}