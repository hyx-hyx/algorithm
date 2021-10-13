#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
const int maxn = 1e5 + 10;
const int mod = 998244353;
using namespace std;
ll fastpower(ll base,ll power)
{
	ll res = 1;
	while(power)
	{
		if(power & 1)
			res = (res * base) % mod;
		base = (base * base) % mod;
		power >>= 1;
	}
	return res % mod;
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string s,p;
		int f[maxn][10] = {0};
		int a[maxn] = {0};
		p = "nunhehheh";
		cin >> s;
		a[0] = 0;
		Fore(i,1,s.size())
			a[i] = a[i - 1] + (s[i-1] == 'a' ? 1 : 0);
		ll sum = 0;
		f[0][0] = 1;
		Fore(j,1,p.size())
		{
			sum = f[0][j - 1];
			Fore(i,1,s.size())
			{
				if(s[i - 1] == p[j - 1])
					f[i][j] = sum;
				sum = (sum + f[i][j - 1]) % mod;
			}
		}
		ll ans = 0;
		for(int i = 1; i <= s.size(); ++i)
			ans = (f[i][9] * (ll)(fastpower(2,(a[s.size()] - a[i-1])) - 1) % mod+ans)%mod;
		cout << ans << endl;
	}
	return 0;
}