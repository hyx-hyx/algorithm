/*
题意：给定n条直线，输出n条直线所有的交点。
分析：
简化版在HDU1466
在简化版的基础上
设 f[i][j] 表示用 i 条直线是否能凑出 j 个交点。
可以用bitset来优化转移，做到 O(n 4 /w) 的时间复杂度，这是难以通过 1 s的时间限制的。
观察发现答案有相当长一段连续可行后缀，打表后发现最大不可行交点数不超过 35000 ，于是时间可以优化到 35000 * n*n /w ，可以通过本题。
*/
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