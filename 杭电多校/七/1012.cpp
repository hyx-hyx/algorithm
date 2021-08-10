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
#define maxn 5000005
#define mod 998244353
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	int t;
	cin >> t;
	int dp[maxn][maxn][27];
	while (t--)
	{
		cin >> s;
		int maxchar = 0;
		for (int i = 0; i < s.size(); ++i)
			maxchar = max((int)s[i],maxchar);
		for (int i = 1; i <= s.size(); ++i)
			dp[0][i][s[0]] = 0;
		for (int i = 1; i <= s.size(); ++i)
		{
			for (int j = i; j <= s.size(); ++j)
			{
				if ()
					dp[i][j][c] = ( dp[i - 1][j][c] - 1 ) * ( dp[i - 1][j][c] - 1 ) % mod;
				else
					dp[i][j][c] = dp[i - 1][j][c] * dp[i - 1][j][c] % mod;
			}
		}
		for(int i=1;i<=s.size();++i)
		cout<< <<endl;
	}
	return 0;
}
//===========================================================
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
#define maxn 5005
#define mod 998244353
typedef long long ll;
int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		int sum[maxn] = { 0 };
		int flag[27] = { 0 };
		char c = 0;
		char ch[maxn];
		int cnt = 0;
		int kind = 0;
		while (c != '\n')
		{
			scanf("%c", &c);
			if (!flag[c - 97])
				kind++;
			flag[c - 97]++;
			ch[cnt++] = c;
		}

		for (int i = 0; i < cnt - 1; ++i)
		{
			int temp = 0;
			if (i)
				flag[ch[i-1] - 97]--;
			for (int j = 0; j < 27; ++j)
				temp = ( temp + ( flag[j] * flag[j] % mod ) ) % mod;
			sum[i] = temp;
		}
		int ans = 0;
		int temp = cnt;
		for (int i = 1; i < cnt; ++i)
			ans = ( ans + ( sum[i - 1] * i) % mod ) % mod;
		cout << ans << endl;
	}
	return 0;
}
