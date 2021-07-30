#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 100000
using namespace std;
void build(int arr[], int tree[], int node, int start, int end)
{
	if (start == end)
		tree[node] = arr[start];
	else
	{
		int mid = (start + end) / 2;
		int left_node = 2 * node + 1;
		int right_node = 2 * node + 2;
		build(arr, tree, left_node, start, mid);
		build(arr, tree, right_node, mid + 1, end);
		tree[node] = tree[left_node] + tree[right_node];
	}
}
void update(int arr[], int tree[], int node, int start, int end, int index, int val)
{
	if (start == end)
	{
		arr[index] = val;
		tree[node] = val;
	}
	else
	{
		int mid = (start + end) / 2;
		int left_node = 2 * node + 1;
		int right_node = 2 * node + 2;
		if (start <= index && mid >= index)
			update(arr, tree, left_node, start, mid, index, val);
		else
			update(arr, tree, right_node, mid + 1, end, index, val);
		tree[node] = tree[left_node] + tree[right_node];
	}
}
int query(int arr[],int tree[],int node,int start, int end,int L,int R)
{
	if (R<start || L>end)
		return 0;
	if (L == R)
		return arr[L];
	else
	{
		int mid = (start + end) / 2;
		int left_node = 2 * node + 1;
		int right_node = 2 * node + 2;
		if (L == start && R == end)
			return tree[node];
		if (L <= mid && R > mid)
			return query(arr, tree, left_node, start, mid, L, mid) + query(arr, tree, right_node, mid + 1, end, mid + 1, R);
		else
			if (L > mid)
				return query(arr, tree, right_node, mid + 1, end, L, R);
			else
				return query(arr, tree, left_node, start, mid, L, R);
	}
}
int main()
{
	int arr[maxn];
	int tree[1000000];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	build(arr, tree, 0, 0, n-1);
	for (int i = 0; i < m; ++i)
	{
		int opt,x,y,k;
		scanf("%d", &opt);
		if (opt == 1)
		{
			scanf("%d%d%d", &x, &y, &k);
			for (int j = x-1; j <= y-1; ++j)
				update(arr, tree, 0, 0, n - 1, j, arr[j]+k);
		}
		else
		{
			scanf("%d%d", &x, &y);
			printf("%d\n",query(arr, tree, 0, 0, n-1, x-1, y-1));
		}
	}
	
	return 0;
}
