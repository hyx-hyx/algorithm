#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int v[maxn],w[maxn];
	int dp[maxn],count[maxn] = {0};
	count[0] = 1;
	memset(dp,-0x3f3f3f3f,sizeof(dp));
	dp[0] = 0;
	int N,V;
	cin >> N >> V;
	for(int i = 1; i <= N; ++i)
		cin >> v[i] >> w[i];
	for(int i = 1; i <= N; ++i)
		for(int j = V; j >= v[i]; --j)
		{
			int value = max(dp[j],dp[j - v[i]] + w[i]);
			int num = 0;
			if(value == dp[j])
				num += count[j];
			if(value == dp[j - v[i]] + w[i])
				num += count[j - v[i]];
			num %= mod;
			dp[j] = value;
			count[j] = num;
		}
	int maxw = 0;
	int ans = 0;
	for(int i = 0; i <= V; i++)
		maxw = max(dp[i],maxw);
	for(int i = 0; i <= V; i++)
		if(dp[i] == maxw)
			ans = (ans+count[i])%mod;
	cout << ans << endl;
	return 0;
}