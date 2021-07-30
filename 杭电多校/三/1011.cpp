/*打表可知：
1.1会先出现k次
2.3会出现k次
3.2的幂次减一会出现n次，n初始等于2k-1次，之后以2*n-1的方式迭代。得到的n等于4k-3,8k-7,16k-15等。
4.在两个2的y次幂跟y+1次幂中间会出现x个只出现一次的奇数。。。。
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
typedef long long ll;
using namespace std;
ll fastpower(ll base, ll power)
{
	ll res = 1;
	while (power)
	{
		if (power & 1)
			res *= base;
		base *= base;
		power >>= 1;
	}
	return res;
}

int main()
{
	int t;
	ll n, k;
	scanf("%d", &t);
	for (int T = 0; T < t; ++T)
	{
		scanf("%lld%lld", &n, &k);
		if (n <= k)
		{
			printf("1\n");
			continue;
		}
		if (n <= 2 * k)
		{
			printf("3\n");
			continue;
		}
		ll sum = 2 * k;
		ll base = k;
		ll index = 2;
		while (n > sum)
		{
			base = base * 2;
			index++;
			sum += base;
		}
		ll diff = sum - n;
		ll repeat = (base-(base / k-1));
		ll ans = fastpower(2,index) - 1;
		if (diff < repeat)
			printf("%lld\n", ans);
		else
		{
			ll d = diff - repeat;
			for (int i = 0; i <= d; ++i)
				ans -= 2;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
//打表时用的程序
/*
#include<cstdio>
#include<iostream>
using namespace std;
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
*/