#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<cstdlib>
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
int main()
{
	int n,k;
	cin >> n >> k;
	vector<int>c(n);
	for(int i = 0; i < n; ++i)
		cin >> c[i];
	int ans = -200005;
	for(int i = 0; i < n; ++i)
	{
		for(int j = i; j < n; ++j)
		{
			vector<int> a(c);
			for(int o = 0; o < k; ++o)
			{
				int minpos = min_element(a.begin()+ i,a.begin()+ j + 1) - a.begin();
				int maxpos = max_element(a.begin(),a.begin()+ i) - a.begin();
				int maxi;
				if(j + 1 < n)
				{
					int maxpos1 = max_element(a.begin() + j + 1,a.begin() + n) - a.begin();
					
					if(a[maxpos] > a[maxpos1])
						maxi = maxpos;
					else
						maxi = maxpos1;
				}
				else
					maxi = maxpos;
				if(a[minpos] < a[maxi])
				{
					int tmp = a[minpos];
					a[minpos] = a[maxi];
					a[maxi] = tmp;
				}
				else
					break;
			}
			int sum = 0;
			for(int o = i; o <= j; ++o)
				sum += a[o];
			ans = max(ans,sum);
		}
	}
	cout << ans << endl;
	return 0;
}