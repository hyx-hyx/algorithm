## 题意
[题目链接](https://codeforces.com/problemset/problem/489/B)

有$m$个男孩和$n$个女孩，每个人都有一个舞蹈熟练度，用一个不超过100的正整数来表示。

一个男孩和一个女孩能够结为舞伴当且仅当两人的熟练度相差不超过1.

问最多能结成多少对舞伴

解法：
符合条件的男孩和女孩连边。之后套匈牙利模板

二分图匹配
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
#define maxn 105
int M, N;            //M, N分别表示左、右侧集合的元素数量
int Map[maxn][maxn]; //邻接矩阵存图
int p[maxn];         //记录当前右侧元素所对应的左侧元素
bool vis[maxn];      //记录右侧元素是否已被访问过
bool match(int i)
{
	for (int j = 1; j <= N; ++j)
		if (Map[i][j] && !vis[j]) //有边且未访问
		{
			vis[j] = true;                 //记录状态为访问过
			if (p[j] == 0 || match(p[j])) //如果暂无匹配，或者原来匹配的左侧元素可以找到新的匹配
			{
				p[j] = i;    //当前左侧元素成为当前右侧元素的新匹配
				return true; //返回匹配成功
			}
		}
	return false; //循环结束，仍未找到匹配，返回匹配失败
}
int Hungarian()
{
	int cnt = 0;
	for (int i = 1; i <= M; ++i)
	{
		memset(vis, 0, sizeof(vis)); //重置vis数组
		if (match(i))
			cnt++;
	}
	return cnt;
}
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, boys[105], girls[105];
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> boys[i];
	int m;
	cin >> m;
	for (int i = 1; i <= m; ++i)
		cin >> girls[i];
	for (int i = 1; i <= n; ++i)
	{
		int b = boys[i];
		for (int j = 1; j <= m; ++j)
		{
			if (girls[j] + 1 == b)
				Map[i][j] = 1;
			if (girls[j] - 1 == b)
				Map[i][j] = 1;
			if (girls[j] == b)
				Map[i][j] = 1;
		}
	}

	for (int i = 1; i <=m; ++i)
	{
		int g=girls[i];
		for (int j = 1; j <= n; ++j)
		{
			if (boys[j]== g-1)
				Map[j][i] = 1;
			if (boys[j]== g+1)
				Map[j][i] = 1;
			if (boys[j]== g)
				Map[j][i] = 1;
		}
	}
	M = n;
	N = m;
	cout << Hungarian() << endl;
	return 0;
}
```