#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
const long long inf = 1000000000000000000ll;
int cnt, T, l, r, mid, ans;
long long A[3000010], n;

int main()
{
	for (int k = 2; k <= 1000000; k++)
	{
		long long a = 0, b = k, c;
		while (1)
		{
			if (b > (inf + a) / (1ll * k * k)) break;
			c = b, b = b * k * k - a, a = c;
			A[++cnt] = b;
		}
	}
	sort(A + 1, A + 1 + cnt);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld", &n);
		l = 1, r = cnt, ans = 0;
		while (l <= r)
		{
			mid = (l + r) >> 1;
			if (A[mid] <= n) ans = mid, l = mid + 1; else r = mid - 1;
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}