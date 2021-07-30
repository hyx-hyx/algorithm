#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#define mod 1000000007
typedef long long ll;
using namespace std;
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		ll n;
		ll ans = 0;
		scanf("%lld", &n);
		if (n == 0 || n == 1)
		{
			printf("0\n");
			continue;
		}
		ans = (2 * (((n % mod)*((n-1)%mod)) ^ 2) % mod)%mod;
		printf("%lld\n", ans%mod);
	}
	return 0;
}