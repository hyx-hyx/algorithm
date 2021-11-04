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
typedef pair<int,int> P;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		vector<P> sticks;
		int n;
		P cur,prev;
		cin >> n;
		int l,w;
		For(i,0,n)
			cin >> l >> w,sticks.push_back(P(l,w));
		sort(sticks.begin(),sticks.end());
		int ans = 0;
		while(!sticks.empty())
		{
			P cur = sticks[0];
			sticks.erase(sticks.begin());
			For(i,0,sticks.size())
			{
				if(sticks[i].first >= cur.first && sticks[i].second >= cur.second)
				{
					cur = sticks[i];
					sticks.erase(sticks.begin() + i);
					i--;
				}
			}
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
