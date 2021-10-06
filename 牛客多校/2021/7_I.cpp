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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int bitx[35], bits[35];
	int x, s;
	cin >> x >> s;
	int index = 0,flag=0;
	if (x == s)
		flag = 1;
	while (s)
	{
		bitx[index] = x & 1;
		bits[index++] = s & 1;
		s >>= 1;
		x >>= 1;
	}
	if (x != 0)
	{
		cout << 0 << endl;
		return 0;
	}
	ll res = 1;
	for (int i = 0; i < index; ++i)
	{
		if (bitx[i] && bits[i])
			res *= 2;
		if (bitx[i] && !bits[i])
		{
			cout << 0 << endl;
			return 0;
		}
	}
	if (flag)
		cout << res - 1 << endl;
	else
		cout << res << endl;
	return 0;
}
