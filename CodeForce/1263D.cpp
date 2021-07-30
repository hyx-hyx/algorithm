#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
#define maxn 200005
using namespace std;
int fa[maxn], ranki[maxn];
vector<int> vis(30,-1);
void init(int n)
{
	for (int i = 0; i < n; ++i)
	{
		fa[i] = i;
		ranki[i] = 1;
	}
}
bool cmp(string s, string t)
{
	return s.size() > t.size();
}
int find(int x)
{
	return fa[x] == x ? fa[x] : (fa[x] = find(fa[x]));
}
void merge(int i, int j)
{
	int x = find(i);
	int y = find(j);
	if (x == y)
		return;
	if (ranki[x] > ranki[y])
		fa[x] = y;
	else
		fa[y] = x;
	if (ranki[x] == ranki[y] && x != y)
		ranki[y]++;
}
int main()
{
	int n;
	scanf("%d", &n);
	vector<string> s(200005);
	init(n);
	for (int i = 0; i <n; ++i)
		cin >> s[i];
	sort(s.begin(), s.begin()+n, cmp);
	for (int i = 0; i <n; ++i)
	{
		for (int j = 0; j < s[i].size(); ++j)
		{
			if (vis[s[i][j] - 96] != -1)
				merge(vis[s[i][j] - 97], i);
			else
				vis[s[i][j] - 96] = i;
		}
	}
	int count = 0;
	for (int i = 0; i <n; ++i)
	{
		if (fa[i] == i)
			count++;
	}
	printf("%d", count);
	return 0;
}