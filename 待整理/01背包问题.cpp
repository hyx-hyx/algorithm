#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n, w, weight[101], p[101], ans = 0;
    cin >> n >> w;
    int dp[10001] = { 0 };
    for (int i = 1; i <= n; ++i)
        cin >> weight[i] >> p[i];
    int i;
    for (i = 1; i <= n; ++i)
    {
        int j;
        for (j = w; j>=weight[i]; ++j)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + p[i]);
            ans = max(ans, dp[j]);
        }
    }
    cout << ans << endl;
    return 0;
}