#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	double n_d = (double)n;
	int x = (int)((n_d * n_d - 3 * n_d) / 2) + 1;
	int ans=x / 3;
	if (x % 3)
		ans++;
	printf("%d\n", ans);
	int i = 0;
	while (ans--)
	{
		i+=3;
		printf("%d %d %d\n", i-2,i-1,i);
	}
	return 0;
}
