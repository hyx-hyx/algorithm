#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
typedef long long ll;
const int maxn = 3e6+5;
using namespace std;
int main()
{
	int n,a[maxn] = {0},f[maxn] = {0};
	cin >> n;
	stack<int> s;
	For(i,1,n+1)
	{
		cin >> a[i];
		while(!s.empty() && a[s.top()] < a[i])
		{
			f[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	For(i,1,n+1)
		cout << f[i] << " ";
	return 0;
}
