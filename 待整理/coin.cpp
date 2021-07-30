#include<iostream>
#include <vector>
using namespace std;
int k;
int acountcoin(int acount, int a[],vector<int> dp)
{
    int mincoin = 10000, temp,index;
    if (acount == 0)
        return 0;
    for (int i = 0; i < k; ++i)
    {
        index = acount - a[i];
        if (index >= 0)
        {
            if (dp[index] < 0)
                temp = acountcoin(index, a, dp) + 1;
            else
                temp = dp[index] + 1;
        }
        else
            return 100000;
        if (mincoin > temp)
            mincoin = temp;
    }
    dp[acount] = mincoin;
    return mincoin;
}
int main()
{
    int coins[100], acount;
    vector<int> dp(1000, -1);
    cin >> acount;
    cin >> k;
    for (int i = 0; i < k; ++i)
        cin >> coins[i];
    cout << acountcoin(acount, coins,dp);
    return 0;
}
