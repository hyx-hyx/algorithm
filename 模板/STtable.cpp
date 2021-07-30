#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 1000005
using namespace std;
int f[maxn][50];
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
		}
	}
}
int query(int l, int r)
{
	int k = logn[r - l + 1];
	return max(f[l][k], f[r - (1 << k) + 1][k]);
}
//输入数据直接赋值给f[i][0],i从1到n