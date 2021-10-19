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
const int maxn = 15;
using namespace std;
struct time
{
	int H;
	int MM;
}t[maxn];
struct time offset[maxn];
int main()
{
	int P;
	cin >> P;
	while(P--)
	{
		int K,N;
		cin >> K >> N;
		string s;
		
		For(i,0,N)
		{
			cin >> s;
			t[i].H = s[0]-'0',t[i].MM = (s[2] - '0') * 10 + s[3] - '0';
		}
		For(i,0,N)
		{
			cin >> s;
			if(s[0] == '-')
				offset[i].H = -1 * (s[1] - '0'),offset[i].MM= (s[3] - '0') * 10 + s[4] - '0';
			else
				offset[i].H = s[0] - '0',offset[i].MM=(s[2] - '0') * 10 + s[3] - '0';
		}
	}
	return 0;
}
