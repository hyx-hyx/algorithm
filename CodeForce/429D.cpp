//直接套模板，模板没问题，不过这题会TLE。。。。。。。。
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 10005
typedef long long ll;
struct pt
{
	int x,y;
	int id;
};
bool cmpx(const pt a,const pt b)
{
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool cmpy(const pt a,const pt b)
{
	return a.y < b.y;
}
ll mindist;
int ansa,ansb;
void upd_ans(const pt& a,const pt& b)
{
	ll dist = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	if(dist < mindist) mindist = dist,ansa = a.id,ansb = b.id;
}
int n;
vector<pt> a(maxn,{-1,-1});
void rec(int l, int r) 
{
  if (r - l <= 3) 
  {
    for (int i = l; i <= r; ++i)
		for(int j = i + 1; j <= r; ++j) upd_ans(a[i],a[j]);
    sort(a.begin() + l, a.begin() + r + 1,cmpy);
    return;
  }
  int m = (l + r) >> 1;
  ll midx = a[m].x;
  rec(l, m), rec(m + 1, r);
  static pt t[maxn];
  merge(a.begin() + l, a.begin() + m + 1, a.begin() + m + 1, a.begin() + r + 1, t, cmpy);
  copy(t, t + r - l + 1, a.begin() + l);

  int tsz = 0;
  for (int i = l; i <= r; ++i)
    if (fabs(a[i].x - midx) < mindist)
	{
      for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
        upd_ans(a[i], t[j]);
      t[tsz++] = a[i];
    }
}
int main()
{
	int n;
	cin >> n;
	int b[maxn];
	int sum[maxn] = {0};
	for(int i = 1; i <=n; ++i)
		cin >> b[i],sum[i] = sum[i - 1] + b[i];
	for(int i = 0; i < n; ++i)
		a[i].x = i + 1,a[i].y = sum[i + 1];
	sort(a.begin(),a.begin() + n,cmpx);
	mindist = 1E20;
	rec(0,n - 1);
	cout << mindist<<endl;
	return 0;
}
//===============================================
//另一种简单做法
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define N 100010
ll a[N];
ll sum[N];
ll ans;

int main()
{
	int n;
	sum[0] = 0;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld",&a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	ans = a[2] * a[2] + 1;
	for(ll i = 1; i < n; i++)
	{
		if(i * i > ans) break;//so  important
		ll t = ans;
		for(int j = i + 1; j <= n; j++)
		{
			t = min(t,(sum[j] - sum[j - i]) * (sum[j] - sum[j - i]));
		}
		ans = min(ans,(t + i * i));
	}
	cout << ans << endl;
}