#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
using namespace std;
const int maxn = 1e4 + 5;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	int N,M;
	vector<int> vec;
	unordered_map<int,int>mp;
	int sticks[10] = {0,2,5,5,4,5,6,3,7,6};
	cin >> N >> M;
	int f[maxn];
	memset(f,-0x3f3f3f3f,sizeof f);
	f[0] = 1;
	For(i,0,M)
	{
		int x;
		cin >> x;
		if(mp.find(sticks[x]) == mp.end())
			mp[sticks[x]] = x;
		else
			mp[sticks[x]] = max(mp[sticks[x]],x);
	}
	for(auto it = mp.begin(); it != mp.end();++it)
		vec.push_back(it->second);
	for(int i = 0; i < vec.size(); ++i)
		for(int j = sticks[vec[i]]; j <= N; ++j)
			f[j] = max(f[j],f[j - sticks[vec[i]]] + 1);
	sort(vec.begin(),vec.end(),cmp);
	while(N)
	{
		for(int i = 0; i < M; ++i)
			if(N >= sticks[vec[i]] && f[N -sticks[vec[i]]] + 1 == f[N])
			{
				printf("%c",(char)(mp[sticks[vec[i]]] + '0'));
				N -= sticks[vec[i]];
				break;
			}
	}
	cout << endl;
	return 0;
}
