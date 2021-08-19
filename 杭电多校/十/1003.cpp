#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<vector<int> > dp;
void slove(int n)
{
    int m = 0;
    dp.assign(n+1,vector<int>((n*(n-1)/2+10),0));
    dp[0][0] = 1; dp[1][0] = 1;
    for(int i = 2; i<=n; i++)
    {
        for(int k = 0; k<i; k++)
        {
            for(int j = 0; j<=k*( k-1 )/2; j++)
            {
                if(dp[k][j])
                {
                    m = j+( i-k )*k;
                    dp[i][m] = 1;
                }
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {    
        int n;
        cin>>n;
        slove(n);
        for(int i = 0; i<=n*( n-1 )/2; i++)
        {
            if(dp[n][i])
                printf(i==0 ? "%d" : " %d",i);
        }
        printf("\n");
    }
    return 0;
}
