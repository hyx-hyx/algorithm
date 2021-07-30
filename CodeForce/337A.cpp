#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#include<algorithm>
#define maxn 55
using namespace std;
int main()
{
	int n, m;
	vector<int> a(maxn, 0);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
		scanf("%d", &a[i]);
	sort(a.begin(), a.begin() + m);
	int result=10000;
	for (int i = 0; i <=m-n; ++i)
		result = min(result, a[i + n-1] - a[i]) ;
	printf("%d\n", result);
	return 0;
}