#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
using namespace std;
struct course
{
	int x,y;
};
int f[55][505],dp[55][505][4];
map<string,int> mp;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		mp.clear();
		memset(f,-0x3f3f3f3f,sizeof f);
		memset(dp,-0x3f3f3f3f,sizeof dp);
		vector<course> vec[55];
		int n;
		string s;
		cin >> n;
		Fore(i,1,n)
			cin >> s,mp[s] = i;
		int m;
		cin >> m;
		Fore(i,1,m)
		{
			int x,y;
			cin >> s >> x >> y;
			vec[mp[s]].push_back({x,y});
		}
		int t,p;
		cin >> t >> p;
		for(int i = 1; i <= n; ++i)
			f[i][0] = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 0; j < vec[i].size(); ++j)
				for(int k = t; k >= vec[i][j].y; --k)
					f[i][k] = min(100,max(f[i][k],f[i][k - vec[i][j].y] + vec[i][j].x));
		dp[0][0][0] = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 0; j <= t; ++j)
				for(int k = 0; k <= p; ++k)
					for(int z = 0; z <= j; ++z)
						if(f[i][z] < 60 && k != 0)
							dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j - z][k - 1] + f[i][z]);
						else
							if(f[i][z] >= 60)
								dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j - z][k] + f[i][z]);
		int ans = -1;
		for(int i = 0; i <= p; ++i)
			ans = max(ans,dp[n][t][i]);
		cout << ans << endl;
	}
	return 0;
}
