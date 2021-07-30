#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int n = 0;
inline void pushdown(int node, int start, int end,vector<int> &tree,vector<int>& mark)
{
	int mid = (start + end) / 2;
	mark[node * 2] += mark[node];
	mark[node * 2 + 1] += mark[node];
	tree[node * 2] += mark[node] * (mid - start + 1);
	tree[node * 2 + 1] += mark[node] * (end - mid);
	mark[node] = 0;
}
void update(vector<int> &tree,vector<int> &mark,int L, int R, int val, int node = 1, int start = 0, int end = n - 1)
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
			pushdown(node, start, end,tree,mark);
			update(tree,mark,L, R, val, node * 2, start, mid);
			update(tree,mark,L, R, val, node * 2 + 1, mid + 1, end);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}
}
int query(vector<int> &tree,vector<int>& mark,int start, int end, int node, int L, int R)
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
			pushdown(node, start, end,tree,mark);
			return query(tree,mark,start, mid, node * 2, L, R) + query(tree,mark,mid + 1, end, node * 2 + 1, L, R);
		}
	}
}
int main()
{
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		else
		{
			vector<int> tree(n * 4, 0);
			vector<int> mark(n * 4, 0);
			for (int i = 0; i < n; ++i)
			{
				int a, b;
				scanf("%d%d", &a, &b);
				update(tree,mark,a - 1, b - 1, 1);
			}
			for (int i = 0; i < n-1; ++i)
				printf("%d ", query(tree,mark,0, n - 1, 1, i, i));
			printf("%d", query(tree, mark, 0, n - 1, 1, n - 1, n - 1));
		}
		printf("\n");
	}
	return 0;
}