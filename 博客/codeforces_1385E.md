## 题意
[链接](https://codeforces.com/problemset/problem/1385/E)

给你一个图，$n$个点，$m$条边，但这$m$条边有些是定向的，有些是未定向的，需要你去决定方向，问你是否能让这个图不形成环，而且要对所有未定向的边定向。
## 思路
拓扑排序可以判断一个图是否是有向无环的，所以可以用到.

先对以定向的边进行判断是否已经形成了环，如果形成了环那就肯定不能符合条件.

反之，如果未形成环，那么就一定能符合条件，按照拓扑排序出来的顺序，可以用一个数组pos记录。

当pos[x]<pos[y]时，即意味着x在y之前就出来了，所以可以加上$x$ $\rArr$ $y$的一条边是对这个图的是否有环是没有影响的。

x在y之前代表x的入度小于等于y的入度，此时x->y是不会成环的。
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
using namespace std;
#define maxn 200005
vector<int> edges[maxn];
vector<int> deg(maxn);
int A[maxn];
int toposort(int n)  //拓扑排序模板
{
	int cnt = 0;
	queue<int> q;
	for (int i = 1; i <= n; ++i)
		if (deg[i] == 0)
			q.push(i);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		A[cnt++] = t;
		for (auto to : edges[t])
		{
			deg[to]--;
			if (deg[to] == 0)
				q.push(to);
		}
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		vector<int> xs, ys, ts;
		cin >> n >> m;
		deg.assign(n + 1, 0);
		for (int i = 0; i <= n; ++i)
			edges[i].clear();
		for (int i = 0; i < m; ++i)
		{
			int t, x, y;
			cin >> t >> x >> y;
			if (t)
				edges[x].push_back(y),deg[y]++;  //将已给出有向边进行连边
			xs.push_back(x), ys.push_back(y), ts.push_back(t);
		}
		if (toposort(n) != n) //对所有顶点进行拓扑排序。
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			vector<int> pos(n + 1, 0);
			for (int i = 0; i < n; ++i)
				pos[A[i]] = i+1;   //记录顶点的拓扑序
			for (int i = 0; i < m; ++i)
			{
				if (ts[i])
					cout << xs[i] << " " << ys[i] << endl;
				else
				{
					if (pos[xs[i]]<pos[ys[i]])  //如果xs[i]在ys[i]前面
						cout << xs[i] << " " << ys[i] << endl;
					else
						cout << ys[i] << " " << xs[i] << endl;
				}
			}
		}
	}
	return 0;
}
```