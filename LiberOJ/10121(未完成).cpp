#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 200005
using namespace std;
deque<int>Q;
int main()
{
	int n, m, a[maxn], x, y;
	int maxlen = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &x, &y);
		maxlen = 0;
		Q.clear();
		vector<int> vis(2000005, 0);
		for (int j = x; j <=y; ++j)
		{
			if (vis[a[j]+1e6])
			{
				maxlen = max(maxlen, (int)Q.size());
				while (!Q.empty() && Q.front() != a[j])
				{
					vis[Q.front()+1e6] = 0;
					Q.pop_front();
				}	
				Q.push_back(Q.front());
				Q.pop_front();
			}
			else
			{
				Q.push_back(a[j]);
				vis[a[j]+1e6] = 1;
			}
		}
		printf("%d\n", max(maxlen,(int)Q.size()));
	}
	return 0;
}
