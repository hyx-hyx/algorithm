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
int f[1005];
int main()
{
	int n,m,v;
	scanf("%d%d",&m,&v);
	vector<int> a(m+1,0);
	for(int i = 1; i <= m; ++i)
		scanf("%d",&a[i]);
	cin >> n;
	while(n--)
	{
		int l,r;
		cin >> l >> r;
		vector<int> c(a.begin() + l-1,a.begin() + r+1);
		memset(f,0,sizeof(f));
		for(int i = 1; i <= v; ++i)
			f[i] = 0x3f3f3f3f;
		for(int i = 1; i <= r-l+1; ++i)
			for(int j = c[i]; j <= v; ++j)
				f[j] = min(f[j],f[j - c[i]] +1);
		cout << ((f[v] == 0x3f3f3f3f) ? -1:f[v]) << endl;
	}
	return 0;
}