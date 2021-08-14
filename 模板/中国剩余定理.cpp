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
ll Sunzi(ll *m,ll *a,int len)
{
    ll lcm=1;
    ll ans=0;
    for(int i=0;i<len;++i)
    {
        ll k0,ki;
        ll d=ext_gcd(lcm,m[i],k0,ki);
        if((a[i]-ans)%d!=0)
            return -1;
        else
        {
            ll t=m[i]/d;
            k0=(k0*(a[i]-ans)/d%t+t)%t;
            ans=k0*lcm+ans;
            lcm=lcm/d*m[i];
        }
    }
    return ans;
}
