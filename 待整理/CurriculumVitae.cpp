#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int a[100],n,dp[100],ans=0;
    cin >> n;
    for (int i = 0; i < n;++i)
        cin >> a[i];
    for (int i = 0;i<n;++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i;++j)
        {
            if(a[i]>=a[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}

