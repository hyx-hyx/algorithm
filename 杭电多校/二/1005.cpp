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
const int mod = 1e9+7;
typedef long long ll;
ll fastpower(ll base,ll power)
{
	ll res = 1;
	while(power)
	{
		if(power & 1)
			res = (res * base)%mod;
		base = (base*base)%mod;
		power >>= 1;
	}
	return res%mod;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		getchar();
		int cnt = 0,flag=0;
		char first = 0;
		while(1)
		{
			char c;
			scanf("%c",&c);
			if(c == '\n')
				break;
			if(!cnt)
			{
				cnt++;
				flag = 1;
				first = c;
			}
			if(flag && (c == first) && cnt)
				cnt++;
			if(c !=first)
				flag = 0;
		}
		printf("%lld\n",(ll)(fastpower(2,cnt -2) % mod));
	}
	return 0;
}