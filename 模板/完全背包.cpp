#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1e3+5;
int main()
{
	int N,V,v[maxn],w[maxn];
	cin >> N >> V;
	int f[maxn] = {0};
	for(int i = 1; i <= N; ++i)
		cin >> v[i] >> w[i];
	for(int i = 1; i <= N; ++i)
		for(int j = v[i]; j <= V; ++j)
			f[j] = max(f[j],f[j - v[i]] + w[i]);
	cout << f[V] << endl;
	return 0;
}