#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int dp[1001][1001];
int twoeggdrop(int n)
{
    dp[0][0] = dp[1][0] = 0;
    for (int i = 0; i <= n;++i)
    {
        dp[0][i] = i;
    }
    for (int j = 1)
}
int main()
{
    int n;
    cin >> n;
    return 0;
}
