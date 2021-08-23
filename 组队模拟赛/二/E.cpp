#define _CRT_SECURE_NO_WARNINGS   //洛谷  P3366
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
#define maxn 5005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int fa[maxn];
typedef struct node
{
	int from;
	int to;
	ll w;
}node;
vector<node> edge(200005);
bool cmp(node i,node j)
{
	return i.w < j.w;
}
void init(int n)
{
	for(int i = 0; i < n; ++i)
		fa[i] = i;
}
int find(int x)
{
	return x == fa[x] ? x : find(fa[x]);
}
void merge(int i,int j)
{
	fa[find(j)] = find(i);
}
int main()
{
	int s,p;
	vector<P> points;
	scanf("%d%d",&s,&p);
	for(int i = 1; i <= p; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		points.push_back(P(x,y));
	}
	for(int i = 0; i <points.size(); ++i)
		for(int j=0;j<points.size();++j)
			if(i != j)
				edge[i].from = i,edge[i].to,edge[i].w = ((ll)(points[i].first - points[j].first) * (points[i].first - points[j].first) + (ll)(points[i].second - points[j].second) * (points[i].second - points[j].second));
	init(p);
	int m = p * (p - 1) / 2;
	int k = 0;
	vector<ll> a;
	sort(edge.begin(),edge.begin() + m,cmp);
	for(int i = 0; i <= m; ++i)
	{
		if(k == p - 1) break;
		if(find(edge[i].from) != find(edge[i].to))
		{
			merge(edge[i].from,edge[i].to);
			a.push_back(edge[i].w);
			k++;
		}
	}
	sort(a.begin(),a.end());
	printf("%.2lf",sqrt(a[p - 1 - s]));
	return 0;
}
