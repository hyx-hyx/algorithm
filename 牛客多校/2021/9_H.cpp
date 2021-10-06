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
#define maxn 
typedef long long ll;
string intToA(int n,int radix)    
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
vector<int>diff{1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161,2391484,7174453,21523360,64570081,193710244,581130733,1743392200};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int index=lower_bound(diff.begin(),diff.end(),n)-diff.begin();
	if(n!=diff[index])
		index--;
	string s = intToA(n-diff[index],3);
	for(int i = 0; i<index+1-s.size(); ++i)
		cout<<'2';
	for(int i = 0; i<s.size(); ++i)
	{
		if(s[i]=='0')
			cout<<'2';
		if(s[i]=='1')
			cout<<'3';
		if(s[i]=='2')
			cout<<'6';
	}
	cout<<endl;
	return 0;
}
