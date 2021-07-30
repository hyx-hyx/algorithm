/*
链接：https://ac.nowcoder.com/acm/contest/11255/J
矩阵W的值等于ai+bj;
输入:矩阵的行列n,m,和子矩阵的大小x,y。
    a数组，b数组
输出：求一个子矩阵，使得该子矩阵的平均值。输出平均值。
不妨设选择的那块矩形长为x，宽为y，对应的行列的起始位置分别为xl,xr,yl,yr。
平均值为average=(ySum[xl...xr]+xSum[yl...yr])/(xy)
              =Sum[xl...xr]/x+Sum[yl...yr]/y
              其中Sum[xl...xr]为a数组的xl到xr位置的和。最大化均值相当于分别求a、b两个数组的连续子区间的最大均值然后再求和。
              而这个问题可以参考poj2018，https://blog.csdn.net/weixin_43191865/article/details/90612344
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 100005
using namespace std;
double a[maxn] = { 0 }, diff[maxn] = { 0 }, sum[maxn] = { 0 }, b[maxn] = { 0 };
double solve(double arr[], int size, int range)
{
	double r = 100005.0, L = -1.0;
	while (r - L > 1e-10)
	{
		double mid = (r + L) / 2;
		for (int i = 1; i <= size; ++i)
			diff[i] = arr[i] - mid;
		for (int i = 1; i <= size; ++i)
			sum[i] = diff[i] + sum[i - 1];
		double minvalue = 1000000, maxvalue = -10000000;
		for (int i = range; i <= size; ++i)
		{
			minvalue = min(minvalue, sum[i - range]);
			maxvalue = max(maxvalue, sum[i] - minvalue);
		}
		if (maxvalue >= 0)
			L = mid;
		else
			r = mid;
	}
	return r;
}
int main()
{
	int n, m, x, y;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i = 1; i <= n; ++i)
		scanf("%lf", a + i);
	for (int i = 1; i <= m; ++i)
		scanf("%lf", b + i);
	double ansa = solve(a,n,x);
	double ansb = solve(b,m,y);
	printf("%.10f\n",ansa+ansb);
	return 0;
}
