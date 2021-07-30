#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> Pair;
struct cmp
{
	bool operator()(Pair a, Pair b)
	{
		if (a.first == b.first)
			return a.second > b.second;
		else
			return a.first < b.first;
	}
};
priority_queue<pair<int,int>,vector<pair<int, int> >,cmp>Q;
vector<int> vis;
queue<int> Q_2;
int main()
{
	int q,cnt=1,num,m;
	cin >> q;
	vis.push_back(0);
	while (scanf("%d",&num)!=EOF)
	{
		if (num == 1)
		{
			scanf("%d",&m);
			Q.push(Pair(m,cnt));
			Q_2.push(cnt);
			vis.push_back(cnt++);
		}
		else
		{
			if (num == 2)
			{
				while (!vis[Q_2.front()])
					Q_2.pop();
				printf("%d ", (Q_2.front()));
				vis[Q_2.front()] = 0;
			}
			else
			{
				while(!vis[Q.top().second])
					Q.pop();
				Pair temp = Q.top();
				printf("%d ",temp.second);
				vis[temp.second] = 0;
				
				
			}
		}
	}
	return 0;
}
