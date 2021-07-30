/*
F-Just a Joke
题意
博弈游戏，给一个无环图，每次可以删除一条边或者一个连通分量。

解析
由于无环连通，因此k个点的连通分量必须是k-1条边，当我们删除点的时候减少的边数和点数为2k-1。
我们有两种操作，都是减少奇数个元素。
1.减少一条边
2.减少一个连通分量
我们最开始的元素总数为(n+m)=k(n+m)=k，假设A先手，使得K减去一个奇数，变为一个偶数，随后B出手，使得这个偶数又变为奇数。因此每一轮次操作后，结果的奇偶性不变，而操作后元素为0才算胜利，因此只要判断元素总和的奇偶性即可。
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    cout << ((n + m) & 1 ? "Alice" : "Bob" )<< endl;
    return 0;
}
