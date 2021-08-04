#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
#define maxn 300005
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, flag = 0;
		scanf("%d", &n);
		getchar();
		string a, b;
		cin >> a >> b;
		if (a == b)
		{
			printf("0\n");
			continue;
		}
		int counta=1;
		int countb = 1;
		if (a[0] > b[0])
		{
			printf("-1\n");
			continue;
		}
		for (int i = 1; i < n; ++i)
		{
			if (a[i] == b[i])
				continue;
			else
			{
				if (a[i] != a[i - 1])
					counta++;
				if (b[i] != b[i - 1])
					countb++;
				if (b[i] < a[i])
				{
					printf("-1\n");
					flag = 1;
					break;
				}
			}
		}
		if (!flag)
			printf("%d\n", max(counta, countb));
	}
	return 0;
}