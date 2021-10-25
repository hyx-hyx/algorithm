#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<map>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
using namespace std;
typedef pair<int,int> P;
map<int,P> mp;
int main()
{
	int k,n,a[200005];
	cin >> k;
	int flag = 0;
	For(j,0,k)
	{
		int sum = 0;
		cin >> n;
		For(i,0,n)
		{
			cin >> a[i];
			sum += a[i];
		}
		For(i,0,n)
		{
			map<int,P>::iterator it= mp.find(sum - a[i]);
			if(it != mp.end())
			{
				if(!flag && j != 0&&it->second.first!=j)
				{
					flag = 1;
					cout << "YES" << endl;
					cout << j + 1 << " " << i + 1 << endl;
					cout << it->second.first + 1 << " " << it->second.second + 1 << endl;
				}
			}
			else
				mp[sum - a[i]] = P(j,i);
		}
	}
	if(!flag)
		cout << "NO" << endl;
	return 0;
}
