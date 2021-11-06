#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<list>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
using namespace std;
list<int> l,r;
int lsize,rsize;
int main()
{
	int n;
	scanf("%d",&n);
	int cnt = 0;
	int vis[10000005] = {0};
	Fore(i,1,n)
	{
		char c;
		getchar();
		scanf("%c",&c);
		if(c == 'L')
			l.emplace_front(++cnt);
		if(c == 'R')
			r.emplace_back(++cnt);
		if(c == 'G')
		{
			int x;
			cin >> x;
			vis[x] = 0;

		}
		if(c == 'Q')
		{

		}
	}
	return 0;
}
