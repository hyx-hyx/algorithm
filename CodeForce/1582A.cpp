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
		int a,b,c;
		cin >> a >> b >> c;
		int suma,sumb,sumc;
		suma = a;
		sumb = 2 * b;
		sumc = 3 * c;
		if((suma + sumb + sumc) % 2 == 0)
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}
	return 0;
}
