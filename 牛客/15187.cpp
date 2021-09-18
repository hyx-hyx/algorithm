//快速幂不可对指数取模
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
typedef long long ll;
ll fastpower(ll base,ll power,ll mod)
{
	ll res = 1;
	while(power)
	{
		if(power & 1)
			res = res * base%mod;
		base = base*base%mod;
		power >>= 1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll s,v,w,e,a;
	cin >> s >> v >> w >> e >> a;
	cout<<fastpower((fastpower(s%a,w,a) * fastpower(v%a,w,a))%a,e,a)%a<<endl;
	return 0;
}