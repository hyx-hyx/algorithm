#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<list>
using namespace std;
int main()
{
	char ch[100005];
	scanf("%s", ch);
	string s(ch);
	list<char> wire(ch,ch+s.size());
	list<char>::iterator it = wire.begin();
	it++;
	int flag = 0;
	while (it!=wire.end())
	{
		list<char>::iterator temp = it;
		if ((*it) == (*(--temp)))
		{
			list<char>::iterator temp1 = it;
			it++;
			wire.erase(temp1);
			wire.erase(temp);
			if (!wire.size())
				flag = 1;
		}
		else
			it++;
	}
	if (flag)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
