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
void read(string *s)
{
	char c = 0;
	while(1)
	{
		scanf("%c",&c);
		if(c == ' '||c=='\n')
			break;
		s->push_back(c);
	}
}
int main()
{
	int T;
	cin >> T;
	getchar();
	Fore(i,1,T)
	{
		string a,b,c;
		read(&a),read(&b),read(&c);
	}
	return 0;
}
