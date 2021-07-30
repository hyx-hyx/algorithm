#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int main()
{
	int a, b,t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		scanf("%d%d", &a, &b);
		int temp = abs(b - a);
		if(temp%10)
			printf("%d\n", temp / 10 + 1);
		else
			printf("%d\n", temp / 10)   ;
	}
	return 0;
}