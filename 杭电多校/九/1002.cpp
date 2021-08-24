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
typedef pair<int,int> P;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		ll k;
		cin >> n >> m >> k;
		vector<int> row(n);
		vector<int> col(m,0x3f3f3f3f);
		vector<vector<int> >a(n,vector<int>(m,0));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				cin >> a[i][j],row[i]= max(row[i],a[i][j]),col[j] = min(col[j],a[i][j]);
		if(k == 1)
		{
			cout << row[0] << endl;
			continue;
		}
		if(k % 2)
		{
			int minv = 0x3f3f3f3f;
			for(int i = 0; i < n; ++i)
				minv = min(minv,row[i]);
			cout << max(a[0][0],minv)<<endl;
		}
		else
		{
			int maxv = 0;
			for(int i = 0; i < m; ++i)
				maxv = max(maxv,col[i]);
			cout << max(a[0][0],maxv) << endl;
		}
	}
	return 0;
}
