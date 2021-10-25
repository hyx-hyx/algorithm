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
typedef map<string,map<string,int>> m;
m mp;
int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		mp.clear();
		int M,index = 0;
		cin >> M;
		For(i,0,M)
		{
			string name,addr;
			int num;
			cin >> name >> addr >> num;
			mp[addr][name] += num;
		}
		for(auto it = mp.begin(); it != mp.end(); ++it)
		{
			cout << it->first << endl;
			for(auto itson = it->second.begin(); itson != it->second.end(); ++itson)
				cout << "   " << "|----" << itson->first << "(" << itson->second << ")" << endl;
		}
		if(N)
			cout << endl;
	}
	return 0;
}