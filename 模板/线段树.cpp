//模板题 洛谷P3372
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
using namespace std;
const int M = 100005;
int a[M] = {0};
struct segment_tree
{
	int l,r;
	ll sum,maxn,mark = 0;
}tr[M*4];
void pushup(int n)
{
	tr[n].sum = tr[n << 1].sum + tr[n << 1 | 1].sum;
	tr[n].maxn = max(tr[n << 1].maxn ,tr[n << 1 | 1].maxn);
}
void build(int n,int l,int r)
{
	tr[n].l = l,tr[n].r = r;
	if(tr[n].l == tr[n].r)
		tr[n].sum = a[l],tr[n].maxn = a[l];
	else
	{
		int mid = (l + r) >> 1;
		build(n << 1,l,mid);
		build(n << 1|1,mid+1,r);
		pushup(n);
	}
}
void pushdown(int n)
{
	int mid = (tr[n].l + tr[n].r) >> 1;
	tr[n << 1].mark += tr[n].mark;
	tr[n << 1 | 1].mark += tr[n].mark;
	tr[n << 1].sum += tr[n].mark * (mid - tr[n].l + 1);
	tr[n << 1|1].sum += tr[n].mark * (tr[n].r-mid);
	tr[n].mark = 0;
}
void update(int n,int l,int r,int v)
{
	if(tr[n].l >= l && tr[n].r <= r)
		tr[n].sum += v * (tr[n].r - tr[n].l + 1),tr[n].mark += v;
	else
	{
		int mid = (tr[n].l+tr[n].r) >> 1;
		pushdown(n);
		if(l <= mid)
			update(n<<1,l,r,v);
		if(r > mid)
			update(n << 1 | 1,l,r,v);
		pushup(n);
	}
}
ll query(int n,int l,int r)
{
	if(tr[n].l >=l&&tr[n].r<=r)
		return tr[n].sum;
	else
	{
		ll ret = 0;
		int mid = (tr[n].l + tr[n].r) >> 1;
		pushdown(n);
		if(l <= mid)
			ret+=query(n << 1,l,r);
		if(r > mid)
			ret+=query(n << 1 | 1,l,r);
		return ret;
	}
}
int main()
{
	int m,n;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	build(1,1,n);
	for(int i = 1; i <= m; ++i)
	{
		int op,x,y,k;
		cin >> op;
		if(op == 1)
		{
			cin >> x >> y >> k;
			update(1,x,y,k);
		}
		else
		{
			cin >> x >> y;
			cout << query(1,x,y) << endl;
		}
	}
	return 0;
}