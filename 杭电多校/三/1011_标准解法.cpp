//此方法测试时比打表慢，但思路好写。
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
#include<unordered_map>
using namespace std;
const int maxn = 1e9;
typedef long long ll;
unordered_map<ll,ll> mp;
ll getans(ll l,ll r,ll k)
{
	if(r - l + 1 <= k)
		return 1;
	else
	{
		ll mid = (l + r) / 2;
		ll left=0,right=0;
		unordered_map<ll,ll>::iterator it=mp.find(mid - l + 1);
		if(it != mp.end())
			left = (*it).second;
		else
			left = getans(l,mid,k),mp[mid - l + 1] = left;
		it = mp.find(r - mid);
		if(it != mp.end())
			right = (*it).second;
		else
			right = getans(mid + 1,r,k),mp[r-mid] = right;
		return left + right+1;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		ll n,k;
		cin >> n >> k;
		mp.clear();
		cout<<getans(1,n,k)<<endl;
	}
	return 0;
}