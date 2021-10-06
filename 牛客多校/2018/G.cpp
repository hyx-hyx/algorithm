/*
题目描述
给定两个正整数 c,n，求一个数对 (a,b)，满足 1<=a,b<=n，且 gcd(a,b)=c
要求输出最大的 a,b,不存在则输出-1
1<=c,n<=10^9

解题思路
首先 a 和 b 一定都是 c 的倍数，如果 n<2c，那么选 a=b=c 最优
否则选 a=(n/c)*c , b=((n/c)-1)*c
思路：转化为a'=a/c,b'=b/c，a'*b'最大且a' b'互质
相邻的两个数互质！则a=a'*c,,b=b'*c，，a与b的最大公约数为c
需要注意a==b的情况和输出-1的情况
总结：相邻的两个数互质！a' b'互质，则a=a'*c,,b=b'*c，，a与b的最大公约数为c
*/
#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long ll;
using namespace std;
int main()
{
    int c,n;
    cin >> c >> n;
    if(c > n)
        cout << -1 << endl;
    else
    {
        if(n < 2 * c)
            cout << 1LL * c * c << endl;
        else
            cout << (ll)(n / c * c) * (((n / c) - 1) * c) << endl;
    }
	return 0;
}