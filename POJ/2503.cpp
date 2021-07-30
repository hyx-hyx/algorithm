#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <bits\stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
typedef map<string, string> map_str_str;
int main()
{
	map_str_str dict;
	string en, other;
	char line[25];
	while (1)
	{
		gets_s(line);
		if (line[0] == '\0')
			break;
		else
		{
			string read_line(line);
			int index = read_line.find(" ");
			string en = read_line.substr(0, index);
			string other = read_line.substr(index + 1, read_line.size() - index - 1);
			dict[other] = en;
		}
	}
	char ch[25];
	while (scanf("%s",ch)!=EOF)
	{
		string s(ch);
		char output[15];
		map_str_str::iterator it = dict.find(s);
		if (it == dict.end())
			printf("%s\n", "eh");
		else
		{
			string temp = (*it).second;
			strcpy(output, temp.c_str());
			printf("%s\n", output);
		}
	}
	return 0;
}