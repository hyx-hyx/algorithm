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
#define maxn 100005
#define mod 998244353
typedef long long ll;
int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		char temp = 0;
		char charr[maxn];
		vector<char> ch;
		int cnt = 0;
		int flag[27] = { 0 };
		while (1)
		{
			scanf("%c", &temp);
			if (temp == '\n') break;
			charr[cnt++] = temp;
			if (!flag[temp - 97])
				flag[temp - 97] = 1, ch.push_back(temp);
		}
		charr[cnt] = 0;
		string s(charr);
		int n = s.size();
		vector<vector<vector<int> > >dp(2, vector<vector<int> >(n, vector<int>(27, 0)));
		int sum = 0;
		dp[0][0][s[0] - 97]++;
		sum = 1;
		for (int i = 1; i < s.size(); ++i)
		{
			dp[0][i][s[i] - 97] = dp[0][i - 1][s[i] - 97] + 1;
			sum = ( sum + ( dp[0][i][s[i] - 97] * dp[0][i][s[i] - 97] ) % mod ) % mod;
			for (int j = 0; j < ch.size(); ++j)
			{
				int c = ch[j] - 97;
				if (s[i] - 97 == c)
					continue;
				else
					dp[0][i][c] = dp[0][i - 1][c], sum = ( sum + ( dp[0][i][c] * dp[0][i][c] ) % mod ) % mod;
			}
		}
		for (int i = 1; i < s.size(); ++i)
		{
			int index = i & 1;
			for (int j = i; j < s.size(); ++j)
			{
				for (int c = 0; c < ch.size(); ++c)
				{
					int k = ch[c] - 97;
					int temp = 0;
					if (s[i - 1] == k + 97)
						dp[index][j][k] = dp[index ^ 1][j][k] - 1;
					else
						dp[index][j][k] = dp[index ^ 1][j][k];
					sum = ( sum + ( dp[index][j][k] * dp[index][j][k] ) % mod ) % mod;
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}