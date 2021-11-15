#include<cstdio>
#define MAXN 1005
//prime存储质数，s[i]表示i的约数和，psum为预处理的中间数组。
int s[MAXN],prime[MAXN],psum[MAXN],pn;
bool vis[MAXN];
void sieve(int n)
{
	s[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			prime[++pn]=i;
			psum[i]=s[i]=i+1;
		}
		for(int j=1;j<=pn&&i*prime[j]<=n;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				psum[i*prime[j]]=psum[i]*prime[j]+1;
				s[i*prime[j]]=s[i]/psum[i]*psum[i*prime[j]];
				break;
			}
			s[i*prime[j]]=s[i]*(prime[j]+1);
			psum[i*prime[j]]=1+prime[j];
		}
	}	
}
int main()
{
	
}
