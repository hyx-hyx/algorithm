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
	int n,vis[100005] = {0};
	cin >> n;
	int maxans = 0;
	int ans = 0;
	For(i,0,2 * n)
	{
		int x;
		cin >> x;
		if(!vis[x])
			ans++,vis[x]++,maxans = max(ans,maxans);
		else
			ans--;
	}
	cout << maxans << endl;
	return 0;
}