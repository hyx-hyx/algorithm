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
const int M = 200005;
int a[M] = {0};
struct segment_tree
{
	int l,r;
	ll sum=0,maxn=0,mark = 0;
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
		tr[n].sum = tr[n].maxn = a[l];
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
	tr[n << 1].maxn += tr[n].mark;
	tr[n << 1 | 1].maxn += tr[n].mark;
	tr[n].mark = 0;
}
//单点更新 p为下标，a[p]=x;
void change(int n,int p,int x)
{
	if(tr[n].l == tr[n].r)
		tr[n].sum = tr[n].maxn=x;
	else
	{
		int mid = (tr[n].l + tr[n].r) >> 1;
		if(p <= mid)
			change(n << 1,p,x);
		else
			change(n << 1 | 1,p,x);
		pushup(n);
	}
}
void change_range(int n,int l,int r,int v)
{
	if(tr[n].l >= l && tr[n].r <= r)
		tr[n].sum = max(tr[n].sum,(ll)(tr[n].r - tr[n].l + 1) * v);
	else
	{
		int mid = (tr[n].l + tr[n].r) >> 1;
		if(l <= mid) change_range(n << 1,l,r,v);
		if(r > mid) change_range(n << 1 | 1,l,r,v);
		pushup(n);
	}
}
void update(int n,int l,int r,int v)
{
	if(tr[n].l >= l && tr[n].r <= r)
		tr[n].sum += v * (tr[n].r - tr[n].l + 1),tr[n].mark += v,tr[n].maxn+=v;
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
ll query_max(int n,int l,int r)
{
	if(tr[n].l >= l && tr[n].r <= r)
		return tr[n].maxn;
	else
	{
		ll ans = 0;
		int mid = (tr[n].l + tr[n].r) >> 1;
		if(l <= mid)
			ans=max(query_max(n << 1,l,r),ans);
		if(r > mid)
			ans=max(query_max(n << 1 | 1,l,r),ans);
		return ans;
	}
}
int main()
{
	int m,n;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(tr,0,sizeof tr);
		memset(a,0,sizeof a);
		for(int i = 1; i <= n; ++i)
			scanf("%d",&a[i]);
		build(1,1,n);
		for(int i = 1; i <= m; ++i)
		{
			char op;
			getchar();
			scanf("%c",&op);
			if(op == 'U')
			{
				int A,B;
				scanf("%d%d",&A,&B);
				change(1,A,B);
			}
			else
			{
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%lld\n",query_max(1,x,y));
			}
		}
	}
	return 0;
}
