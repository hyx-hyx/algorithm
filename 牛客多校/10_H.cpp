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
int g(int n)
{
	return n^( n>>1 );
}
string intToA(int n,int radix)    //n是待转数字，radix是指定的进制
{
	string ans = "";
	do
	{
		int t = n%radix;
		if(t>=0&&t<=9)	ans += t+'0';
		else ans += t-10+'a';
		n /= radix;
	} while(n!=0);	//使用do{}while（）以防止输入为0的情况
	reverse(ans.begin(),ans.end());
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int a[maxn];
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int index = 0;
	int flag = 0;

	while(1)
	{
		int temp = g(0);
	}
	return 0;
}
