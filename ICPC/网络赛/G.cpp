#include<cstdio>
#include<iostream>
#include<cmath>
#include<math.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
typedef long long ll;
using namespace std;
const int maxn = 1e5 + 5;
ll a[maxn],b[maxn],f[maxn] = {0};
int n,t;
void taile(int x,int y)
{
	FOR(i,1,t+1)
		f[i-1] += x * pow(-1,i + 1) * pow(y,i);
}
inline int gcd(int a,int b)
{
	return b > 0 ? gcd(b,a % b) : a;
}
int main()
{
	cin >> n >> t;
	FOR(i,0,n)
	{
		cin >> a[i] >> b[i];
		taile(a[i],b[i]);
	}
	if(t == 0)
	{
		cout << 0;
		return 0;
	}
	FOR(i,0,t-1)
	{
		if(f[i] != 0)
		{
			cout << "infinity";
			return 0;
		}
	}
	ll fz = f[t-1],ft = t;
	fz /= gcd(fz,ft);
	ft /= gcd(fz,ft);
	if(ft == 1)
		cout << fz;
	else
		cout << fz << "/" << ft;
	return 0;
}