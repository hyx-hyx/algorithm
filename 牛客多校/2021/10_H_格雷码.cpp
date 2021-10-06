#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 5e3;
typedef long long ll;
/*求出某个数的格雷码
举个例子，3位二进制数的格雷码序列为000,001,011,010,110,111,101,100
注意序列的下标我们以0为起点，也就是说G(0)=000,G(4)=110.
*/
int g(int n)  
{
	return n^( n>>1 );
}
ll fastpower(ll base,ll power)
{
	ll res = 1;
	while(power)
	{
		if(power&1)
			res = res*base;
		base *= base;
		power >>= 1;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int m = fastpower(2,n);
	int flag = 1;
	string s(m,'a');
	int next=1;
	for(int i = 0; i<m; ++i)
		s[g(i)] = ( flag&1^1 )+48,flag = flag&1^1;
	for(int i = 0; i<m; ++i)
			cout<<s[i];
	return 0;
}
