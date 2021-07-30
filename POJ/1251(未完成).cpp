#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 27
using namespace std;
int fa[maxn], value[maxn] = { 0 };
void init(int n)
{
    for (int i = 0; i <= n; ++i)
        fa[i] = i;
}
int find(int x)
{
    if (x != fa[x])
    {
        int t = fa[x];
        fa[x] = find(fa[x]);
        value[x] += value[t];
    }
    return fa[x];
}
void merge(int i, int j, int s)
{
    int x = find(i);
    int y = find(j);
    if (x != y)
    {
        fa[x] = y;
        value[x] = -value[i] + value[j] + s;
    }
    else
    {
        if (value[i] <= value[j])
            value[j] = min(s + value[i], value[j]);
        else
            value[i] = min(s + value[j], value[i]);
    }
}
int main()
{
	int n;
	while (1)
	{
        int sum = 0;
		scanf("%d", &n);
        getchar();
		if (!n)
			break;
		else
		{
            init(n);
			for (int i = 0; i < n-1; ++i)
			{
                int k;
                char x;
                scanf("%c%d", &x, &k);
                if (k)
                {
                    for (int i = 0; i < k; ++i)
                    {
                        char c;
                        int temp;
                        getchar();
                        scanf("%c%d", &c, &temp);
                        merge(x-65, c-65, temp);
                    }
                }
                getchar();
			}
		}
        for (int i = 0; i < n; ++i)
            sum += value[i];
        printf("%d\n", sum);
	}
	return 0;
}
