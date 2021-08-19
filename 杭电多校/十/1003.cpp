#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
#include<bitset>
using namespace std;
typedef long long ll;
const int maxn = 31500;
int main()
{
	bitset<maxn> dp[710];
	int t;
	cin >> t;
	dp[0][0] = 1;
	for(int i = 1; i < 710; ++i)
		for(int j = 1; j <= i; ++j)
			dp[i] |= dp[i - j] << (j * (i - j));
	while(t--)
	{
		int n;
		cin >> n;
		int lim = min(maxn-1,n * (n - 1) / 2);
		for(int i = 0; i < lim; i++) if(dp[n][i]) printf("%d ",i);	
		for(int i = lim + 1; i < n * (n - 1)/2; i++) printf("%d ",i);
		putchar('\n');
	}
	return 0;
}