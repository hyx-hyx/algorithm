//分块知识点网址：https://zhuanlan.zhihu.com/p/114268236
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#define maxn 50005
#define SQ 230
using namespace std;
int a[maxn], st[SQ], ed[SQ], bel[maxn], b_size[maxn], mark[maxn] = {0};
vector<int> v[SQ];
void init_block(int n)
{
	int sq = sqrt(n);
	for (int i = 1; i <= sq; ++i)
	{
		st[i] = n / sq * (i - 1) + 1;
		ed[i] = n / sq * i;
	}
	ed[sq] = n;
	for (int i = 1; i <= sq; ++i)
		for (int j = st[i]; j <= ed[i]; ++j)
			bel[j] = i;
	for (int i = 1; i <= sq; ++i)
		b_size[i] = ed[i] - st[i] + 1;
}
void update(int b)
{
	for (int i = 0; i <b_size[b]; ++i)
		v[b][i] =a[st[b]+i];
	sort(v[b].begin(), v[b].end());
}
int main()
{
	int n;
	cin >> n;
	int sq = sqrt(n);
	init_block(n);
	for (int i = 1; i <=n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= sq; ++i)
		for (int j = st[i]; j <= ed[i]; ++j)
			v[i].push_back(a[j]);
	for (int i = 1; i <= sq; ++i)
		sort(v[i].begin(), v[i].end());
	for (int i = 0; i < n; ++i)
	{
		int opt, l, r, c;
		scanf("%d%d%d%d", &opt, &l, &r, &c);
		if (!opt)
		{
			if (bel[l] == bel[r])
			{
				for (int j = l; j <= r; ++j)
					a[j] += c;
				update(bel[l]);
			}		
			else
			{
				for (int j = l; j <= ed[bel[l]]; ++j)
					a[j] += c;
				for (int j = st[bel[r]]; j <=r; ++j)
					a[j] += c;
				update(bel[l]);
				update(bel[r]);
				for (int j = bel[l] + 1; j < bel[r]; ++j)
					mark[j] += c;
			}
		}
		else
		{
			if (bel[l] == bel[r])
			{
				int count=0;
				for (int j = l; j <= r; ++j)
					if (a[j] + mark[bel[l]] < (c * c))
						count++;
				printf("%d\n", count);
			}
			else
			{
				int count=0;
				for (int j = l; j <= ed[bel[l]]; ++j)
					if (a[j] + mark[bel[l]] < (c*c))
						count++;
				for (int j = st[bel[r]]; j <= r; ++j)
					if (a[j] + mark[bel[r]] < (c*c))
						count++;
				for (int j = bel[l] + 1; j < bel[r]; ++j)
					count += lower_bound(v[j].begin(), v[j].end(), (c*c) - mark[j])-v[j].begin();
				printf("%d\n", count);
			}
		}
	}
	return 0;
}
