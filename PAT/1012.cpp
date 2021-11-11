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
struct student
{
	int c,m,e;
	int bestr = 10000;
	char subject;
	double a;
};
map<int,student> mp;
bool cmp1(student a,student b)
{
	return a.c > b.c;
}
bool cmp2(student a,student b)
{
	return a.m > b.m;
}
bool cmp3(student a,student b)
{
	return a.e > b.e;
}
bool cmp4(student a,student b)
{
	return a.a > b.a;
}
int main()
{
	int N,M,id;
	cin >> N >> M;
	For(i,0,N)
	{
		student s;
		cin >> id >> s.c >> s.m >> s.e;
		int sum = s.c + s.m + s.e;
		s.a = ((double)sum) / 3 + (sum % 3 == 2 ? 1 : 0);
		mp[id] = s;
	}
	int i;
	auto it = mp.begin();
	sort(mp.begin(),mp.end(),cmp3);
	for(it = mp.begin(),i = 0; it != mp.end(); ++it,++i)
		if(it->second.bestr > i)
			mp[i].bestr = i + 1,mp[i].subject = 'e';
	sort(mp.begin(),mp.end(),cmp2);
	for(it = mp.begin(),i = 0; it != mp.end(); ++it,++i)
		if(it->second.bestr > i)
			mp[i].bestr = i + 1,mp[i].subject = 'm';
	sort(mp.begin(),mp.end(),cmp1);
	for(it = mp.begin(),i = 0; it != mp.end(); ++it,++i)
		if(it->second.bestr > i)
			mp[i].bestr = i + 1,mp[i].subject = 'c';
	sort(mp.begin(),mp.end(),cmp4);
	for(it = mp.begin(),i = 0; it != mp.end(); ++it,++i)
		if(it->second.bestr > i)
			mp[i].bestr = i + 1,mp[i].subject = 'a';
	For(i,0,M)
	{
		int x;
		cin >> x;
		auto it = mp.find(x);
		if(it == mp.end())
			cout << "N/A" << endl;
		else
			cout << it->second.bestr << " " << it->second.subject << endl;
	}
	return 0;
}
