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
	cin>>t;
	while(t--)
	{
		int n,m;
		ll k;
		cin>>n>>m>>k;
		vector<P> row(n);
		vector<P> col(m,P(-1,0x3f3f3f3f));
		vector<vector<int> >a(n,vector<int>(m,0));
		for(int i = 0; i<n; ++i)
		{
			for(int j = 0; j<m; ++j)
			{
				cin>>a[i][j];
				if(row[i].second<a[i][j])
					row[i].first = j,row[i].second = a[i][j];
				if(col[j].second>a[i][j])
					col[j].second = a[i][j],col[j].first = i;
			}
		}
		int flag = 0;
		P pos(0,0);
		while(k--)
		{
			if(!flag)
				pos.second = row[pos.first].first;
			else
				pos.first = col[pos.second].first;
			flag = flag&1^1;
		}
		cout<<a[pos.first][pos.second]<<endl;
	}
	return 0;
}
