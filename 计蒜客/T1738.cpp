#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n,m,x1,x2,y1,y2;
    cin>>n>>m;
    int result[1001][1001]={0};
    for (int i = 0; i <m; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int k = x1; k <= x2;++k)
        {
            for (int a = y1; a <= y2;++a)
            {
                result[k][a]++;
            }
        }
    }
    for (int i = 1;i<=n;++i)
    {
        for (int j = 1; j <=n;++i)
        {
            cout << result[i][j];
        }
    }
    return 0;
}