#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int main()
{
	int L = 0, R = 0, U = 0, D = 0,t,x,y;
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		scanf("%d%d", &x, &y);
		getchar();
		L = 0, R = 0, U = 0, D = 0;
		char ch=0;
		while (ch != '\n')
		{
			ch = getchar();
			if (ch == 'L')
				L++;
			if (ch == 'R')
				R++;
			if (ch == 'U')
				U++;
			if (ch == 'D')
				D++;
		}
		if(x>=0)
		{
			if (R < x)
			{
				printf("NO\n");
				continue;
			}
		}
		else
		{
			if (L < -x)
			{
				printf("NO\n");
				continue;
			}
		}
		if (y >= 0)
		{
			if (U < y)
			{
				printf("NO\n");
				continue;
			}
		}
		else
		{
			if (D < -y)
			{
				printf("NO\n");
				continue;
			}
		}
		printf("YES\n");		
	}
	return 0;
}