#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int main()
{
	char ch=0;
	int a[27] = {0};
	while (ch!='\n')
	{
		ch = getchar();
		a[ch - 'a']++;
	}
	int count = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (a[i] % 2)
			count++;
	}
	if ((count % 2)||(count==0))
		printf("First\n");
	else
		printf("Second\n")  ;
	return 0;
}