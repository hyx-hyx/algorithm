#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int main()
{
	int n, a[105] = {0}, ans = 1;
	vector<int> dp(105,1);
	cin >> n;
	for (int i = 1; i <=n; ++i)
		scanf("%d", &a[i]);
	for (int i = 2; i <=n; ++i)
	{
		for (int j = 1; j <i; ++j)
		{
			if (a[j] <= a[i])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}
