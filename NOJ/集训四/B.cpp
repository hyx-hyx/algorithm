#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<windows.h>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
using namespace std;
deque<int> maxi,mini;
int main()
{
	int n,k;
	vector<int> maxarr;
	int a[1000005];
	scanf("%d%d",&n,&k);
	For(i,0,n)
	{
		scanf("%d",&a[i]);
		if(!maxi.empty() && i - maxi.front()>=k)
			maxi.pop_front();
		while(!maxi.empty() && a[maxi.back()]<a[i])
			maxi.pop_back();
		maxi.push_back(i);
		if(i >= k - 1)
			maxarr.emplace_back(maxi.front());//push_back比emplace_back慢，会超时

		if(!mini.empty() && i-mini.front()>=k)
			mini.pop_front();
		while(!mini.empty() && a[mini.back()]>a[i])
			mini.pop_back();
		mini.push_back(i);
		if(i >= k - 1)
			printf("%d ",a[mini.front()]);
	}
	printf("\n");
	For(i,0,n - k + 1)
		printf("%d ",a[maxarr[i]]);
	return 0;
}