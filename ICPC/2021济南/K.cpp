#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
#define edgecount 210
#define pointcount 105
using namespace std;
struct edge
{
	int to;
	int next;
	int w;
};
vector<edge> edges(edgecount);
vector<int> head(pointcount,0);
typedef pair<int,int> Pair;
int cnt = 0;
inline void add(int from,int to,int w)
{
	edges[++cnt].to = to;
	edges[cnt].w = w;
	edges[cnt].next = head[from];
	head[from] = cnt;
}
int vis[240] = {0};
int ans = 0,sum=0;
stack<int>st;
void dfs(int s)
{
	for(int e = head[s]; e != 0; e = edges[e].next)
	{
		int to = edges[e].to;
		if(!vis[to])
		{
			ans++;
			sum += ans;
			vis[to] = 1;
			st.pop();
			dfs(to);
			if(!st.empty())
				ans++;
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		head.assign(pointcount,0);
		edges.resize(edgecount);
		cnt = 0,sum = 0,ans = 0;
		memset(vis,0,sizeof vis);
		int n;
		cin >> n;
		Fore(i,1,n-1)
			st.push(1);
		For(i,0,n-1)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b,0),add(b,a,0);
		}
		vis[1] =1;
		dfs(1);
		double ansd = (double)sum / (n - 1);
		printf("%.10lf\n",ansd);
	}
	return 0;
}
