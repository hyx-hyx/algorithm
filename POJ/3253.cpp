#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > Q;
int main()
{
	int n;
    __int64 sum = 0; //注意sum值的大小，sum值过大，需使用__int64
    cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		Q.push(temp);
	}
	for (int i = 0; i < n-1; ++i)
	{
		int temp;
		temp = Q.top();
		Q.pop();
		int newcount = temp + Q.top();
		sum += newcount;
		Q.pop();
		Q.push(newcount);
	}
	printf("%I64i\n", sum);  //sum类型为__int64,格式字符串为“%I64i“
	return 0;
}
