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
using namespace std;
int n;
const int eps = 1;
vector<ll>a(200005);
ll t[200005] = {0};
__int128 f(ll d)
{
	Fore(i,1,n)
		t[i] = a[i] - (i - 1) * d;
	nth_element(t + 1,t + n / 2 + 1,t + n + 1);
	ll x = t[n / 2 + 1];
	__int128 ans = 0;
	Fore(i,1,n)
		ans += fabs(x - t[i]);
	return ans;
}
ll three_div(ll l,ll r)
{
	ll lmid,rmid;
	while(l < r - 1)
	{
		lmid = (l + r) >> 1;
		rmid = (lmid + r) >> 1;
		if(f(lmid) > f(rmid))l = lmid;
		else r = rmid;
	}
	return r;
}
int main()
{
	cin >> n;
	Fore(i,1,n)
		cin >> a[i];
	ll dans=three_div(-1e13,1e13);
	__int128 ans = f(dans);
	printf("%lld\n",ans);
	return 0;
}
