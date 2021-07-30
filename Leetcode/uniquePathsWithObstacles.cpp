class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int dp[101][101],m,n;
        dp[0][0]=1;
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        for (int i = 0; i < m;++i)
        {
            for (int j = 0; j < n;++j)
            {
                if(obstacleGrid[i][j])
                {
                    dp[i][j]=0;
                    continue;
                }
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
        return dp[m-1][n-1];
        }
};