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
const int mod = 1e9+7;
typedef long long ll;
ll fastpower(ll base,ll power)
{
	ll res = 1;
	while(power)
	{
		if(power&1)
			res = res*base%mod;
		base = base*base%mod;
		power >>= 1;
	}
	return res%mod;
}
ll pow(ll a,ll n,ll p)
{
	ll ans = 1;
	while(n)
	{
		if(n&1) ans = ans*a%p;
		a = a*a%p;
		n >>= 1;
	}
	return ans;
}

ll niyuan(ll a,ll p)
{
	return pow(a,p-2,p);
}

int main()
{
	ll n;
	cin>>n;
	ll temp = fastpower(2,n);
	ll ans=(temp*(temp+1)%mod)%mod*niyuan(2,mod)%mod;
	cout<<ans<<endl;
	return 0;
}
