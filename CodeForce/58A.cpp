#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int numarr[200000];
bool index[200000];
int flag=0;
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
	{
		if (flag == 0)
		{
			if (s[i] == 'h')
				flag = 1;
		}
		if (flag == 1)
		{
			if (s[i] == 'e')
				flag = 2;
		}
		if (flag == 2||flag==3)
		{
			if (s[i] == 'l')
				flag++;
		}
		if (flag == 4)
		{
			if (s[i] == 'o')
				flag++;
		}
		if (flag == 5)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
