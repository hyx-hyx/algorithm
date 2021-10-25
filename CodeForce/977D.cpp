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
typedef pair<int,ll> P;
vector<P> vec;
bool cmp(P a,P b)
{
	if(a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}
int main()
{
	int n;
	cin >> n;
	For(i,0,n)
	{
		ll x,in;
		cin >> in;
		x = in;
		int cnt = 0;
		while(!(x % 3))
		{
			x /= 3;
			cnt++;
		}
		vec.push_back(P(cnt,in));
	}
	sort(vec.begin(),vec.end(),cmp);
	For(i,0,n-1)
		cout << vec[i].second <<" ";
	cout << vec[n - 1].second << endl;
	return 0;
}
