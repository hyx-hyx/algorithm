/*
平面上有n条直线，且无三线共点，问这些直线能有多少种不同交点数。
比如,如果n=2,则可能的交点数量为0(平行)或者1(不平行)。
Input
输入数据包含多个测试实例,每个测试实例占一行,每行包含一个正整数n（n<=20）,n表示直线的数量.
Output
每个测试实例对应一行输出，从小到大列出所有相交方案，其中每个数为可能的交点数,每行的整数之间用一个空格隔开。
Sample Input
2
3
Sample Output
0 1
0 2 3
首先n条线段，全部平行，0；
n-1条线段平行，n-1；
n-2条线段平行，2*(n-2)+2条线段的交点数；
n-3条线段平行，3*(n-3)+3条线段的交点数；
n-4条线段平行，4*(n-4)+4条线段的交点数；
以此类推！
上面“+2条线段的交点数；”这个部分需要注意！恰好是我们可以记录下来的前面的数据，所以我们得先打个表！打表记录每一种情况，然后后面再来用到前面的数据.
所以,采取dp[i][j]的方式来记录，注意dp[i][j]只是状态表示，表示n为i的时候j如果是可能的交点数则dp[i][j]=1,否则dp[i][j]=0.
*/
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
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	while(cin>>n)
	{
		int dp[21][191] = {0};
		for(int i = 1; i<=n; ++i)
			dp[i][0] = 1;
		for(int i = 2; i<=n; ++i)
			for(int j = 1; j<i; ++j)
				for(int k = 0; k<=j*( j-1 )/2; ++k)
					if(dp[j][k])
						dp[i][j*( i-j )+k] = 1;
		cout<<0<<" ";
		for(int i = 1; i<n*( n-1 )/2; ++i)
			if(dp[n][i])
				cout<<i<<" ";
		cout<<n* ( n-1 )/2<<endl;
	}
	return 0;
}
/*
头文件 #include<bitset>
定义 bitset<位数> bset;
bset[j]得到第j位的值

//使用bitset优化
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
#include<bitset>
using namespace std;
typedef long long ll;
const int maxn = 191;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	bitset<maxn> dp[21];
	while(cin >> n)
	{
		for(int i = 1; i <= 20; ++i)
			dp[i][0] = 1;
		for(int i = 2; i <= n; ++i)
			for(int j = 1; j < i; ++j)
				dp[i] |= (dp[j] << (j * (i - j)));
		cout << 0 << " ";
		for(int i = 1; i < n * (n - 1) / 2; ++i)
			if(dp[n][i])
				cout << i << " ";
		cout << n * (n - 1) / 2 << endl;
	}
	return 0;
}
*/

