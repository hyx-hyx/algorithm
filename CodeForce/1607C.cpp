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
		ll a[200005];
		int n;
		cin >> n;
		For(i,0,n)
			cin >> a[i];
		if(n == 1)
			cout << a[0] << endl;
		else
		{
			sort(a,a + n);
			ll diff[200005];
			diff[0] = a[0];
			for(int i=1;i<n;++i)
				diff[i] = a[i] - a[i - 1];
			cout << *(max_element(diff,diff +n)) << endl;
		}
	}
	return 0;
}
