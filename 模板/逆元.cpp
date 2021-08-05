//求取 (a/b)%p 等同于 求取 a∗(b的逆元)%p。
ll pow(ll a, ll n, ll p)    //快速幂 a^n % p
{
    ll ans = 1;
    while(n)
    {
        if(n & 1) ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}

ll niyuan(ll a, ll p)   //费马小定理求逆元
{
    return pow(a, p - 2, p);
}