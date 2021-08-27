#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
//网址：https://www.acwing.com/problem/content/8
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N,V,M;
	int v[maxn],m[maxn],w[maxn],dp[maxn][maxn] = {0};
	cin >> N >> V>>M;
	for(int i = 1; i <=N; ++i)
		cin >> v[i] >> m[i] >> w[i];
	for(int i = 1; i <= N; ++i)
		for(int j = V; j >= v[i]; --j)
			for(int k = M; k >= m[i]; --k)
				dp[j][k] = max(dp[j][k],dp[j - v[i]][k - m[i]] + w[i]);
	cout << dp[V][M]<<endl;
	return 0;
}