#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;
typedef pair<int, int> Pair;
map<int, int> mp[200005];
queue<int> Q;
vector<int> path(2e5+5,0);
vector<int> vis(2e5+5,0);
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);	
		mp[temp1][temp2] = 1;
		mp[temp2][temp1] = 1;
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &path[i]);
	}
	Q.push(1);
	int loc = 1;
	while (!Q.empty())
	{
		int p = Q.front();
		Q.pop();
		vis[p] = 1;
		while (mp[p][path[loc]])
		{
			Q.push(path[loc]);
			loc++;
		}
	}
	for (int i = 1; i <=n; ++i)
	{
		if (!vis[i])
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}