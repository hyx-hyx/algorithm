#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define maxn 100005
typedef long long ll;
using namespace std;
int main()
{
	int n, m, a[maxn], k;
	int diff[maxn];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n - 1; ++i)
		diff[i] = a[i + 1] - a[i];
	for (int a = 0; a < m; ++a)
	{
		scanf("%d", &k);
		ll sum = 0;
		ll ans = 0;
		for (int i = 0; i < n; ++i)
		{
			sum = 0;
			for (int j = i; j < n; ++j)
			{
				sum += diff[j];
				if (sum > k)
				{
					ans += n - 1 - j;
					break;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
