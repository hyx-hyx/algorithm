#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
using namespace std;
//0:right 1:down
ll dp[105][105][2];
int dir[105][105][2];
ll fastpower(int base,int power)
{
	ll res = 1;
	while(power)
	{
		if(power & 1)
			res = res * base;
		base *= base;
		power >>= 1;
	}
	return res;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		memset(dp,0x3f3f3f3f,sizeof dp);
		memset(dir,-1,sizeof dir);
		dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = dp[0][1][1] = dp[1][0][0] = dp[1][0][1] = 0;
		int N,a[105][105];
		cin >> N;
		Fore(i,1,N)
			Fore(j,1,N)
			cin >> a[i][j];
		Fore(i,1,N)
		{
			Fore(j,1,N)
			{
				ll right = dp[i - 1][j][1] + fastpower(2,dir[i - 1][j][1] + 1);
				if(right <= dp[i][j - 1][0])
					dp[i][j][0] = right,dir[i][j][0] = dir[i - 1][j][1] + 1;
				else
					dp[i][j][0] = dp[i][j - 1][0];
				dp[i][j][0] += a[i][j];

				ll down = dp[i][j - 1][0] + fastpower(2,dir[i][j - 1][0] + 1);
				if(down <= dp[i-1][j][1])
					dp[i][j][1] = down,dir[i][j][1] = dir[i][j - 1][0] + 1;
				else
					dp[i][j][1] = dp[i - 1][j][1];
				dp[i][j][1] += a[i][j];
			}
		}
		cout << min(dp[N][N][0],dp[N][N][1]) << endl;
	}
	return 0;
}
