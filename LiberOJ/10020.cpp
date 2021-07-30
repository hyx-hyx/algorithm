#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include <vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
int n;
vector<int> wood(60);
bool success = false;
int vis[60];
int L;
bool cmp(int x, int y)
{
	return x > y;
}
void dfs(int num, int len,int stat)
{
	if (!num)
	{
		if(!len)
			success = true;
		return ;
	}
	if (!len && num)
	{
		len = L;
		stat = 0;
	}
	for (int i = stat; i<n ;++i)
	{
		if (!vis[i]&&(len-wood[i])>=0)
		{
			vis[i] = 1;
			dfs(num - 1, len - wood[i],stat+1);
			if (success)
				return;
			vis[i] = 0;
			if(len==L)
				break;
			while (wood[i] == wood[i + 1])
				i++;
		}
	}
}
int main()
{
	int sum=0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &wood[i]);
		sum += wood[i];
	}
	sort(wood.begin(), wood.begin()+n,cmp);
	for (L = wood[0]; L <= sum; ++L)
	{
		if (sum % L)
			continue;
		dfs(n, L,0);
		if (success)
		{
			printf("%d", L);
			break;
		}
	}
	return 0;
}
