#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 100005
using namespace std;
typedef pair<int, int> P;
int main()
{
	int n, d;
	vector<P> arr(maxn);
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	sort(arr.begin(), arr.begin() + n);
	int l = 0, r = -1;
	long long sum = 0;
	long long ans = arr[0].second;
	while (r<=n-1)
	{
		r++;
		sum += arr[r].second;
		while (arr[r].first - arr[l].first >= d)
			sum -= arr[l++].second;
		ans = max(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}