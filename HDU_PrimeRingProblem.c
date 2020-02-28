#include<stdio.h>
#include<math.h>
void dfs(int  step);
void prime(int max);
int primearr[40],n,output[40],book[21];
int main()
{
	scanf("%d",&n);
	if(n==1)
		printf("1");
	else
	{
		output[0]=1;
		primearr[4]=1;
		prime(n*2);
		dfs(0);
	}
	return 0;
}
void dfs(int step)
{
	int i,j;
	if(step==n-1&&output[n-1]!=0&&!primearr[output[n-1]+output[0]])
	{
		for(j=0;j<n;++j)
			printf("%d ",output[j]);
		printf("\n");
		return ;
	}
	for(i=2;i<=n;i++)
	{
		if(book[i]==0&&!primearr[i+output[step]])
		{
			book[i]=1;
			output[step+1]=i;
			dfs(step+1);
			book[i]=0;
		}
	}
}
void prime(int max)
{
	int i,j;
	for(i=3;i<max/2;++i)
	{
		for(j=2;j<i;++j)
		if((i%j))
			break;
		if(j<i)
		for(j=2;i*j<max;++j)
			primearr[i*j]=1;
	}		
}