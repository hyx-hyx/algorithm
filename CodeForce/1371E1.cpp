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
const int maxn = 2005;
int main()
{
	int n,p;
	cin >> n >> p;
	int a[maxn] = {0};
	int minv = maxn,maxv = 0;
	vector<int> ans;
	For(i,0,n) cin >> a[i];
	sort(a,a + n);
	for(int i = a[0]; i <= a[n-1]; ++i)
	{
		int flag = 1;
		for(int j = 0; j < n; ++j)
		{
			int cnt = upper_bound(a,a + n,i + j) - a;
			if(!((cnt - j) % p))
			{
				flag = 0;
				break;
			}
		}
		if(flag)
			ans.push_back(i);
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	return 0;
}
