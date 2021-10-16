#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int rk[N], temp[N], sa[N], height[N];
char s[N];
ll n, k, m;
inline ll rd()
{
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48); ch=getchar();}
	return x*f;
}
bool cmp_sa(int i,int j)
{
	if(rk[i] != rk[j])	return rk[i] < rk[j];
	int ri = i + k <= n ? rk[i + k] : -1;
	int rj = j + k <= n ? rk[j + k] : -1;
	return ri < rj;
}
void cal_sa()
{
	for(int i = 1;i <= n;i++)
	{
		rk[i] = s[i];//按照权值进行排序 
		sa[i] = i;
	}
	for(k = 1;k <= n;k <<= 1)
	{
		sort(sa + 1,sa + n + 1,cmp_sa);
		temp[sa[1]] = 1;
		for(int j = 1;j < n;++j)
			temp[sa[j + 1]] = temp[sa[j]] + (cmp_sa(sa[j],sa[j + 1])?1:0);
		for(int j = 1;j <= n;++j)
			rk[j] = temp[j];
	}
}
void Get_Height()
{
	int k = 0;
	for(int i = 1;i <= n;++i)	
		rk[sa[i]] = i;
	for(int i = 1;i <= n;++i)
	{
		if(rk[i] == 1)	
			continue;
		if(k)	k -= 1;
		int j = sa[rk[i] - 1];
		while(i + k <= n &&j + k <= n && s[j + k] == s[i + k])	
			k += 1;
		height[rk[i]] = k;
	}
}
//对于i，不同子串的数量为 len-sa[i]+1-height[i]

int sum[N], w[30];

ll check(int x)
{
	ll cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int l = sa[i], r = n, ans;
		if(sum[l]-sum[l-1] > x)
			continue;
		while(l <= r)//二分找出从sa[i]开始权值小于等于x的子串
		{
			int mid = (l+r)>>1;
			int t = sum[mid]-sum[sa[i]-1];
			if(t <= x)
				l = mid+1, ans = mid;
			else 
				r = mid-1;
		}
		cnt += max(ans-sa[i]+1-height[i], 0);
	}
	return cnt;
}

void solve()
{
	n = rd(), m = rd();
	scanf("%s", s+1);
	for(int i = 0; i < 26; i++)
		w[i] = rd();
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i-1] + w[s[i]-'a'];
	cal_sa(); Get_Height();
	int l = 0, r = sum[n], ans = sum[n];
	while(l <= r)
	{
		int mid = (l+r) >> 1;
		ll t = check(mid);
		if(t >= m)
			r = mid-1,ans=mid;
		else 
			l = mid+1;
	}
	if(check(ans) < m)
		puts("-1");
	else 
		printf("%lld\n", ans);
}

int main() 
{
	int T;
	for(cin >> T;T--;)
		solve();
	return 0;
}
