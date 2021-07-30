#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 55
typedef long long ll;
using namespace std;
int main()
{	
	int t,a[maxn],b[maxn];
	scanf("%d", &t);
	while (t--)
	{
		int n,mina=1e9+5, minb=1e9+5;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			mina=min(mina, a[i]);
		}
		for(int i=0;i<n;++i)
			a[i] -= mina;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &b[i]);
			minb = min(minb, b[i]);
		}
		for (int i = 0; i < n; ++i)
			b[i] -= minb;
		ll ans = 0;
		for (int i = 0; i < n; ++i)
			ans += max(a[i], b[i]);
		printf("%lld\n", ans);
	}
	return 0;
}