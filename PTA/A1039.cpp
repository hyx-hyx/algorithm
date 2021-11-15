#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<unordered_map>
#include<vector>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
using namespace std;
unordered_map<string,int> mp;
int main()
{
	int n,k,cnt=0;
	cin >> n >> k;
	priority_queue<int,vector<int>,greater<int>> stu[40005];
	For(i,0,k)
	{
		int index,ni;
		cin >> index >> ni;
		For(i,0,ni)
		{
			string name;
			cin >> name;
			auto it = mp.find(name);
			if(it == mp.end())
				mp[name] = cnt++;
			stu[mp[name]].push(index);
		}
	}
	string name;
	For(i,0,n)
	{
		cin >> name;
		cout << name;
		if(mp.find(name) == mp.end())
			cout << " " << 0;
		else
		{
			cout << " " << stu[mp[name]].size();
			while(!stu[mp[name]].empty())
				cout << " " << stu[mp[name]].top(),stu[mp[name]].pop();
		}
		if(i != n - 1)
			cout << endl;
	}
	return 0;
}
