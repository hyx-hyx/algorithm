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
	string s;
	cin >> s;
	ll N = 0,E = 0;
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == 'N')
			N++;
		if(s[i] == 'S')
			N--;
		if(s[i] == 'E')
			E++;
		if(s[i] == 'W')
			E--;
	}
	int n = 0;
	cin >> n;
	int step;
	step=n/s.size();
	ll  x = step * E,y = step * N;
	for(int i = 0; i < n%s.size(); ++i)
	{
		if(s[i] == 'N')
			y++;
		if(s[i] == 'S')
			y--;
		if(s[i] == 'E')
			x++;
		if(s[i] == 'W')
			x--;
	}
	cout << x<<" " <<y << endl;
	return 0;
}
