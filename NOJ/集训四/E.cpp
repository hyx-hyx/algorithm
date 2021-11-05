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
const int maxn = 100;
using namespace std;
int fa[maxn],ranki[maxn];
void init(int n)
{
	for(int i = 0; i <= n; ++i)
	{
		fa[i] = i;
		ranki[i] = 1;
	}
}
int find(int x)
{
	return fa[x] == x ? fa[x] : (fa[x] = find(fa[x]));
}
int cnt = 0;
void merge(int i,int j)
{
	int x = find(i);
	int y = find(j);
	if(x == y)
	{
		cnt++;
		return;
	}
	fa[x] = y;
}
int main()
{
	int n,m;
	cin >> n >> m;
	init(n);
	For(i,0,m)
	{
		int x,y;
		cin >> x >> y;
		merge(x,y);
	}
	if(cnt == 1)
		cout << "FHTAGN!" << endl;
	else
		cout << "NO" << endl;
	return 0;
}