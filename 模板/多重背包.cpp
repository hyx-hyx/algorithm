#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1e3 + 5;
int main()
{
	int N,V,v[maxn],w[maxn],s[maxn];
	cin >> N >> V;
	int f[maxn] = {0};
	for(int i = 1; i <= N; ++i)
		cin >> v[i] >> w[i] >> s[i];
	for(int i = 1; i <= N; ++i)
		for(int j = V; j >=v[i]; --j)
			for(int k = 0; k * v[i] <= j && k <= s[i]; ++k)
				f[j] = max(f[j],f[j - k * v[i]] + k * w[i]);
	cout << f[V] << endl;
	return 0;
}