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
#define maxn 2505
#define INF 0x3f3f3f3f
typedef long long ll;
typedef struct edge {
	int to;
	int next;
	int weight;
}edge;
edge edges[maxn << 1], mst[maxn << 1];
int head[maxn],headmst[maxn],tot, vis[maxn] = {0};
vector<int> dis(maxn, INF);
int n;
inline void addEdge(int u, int v, int w,int head[],edge edges[])
{
	++tot;
	edges[tot].to = v;
	edges[tot].weight = w;
	edges[tot].next = head[u];
	head[u] = tot;
}
void Prim(int s)
{
	vector<int> v; //存储点集
	v.push_back(s);
	int cnt=1;
	while (cnt != n - 1)
	{
		int minv = s;
		int mindist = INF;
		int cur = v.front();
		for(int i=0;i<v.size();++i)
		{
			vis[cur] = 1;
			for (int e = head[cur]; e != 0; e = edges[e].next)
			{
				int to = edges[e].to;
				if (vis[to])
					continue;
				if (dis[to] > edges[e].weight)
				{
					dis[to] = edges[e].weight;
					if (mindist > dis[to])
						mindist = dis[to], minv = to;
				}
			}
		}
		if(mindist!=INF)
			addEdge(cur, minv, mindist, headmst, mst),addEdge(minv, cur, mindist, headmst, mst);
		v.push_back(minv);
		cnt++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int temp;
			cin >> temp;
			addEdge(i, j, temp,head,edges);
			addEdge(j, i, temp,head,edges);
		}
	}
	tot = 0;
	Prim(1);
	return 0;
}
/*
0 6 1 5 100 100
6 0 5 100 3 100
1 5 0 5 6 4
5 100 5 0 100 2
100 3 5 100 0 6
100 100 4 2 6 0
*/