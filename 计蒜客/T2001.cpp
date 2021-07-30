#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n,a[10001],b[10001],g[10001],k[10001],x,y,ans=-1;
    cin>> n;
    for (int i = 1; i <=n;++i)
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    cin >> x >> y;
    for (int i = 1; i <=n;++i)
    {
        if(a[i]<=x&&g[i]+a[i]>=x)
        {
            if(b[i]<=y&&k[i]+b[i]>=y)
                ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}