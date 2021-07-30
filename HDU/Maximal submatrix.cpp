#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int T, N, M;
const int MaxN = 2001, MaxM = 2001;
int m[MaxN][MaxM];
int s[MaxN][MaxM];
int dp[MaxN][MaxM];
int minarr[MaxN][MaxM];
int row[MaxN];
int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		cin >> M;
		for (int i = 0; i < N; ++i) 
		{
			int count = 0;
			for (int j = 0; j < M; ++j) 
			{
				// cin >> m[i][j];
				scanf("%d", &m[i][j]);
				if (i == 0)
					s[i][j] = 1;
				else
				{
					if (m[i][j] >= m[i - 1][j])
					{
						s[i][j] = s[i - 1][j] + 1;
						count++;
					}
					else
						s[i][j] = 1;
				}
			}
			row[i] = count;
		}
		dp[0][0] = 1;
		minarr[0][0] = 1;
		dp[0][1] = 2;
		minarr[0][1] = 1;
		dp[1][0] = s[1][0];
		minarr[1][0] = 2;

		for (int i = 1; i < N; ++i)
		{
			for (int j = 1; j < M; ++j)
			{
				int cnt = 0;
				minarr[i][j] = min(minarr[i][j - 1], s[i][j]);
				int right = minarr[i][j] * (i + 1);
				if(row[i-1]<row[i])
					dp[i][j]=max()
				
			}
		}
		cout << res << endl;
	}
}