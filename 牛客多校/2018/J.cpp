#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long ll;
using namespace std;
int main()
{
	ll n,p2,p3;
	cin >> n >> p2 >> p3;
	if(n <= 2)
		cout << min(p2,p3) << endl;
	else
	{
		double two = (double)p2 / 2,three = (double)p3 / 3;
		ll sum = 0;
		if(two <= three)
		{
			sum = n / 2 * p2;
			if(n % 2)
				sum += min(p3 - p2,min(p2,p3));
		}
		else
		{
			sum = n / 3 * p3;
			if(n % 3 == 2)
				sum += min(p2,p3);
			if(n % 3 == 1)
				sum += min((2 * p2 - p3),min(p2,p3));
		}
		cout << sum << endl;
	}
	return 0;
}