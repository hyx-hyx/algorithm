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
inline int gcd(int a,int b)
{
	return b > 0 ? gcd(b,a % b) : a;
}
vector<int> a;
int main()
{
	int x,y;
	cin >> x >> y;
	int d = gcd(x,y);
	int sqrtd = sqrt(d);
	for(int i = 1; i <= sqrtd; ++i)
		if(d % i == 0) a.emplace_back(i);
	if(d % sqrtd == 0 && d / sqrtd != sqrtd) a.emplace_back(d / sqrtd);
	for(int i = sqrtd - 1; i >= 1; --i)
		if(d % i == 0) a.emplace_back(d / i);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d%d",&x,&y);
		auto it = upper_bound(a.begin(),a.end(),y);
		if(*(--it) >= x)
			printf("%d\n",*it);
		else
			printf("-1\n");
	}
	return 0;
}