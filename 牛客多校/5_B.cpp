#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define maxn 1005
#define ll long long
#define mod (ll)(1e9+7)
ll a[100005];
ll Pow(ll a, ll b) {
    a %= mod;
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans % mod;
}
ll Quk(ll a, ll b) {
    a %= mod;
    ll ans = 0;
    while (b)
    {
        if (b & 1)
            ans = (ans + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return ans % mod;
}
ll C(ll n, ll m) {
    return Quk(Quk(a[n], Pow(a[n - m], mod - 2)), Pow(a[m], mod - 2)) % mod;
}
int main()
{
    a[0] = a[1] = 1;
    for (ll i = 2; i <= 100000; i++)
        a[i] = Quk(a[i - 1], i);
    int n;
    double w[maxn],c,sumpre[maxn];
    scanf("%d%lf", &n,&c);
    for (int i = 0; i < n; ++i)
    	scanf("%lf", &w[i]);
    sort(w, w + n);
    sumpre[0] = w[0];
    for (int i = 1; i < n; ++i)
        sumpre[i] = sumpre[i - 1] + w[i];
    double sum = 2*c;
    for (int i = 1; i <=n-1; ++i)
    {
        double sum_w = 0;
        for(int j=min(i,n-i);j<=n-1;++j)
            sum_w += sumpre[j-1]+c;
        double tempc = C(n, i);
        sum+=tempc*sum_w;
    }
    int count = pow(2, n);
    printf("%lf", sum/count);
    return 0;
}
