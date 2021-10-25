#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<vector>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
using namespace std;
vector<ll>a;
int n;
int ans[105] = {0},vis[101] = {0};
int flag = 0;
void f(ll x,int index)
{
	if(index == n - 1)
	{
		For(i,0,n - 1)
			cout << ans[i] << " ";
		cout << ans[n - 1] << endl;
	}
	if(x % 3 == 0)
	{
		int temp = find(a.begin(),a.begin() + n,x / 3) - a.begin();
		if(temp != n && !vis[temp])
			ans[index++] = x / 3,f(x / 3,index+1);
	}
	if(find(a.begin(),a.begin() + n,x * 2) != a.begin() + n)
	{
		int temp = find(a.begin(),a.begin() + n,x * 2) - a.begin();
		if(temp != n && !vis[temp])
			ans[index++] = x * 2,f(x * 2,index+1);
	}
}
int main()
{
	int x;
	cin >> n;
	For(i,0,n)
		cin >> x,a.push_back(x);
	For(i,0,n)
		if(!flag)
			f(a[i],0);
		else
			break;
	return 0;
}
