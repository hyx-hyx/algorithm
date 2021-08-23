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
#define maxn 
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int flag[30] = {0};
		int n;
		cin >> n;
		string s;
		cin >> s;
		int kind = 0;
		int mode;
		if(s[0] == s[1])
			mode = 0;
		else
			mode = 1;
		int circle = 0;
		for(int i = 0; i < s.size(); ++i)
		{
			if(s[i] != s[n - i - 1])
				circle = 1;
			if(!flag[s[i] - 96])
				kind++;
			flag[s[i] - 96]++;
		}
		if(circle)
		{
			cout << 1 << endl;
			continue;
		}
		if(kind > 2)
		{
			cout << 2 << endl;
			continue;
		}
		if(kind == 1)
		{
			cout << -1 << endl;
			continue;
		}
		else
		{
			if(!(n % 2))
				cout << 2 << endl;
			else
			{
				int mid = n / 2;
				int ok = 0;
				for(int i = 1; i <=n/2; ++i)
				{
					if(mode)
					{
						if(s[mid + i] == s[mid + i - 1])
						{
							ok = 1;
							break;
						}

					}
					else
					{
						if(s[mid + i] != s[mid + i - 1]&&i!=1)
						{
							ok = 1;
							break;
						}
					}	
				}		
				if(ok)
					cout << 2 << endl;
				else
					cout << -1 << endl;
			}
		}
	}
	return 0;
}
