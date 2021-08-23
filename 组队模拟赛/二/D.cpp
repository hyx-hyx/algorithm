#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 1005
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	ll h[maxn];
	ll dp[maxn][maxn] = {0};
	for(int i = 1; i <=n; ++i)
		cin >> h[i];
	for(int i = 1; i <=n; ++i)
	{
		for(int j= 1; j <=i; ++j)
		{
			if(j <= k)
				dp[i][j] = dp[i - 1][j - 1] + h[i];
			else
				dp[i][j%k] = dp[i - 2][k]+h[i];
		}
	}
	ll ans = 0;
	for(int i = 1; i <= k; ++i)
		ans = max(ans,dp[n][i]);
	cout << ans << endl;
	return 0;
}
