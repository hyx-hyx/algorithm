/*
题目大意：
给定整数 1 ， 2 ， ⋯ ， n 把这些数字分成m个不相交的集合，使第j个集合的中位数为bj。确定这是否可能。
注：这题中，偶数个数的集合的中位数取中间两个数中较小的那个。
题目分析：
显然 b1,b2,··· ,bm 这 m 个数要放在 m 个不同的集合中，剩下的 n − m 个数字要放到这 m 个集合里且不影响每个集合的中位数。
使用一个例子以方便说明：假设 n = 6,m = 2,b 1 = 3,b 2 = 5，那么 1,2,··· ,n 这些数会被 b 分成 1,2、4、6 这三段，且任意两段中的任意一对数字可以配对消掉。
所以最后剩下的所有数字一定是同一段内的。
因此讨论两种情况：
• 如果长度最大的段的数字个数不大于其它段的数字个数之和，那么最终要么全部消掉，要么剩下一个，且剩下的这个数可以在任何一段内。
如果会剩下，不妨将最后一段的数字剩下一个，此时再把最后一段的数字放到中位数最小的集合中即可满足题意，所以答案为 YES。
• 如果长度最大的段的数字个数大于其它段的数字个数之和，那么最终剩下的所有数字都在最大的这段内。
设中位数小于这一段的最小值的集合的个数为 x，容易发现当且仅当 x 不小于这一段剩下的数字个数时有解。
时间复杂度 O(n)。
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<assert.h>
using namespace std;
typedef pair<int, int> Pair;
#define maxn 100005
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		vector<Pair> size;
		int n, m, b[maxn];
		int flag[maxn] = { 0 };
		cin >> n >> m;
		for (int i = 1; i <=m; ++i)
			cin >> b[i],flag[b[i]] = 1;
        flag[n + 1] = 1;
		int len = 0, num = 0;
		for (int i = 1; i <=n+1; ++i)
		{
			if (flag[i])
			{
				if (len)
					size.push_back(Pair(len, num));
				len = 0;
				num++;
			}
			else
				len++;
		}
        int sum = 0;
        for (auto s : size)
            sum += s.first;
		if (size.empty())
			cout << "YES" << endl;
		else
		{
			sort(size.begin(), size.end());
			if (size.back().first <=sum - size.back().first+size.back().second)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}