#include <bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
const int MAXN = 3200000, MAXBIT = 31;
int next[MAXN][2], cnt;
int num[MAXN];
void init()
{
    memset(next, 0, sizeof(next));
    memset(num, 0, sizeof(num));
    cnt = 1;
}
void insert(int n)
{
    int cur = 1;
    for (int i = MAXBIT; i >= 0; --i)
    {
        int bit = n >> i & 1; // 求出当前位并插入
        if (!next[cur][bit])
            next[cur][bit] = ++cnt;
        cur = next[cur][bit];
    }
    num[cur] = n;
}
int find_max(int x) // 找到与x异或最大的那个数
{
    int cur = 1;
    for (int i = MAXBIT; i >= 0; --i)
    {
        int bit = x >> i & 1;
        if (next[cur][bit ^ 1]) // 优先走与当前位不同的路径
            cur = next[cur][bit ^ 1];
        else
            cur = next[cur][bit];
    }
    return x ^ num[cur];
}