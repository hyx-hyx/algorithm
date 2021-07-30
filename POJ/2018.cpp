/*（注意：这道题用二分法只有输出r才不会wa，输出mid和l都会wa！！我也搞不懂为什么，调二分精度也没用）

题目：http://poj.org/problem?id=2018
题意 ：给一个正整数数列，求一个平均数最大且长度不小于L的连续子串，输出平均值*1000

先谈谈我对求区间子串最大值的理解 ；
1.没有长度限制：
按方向遍历，保存0~i的值，假如这个值小于0，则令这个值等于下一个即将遍历的值，每一步都比较并保存最终答案。
for(int i=0;i<n;i++)  
{  
    if(b>0) 
        b=b+a[i];  
    else
        b=a[i];  
    if(b>sum)
        sum=b;    
}  
为什么这么做是可以的呢，这个问题可以转化成：最大区间【l,r】是否可以被这种方法遍历出来。

答案是可以的，因为当i<l的时候，因为是最大区间，因此a[i]必然小于0，此时b会被重置，当i>r的时候也同理，既然这种区间一定可以被遍历出来，那么原问题就解决啦。

其实还可以换一个思路，我们主要就是担心当l~r区间总和小于0被舍弃之后，下一个就会从r+1开始。而最大的区间会不会是从l~r中间的某一个数开始的。

其实也并不会，假设连续的五个数 q,w,e,r,t 总和小于0被舍弃，那么首先按照这个算法，q+w+e+r一定大于0（并没有被舍弃），同理 q+w+e ， q+w ， q一定都大于0，但是w+e+r ， e+r ， r则不一定了，所以假如q开头都小于0的话，从w，e，r开头就更不用说了。


2.有长度限制，长度最短为r

这个时候有长度限制，我们可以使用前缀和，以sum[i]表示 1~i 的所有数的总和，那么以i结尾的最大的区间应该是
ans=sum[i]-sum[j]   其中 j=min(sum[k]) ,k=(0~i-r) .

因为在实际操作中是递推过去的，因此对于 sum[j]我们只需要记录其最小值，然后每前进一步就拿新加进来的跟其比较，保留较小值即可。
 

3.有长度限制，长度最长为r

这题思路和2一样，只不过j改成（i-r~i） ， 可以使用优先队列帮助实现


回到本题：
这道题很明显是第二种情况，但是多了一个平均值，怎么处理呢？因为最大子段和最大平均值的子段并不一定对应，因此不能直接做。
但是有一种转换方法，就是二分答案，然后对于每一个答案判断是否存在一个子串使得子串平均值符合即可。
这样子还是要求子串平均值，因此我们可以让数列每一个数都减去该答案，判断是否存在一个子串最大值大于0即可。
 
代码如下：*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 105
using namespace std;
int main()
{
	int n, f;
	double a[maxn] = { 0 }, diff[maxn] = { 0 }, sum[maxn] = { 0 };
	scanf("%d%d", &n, &f);
	for (int i = 1; i <= n; ++i)
		scanf("%lf", a + i);
	double r = 20000.0, L = -1.0;
	while (r - L > 1e-4)
	{
		double mid = (r + L) / 2;
		for (int i = 1; i <= n; ++i)
			diff[i] = a[i] - mid;
		for (int i = 1; i <= n; ++i)
			sum[i] = diff[i] + sum[i - 1];
		double minvalue = 1000000, maxvalue = -10000000;
		for (int i = f; i <= n; ++i)
		{
			minvalue = min(minvalue, sum[i - f]);
			maxvalue = max(maxvalue, sum[i] - minvalue);
		}
		if (maxvalue >= 0)
			L = mid;
		else
			r = mid;
	}
	printf("%d\n", (int)(r * 1000));
	return 0;
}
