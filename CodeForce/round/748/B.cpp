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
const int inf = 0x3f3f3f3f;
int depart(int a[],ll n)
{
	int index = 0;
	while(n)
		a[index++] = n % 10,n /= 10;
	return index;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int digit[20],loc_5 = 30,loc_0 = 30;
		ll n;
		cin >> n;
		int flag_0 = 0;
		int index= depart(digit,n);
		for(int i = 0; i < index; ++i)
		{
			if(digit[i] == 5)
				loc_5 = min(i,loc_5);
			if(digit[i] == 0)
				loc_0 = min(i,loc_0);
		}
		int ans_00=30,ans_50=30;
		for(int i = loc_0+1; i < index; ++i)
		{
			if(digit[i] == 5)
				ans_50 = min(i,ans_50);
			if(digit[i] == 0)
				ans_00 = min(i,ans_00);
		}
		ans_50 -= 1;
		ans_00 -= 1;
		int ans_25=30,ans_75=30;
		for(int i = loc_5 + 1; i < index; ++i)
		{
			if(digit[i] == 7)
				ans_75 = min(ans_75,i);
			if(digit[i] == 2)
				ans_25 = min(ans_25,i);
		}
		ans_25 -= 1;
		ans_75 -= 1;
		cout<<min(min(min(ans_00,ans_25),ans_50),ans_75)<<endl;
	}
	return 0;
}
