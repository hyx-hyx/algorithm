#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int main()
{
	vector<int> a(105,0);
	int ans[7][2] = { 0 };
	int t;
	scanf("%d", &t);
	int d = 0;
	int count = 6;
	int mini=105, maxi=0;
	while (t--)
	{
		d++;
		mini = 105;
		maxi = 0;
		a.assign(105, 0);
		string s;
		count = 6;
		for (int i = 0; i < 30; ++i)
		{
			getchar();
			for (int j = 0; j < 100; ++j)
			{
				char c = getchar();
				if (c == '#')
					a[j] = 1;
			}
		}
		printf("Case #%d:\n",d);
		int flag = 0;
		int i;
		for (i = 99; i >=0; --i)
		{
			if (a[i])
			{
				flag = 1;
				maxi = max(maxi, i);
			}
			if (!a[i] && flag)
			{
				ans[count][0] = (min(mini, i)+2);
				ans[count--][1] = (maxi+1);
				mini = 105;
				maxi = 0;
				flag = 0;
			}
			if (count == 0)
				break;
		}
		for (int j = i-1; j >= 0; --j)
			if (a[j] == 1)
			{
				ans[0][1] = (j + 1);
				break;
			}
		for (int j = 0; j <i; ++j)
			if (a[j] == 1)
			{
				ans[0][0] = (j + 1);
				break;
			}
		for (int i = 0; i < 7; ++i)
			printf("%d %d\n", ans[i][0], ans[i][1]);
	}
	return 0;
}
