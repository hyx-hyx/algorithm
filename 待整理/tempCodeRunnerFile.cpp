#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n, v, c[1001],weight[1001], ans = 0,t=0;
    cin >> t;
    for (int a = 0; a < t;++a)
    {
        scanf("%d%d", &n, &v);
        int dp[50001] = { 0 };
        for (int i = 0; i < n;++i)
            cin >> weight[i];
        for (int i = 0; i < n;++i)
        {
            int temp;
            scanf("%d", &temp);
            if(temp==-1)
                c[i] = 1004;
            else
                c[i] = temp;
        }
        int i;
        for (i = 0; i < n; ++i)
        {
            int j;
            for (j = v; j >=1; --j)
            {
                for (int k = 0; k <= min(c[i], j); ++k)
                    dp[j] = max(dp[j], dp[j - k] + k * weight[i]);
                ans = max(ans, dp[j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}