/*
题意：有 n 个盒子和 n 种不同颜色的球，第 i 种颜色的球有 ai 个。开始时，所有的球都在第一个盒子中。现在将某个非空盒子中的球全部拿起（拿起后盒子变空），在剩下的为空的盒子中选择 k ( k=2 | k=3 )个，可以将球分成 k 组放入这 k 个盒子中，直到第 i 种颜色的球全部放入第 i 个盒子中。问每次取出的球的个数和的最小值为多少？
思路：可以发现每次取出的球个数是相同的，当放入 3 个盒子中时会更优。所以一开始我想，是不是每次取出最大的两个放入相应的盒子中，其他的作为一组放入一个盒子中，再不断的将该盒子中的球放入相应位置就可以了呢？
很可惜这样是不对的，这样每次分成的三组没法保证其再往下分的结果是最小的，也有可能是每组中的球都是混合颜色的时候才最优。
我们可以反向思考，开始的时候，第 i 种颜色的球全都在第 i 个盒子中，然后每次取出 3 个将其合并，直到合并成一组。很明显，每次取最小的 3 个数时结果最优。不知道你在做这个题的时候有没有想到哈夫曼树，哈夫曼树是每次取两个最小值合成一个新值，然后再在所有的数中取两个最小的……直到全部取完。不同的是哈夫曼树是每次取 2 个数，这个题是 3 个。
具体实现：哈夫曼树就是对于加入的数不断的维护数组每次可以取最小的几个树，所以可以用优先队列实现。
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 200005
typedef long long ll;
using namespace std;
priority_queue<ll, vector<ll>, greater<ll> > Q;
int main()
{
	int n,a[maxn];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		Q.push(a[i]);
	}
	if (n%2==0)//如果n为偶数，一次合并三个压入一个，相当于减少两个。合并到最后只剩两个，不满足while的循环条件，所以补个零。
		Q.push(0);
	ll ans = 0;
	while (Q.size() > 2)
	{
		ll sum = 0;
		//依次弹出三个最大数，用sum记录最大数的和，然后更新ans,压入三个数的和（哈夫曼树的实现原理）
		sum += Q.top();
		Q.pop();
		sum += Q.top();
		Q.pop();
		sum += Q.top();
		Q.pop();
		Q.push(sum);
		ans += sum;
	}
	printf("%lld\n", ans);
	return 0;
}
