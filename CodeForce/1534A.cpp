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
	int t;
	cin >> t;
	while(t--)
	{
		int flagr = -1,flagw = -1;
		char a[55][55];
		vector<int>R,W;
		int n,m;
		cin >> n >> m;
		int flag = 0;
		For(i,0,n)
		{
			For(j,0,m)
			{
				cin >> a[i][j];
				if(a[i][j] == 'R')
					R.push_back(i + j);
				if(a[i][j] == 'W')
					W.push_back(i + j);
			}
		}
		For(i,0,R.size())
			if(flagr == -1)
				flagr = R[i] % 2;
			else
				if(flagr != R[i] % 2)
				{
					cout << "NO" << endl;
					flag = 1;
					break;
				}
		if(flag)
			continue;
		For(i,0,W.size())
			if(flagw == -1)
				flagw = W[i] % 2;
			else
				if(flagw != W[i] % 2)
				{
					cout << "NO" << endl;
					flag = 1;
					break;
				}
		if(flagr == -1)
			if(flagw == -1)
				flagr = 1,flagw = 0;
			else
				flagr = (1 - flagw) % 2;
		else
			if(flagw == -1)
				flagw = (1 - flagr) % 2;
			else
				if(flagr == flagw)
					cout << "NO" << endl,flag = 1;
		if(flag)
			continue;
		For(i,0,n)
		{
			For(j,0,m)
			{
				if(a[i][j] == '.')
					if((i + j) % 2 == flagr)
						a[i][j] = 'R';
					else
						a[i][j] = 'W';
			}
		}
		cout<<"YES"<<endl;
		For(i,0,n)
		{
			For(j,0,m)
				cout << a[i][j];
			cout << endl;
		}
	}
	return 0;
}
