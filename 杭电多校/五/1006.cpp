#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 200005
using namespace std;
int dp[maxn];
int ans(int n)
{
	if (n >= 3)
	{
		if (!dp[n / 3])
		{
			dp[n / 3] = ans(n / 3);
			if (dp[n / 3]!=1)
				dp[n / 3] += 1;
		if (!dp[n - 2 * n / 3])
			dp[n - 2 * n / 3] = ans(n - 2 * n / 3) + 1;
		return 2 * dp[n / 3] + dp[n - 2 * n / 3] + 1;
	}
	if (n == 2)
	{
		if (!dp[n / 2])
			dp[n / 2] = ans(n / 2);
		return 2 * dp[n / 2];
	}
	if (n == 1)
		return 1;
}
int main()
{
	int t, n, a[maxn];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		printf("%d\n", ans(n));
	}
	return 0;
}
