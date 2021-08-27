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
const int maxn = 1e3+5;
typedef long long ll;
int dp[maxn][maxn] = {0};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int v[maxn] = {0},w[maxn] = {0};
	int N,V;
	cin >> N >> V;
	for(int i=1;i<=N;++i)
		cin >> v[i] >> w[i];
	for(int i = N; i >= 1; --i)
		for(int j = 0; j <= V; ++j)
		{
			dp[i][j] = dp[i + 1][j];
			if(j >= v[i])
				dp[i][j] = max(dp[i][j],dp[i + 1][j - v[i]] + w[i]);
		}
	int vol = V;
	for(int i = 1; i <= N; ++i)
		if(dp[i][vol] == dp[i+1][vol - v[i]] + w[i]&&(vol-v[i]>=0))
		{
			cout << i << " ";
			vol -= v[i];
		}
	return 0;
}