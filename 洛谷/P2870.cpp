#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1000010;
char s[N]; //原字符串
int n,sa[N],rk[N],oldrk[N << 1],id[N],px[N],cnt[N];
int ht[N];
// px[i] = rk[id[i]]（用于排序的数组所以叫 px）
bool cmp(int x,int y,int w)
{
	return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
}
void getsa()
{
	int i,m = 300,p,w;
	n = strlen(s + 1);
	for(i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
	for(i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	for(i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;

	for(w = 1;; w <<= 1,m = p)
	{  // m=p 就是优化计数排序值域
		for(p = 0,i = n; i > n - w; --i) id[++p] = i;
		for(i = 1; i <= n; ++i)
			if(sa[i] > w) id[++p] = sa[i] - w;
		memset(cnt,0,sizeof(cnt));
		for(i = 1; i <= n; ++i) ++cnt[px[i] = rk[id[i]]];
		for(i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
		for(i = n; i >= 1; --i) sa[cnt[px[i]]--] = id[i];
		memcpy(oldrk,rk,sizeof(rk));
		for(p = 0,i = 1; i <= n; ++i)
			rk[sa[i]] = cmp(sa[i],sa[i - 1],w) ? p : ++p;
		if(p == n)
		{
			for(int i = 1; i <= n; ++i) sa[rk[i]] = i;
			break;
		}
	}
}
void getht()
{
	for(int i = 1,k = 0; i <= n; ++i)
	{
		if(k) --k;
		while(s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
		ht[rk[i]] = k;  // height太长了缩写为ht
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <=n; ++i)
		cin >> s[i];
	s[n + 1] = '#';
	for(int i = 1; i <=n; ++i)
		s[2*n+2-i] = s[i];
	getsa();
	int l = 1,r = n;
	n = 2 * n + 1;
	int i = 0;
	while(l != r)
	{
		cout<<(rk[l] < rk[n + 1 - r] ? s[l++] : s[r--]);
		i++;
		if(i == 80)
			cout << "\n",i = 0;
	}
	cout << s[l];
	return 0;
}