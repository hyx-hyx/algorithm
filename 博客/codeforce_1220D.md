## 题意
[链接](https://codeforces.com/problemset/problem/1220/D)

首先给你一个集合B，定义一个图是由所有整数集合为顶点，若i，j为整数，且 $abs(i-j)$在集合 B 之中，那么图中存在一条连接 i，j 的无向边。问至少去掉 B 中多少个元素才能使这张图为一个二分图。
## 分析
用到了判定二分图的基本方法：不存在奇环。

如何让这个图不存在奇环？

我们考虑起点为 0，如果 B 中存在整数 a， 那么 0 与 a 之间有一条边，a 与 2 * a 之间也有一条边，如果这时 B 中还存在着整数 2 * a，那么这时 0，a，2 * a 这三个点就形成了奇环。

考虑到这里，我们发现，如果我们已经选中了一个数 a，那么要不存在奇环，只有将 a / 2（a % 2 == 0） ， a / 4（a % 4 == 0）…… ，a * 2 ，a * 4，…… 全部删去。

但这样思考却很难求出答案，那就只有换一个思考方向，想一想如果选中了 a，那么哪些数可以保留，不难发现，只有和 a 同次数（不停的除以 2，直到无法除尽或等于 0 为止，这样操作的次数）的数才能和 a 一起保留。因为这样的话，这些数中就不会出现翻倍的关系。

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
#define maxn 200005
typedef long long ll;
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	vector<ll> b(maxn);
	vector<ll> cnt(maxn,0);
	vector<ll> num(63,0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	for (int i = 0; i < n; ++i)
	{
		ll temp = b[i];
		while (temp && temp % 2 == 0)
		{
			cnt[i]++;
			temp /= 2;
		}
		num[cnt[i]]++;
	}
	int id = 0;
	for (int i = 0; i < 63; ++i)
		if (num[i] > num[id])
			id = i;
	cout << n - num[id]<<endl;
	for (int i = 0; i < n; ++i)
		if (cnt[i] != id)
			cout << b[i]<<" ";
	return 0;
}
```