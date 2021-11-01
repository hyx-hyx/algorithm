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
		int a,b,c,maxvv,A,B,C;
		cin >> a >> b >> c;
		maxvv = max(max(a,b),c);
		A = maxvv - a;
		B = maxvv - b;
		C = maxvv - c;
		if(A + a == b || A + a==c)
			A++;
		if(B + b == a || B + b == c)
			B++;
		if(C + c == a || C + c == b)
			C++;
		cout <<A << " "<<B << " " <<C<< endl;
	}
	return 0;
}
