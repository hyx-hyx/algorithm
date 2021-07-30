#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 105
using namespace std;
int main()
{
	int n;
	vector<int> a(maxn, 0);
	vector<int> ans(maxn, -1);
	cin >> n;
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a.begin(), a.begin() + n);
	int index1 = 0, index2 = n - 1;
	int aindex = 0;
	while (aindex<n)
	{
		ans[index1] = a[aindex];
		if(aindex+1<n)
			ans[index2] = a[aindex + 1];
		aindex += 2;
		index1++;
		index2--;
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	return 0;
}