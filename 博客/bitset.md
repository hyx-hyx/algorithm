## bitset类
### 头文件
```cpp
#include<bitset>
```
### 定义
```cpp
bitset<N> bset;//N为bset的位数
```
### 成员函数
* bitset <N> & operator &= (const bitset <N> & rhs);  //和另一个 bitset 对象进行与操作
* bitset <N> & operator |= (const bitset <N> & rhs);  //和另一个 bitset 对象进行或操作
* bitset <N> & operator ^= (const bitset <N> & rhs);  //和另一个 bitset 对象进行异或操作
* bitset <N> & operator <<= (size_t num);  //左移 num 位
* bitset <N> & operator >>= (size_t num);  //右移 num 位
* bitset <N> & set();  //将所有位全部设成 1
* bitset <N> & set(size_t pos, bool val = true);  //将第 pos 位设为 val
* bitset <N> & reset();  //将所有位全部设成0
* bitset <N> & reset (size_t pos);  //将第 pos 位设成 0
* bitset <N> & flip();  //将所有位翻转（0变成1，1变成0）
* bitset <N> & flip(size_t pos);  //翻转第 pos 位
* reference operator[] (size_t pos);  //返回对第 pos 位的引用
* bool operator[] (size_t pos) const;  //返回第 pos 位的值
* reference at(size_t pos);  //返回对第 pos 位的引用
* bool at (size_t pos) const;  //返回第 pos 位的值
* unsigned long to_ulong() const;  //将对象中的0、1串转换成整数
* string to_string () const;  //将对象中的0、1串转换成字符串（Visual Studio 支持，Dev C++ 不支持）
* size_t count() const;  //计算 1 的个数size_t size () const;  //返回总位数
* bool operator == (const bitset <N> & rhs) const;
* bool operator != (const bitset <N> & rhs) const;
* bool test(size_t pos) const;  //测试第 pos 位是否为 1
* bool any() const;  //判断是否有某位为1
* bool none() const;  //判断是否全部为0
* bitset <N> operator << (size_t pos) const;  //返回左移 pos 位后的结果
* bitset <N> operator >> (size_t pos) const;  //返回右移 pos 位后的结果
* bitset <N> operator ~ ();  //返回取反后的结果
* bitset <N> operator & (const bitset <N> & rhs) const;  //返回和另一个
* bitset 对象 rhs 进行与运算的结果
* bitset <N> operator | (const bitset <N> & rhs) const;  //返回和另一个
* bitset 对象 rhs 进行或运算的结果
* bitset <N> operator ^ (const bitset <N> & rhs) const;  //返回和另一个
* bitset 对象 rhs 进行异或运算的结果
### 用途
主要对动态规划进行优化转移

**HDU1466**

平面上有n条直线，且无三线共点，问这些直线能有多少种不同交点数。

比如,如果n=2,则可能的交点数量为0(平行)或者1(不平行)。

Input

输入数据包含多个测试实例,每个测试实例占一行,每行包含一个正整数n（n<=20）,n表示直线的数量.

Output
每个测试实例对应一行输出，从小到大列出所有相交方案，其中每个数为可能的交点数,每行的整数之间用一个空格隔开。

Sample Input

2

3

Sample Output

0 1

0 2 3
### 分析

* 首先n条线段，全部平行，0；
* n-1条线段平行，n-1；
* n-2条线段平行，2*(n-2)+2条线段的交点数；
* n-3条线段平行，3*(n-3)+3条线段的交点数；
* n-4条线段平行，4*(n-4)+4条线段的交点数；以此类推！
* 上面“+2条线段的交点数；”这个部分需要注意！恰好是我们可以记录下来的前面的数据，所以我们得先打个表！打表记录每一种情况，然后后面再来用到前面的数据.
* 所以,采取dp[i][j]的方式来记录，注意dp[i][j]只是状态表示，表示n为i的时候j如果是可能的交点数则dp[i][j]=1,否则dp[i][j]=0.

#### 朴素动态转移
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	while(cin>>n)
	{
		int dp[21][191] = {0};
		for(int i = 1; i<=n; ++i)
			dp[i][0] = 1;
		for(int i = 2; i<=n; ++i)
			for(int j = 1; j<i; ++j)
				for(int k = 0; k<=j*( j-1 )/2; ++k)
					if(dp[j][k])
						dp[i][j*( i-j )+k] = 1;
		cout<<0<<" ";
		for(int i = 1; i<n*( n-1 )/2; ++i)
			if(dp[n][i])
				cout<<i<<" ";
		cout<<n* ( n-1 )/2<<endl;
	}
	return 0;
}
```
#### 用bitset优化
```cpp
//头文件 #include<bitset>
//定义 bitset<位数> bset;
//bset[j]得到第j位的值
//使用bitset优化
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
#include<bitset>
using namespace std;
typedef long long ll;
const int maxn = 191;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	bitset<maxn> dp[21];
	while(cin >> n)
	{
		for(int i = 1; i <= 20; ++i)
			dp[i][0] = 1;
		for(int i = 2; i <= n; ++i)
			for(int j = 1; j < i; ++j)
				dp[i] |= (dp[j] << (j * (i - j)));
		cout << 0 << " ";
		for(int i = 1; i < n * (n - 1) / 2; ++i)
			if(dp[n][i])
				cout << i << " ";
		cout << n * (n - 1) / 2 << endl;
	}
	return 0;
}
```
