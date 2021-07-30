#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
#define maxn 1005
using namespace std;
deque<int> Q;//存储编号
int v[maxn] = { 0 };//存储输入值
int main()
{
	int n, k;
	cin >> n >> k;  //n代表输入个数
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v[i]);
		if (!Q.empty() && i - Q.front() >= k)  //超出范围  k代表范围大小
			Q.pop_front();
        //单调递增队列。如果是单调递减队列，将v[Q.back()] <v[i]改为v[Q.back()] >v[i]
		while(!Q.empty() && v[Q.back()] <v[i])  //新入队列的值大于原队列的值，把原队列的值弹出
			Q.pop_back();
		Q.push_back(i);
		if (i >= k - 1)
		{
			printf("%d ", v[Q.front()]);
		}
	}
	return 0;
}

