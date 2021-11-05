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
	int N;
	while(cin >> N)
	{
		priority_queue<P,vector<P>,less<P> > pri[4];
		int d,p;
		string op;
		int cnt = 0;
		For(i,0,N)
		{
			cin >> op;
			if(op == "IN")
			{
				cin >> d >> p;
				++cnt;
				pri[d].push(P{p,-cnt});
			}
			else
			{
				cin >> d;
				if(pri[d].empty())
					cout << "EMPTY" << endl;
				else
					cout << (-1) * (pri[d].top().second) << endl,pri[d].pop();
			}
		}
	}
	return 0;
}