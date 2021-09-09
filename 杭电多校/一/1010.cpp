#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1e5+10;
int T,n,m,k,a[maxn],num[maxn],sum[maxn],ans[maxn];
struct da{int l,r,L,R,id;}q[maxn];
bool cmp(da aa,da bb){
        if (aa.l/k==bb.l/k){
                if ((aa.l/k)&1) return aa.r<bb.r;else return aa.r>bb.r;
       }
        return aa.l/k<bb.l/k;
}
void add(int x) {if (++num[x]==1) sum[x/k]++;}
void dec(int x) {if (--num[x]==0) sum[x/k]--;}
int calc(int x){
        int now=0;
        for (int i=0;i<x/k;i++) now+=sum[i];
        for (int i=(x/k)*k;i<=x;i++) now+=(num[i]>=1);
        return now;
}
void solve(){
        memset(num,0,sizeof num); memset(sum,0,sizeof sum); scanf("%d%d",&n,&m); k=313;
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=m;i++) scanf("%d%d%d%d",&q[i].l,&q[i].L,&q[i].r,&q[i].R),q[i].id=i;
        sort(q+1,q+m+1,cmp); int pl=q[1].l,pr=q[1].r;
        for (int i=pl;i<=pr;i++) add(a[i]);
        ans[q[1].id]=calc(q[1].R)-calc(q[1].L-1);
        for (int i=2;i<=m;i++){
                while (pl>q[i].l) pl--,add(a[pl]);
                while (pr<q[i].r) pr++,add(a[pr]);
                while (pl<q[i].l) dec(a[pl]),pl++;
                while (pr>q[i].r) dec(a[pr]),pr--;
                ans[q[i].id]=calc(q[i].R)-calc(q[i].L-1);
        }
        for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
}
int main(){
		freopen("1.in","r",stdin);
		freopen("1.out","w",stdout);
        scanf("%d",&T); while (T--) solve();
return 0;
}
//============================================================
//自己写的，未通过，以后补（或许）
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
int cur=0;
const int MAXQ = 100005;
int sq,sum[maxn],index[maxn];
struct query // 把询问以结构体方式保存
{
	int x0,y0,x1,y1,id;
	bool operator<(const query& o) const // 重载<运算符，奇偶化排序
	{
		if(x0 / sq != o.x0 / sq)
			return x0 < o.x0;
		if(x0 / sq & 1)
			return x1 < o.x1;
		return  x1 > o.x1;
	}
} Q[MAXQ];
const int SQ = 400;
int f[maxn],st[SQ],ed[SQ],bel[maxn];
void init_block(int n)
{
	sq = sqrt(n);
	for(int i = 1; i <= sq; ++i)
	{
		st[i] = n / sq * (i - 1);
		ed[i] = n / sq * i;
	}
	ed[sq] = n;
	for(int i = 1; i <= sq; ++i)
		for(int j = st[i]; j <= ed[i]; ++j)
			bel[j] = i;
}
int query(int x,int y)
{
	int ans = 0;
	if(bel[x] == bel[y])
		for(int i = x; i <= y; ++i)
			ans += (index[i]==0?0:1);
	else
	{
		for(int i = x; i <= ed[bel[x]]; ++i)
			ans += (index[i] == 0 ? 0 : 1);
		for(int i = st[bel[y]]; i <= y; ++i)
			ans += (index[i] == 0 ? 0 : 1);
		for(int i = bel[x] + 1; i < bel[y]; ++i)
			ans += sum[i];
	}
	return ans;
}
void add(int p)
{
	index[f[p]]++;
	if(index[f[p]]==1)
		cur++;
}
void del(int p)
{
	index[f[p]]--;
	if(!index[f[p]])
		cur--;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,m,ans[MAXQ] = {0},sum[SQ] = {0};
		cin >> n >> m;
		int maxv = 0;
		init_block(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> f[i],index[f[i]]++;
			if(index[f[i]] == 1)
				sum[bel[f[i]]]++;
		}
		int maxx = 0;
		for(int i = 0; i < m; ++i)
		{
			cin >> Q[i].x0 >> Q[i].y0 >> Q[i].x1 >> Q[i].y1;
			maxx = max(Q[i].x1,maxx);
			Q[i].id = i;
		}
		sort(Q,Q + m);
		int l = 1,r = maxx;
		for(int i = 0; i < m; ++i)
		{
			cur = query(Q[i].y0,Q[i].y1);
			while(l > Q[i].x0)
				add(--l);
			while(r < Q[i].x1)
				add(++r);
			while(l < Q[i].x0)
				del(l++);
			while(r > Q[i].x1)
				del(r--);
			ans[Q[i].id] = cur; // 储存答案
		}
		for(int i = 0; i < m; ++i)
			cout << ans[i] << endl;
	}
	return 0;
}