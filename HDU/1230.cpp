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
#define maxn 105
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
	Prime();
	while(1)
	{
		char c;
		int a[28],b[28],indexa = 0,indexb = 0,ans[28],w[28] = {0},tempa[28],tempb[28];
		memset(a,-1,sizeof a);
		memset(b,-1,sizeof b);
		while(scanf("%d%c",&tempa[indexa++],&c))
			if(c != ',')
				break;
		while(scanf("%d%c",&tempb[indexb++],&c))
			if(c != ',')
				break;
		if(indexa == 1 && indexb == 1 && tempa[0] == 0 && tempb[0] == 0)
			break;
		else
		{
			for(int i = indexa - 1; i >= 0; --i)
				a[indexa - i - 1] = tempa[i];
			for(int i = indexb - 1; i >= 0; --i)
				b[indexb - i - 1] = tempb[i];
			for(int i = 0; i <= max(indexa,indexb); ++i)
			{
				if(a[i] < 0)
					a[i] = 0;
				if(b[i] < 0)
					b[i] = 0;
			}
			for(int i = 0; i <= max(indexa,indexb); ++i)
			{
				ans[i] = (a[i] + b[i] + w[i]) % prime[i + 1];
				w[i + 1] = (a[i] + b[i] + w[i]) / prime[i + 1];
			}
			int begin = max(indexa,indexb);
			if(ans[max(indexa,indexb)] == 0)
				begin -= 1;
			for(int i = begin; i > 0; --i)
				if(ans[i] >= 0)
					cout << ans[i] << ',';
			cout << ans[0] << endl;
		}
	}
	return 0;
}