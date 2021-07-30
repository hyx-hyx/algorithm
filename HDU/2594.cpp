#define _CRT_SECURE_NO_WARNINGS
#include <bits\stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#define min(a,b) (((a) < (b)) ? (a) : (b))
using namespace std;
vector<int> nextval(100005);
void getNext(string s, vector<int>& nextval)
{
	nextval[0] = -1;
	int i = 0, j = -1;
	while (i < s.size())
	{
		if (j == -1 || s[i] == s[j])
			nextval[++i] = ++j;
		else
			j = nextval[j];
	}
}
int main()
{
	char pre[50005], suf[50005];
	while (scanf("%s %s",&pre,&suf)!=EOF)
	{
		string prefix(pre);
		string suffix(suf);
		string s = prefix + suffix;
		getNext(s,nextval);
		int cnt=nextval[s.size()];
		if(cnt> min(prefix.size(), suffix.size()))
			cnt = min(prefix.size(), suffix.size());
		if (!cnt)
			printf("0\n");
		else
		{
			char output[100005];
			s = s.substr(0, cnt);
			strcpy(output, s.c_str());
			printf("%s %d\n", output,cnt);
		}
	}
	return 0;
}