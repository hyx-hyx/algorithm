/*
思路：这道题如果直接DP，因为有一定要选K件物品的条件，所以复杂度会达到O（10^12）.
考虑将物品的价值排序，然后将所有商品减去第一个的价值，用dp[I]表示当前价格为I时最少需要多少物品，因为每件商品都减去了第一件商品的价值，所以假如选不满k件商品就用第一种商品来补差价
这样一来问题就转化成了完全背包，时间复杂度为O(1000*n*k)，
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
#define eps 1e-6
#define LL long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
using namespace std;

const int MAXN = 2000;
int n, k;
int a[MAXN], dp[MAXN * MAXN];
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int m = unique(a + 1, a + n + 1) - (a + 1);//去重
	for (int i = 2; i <= m; i++)
		a[i] -= a[1];                       //求差值
	for (int i = 1; i <= a[m] * k; i++)
		dp[i] = k + 1;                  
	dp[0] = 0;

    //完全背包 dp[i]表示当前价格为i时最少需要的物品
	for (int i = 2; i <= m; i++) 
    {
		for (int j = a[i]; j <= a[i] * k; j++)
			dp[j] = min(dp[j], dp[j - a[i]] + 1);
	}

    //因为先前对a[i]求差值，这里合并得到最终结果
	for (int i = 0; i <= a[m] * k; i++)
		if (dp[i] <= k)
			printf("%d ", i + a[1] * k);        //i+a[1]*k,等价于a[m]*k+a[1]*k得到原来数组的值。
	return 0;
}