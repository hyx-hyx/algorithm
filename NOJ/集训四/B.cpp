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
using namespace std;
deque<int> maxi,mini;
typedef pair<int,int> P;
int main()
{
	int n,k;
	vector<P>a;
	vector<int> maxarr,minarr;
	cin >> n >> k;
	For(i,0,n)
	{
		int temp;
		cin >> temp;
		a.push_back(P(i,temp));

		while(!maxi.empty()&&a[i].second > maxi.front())
			maxi.pop_back();
		if(!maxi.empty()&&maxi.front() < i - k + 1)
			maxi.pop_front();
		maxi.push_back(a[i].first);
		if(i>=k-1)
			maxarr.push_back(maxi.front());

		while(!mini.empty()&&a[i].second < mini.back())
			mini.pop_back();
		if(!mini.empty()&&mini.front() < i - k + 1)
			mini.pop_front();
		mini.push_back(a[i].first);
		if(i>=k-1)
			minarr.push_back(mini.front());
	}
	For(i,0,n - k+1)
		cout << a[minarr[i]].second << " ";
	cout << endl;
	For(i,0,n - k+1)
		cout << a[maxarr[i]].second << " ";
	return 0;
}
