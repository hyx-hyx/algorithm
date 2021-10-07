#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		int A[405][405] = {0};
		int sumrow[405][405] = {0},sumcol[405][405] = {0};
		cin >> n >> m;
		for(int i = 1; i <= n; ++i)
		{
			string s;
			cin >> s;
			for(int j = 1; j <= m; ++j)
			{
				A[i][j] = s[j - 1] - '0';
				sumcol[i][j] += sumcol[i][j - 1] + A[i][j];
				sumrow[i][j] += sumrow[i - 1][j] + A[i][j];
			}
		}
		int ans = 0x3f3f3f3f;
		for(int a = 5; a <= n; ++a)
		{
			for(int b = 4; b <= m; ++b)
			{
				for(int j = 4; j < a; ++j)
				{
					for(int k = 3; k < b; ++k)
					{
						int bnum = sumrow[a - 1][b] - sumrow[a - j][b] + sumrow[a - 1][b - k-1] - sumrow[a - j][b - k-1];
						int anum = sumcol[a - j-1][b - 1] - sumcol[a - j-1][b - k] + sumcol[a][b - 1] - sumcol[a][b - k];
						int sum = 0;
						for(int i = a - j + 1; i < a; ++i)
							sum += (sumcol[i][b - 1] - sumcol[i][b - k]);
						int temp = ((b - 2) * 2 + 2 * (a - 2) + sum - bnum - anum);
						ans = min(ans,((b - 2) * 2 + 2 * (a - 2) + sum - bnum - anum));
					}
				}
			}
		}
		cout << ans << endl;
	}
}