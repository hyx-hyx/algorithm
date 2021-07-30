#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int main()
{
	int a, b,n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		int ans = a + b;
		if (ans > 1023)
			ans -= 2048;
		if (ans < -1024)
			ans += 2048;
		printf("%d\n", ans);
	}
	return 0;
}
