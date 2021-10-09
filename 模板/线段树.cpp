//模板题 洛谷P3372
#define _CRT_SECURE_NO_WARNINGS
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 100005
typedef long long ll;
using namespace std;
int n = 0;
//arr读入时下标从1到n
ll tree[maxn * 4] = {0},arr[maxn]={0},mark[maxn * 4] = {0};
void build(int start=1,int end=n,int node=1)
{
	if(start == end)
		tree[node] = arr[start];
	else
	{
		int mid = (start + end) / 2;
		build(start,mid,node * 2);
		build(mid + 1,end,node * 2 + 1);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}
inline void pushdown(int node,int start,int end)
{
	int mid = (start + end) / 2;
	mark[node * 2] += mark[node];
	mark[node * 2 + 1] += mark[node];
	tree[node * 2] += mark[node] * (mid - start + 1);
	tree[node * 2 + 1] += mark[node] * (end - mid);
	mark[node] = 0;
}
void update(int L,int R,int val,int node = 1,int start = 1,int end = n)
{
	if(start > R || end < L)
		return;
	else
	{
		if(L <= start && R >= end)
		{
			tree[node] += val * (end - start + 1);
			if(end > start)
				mark[node] += val;
		}
		else
		{
			int mid = (start + end) / 2;
			pushdown(node,start,end);
			update(L,R,val,node * 2,start,mid);
			update(L,R,val,node * 2 + 1,mid + 1,end);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}
}
ll query(int L,int R,int start = 1,int end = n,int node = 1)
{
	if(end < L || R < start)
		return 0;
	else
	{
		if(start >= L && end <= R)
			return tree[node];
		else
		{
			int mid = (start + end) / 2;
			pushdown(node,start,end);
			return query(L,R,start,mid,node * 2) + query(L,R,mid + 1,end,node * 2 + 1);
		}
	}
}
int main()
{
	int m;
	cin >> n >> m;
	for(int i=1;i<=n;++i)
		cin >> arr[i];
	build();
	for(int i=1;i<=m;++i)
	{
		int op,x,y,k;
		cin >> op;
		if(op == 1)
		{
			cin >> x >> y >> k;
			update(x,y,k);
		}
		else
		{
			cin >> x >> y;
			cout << query(x,y) << endl;
		}
	}
	return 0;
}