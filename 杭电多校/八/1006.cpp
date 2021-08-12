#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 10000005
typedef long long ll;
int prime[maxn];
int visit[maxn];
int num[maxn];
void Prime() {
	memset(visit, 0, sizeof(visit));
	memset(prime, 0, sizeof(prime));
	memset(num, 0, sizeof(num));
	for (int i = 2; i <= maxn; i++) {
		if (!visit[i])
			prime[++prime[0]] = i, num[i] = 1;
		for (int j = 1; j <= prime[0] && i * prime[j] <= maxn; j++) 
		{
			visit[i * prime[j]] = 1;
			num[i * prime[j]] = num[i] + 1;
			if (i % prime[j] == 0)
				break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	Prime();
	while (t--)
	{
		int n;
		cin >> n;
		int ans=0;
		for (int i = 0; i < n; ++i)
		{
			int temp; 
			cin >> temp;
			ans ^=num[temp];
		}
		if (ans)
			cout << "Alice" << endl;
		else
			cout << "Bob" << endl;
	}
	return 0;
}

