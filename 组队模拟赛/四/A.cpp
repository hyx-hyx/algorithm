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
#define maxn 5005
typedef long long ll;
ll fact[maxn] = {1,1},mod;
ll strling[maxn][maxn] = {0};
ll pow(ll a,ll n,ll p)
{
	ll ans = 1;
	while(n)
	{
		if(n & 1) ans = ans * a % p;
		a = a * a % p;
		n >>= 1;
	}
	return ans;
}
ll niyuan(ll a,ll p)
{
	return pow(a,p - 2,p);
}
ll A(int n,int i)
{
	return (fact[n]*niyuan(fact[n - i],mod))%mod;
}
void factmul(int n)
{
	for(int i = 2; i <=n; ++i)
		fact[i] = fact[i - 1] * i % mod;
}
void getstrling()
{
	for(int i = 2; i < maxn; ++i)
		for(int j = 1; j <= i; ++j)
			strling[i][j] = (strling[i - 1][j - 1] + (j * strling[i - 1][j]%mod))%mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m >> mod;
	ll ans = 0;
	factmul(n);
	strling[1][1] = 1;
	getstrling();
	for(int i = 1; i <=m;++i)
		ans =(ans+(((A(n,i) * strling[m][i])) % mod * i) % mod)%mod;	
	cout << ans << endl;
	return 0;
}