#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll fastpower(ll base,ll power)
{
    ll res=1;
    while(power)
    {
        if(power&1)
            res=res*base;
        base*=base;
        power>>=1;
    }
    return res;
}
int main()
{
    cout<<fastpower(2,10)<<endl;
    return 0;
}