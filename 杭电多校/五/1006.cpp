#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 200005
typedef long long ll;
using namespace std;
ll dp[maxn] = {0,1,3,4};
ll ans(int n)
{
	if (n <= 3)
		return dp[n];
	if (!dp[n / 3])
		dp[n / 3] = ans(n / 3);
	if (!dp[n - 2 * n / 3])
		dp[n - 2 * n / 3] = ans(n - 2 * n / 3);
	if (!(n % 3))
		dp[n] = 3 * dp[n / 3]+1;
	if (n % 3 == 1)
		dp[n] = 2 * dp[n / 3] + dp[n - 2 * n / 3] + 1;
	if (n % 3 == 2)
		dp[n] = 2 * dp[n / 3 + 1] + dp[n / 3] + 1;
	return dp[n];
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
		printf("%lld\n", ans(n));
	}
	return 0;
}
