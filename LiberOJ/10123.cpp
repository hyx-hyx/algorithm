#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 50005
using namespace std;
int f[maxn][50];
int g[maxn][50];
int logn[maxn] = { 0,0,1 };
void init(int n)
{
	for (int i = 3; i <= n; ++i)
		logn[i] = logn[i / 2] + 1;
	for (int j = 1; (1 << j) <= n; ++j)
	{
		for (int i = 1; i + (1 << j) - 1 <= n; ++i)
		{
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
			g[i][j] = min(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int query(int l, int r,int flag)
{
	int k = logn[r - l + 1];
	if (flag)
		return max(f[l][k], f[r - (1 << k) + 1][k]);
	else
		return min(g[l][k], g[r - (1 << k) + 1][k]);
}
int main()
{
	int n, m,x,y;
	cin >>n>>m;
	for (int i = 1; i <=n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		f[i][0] = temp;
		g[i][0] = temp;
	}
	init(n);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n",query(x, y,1)-query(x,y,0));
	}
	return 0;
}