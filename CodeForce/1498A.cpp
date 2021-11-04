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
int num[20] = {0};
int index = 0;
ll gcd(ll a,ll b)
{
	return b > 0 ? gcd(b,a % b) : a;
}
void digit(ll n)
{
	if(!n)
		return;
	num[index++] = n % 10;
	digit(n / 10);
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		index = 0;
		digit(n);
		int sum = 0;
		For(i,0,index)
			sum += num[i];
		while(1)
		{
			if(gcd(n,sum) == 1LL)
			{
				index = 0;
				digit(++n);
				sum = 0;
				For(i,0,index)
					sum += num[i];
			}
			else
			{
				cout << n << endl;
				break;
			}
		}
	}
	return 0;
}
