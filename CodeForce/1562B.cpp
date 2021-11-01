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
#define maxn 100
int prime[maxn];
int visit[maxn];
void Prime()
{
	memset(visit,0,sizeof(visit));
	memset(prime,0,sizeof(prime));
	for(int i = 2; i <= maxn; i++)
	{
		if(!visit[i])
			prime[++prime[0]] = i;
		for(int j = 1; j <= prime[0] && i * prime[j] <= maxn; j++)
		{
			visit[i * prime[j]] = 1;
			if(i % prime[j] == 0)
				break;
		}
	}
}
int main()
{
	int t;
	Prime();
	visit[1] = 1;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		char a[55];
		cin >> a;
		int flag = 0;
		For(i,0,n)
		{
			int temp = a[i] - 48;
			if(visit[temp])
			{
				flag = 1;
				cout << 1 << endl,cout << temp << endl;
				break;
			}
		}
		if(flag)
			continue;
		For(i,0,n-1)
		{
			For(j,i+1,n)
			{
				int temp = (a[i] - 48) * 10 + a[j] - 48;
				if(visit[temp])
				{
					flag = 1;
					cout << 2 << endl;
					cout << temp << endl;
					break;
				}
			}
			if(flag)
				break;
		}
	}
	return 0;
}
