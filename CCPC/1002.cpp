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
ll cal(ll a,ll b,ll c,ll x)
{
	return (ll)(a * x * x + b * x + c);
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		int x0,x1,y0,y1,y2;
		cin >> x0 >> x1 >> y0 >> y1 >> y2;
		ll ya = cal(a,b,c,x0);
		ll yb = cal(a,b,c,x1);
		if(ya <= y0)
			cout << "No" << endl;
		else
		{
			if(yb < y0)
				cout << "Yes" << endl;
			else
			{
				if((yb > y2) || (yb == y0))
					cout << "No" << endl;
				else
				{
					int xdc = x1 + (x1 - x0);
					ll ydc = cal(a,b,c,xdc);
					if(ydc < y0)
						cout << "Yes" << endl;
					else
						cout << "No" << endl;
				}
			}
		}
	}
	return 0;
}