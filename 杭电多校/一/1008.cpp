#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2e3 + 10;

int arr[N][N];
int val[N][N];
int L[N][N];
int R[N][N];

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) 
	{
		int n;
		int m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= m; j++) 
			{
				scanf("%d", &arr[i][j]);
				val[i][j] = 1;
				if (arr[i][j] >= arr[i - 1][j]) val[i][j] = val[i - 1][j] + 1;
				L[i][j] = R[i][j] = j;
			}
		for (int i = 2; i <= n; i++) 
			for (int j = 1; j <= m; j++) 
				while (L[i][j] > 1 && val[i][j] <= val[i][L[i][j] - 1]) L[i][j] = L[i][L[i][j] - 1];//L[i][j]向左可以到的地方

		for (int i = 2; i <= n; i++) 
			for (int j = m; j; j--) 
				while (R[i][j] < m && val[i][j] <= val[i][R[i][j] + 1]) R[i][j] = R[i][R[i][j] + 1];

		int ans = m;
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= m; j++) 
				ans = max(ans, val[i][j] * (R[i][j] - L[i][j] + 1));
		printf("%d\n", ans);
	}
	return 0;
}