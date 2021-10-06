/*
I-Inverse Pair
题意
对序列的元素+1或者+0，构造出新的序列，求经过这个操作后，此序列的最小逆序对。
题解：
对序列求出原来的逆序对个数，用pos数组存储每个数对应的在序列中的位置，然后按数值从小到大依次访问。
如果pos[i]>pos[i-1],则排列为顺序，反之为逆序。
使用flag标志表示该位的逆序对是否被修改。
若逆序且flag为0，我们将逆序对个数减一，代表我们通过+1操作使逆序对减少。若flag=1，则不操作。
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
#define maxn 205
#define lowbit(x) ((x)&(-x))
int tree[maxn];
inline void update(int i, int x)
{
	for (int pos = i; pos < maxn; pos += lowbit(pos))
		tree[pos] += x;
}
inline int query(int n)
{
	int ans = 0;
	for (int pos = n; pos; pos -= lowbit(pos))
		ans += tree[pos];
	return ans;
}
inline int query(int a, int b)
{
	return query(b) - query(a - 1);
}
int main()
{
	int n;
	long long ans = 0;
	scanf("%d",&n);
	int a[maxn] = { 0 }, pos[maxn] = {0};
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		update(a[i],1);
		pos[a[i]] = i;
		ans +=(long long)query(n) -(long long)query(a[i]);
	}
	int flag = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (pos[i] > pos[i - 1])
			flag = 0;
		else
		{
			if (flag==1)
				flag = 0;
			else
			{
				ans--;
				flag = 1;
			}
		}
	}
	printf("%lld\n", ans); 
	return 0;
}
