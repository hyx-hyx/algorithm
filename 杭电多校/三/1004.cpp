#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#include<algorithm>
#define maxn 100005
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
typedef pair<int, int> P;
vector<P> a(maxn);
int main()
{
	int t, kind[maxn] = {0}; //kind下标i对应直线出现的次数，值对应有多少种出现了i次的直线。
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			int dx = x2 - x1, dy = y2 - y1;
			if (dx == 0) dy = 1;
			else
			{
				if (dy == 0) 
					dx = 1;
				else
				{
					if (dx < 0) dx = -dx, dy = -dy;
					int d = gcd(abs(dx), abs(dy));
					dx /= d;
					dy /= d;
				}
			}
			a[i] = P(dx, dy);
		}
		sort(a.begin(), a.begin() + n);
		int j;
		for (int i = 0; i < n; ++i)
			kind[i] = 0;
		for (int i = 0; i < n; i=j)
		{
			for (j = i; j < n && a[i] == a[j]; ++j);
			for (int k = 0; k <=j - i; ++k)
				kind[k]++;
		}
		for (int i = 0; i < n; ++i)
		{
			int j = 0;
			while (!kind[j])
				j++;
			kind[j]--;
			printf("%d\n", i - j);
		}
	}
	return 0;
}
