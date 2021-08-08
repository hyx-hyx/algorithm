## 题意
[题目链接](https://codeforces.com/problemset/problem/1081/D)

给出一张图，存在自环和重边，规定图的顶点和边权。
定义路径的成本为路径上的权重最大的边，两点的距离为两点所有路径的成本的最小值。
给出一些特殊点，求出每个特殊点到其他特殊点的最大距离。
## 分析
我们可以将两点之间有两条以上的边组成的路径看作一条边e，边e的权重为原来的几条边的最大权重，两点的距离即为两点边权的最小值。

则可以先用kruskal算法生成的最小生成树求出每个点到其他点的距离，取最
大输出即可。

因为每个点都可以选择经过距离最大的那条边到达另一个点，所以每个特殊点到其他特殊点的最大距离都是相等的，用一个ans记录最大值即可。

#### 完整代码
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
typedef long long ll;
#define maxn 100050
using namespace std;
int fa[maxn];
typedef struct node
{
	int from;
	int to;
	int w;
}node;
vector<node> edge(200300);	//存图
bool cmp(node i, node j)
{
	return i.w < j.w;
}
void init(int n)
{
	for (int i = 0; i <= n; ++i)
		fa[i] = i;
}
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int i, int j)
{
	fa[find(j)] = find(i);
}
int main()
{
	int flag[maxn] = { 0 }, temp;	//flag标记以该点为根节点的连通块是否含有特殊点。
	int n, m, k;
	int ans = 0;
	scanf("%d%d%d", &n, &m, &k);
	init(n);
	for (int i = 0; i < k; ++i)
		scanf("%d", &temp), flag[temp] = 1;
	for (int i = 0; i < m; ++i)
		scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].w);
	sort(edge.begin(), edge.begin() + m, cmp);//kruskal算法，先排序。
	for (int i = 0; i < m; ++i)
	{
		int fa_from = find(edge[i].from);  //起始点的父节点
		int fa_to = find(edge[i].to);      //终点的父节点
		if (fa_from!=fa_to)
		{
			merge(fa_from,fa_to);  //往树中添加一条边等价于把边的两个端点加入同一个连通块。
			if (flag[fa_from] && flag[fa_to])  //两个端点的父节点的连通块都含有特殊点，更新最大距离。
				ans = max(ans, edge[i].w);
			else
			{
				//注意这里是把两个点的父节点标记为1，而不是这两个点标记为1
				if (flag[fa_from] || flag[fa_to])   //两个点中的父节点有一个特殊点，两个点在同一个连通块中，flag赋值为1.
					flag[fa_from] = flag[fa_to] = 1;
			}
		}
	}
	for (int i = 0; i < k; ++i)
		printf("%d%c", ans, i == k - 1 ? '\n' : ' ');
	return 0;
}
```