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
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		char a[100005];
		cin >> n;
		getchar();
		For(i,0,n)
			cin >> a[i];
		int ans = 100010;
		For(i,0,26)
		{
			int cnt = 0;
			int l = 0,r = n-1;
			while(l <= r)
			{
				if(a[l] == a[r])
					l++,r--;
				else
				{
					if(a[l] == i + 97)
						l++,cnt++;
					else
						if(a[r] == i + 97)
							cnt++,r--;
						else
						{
							cnt = n + 1;
							break;
						}
				}
			}
			ans = min(ans,cnt);
		}
		if(ans == n + 1)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
