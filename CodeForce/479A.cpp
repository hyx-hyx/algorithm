#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int main()
{
	int a, b, c,ans;
	scanf("%d%d%d", &a, &b, &c);
	if (a >= c)
	{
		ans = max(b + c, b * c);
		if (a == 1)
			printf("%d\n", ans + 1);
		else
			printf("%d\n", ans * a);
	}
	else
	{
		ans = max(a + b, a * b);
		if (c == 1)
			printf("%d\n", ans + 1);
		else
			printf("%d\n", ans * c);
	}
	return 0;
}