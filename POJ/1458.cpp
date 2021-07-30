#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int dp[100][100]={0};
    string a, b;
    while(cin>>a>>b)
    {
        int i, j;
        for (i = 1; i <=a.size(); ++i)
        {
            for (j = 1; j <= b.size(); ++j)
            {
                if (a[i-1]==b[j-1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        cout << dp[i-1][j-1] << endl;
    }
    return 0;
}