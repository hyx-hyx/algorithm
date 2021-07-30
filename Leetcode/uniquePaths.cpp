#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int dp[100][100], m, n;
    cin>>m>>n;
    dp[1][0] = 1;
    dp[0][1] = 1;
    dp[0][0] = 1;
    for (int i = 0; i < m;++i)
    {
        for (int j = 0; j < n;++j)
        {
            if(!i)
            {
                if(!j)
                    continue;
                else
                    dp[i][j] = dp[i][j-1];
            }
            else
            {
                if(!j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[m-1][n-1] << endl;
    return 0;
}