#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 204
using namespace std;
int main()
{
	int t, maxr = -200, maxb = -200;
	scanf("%d", &t);
	while (t--)
	{
		int r[maxn] = { 0 }, b[maxn] = { 0 };
		maxr = -200, maxb = -200;
		int sumr[maxn] = { 0 }, sumb[maxn] = {0};
		int n, m;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &r[i]);
			if (!i)
				sumr[0] = r[0];
			else
				sumr[i] =sumr[i-1]+r[i];
			maxr = max(maxr, sumr[i]);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d", &b[i]);
			if (!i)
				sumb[0] = b[0];
			else
				sumb[i] = sumb[i-1]+b[i];
			maxb = max(maxb, sumb[i]);
		}
		printf("%d\n", max(0,max(maxr + maxb,max(maxr,maxb))));
	}
	return 0;
}