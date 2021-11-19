//eps:误差，此时求最大值，求最小值将小于改成大于
while(fabs(r - l) > eps)
{
    mid = (l + r) / 2;
    double fl = f(mid - eps),fr = f(mid + eps);
    if(fl < fr)   //求最大值，求最小值改成大于
        l = mid;
    else
        r = mid;
}
//整数逼近
ll three_div(ll l,ll r)
{
	ll lmid,rmid;
	while(l < r - 1)
	{
		lmid = (l + r) >> 1;
		rmid = (lmid + r) >> 1;
		if(f(lmid) > f(rmid))l = lmid;
		else r = rmid;
	}
	return r;
}