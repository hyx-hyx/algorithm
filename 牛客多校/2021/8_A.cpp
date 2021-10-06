#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
ll pow(ll a, ll n, ll p)
{
	ll ans = 1;
	while (n)
	{
		if (n & 1) ans = ans * a % p;
		a = a * a % p;
		n >>= 1;
	}
	return ans;
}

ll niyuan(ll a, ll p)
{
	return pow(a, p - 2, p);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k, a, l;
	cin >> n >> m >> k >> a >> l;
	ll ans = 1;
	ll num = 0;
	ll den = 0;
	for (int i = 0; i < k; ++i)
	{
		ll x, y, z;
		cin >> x >> y >> z;
		if (x != 0)
		{
			if (num == 0 && den == 0)
				num = ( z - y ) % 4933, den = z % 4933;
			else
			{
				if (y && z)
					num = ( num * ( z - y ) ) % 4933, den = ( den * z ) % 4933;
			}
		}
	}
	num = ( num + a * den ) % 4933;
	cout << ( num * niyuan(den, 4933) ) % 4933 << endl;
	return 0;
}
