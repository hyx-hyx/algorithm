#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
typedef long long ll;
using namespace std;
int main()
{
	ll n, m, a,x,y;
	scanf("%lld%lld%lld", &n, &m, &a);
	if (!(n % a))
		x = n / a;
	else
		x = n / a + 1;
	if (!(m % a))
		y = m / a;
	else
		y = m / a + 1;
	printf("%lld\n", x*y)   ;
	return 0;
}