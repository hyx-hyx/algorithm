#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define maxn 10000005
using namespace std;
typedef long long ll;
int vis[maxn] = { 0 };
vector<int> prime(maxn, 0);
vector<int> primearr(maxn,0);
void eula_prim(int n)
{
	int cnt = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (!vis[i])
		{
			prime[++cnt] = i;
			primearr[i] = 1;
		}
		for (int j = 1; j <= cnt && i * prime[j] <= n; ++j)
		{
			vis[i * prime[j]] = 1;
			if (!(i % prime[j]))
				break;
		}
	}
}
int main()
{
	int n,t;
	scanf("%d", &t);
	eula_prim(maxn);
	for (int k = 0; k < t; ++k)
	{
		scanf("%d", &n);
		ll ans = 0;
		for (int i = 3; i <= n; ++i)
		{
			if(primearr[i])
				ans += i * 2;
			else
				ans += i;
		}
		printf("%lld\n", ans);
	}
	return 0;
}