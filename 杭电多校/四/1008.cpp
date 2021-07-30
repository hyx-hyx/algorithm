#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#define maxn 100005
using namespace std;
int dir[2][2] = { {1,0},{0,1} };
int n, m, k;
vector<vector<int> > map(maxn,vector<int>(maxn,0));
int countpoint = 1;
void dfs(int x, int y)
{
	for (int i = 0; i < 2; ++i)
	{
		int nextx = dir[i][0] + x;
		int nexty = dir[i][1] + y;
		if (nexty <= m && nextx <= n && !map[nextx][nexty])
		{
			map[nextx][nexty] = 1;
			countpoint++;
			dfs(nextx, nexty);
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		countpoint = 1;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i <= n; ++i)
			map[i].assign(n+1, 0);
		for (int i = 0; i < k; ++i)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			map[x][y] = 1;
		}
		dfs(1, 1);
		printf("%d\n", countpoint);
	}
	return 0;
}
