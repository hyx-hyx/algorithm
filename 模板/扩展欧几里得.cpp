ll ext_gcd(ll a,ll b,ll &x,ll &y)
{
    ll d =a;
    if(!b)
        x=1,y=0;
    else
    {
        d=ext_gcd(b,a%b,y,x);
        y-=a/b*x;
    }
    return d;
}
