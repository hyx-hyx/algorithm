#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n, m,v[26],p[26],dp[26][30001],ans=0;
    cin >> n >> m;
    for (int i = 0; i < m;++i)
        cin >> v[i] >> p[i];
    for(int i = 1; i <=m;++i)
    {
        for (int j = n; j > v[i];--j)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + v[i] * p[i]);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}