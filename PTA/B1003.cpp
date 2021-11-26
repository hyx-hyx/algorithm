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
int main()
{
	int n;
	cin >> n;
	For(i,0,n)
	{
		string s;
		int cnt = 0;
		int t = 0,p = 0,ti = 0,pi = 0,a = 0;
		cin >> s;
		For(i,0,s.size())
		{
			if(s[i] == 'A')
				a++;
			if(s[i] == 'T')
				t++,ti = i;
			if(s[i] == 'P')
				p++,pi = i;
		}
		if(t != 1 || p != 1 || !a)
			cout << "NO" << endl;
		else
		{
			int al=0,ar=0,am=0;
			int flag = 1;
			For(i,0,s.size())
			{
				if(s[i] == 'A')
				{
					if(i < pi)
						al++;
					else if(i > pi && i < ti)
						am++;
					else
						ar++;
				}
				else
				{
					if(s[i] != 'P' && s[i] != 'T')
					{
						flag = 0;
						break;
					}
				}
			}
			if(!flag)
				cout << "NO" << endl;
			else
				if(al * am == ar)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
		}
	}
	return 0;
}
