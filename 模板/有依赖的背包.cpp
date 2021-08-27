#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 1e2 + 5;
typedef long long ll;
#define edgecount maxn+5
#define pointcount maxn
int N,V;
int v[maxn],w[maxn];
struct edge
{
	int to;
	int next;
	int w;
};
vector<edge> edges(edgecount);
vector<int> head(pointcount,0);
int dp[maxn][maxn] = {0};
int cnt = 0;
inline void add(int from,int to,int w)
{
	edges[++cnt].to = to;
	edges[cnt].w = w;
	edges[cnt].next = head[from];
	head[from] = cnt;
}
void dfs(int u)
{
	for(int e = head[u]; e; e = edges[e].next)
	{
		int to = edges[e].to;
		dfs(to);
		for(int j = V - v[u]; j >= 0; --j)
			for(int k = 0; k <= j; ++k)
				dp[u][j] = max(dp[u][j],dp[u][j - k] + dp[to][k]);
	}
	for(int i = V; i >= v[u]; --i)
		dp[u][i] = dp[u][i - v[u]] + w[u];
	for(int i = 0; i < v[u]; ++i)
		dp[u][i] = 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int root;
	cin >> N >> V;
	for(int i = 1; i <= N; ++i)
	{
		int p;
		cin >> v[i] >> w[i] >> p;
		if(p != -1)
			add(p,i,0);
		else
			root = i;
	}
	dfs(root);
	cout << dp[root][V] << endl;
	return 0;
}