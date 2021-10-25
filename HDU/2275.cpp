#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
using namespace std;
multiset<int> vec;
int main()
{
	int N;
	while(cin >> N)
	{
		vec.clear();
		For(i,0,N)
		{
			string c;
			int x;
			cin >> c >> x;
			if(c == "Push")
				vec.insert(x);
			else
			{
				multiset<int>::iterator it = vec.upper_bound(x);
				if(it != vec.begin())
					cout << *(--it) << endl,vec.erase(it);
				else
					cout << "No Element!" << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
