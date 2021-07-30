#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include <vector>
#include<string>
#include<queue>
using namespace std;
char map[55][55];
int vis[55][55] = {0};
int nextval[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };
int n, m;
bool circle = false;
void dfs(int startx, int starty, int lastx ,int lasty)
{
	if (circle)
		return;
	vis[startx][starty] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int nextx = startx + nextval[i][0];
		int nexty = starty + nextval[i][1];
		if (nextx < n && nextx >= 0 && nexty >= 0 && nexty < m&&(map[nextx][nexty]==map[startx][starty])&&((lastx!=nextx)||(lasty!=nexty)))
		{
			if (vis[nextx][nexty])
				circle = true;
			else
			{
				dfs(nextx, nexty,startx,starty);
				vis[nextx][nexty] = 0;
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		getchar();
		for (int j = 0; j < m; ++j)
		{
			scanf("%c",&map[i][j]);
		}
		map[i][m] = '\0';
	}
	for(int i=0;i<n;++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!vis[i][j])
			{
				dfs(i, j,-1,-1);
				if (circle)
				{
					cout << "Yes" << endl;
					return 0;
				}
			}
			vis[i][j] = 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
