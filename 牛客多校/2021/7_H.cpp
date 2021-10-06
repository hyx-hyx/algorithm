#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<cmath>
using namespace std;
#define maxn 1005
typedef long long ll;
unordered_map<int, int> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, a[maxn];
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], mp[a[i]]++;
	for (auto i = mp.begin(); i != mp.end(); ++i)
		v.push_back(i->first);
	sort(v.begin(), v.end());
	int maxvalue = v[v.size() - 1];
	ll ans = 0;
	for (int i = 0; i<v.size()&&v[i]<(int)(sqrt(maxvalue)+1); ++i)
	{
		for (int j = i; j < v.size(); ++j)
		{
			ll k = v[i] * v[j];
			if (k > maxvalue)
				break;
			if (v[j] != v[i])
				ans += mp[v[i]] * mp[v[j]] * 2 * mp[k];
			else
				ans += mp[v[i]] * mp[v[j]] * mp[k];
		}
	}
	cout << ans << endl;
	return 0;
}
