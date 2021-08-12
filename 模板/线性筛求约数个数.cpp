int d[MAXN],prime[MAXN],num[MAXN],vis[MAXN],pn;
void sieve(int n)
{
	d[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			prime[++pn]=i;
			num[i]=1;
			d[i]=2;
		}
		for(int j=1;j<=pn&&i*prime[j]<=n;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				num[i*prime[j]]=num[i]+1;
				d[i*prime[j]]=d[i]/(num[i]+1)*(num[i]+2);
				break;
			}
			d[i*prime[j]]=d[i]*2;
			num[i*prime[j]]=1;
		}
	}
	
}
