#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 200
using namespace std;
int main()
{
	int t;
	int mat_01[maxn][maxn];
	int mat[maxn];
	int height[maxn][maxn], left[maxn][maxn] = { 0 }, right[maxn][maxn];
	int maxarea = 0;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		memset(right, m - 1, sizeof(right));
		vector<int>left_stop(n, 0);
		vector<int> right_stop(n, m - 1);
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				if (!j)
					scanf("%d", &mat[k]);
				else
				{
					int w;
					scanf("%d", &w);
					if (w >= mat[k])
						mat_01[j][k] = 0;
					else
						mat_01[j][k] = 1;
					mat[k] = w;
				}
			}
			for (int k = 0; k < m; ++k)
			{
				if (mat_01[j][k - 1] == 0 && mat_01[j][k - 1] == 0)
					left[j][k] = left[j][k - 1];
				else
					left[j][k] = k;
			}
			for (int k = m - 2; k >= 0; --k)
			{
				if (mat_01[j][k] == 0 && mat_01[j][k + 1] == 0)
					right[j][k] = right[j][k + 1];
				else
					right[j][k] = k;
			}
		}
		height[0][0] = 1;
		left[0][0] = 0;
		right[0][0] = m - 1;
		for (int j = 1; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				if (!mat_01[j][k])
					height[j][k] = height[j - 1][k] + 1;
				else
					height[j][k] = 1;
				left[j][k] = max(left[j - 1][k], left[j][k]);
				right[j][k] = min(right[j - 1][k],right[j][k]);
				maxarea = max(maxarea, height[j][k] * (right[j][k] - left[j][k] + 1));
			}
		}
		printf("%d\n", maxarea);
	}
	return 0;
}
