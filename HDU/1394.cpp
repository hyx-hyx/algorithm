#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 5000
using namespace std;
int n = 0;
int tree[maxn * 4] = { 0 }, arr[maxn] = { 0 }, mark[maxn * 4] = { 0 };
inline void pushdown(int node, int start, int end)
{
	int mid = (start + end) / 2;
	mark[node * 2] += mark[node];
	mark[node * 2 + 1] += mark[node];
	tree[node * 2] += mark[node] * (mid - start + 1);
	tree[node * 2 + 1] += mark[node] * (end - mid);
	mark[node] = 0;
}
void update(int L, int R, int val, int node = 1, int start = 0, int end = n - 1)
{
	if (start > R || end < L)
		return;
	else
	{
		if (L <= start && R >= end)
		{
			tree[node] += val * (end - start + 1);
			if (end > start)
				mark[node] += val;
		}
		else
		{
			int mid = (start + end) / 2;
			pushdown(node, start, end);
			update(L, R, val, node * 2, start, mid);
			update(L, R, val, node * 2 + 1, mid + 1, end);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}
}
int query(int start, int end, int node, int L, int R)
{
	if (end < L || R < start)
		return 0;
	else
	{
		if (start >= L && end <= R)
			return tree[node];
		else
		{
			int mid = (start + end) / 2;
			pushdown(node, start, end);
			return query(start, mid, node * 2, L, R) + query(mid + 1, end, node * 2 + 1, L, R);
		}
	}
}
int main()
{
	int a[maxn];
	while (scanf("%d", &n) != EOF)
	{
		memset(arr, 0, sizeof(arr));
		memset(tree, 0, sizeof(arr));
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			arr[a[i]]=1;
			update(a[i],a[i],1);
			sum += (i + 1 - query(0, n - 1, 1, 0, a[i]));
		}
		int minans = sum;
		for (int i = 0; i < n - 1; ++i)
		{
			sum += n - 1 - 2 * a[i];
			minans = min(minans, sum);
		}
		printf("%d\n", minans);
	}
	return 0;
}
