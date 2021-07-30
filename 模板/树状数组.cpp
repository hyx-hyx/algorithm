#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 300005
#define lowbit(x) ((x)&(-x))
using namespace std;
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
    return 0;
}
