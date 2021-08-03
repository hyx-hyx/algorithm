#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define mod 1000000007
typedef long long ll;
using namespace std;
ll fastpower(ll base, ll power)
{
	ll res = 1;
	while (power)
	{
		if (power & 1)
			res = (res%mod * base%mod) % mod;
		base = (base%mod * base%mod) % mod;
		power = power >> 1;
	}
	return res%mod;
}
int main()
{
	ll n;
	int t;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld", &n);
		ll nmod = n % mod;
		ll maxcost = 0;
		ll base = (((1 + n) % mod * nmod)%mod) / 2;
		ll mul = (((nmod * (nmod + 1))%mod) * (2 * nmod + 1)) % mod / 6;
		ll bottom = (((base % mod) * (mul % mod)) % mod);
		int sumdia = 0;
		sumdia = (mul % mod - fastpower((n * (n + 1) / 2), 2)) % mod;
		sumdia = ((nmod * mul) % mod + sumdia) % mod;
		sumdia = ((sumdia % mod * (((nmod - 1) * (nmod + 2)) % mod))%mod) / 2;
		maxcost = (bottom % mod * fastpower(n, 2)%mod) % mod;
		printf("%lld\n", (sumdia%mod + bottom%mod) % mod);
		printf("%lld\n", maxcost % mod);
	}
	return 0;
}
/*
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define mod 1000000007
typedef long long ll;
using namespace std;
int main()
{
	ll n;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld", &n);
		ll nmod = n % mod;
		ll maxcost = (((((((((n * n%mod) * (n + 1)%mod) * (n + 1)%mod) * ((2 * n%mod) + 1)%mod))%mod * n%mod) * n%mod)) / 12)%mod;
		ll sumdia = (((((((n * (n - 1)%mod) * (n + 2)%mod) * (n + 2)%mod) * (n + 1)%mod) * (n + 1)%mod) + ((((((2 * n)%mod) * n%mod) * (n + 1)%mod) * (n + 1)%mod) * (2 * n + 1)%mod))/24)%mod;
		printf("%llu\n", sumdia%mod);
		printf("%llu\n", maxcost%mod);
	}
	return 0;
}

*/