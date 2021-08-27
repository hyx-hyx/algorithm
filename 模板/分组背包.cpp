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
const int maxn = 1e2+5;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N,V;
	int s[maxn],v[maxn][maxn],w[maxn][maxn];
	int dp[maxn] = {0};
	cin >> N >> V;
	for(int i = 1; i <= N; ++i)
	{
		cin >> s[i];
		for(int j = 1; j <= s[i]; ++j)
			cin >> v[i][j] >> w[i][j];
	}
	for(int i = 1; i <= N; ++i)
		for(int j = V; j >= 0; --j)
			for(int k = 1; k <= s[i]; ++k)
				if(j-v[i][k]>=0)
					dp[j] = max(dp[j],dp[j - v[i][k]] + w[i][k]);
	cout << dp[V] << endl;
	return 0;
}