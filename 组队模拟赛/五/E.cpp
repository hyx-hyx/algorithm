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
const int maxn = 205;
const int N = 200;
int sg[maxn][maxn];
inline int SG(int n,int m)
{
	int f[N] = {0};
	if(sg[n][m] != -1)
		return sg[n][m];
	for(int i = 2; i < n - 1; ++i)
		f[SG(n - i,m) ^ SG(i,m)] = 1;
	for(int i = 2; i < m - 1; ++i)
		f[SG(n,m - i) ^ SG(n,i)] = 1;
	int p = 0;
	while(f[p])
		p++;
	return sg[n][m] = p;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	memset(sg,-1,sizeof(sg));
	while(cin >> n >> m)
	{
		sg[2][2] = 0,sg[2][3] = 0,sg[3][2] = 0;
		if(SG(n,m))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}