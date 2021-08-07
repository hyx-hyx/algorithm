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
int toposort(int n)
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
				edges[x].push_back(y),deg[y]++;
			xs.push_back(x), ys.push_back(y), ts.push_back(t);
		}
		if (toposort(n) != n)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			vector<int> pos(n + 1, 0);
			for (int i = 0; i < n; ++i)
				pos[A[i]] = i+1;
			for (int i = 0; i < m; ++i)
			{
				if (ts[i])
					cout << xs[i] << " " << ys[i] << endl;
				else
				{
					if (pos[xs[i]]<pos[ys[i]])
						cout << xs[i] << " " << ys[i] << endl;
					else
						cout << ys[i] << " " << xs[i] << endl;
				}
			}
		}
	}
	return 0;
}
