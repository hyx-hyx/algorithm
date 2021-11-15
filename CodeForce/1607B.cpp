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
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll x0,n;
		cin >> x0 >> n;
		if(!n)
			cout << x0 << endl;
		else
		{
			if(x0 % 2)
				x0 += 1;
			else
				x0 -= 1;
			n -= 1;
			if(n == 0)
				cout << x0 << endl;
			else
			{
				ll cur = x0 + 4 * (n / 4) * (x0 % 2 == 0 ? 1 : -1);
				ll s = n / 4 * 4 + 2;
				for(int i = 1; i <= n % 4; ++i,++s)
					if(i <= 2)
						cur = cur + s * (x0 % 2 == 0 ? -1 : 1);
					else
						cur = cur + s * (x0 % 2 == 0 ? 1 : -1);
				cout << cur << endl;
			}
		}
	}
	return 0;
}
