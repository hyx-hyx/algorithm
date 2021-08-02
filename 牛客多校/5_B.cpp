#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define maxn 100005
using namespace std;
typedef long long ll;
ll fastpower(ll base, ll power)
{
	ll res = 1;
	while (power)
	{
		if (power & 1)
			res *= base;
		base *= base;
		power >>= 1;
	}
	return res;
}
int main()
{
	int n;
	double c, w[maxn], sum_all=0;
	scanf("%d%lf", &n, &c);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf", &w[i]);
		sum_all += w[i];
	}
	sort(w, w + n);
	double sum = 0;
	for (int i = 0; i < n; ++i)
		sum = sum / 2 + w[i];
	printf("%.12lf\n", min(sum_all, (sum_all-sum+c)));
	return 0;
}
