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
#define maxn 100005
typedef long long ll;
#define lowbit(x) ((x)&(-x))
using namespace std;
ll tree[maxn << 2];
inline void update(ll i,ll x)
{
	for(ll pos = i; pos < maxn; pos += lowbit(pos))
		tree[pos] += x;
}
inline ll query(ll n)
{
	ll ans = 0;
	for(ll pos = n; pos; pos -= lowbit(pos))
		ans += tree[pos];
	return ans;
}
inline ll query(ll a,ll b)
{
	return query(b) - query(a - 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll t[maxn],d[maxn];
	ll dp[maxn] = {0};
	for(ll i = 1; i <= n; ++i)
	{
		cin >> t[i] >> d[i];
		update(i,d[i]);
	}
	for(ll i = 1; i <= n; ++i)
	{
		ll minv = 0x3f3f3f3f;
		ll minj = 0;
		for(ll j = 1; j <= n; ++j)
		{
			if(!d[j])
				continue;
			ll tempd = d[j];
			update(j,-d[j]);
			d[j] = 0;
			ll temp = dp[i - 1] + 2 * t[j] * query(1,n);
			if(temp < minv)
				minj = j,minv = temp;
			update(j,tempd);
			d[j] = tempd;
		}
		dp[i] = minv;
		update(minj,-d[minj]);
		d[minj] = 0;
	}
	cout << dp[n] << endl;
	return 0;
}
//=================================================================================================
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
#define maxn 100005
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> Pair;
#define lowbit(x) ((x)&(-x))
ll tree[maxn];
inline void update(ll i,ll x)
{
	for(ll pos = i; pos < maxn; pos += lowbit(pos))
		tree[pos] += x;
}
inline ll query(ll n)
{
	ll ans = 0;
	for(ll pos = n; pos; pos -= lowbit(pos))
		ans += tree[pos];
	return ans;
}
inline ll query(ll a,ll b)
{
	return query(b) - query(a - 1);
}
inline int gcd(int a,int b)
{
	return b > 0 ? gcd(b,a % b) : a;
}
bool cmp(Pair a,Pair b)
{
	if(a.first.first == b.first.first)
		return a.first.second > b.first.second;
	else
	{
		a.first.second*=b.first.first/gcd(a.first.first,b.first.first);
		b.first.second*= a.first.first/ gcd(a.first.first,b.first.first);
		return a.first.second > b.first.second;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll t[maxn],d[maxn];
	vector<Pair> numden;
	for(ll i = 1; i <= n; ++i)
	{
		cin >> t[i] >> d[i];
		numden.push_back(Pair(P(t[i],d[i]),i));
		update(i,d[i]);
	}
	sort(numden.begin(),numden.end(),cmp);
	ll sum = 0;
	for(ll i = 0; i <n; ++i)
	{
		ll id = numden[i].second;
		sum+=2*t[id]*(query(n) - query(id,id));
		update(id,-d[id]);
	}
	cout << sum << endl;
	return 0;
}