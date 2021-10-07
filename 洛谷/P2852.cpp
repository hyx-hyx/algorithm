//给定一串数字，取其中长度大于等于K的子串，求可以取的所有子串的最大长度。
/*这题是一道后缀数组的模板题。
出现k次，相当于我们选择了k个后缀，之后求出他们的最长公共前缀。
我们知道，后缀(j)和后缀(k)的 最 长 公 共 前 缀 为height[rank[j]+1],
height[rank[j]+2],height[rank[j]+3],…,height[rank[k]]中的最小值(设rank[j]<rank[k])。
那么设k个后缀中rank的min=l，max=r，k个的最长公共前缀就是min(height[l+1->r])
所以k个后缀在rank上一定是连续的。
枚举i，维护height[i->i+k-1]的min，用单调队列即可O(N)解决。(还要加上求出rank,height的时间)
*/
//后缀数组加单调队列
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 20005;
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
	int N,K;
	cin >> N >> K;
	for(int i = 1; i <=N; ++i)
	{
		int c;
		cin >> c;
		s[i] = c + '0';
	}
	getsa();
	getht();
	deque<int> Q;
	int ans = 0;
	for(int i = 2; i <= n; ++i)
	{	
		if(!Q.empty() && i - Q.front() >= K-1)
			Q.pop_front();
		while(!Q.empty() && ht[Q.back()] > ht[i])
			Q.pop_back();
		Q.push_back(i);
		ans = max(ans,ht[Q.front()]);
	}
	cout << ans << endl;
	return 0;
}