#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int main()
{
	int n, q;
	deque<int> Q;
	deque<int> Q_temp;
	vector<int> cards;
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		Q.push_back(temp);
	}
	for (int i = 0; i < q; ++i)
	{
		int query;
		scanf("%d", &query);
		int cnt=0;
		Q_temp.clear();
		while (!Q.empty())
		{
			if (Q.front() != query)
			{
				Q_temp.push_back(Q.front());
				Q.pop_front();
				cnt++;
			}
			else
			{
				printf("%d ", cnt + 1);
				Q.insert(Q.begin()+1,Q_temp.begin(), Q_temp.end());
				break;
			}
		}
	}
	return 0;
}