#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 2e3 + 5;
typedef struct good
{
	int v,w;
}good;
int main()
{
	int N,V,v[maxn],w[maxn],s[maxn];
	cin >> N >> V;
	vector<good> goods;
	int f[maxn] = {0};
	for(int i = 1; i <= N; ++i)
		cin >> v[i] >> w[i] >> s[i];
	for(int i = 1; i <= N; ++i)
	{
		for(int k = 1; k <=s[i]; k *= 2)
		{
			s[i] -= k;
			goods.push_back({v[i] * k,w[i] * k});
		}
		if(s > 0)
			goods.push_back({v[i] * s[i],w[i] * s[i]});
	}
	for(int i = 0; i < goods.size(); ++i)
		for(int j = V; j >=goods[i].v; --j)
			f[j] = max(f[j],f[j -goods[i].v] + goods[i].w);
	cout << f[V] << endl;
	return 0;
}