/*
网址：https://www.acwing.com/problem/content/7
有 N 种物品和一个容量是 V 的背包。
物品一共有三类：
第一类物品只能用1次（01背包）；
第二类物品可以用无限次（完全背包）；
第三类物品最多只能用 si 次（多重背包）；
每种体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。
接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。
si=−1 表示第 i 种物品只能用1次；
si=0 表示第 i 种物品可以用无限次；
si>0 表示第 i 种物品可以使用 si 次；
输出格式
输出一个整数，表示最大价值。
数据范围
0<N,V≤1000
0<vi,wi≤1000
−1≤si≤1000
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 1e3 + 5;
typedef long long ll;
//建立结构体，方便多重背包二进制优化
typedef struct good
{
	int v,w,s;
}good;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N,V;
	vector<good>goods;
	int dp[maxn] = {0};
	cin >> N >> V;
	for(int i = 1; i <= N; ++i)
	{
		int v,w,s;
		cin >> v >> w >> s;
		if(s > 0)  //对多重背包进行二进制优化
		{
			for(int k = 1; k <= s; k *= 2)
				s -= k,goods.push_back({v * k,w * k,-1});
			if(s > 0)
				goods.push_back({v * s,w * s,-1});
		}
		else
			goods.push_back({v,w,s});
	}
	for(int i = 0; i < goods.size(); ++i)
        //01背包，多重背包已转化为01背包。
		if(goods[i].s)    
			for(int j = V; j >= goods[i].v; --j)
				dp[j] = max(dp[j],dp[j - goods[i].v] + goods[i].w);
		else      //完全背包
			for(int j = goods[i].v; j <= V; ++j)
				dp[j] = max(dp[j],dp[j - goods[i].v] + goods[i].w);
	cout << dp[V] << endl;
	return 0;
}