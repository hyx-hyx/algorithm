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
	stack<char> s;
	string str;
	cin >> str;
	int cnt=0;
	For(i,0,str.size())
		if(str[i] == '(')
			s.push(str[i]);
		else
			if(!s.empty())
				s.pop(),cnt++;
			else
				
	return 0;
}
