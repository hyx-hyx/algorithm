#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
typedef long long ll;
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		ll m,n;
		scanf("%lld",&n);
		if (n == 1 || n == 2)
		{
			printf("0\n");
			continue;
		}
		if (n % 2)
			m = n / 2;
		else
			m = n / 2-1;
		ll ans=1;
		while (ans<m)
			ans = ((ans << 1) | 1);
		printf("%lld\n", ans);
	}
	return 0;
}
