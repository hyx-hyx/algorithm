#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 1e9;
const int mod = 1e9 + 7;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		if(n == 0 || n == 1)
			cout << 0 << endl;
		else
		{
			n %= mod;
			cout << (ll)(2 * ((n * (n - 1) % mod) * (n * (n - 1) % mod) % mod)) % mod << endl;
		}
	}
	return 0;
}