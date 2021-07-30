#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 1005
using namespace std;
int fa[maxn], ranki[maxn];
void init(int n)
{
    for (int i = 0; i <=n; ++i)
    {
        fa[i] = i;
        ranki[i] = 1;
    }
}
int find(int x)
{
    return fa[x] == x ? fa[x] : (fa[x] = find(fa[x]));
}
void merge(int i, int j)
{
    int x = find(i);
    int y = find(j);
    if (ranki[x] > ranki[y])
        fa[x] = y;
    else
        fa[y] = x;
    if (ranki[x] == ranki[y] && x != y)
        ranki[y]++;
}
int main()
{
    int n, m,cnt=0;
    int x, y;
    while (1)
    {
        cnt = 0;
        scanf("%d", &n);
        if (n == 0)
            break;
        scanf("%d", &m);
        if (m == 0)
            printf("%d\n",n - 1);
        else
        {
            init(n);
            for (int i = 0; i < m; ++i)
            {
                scanf("%d%d", &x, &y);
                merge(x, y);
            }
            for (int i = 1; i <= n; ++i)
            {
                if (fa[i] == i)
                    cnt++;
            }
            printf("%d\n", cnt - 1);
        }
    }
    return 0;
}