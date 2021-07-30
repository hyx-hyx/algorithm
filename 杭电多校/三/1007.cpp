/*
2021“MINIEYE杯”中国大学生算法设计超级联赛（3）1007(杭电6979) Photoshop Layers
题意：
题解：
预处理出 f[i] 表示图层i左侧第一个合成方式为 “普通” 的图层。对于每个询问，求出 r 左侧第一个合成方式为 “普通” 的图层f[r] ，则中间的部分都是 “线性减淡”，可以用前缀和求出结
果，最后与 255 取最小值。
时间复杂度 O(n + q)。
note:scanf()的格式串中%x代表输入十六进制整数。
	printf()格式串中%x代表输出十六进制整数，x为小写，则十六进制输出对应a-f；X大写，十六进制输出对应A-F。
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#define maxn 1005
using namespace std;
int f[maxn];
int query(int s[], int l, int r) //通过前缀和进行查询
{
	int ans = 0;
	int x = f[r];
	if (x < l) ans = s[r] - s[l - 1];//若范围最左边没遇到模式1图层，则通过前缀和求解。
	else ans = s[r] - s[x - 1];      //若范围最左边遇到模式1图层，则只计算的模式1图层。
	return ans<255? ans:255;
}
int main()
{
	int t, n, q, r[maxn], g[maxn], b[maxn], layer[maxn];
	scanf("%d", &t);
	for(int T=0;T<t;++T)
	{
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; ++i)
		{
			int mode, value;
			scanf("%d%X", &mode, &value);
			b[i] = value & 255;//保留后8位
			value >>= 8;		//将中8位移至后8位
			g[i] = value & 255;
			value >>= 8;
			r[i] = value;
			//对rgb三个数组求前缀和
			r[i] += r[i - 1]; 
			g[i] += g[i - 1];
			b[i] += b[i - 1];
			layer[i] = mode;
			//f数组记录从当前位置开始，往左遇到的第一个模式为1的layer的索引。
			if (layer[i] == 1)
				f[i] = i;
			else
				f[i] = f[i - 1];
		}
		while(q--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%02X%02X%02X\n",query(r,x,y), query(g, x, y), query(b, x, y));
		}
	}
	return 0;
}