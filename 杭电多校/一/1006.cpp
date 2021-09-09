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
#include<bitset>
using namespace std;
typedef long long ll;
//========================================================
const int maxn = 3e6 + 5;//不同节点的不同字符的数量，一般取字符串的个数乘以长度。
int nexti[maxn][2],index_num[maxn];
int cnt;
void init()
{
	memset(nexti,0,sizeof(nexti));
	memset(index_num,0,sizeof(index_num));
	cnt = 1;
}
void insert(int n,int index)
{
	int cur = 1;
	for(int i = 31; i >= 0; --i)
	{
		int bit = n >> i & 1;
		if(!nexti[cur][bit])
			nexti[cur][bit] = ++cnt;
		cur = nexti[cur][bit];
	}
	index_num[cur] = index;
}
int findans(int s,int k)
{
	int cur = 1;
	for(int i = 31; i >= 0; --i)
	{
		int kbit = k >> i & 1;
		int sbit = s >> i & 1;
		if(kbit)
			if(nexti[cur][sbit ^ 1])
				cur = nexti[cur][sbit ^ 1];
			else
				return -1;
		else
		{
			if(nexti[cur][sbit ^ 1])
				return index_num[cur];
			else
				if(nexti[cur][sbit ^ 0])
					cur = nexti[cur][sbit ^ 0];
				else
					return -1;
		}
	}
	return (index_num[cur]==0?-1:index_num[cur]);
}
//====================================================================
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		init();
		int n,k;
		int a[100005] = {0},sum[100005] = {0};
		cin >> n >> k;
		pair<int,int> ans = {1,n};
		int flag = 0;
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		for(int i = 1; i <= n; ++i)
		{
			if(a[i] >= k)
			{
				flag = 1;
				cout << i << " " << i << endl;
				break;
			}
			else
			{
				sum[i] = sum[i - 1] ^ a[i];
				if(i > 1)
				{
					int ans_temp = findans(sum[i],k);
					if(ans_temp != -1)
					{
						if((i - ans_temp) < (ans.second - ans.first))
							ans.first = ans_temp,ans.second = i;
						else
						{
							if((i - ans_temp) == (ans.second - ans.first))
								if(ans_temp < ans.first)
									ans.first = ans_temp,ans.second = i;
						}
					}
				}
				insert(sum[i],i);
			}
		}
		if(!flag)
			cout << ans.first << " " << ans.second << endl;
	}
	return 0;
}