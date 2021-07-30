#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		char c[105];
		scanf("%s", c);
		string s(c);
		if (s[0] != '0')
		{
			printf("NO\n");
			continue;
		}
		int flag = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '+')
			{
				if (s[i + 1] != '0')
				{
					flag = 1;
					printf("NO\n");
					break;
				}
			}
		}
		if (!flag)
			printf("YES\n");
	}
	return 0;
}
