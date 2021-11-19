#include<cstdio>
#include<iostream>
#include<cmath>
#include<math.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
typedef long long ll;
using namespace std;
const int maxn = 69;
int sgn[maxn],a[maxn],b[maxn],c[maxn] = {0};
int main()
{
	int n;
	cin >> n;
	FOR(i,0,n) cin >> sgn[i];
	FOR(i,0,n) cin >> a[i];
	FOR(i,0,n) cin >> b[i];
	FOR(i,0,n)
	{
		int temp = a[i] + b[i];
		if(temp != 2)
			c[i] = temp;
		else
		{
			int j;
			for(j=i+1;j<n;++j)
			{
				if(sgn[i] == sgn[j])
				{
					int temp = a[j] + b[j];
					if(temp == 2)
						c[j] = 1;
					if(temp == 0)
					{
						c[j] = 1;
						break;
					}
				}
				else
				{
					int temp = a[j] + b[j];
					if(temp == 1 || temp == 2)
					{
						c[j] = temp - 1;
						break;
					}
					else
						c[j] = 1;
				}
			}
			i = j;
		}
	}
	FOR(i,0,n-1)
		cout << c[i] << " ";
	cout << c[n - 1];
	return 0;
}