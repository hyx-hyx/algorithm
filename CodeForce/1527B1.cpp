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
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		if((n % 2) && (n > 1))
		{
			if(s[n / 2] == '0')
			{
				int cnt = 0;
				for(int i = 0; i < n; ++i)
					if(s[i] == '0')
						cnt++;
				if(cnt > 1)
					cout << "ALICE" << endl;
				else
					cout << "BOB" << endl;
			}
			else
				cout << "BOB" << endl;
		}
		else
			cout << "BOB" << endl;
	}
	return 0;
}
