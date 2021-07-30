#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
#define maxn 1005
using namespace std;
deque<int> Q_max;
deque<int> Q_min;
int v[maxn] = { 0 };
int out_max[maxn];
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v[i]);
		if (!Q_max.empty() && i - Q_max.front() >= k)
			Q_max.pop_front();
		if (!Q_min.empty() && i - Q_min.front() >= k)
			Q_min.pop_front();

		while(!Q_max.empty() && v[Q_max.back()] <v[i])
			Q_max.pop_back();
		while (!Q_min.empty() && v[Q_min.back()] > v[i])
			Q_min.pop_back();

		Q_max.push_back(i);
		Q_min.push_back(i);
		if (i >= k - 1)
		{
			printf("%d ", v[Q_min.front()]);
			out_max[i - k + 1] = v[Q_max.front()];
		}
	}
	printf("\n");
	for (int i = 0; i < n - k + 1; ++i)
		printf("%d ", out_max[i]);
	return 0;
}

