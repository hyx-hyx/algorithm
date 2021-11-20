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
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	string a,b;
	cin >> a>>b;
	int sa=0,sb=0;
	auto it = a.find('.');
	if(it != string::npos)
		sa = it;
	it = b.find('.');
	if(it != string::npos)
		sb = it;
	string c = a.substr(sa,N);
	string d = b.substr(sb,N);
	if(c == d)
		cout<<"YES"<<" "<< "0." << c << "*10^" << a.size() << endl;
	else
	{
		cout << "NO" <<" "<< "0." << c << "*10^" << a.size() <<" "<< "0." << d << "*10^" << b.size() << endl;
	}
	return 0;
}
