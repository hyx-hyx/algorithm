#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int main()
{
	int n, a[10005] = { 0 }, dpIncrease[10005] = { 1 }, dpDecline[10005] = {1},ansI=1,ansD=1;
	cin >> n;
	for (int i = 1; i <=n; ++i)
		scanf("%d", &a[i]);
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (a[j] < a[i])
				dpIncrease[i] = max(dpIncrease[j] + 1, dpIncrease[i]);				
			if(a[j]>a[i])
				dpDecline[i] = max(dpDecline[j] + 1, dpDecline[i]);
		}
		ansI = max(ansI, dpIncrease[i]);
		ansD = max(ansD, dpDecline[i]);
	}
	cout << ansI << endl;
	cout << ansD << endl;
	return 0;
}
