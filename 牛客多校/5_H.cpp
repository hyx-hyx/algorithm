#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 1005
using namespace std;
int main()
{
	int n, m;
	int a[maxn][maxn]={0};
	for (int i = 0; i < maxn; ++i)
	{
		for (int j = 0; j < maxn; ++j)
		{
			a[i][j] = (i + (j / 2)) % 2;
		}
	}
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			printf("%d", a[i][j]);
		printf("\n");
	}
	return 0;
}
