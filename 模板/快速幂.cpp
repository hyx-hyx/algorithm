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
//高精度快速幂
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    char n[100001];
    int x;
    cin >> x >> n;//x是底数，n是指数
    long long len = strlen(n),t = 0,i,ans = 1;
    for(i = 0; i < len; i++)t = (t * 10 + n[i] - '0') % (mod - 1);
    while(t > 0)
    {
        if(t & 1) ans = ans * x % mod;
        x = x * x % mod;
        t >>= 1;
    }
    cout << ans << endl;
}