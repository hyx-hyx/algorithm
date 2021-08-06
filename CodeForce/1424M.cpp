/*
题意
给定一个共有n页的字典，每一页有k个单词
已知这本字典使用的古老语言的字母是英文字母的子集，不一定26个英文字母都被使用到
问你是否存在一种字典序满足这本字典内单词原来的排列顺序
存在的话只需要输出任意一种即可，不存在输出IMPOSSIBLE

限制
1≤n,k≤1000
0≤pi<1000

思路
将给定的所有单词按照题意进行排序，页码小的放前，页码相同的按照输入顺序排序
然后考虑所有的相邻单词，这里以i,j来描述（j=i+1）
如果i,j两个单词相同，不考虑
如果i,j两个单词不同，且i是j的前缀，不考虑
如果i,j两个单词不同，且j是i的前缀，明显这样不可能有满足的字典序，输出IMPOSSIBLE
如果i,j两个单词不同，且不满足上述两种条件，则只看出现不同字母时下标最小的那个位置k
令a表示第i个单词下标为k的字母，令b表示第j个单词下标为k的字母
可以发现，a的字典序应该是小于b的，所以将26个英文字母看作点，将a→b连边，同时标记b的入度+1
明显的，只有当最后产生的图是一个DAG时才存在一个解，所以我们每次找入度为0的点加入答案中即可，直接拓扑排序搜索即可
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
#define maxn 1000005
using namespace std;
vector<int> edges[28];
vector<char> ans;
vector<int> deg(28);
int vis[28] = { 0 };
void toposort(int n)
{
	int cnt = 0;
	queue<int> q;
	for (int i = 0; i < 28; ++i)
		if (deg[i] == 0 && vis[i])
			q.push(i);
	while (!q.empty())
	{
		int t = q.front();
		ans.push_back(t + 'a');
		q.pop();
		for (auto to : edges[t])
		{
			deg[to]--;
			if (deg[to] == 0 && vis[to])
				q.push(to);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int page;
	cin.tie(0);
	cout.tie(0);
	int n, k;
	string str[maxn];
	cin >> n >> k;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> page;
		int base = page * k;
		string s;
		for (int j = 0; j < k; ++j)
		{
			cin >> s, str[base + j] = s;
			for (int k = 0; k < s.size(); ++k)
				if (!vis[s[k] - 'a'])
					vis[s[k] - 'a'] = 1, cnt++;
		}
	}
	int output = 0;
	if (n * k == 1)
	{
		for (int i = 0; i < 28; ++i)
			if (vis[i])
				cout << (char)('a' + i);
	}
	else
	{
		for (int i = 0; i < n * k - 1; ++i)
		{
			int flag = 0;
			int len = min(str[i].size(), str[i + 1].size());
			for (int j = 0; j < len; ++j)
			{
				if (str[i + 1][j] != str[i][j])
				{
					flag = 1;
					char a = str[i][j];
					char b = str[i + 1][j];
					edges[a - 'a'].push_back(b - 'a');
					deg[b - 'a']++;
					break;
				}
			}
			if (str[i].size() > str[i + 1].size() && !flag)
			{
				output = 1;
				cout << "IMPOSSIBLE" << endl;
				break;
			}
		}
		if (!output)
		{
			toposort(n);
			if (ans.size() != cnt)
				cout << "IMPOSSIBLE" << endl;
			else
				for (int i = 0; i < ans.size(); ++i)
					cout << ans[i];
		}
	}
	return 0;
}
