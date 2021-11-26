#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<stack>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
using namespace std;
map<string,set<string>> pro[5];
int main()
{
	int N;
	cin >> N;
	For(k,0,N)
	{
		string id;
		cin >> id;
		getchar();
		string s;
		For(i,0,5)
		{
			getline(cin,s);
			string str;
			if(i == 2)
			{
				For(j,0,s.size())
				{
					if(s[j] != ' ')
						str.push_back(s[j]);
					else
						pro[i][str].emplace(id),str.clear();
				}
				pro[i][str].emplace(id);
			}
			else
				pro[i][s].emplace(id);
		}
	}
	int M;
	cin >> M;
	getchar();
	For(i,0,M)
	{
		string s;
		getline(cin,s);
		cout << s << endl;
		string str = s.substr(3,s.size() - 3);
		auto itf = pro[s[0] - '0' - 1].find(str);
		vector<string> a;
		if(itf != pro[s[0] - '0' - 1].end())
		{
			set<string> s = itf->second;
			for(auto i = s.begin(); i != s.end(); ++i)
				a.emplace_back(*i);
			sort(a.begin(),a.end());
			for(int i = 0; i < a.size(); ++i)
				cout << a[i] << endl;
		}
		else
			cout << "Not Found" << endl;
	}
	return 0;
}
