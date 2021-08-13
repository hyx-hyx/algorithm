#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
typedef long long ll;
using namespace std;
ll n, k;
ll ans;
void f(ll l, ll r)
{
	if (r - l + 1 <= k)
		return;
	ans += 2;
	f(l, (l + r) / 2);
	f((l + r) / 2 + 1, r);
}

int main()
{
	int t;
	k = 4;
	for (int i = 1; i <= 100; ++i)
	{
		ans = 1;
		f(1, i);
		printf("%d\n", ans);
	}
	return 0;
}
