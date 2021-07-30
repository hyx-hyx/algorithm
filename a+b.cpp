#include<iostream>
int main()
{
    int n,x;
	scanf("%d%d",&n,&x);
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        int temp;
        scanf("%d",&temp);
        if(i%2==0)
            ans+=temp-1;
        else   
            ans+=temp;
    }
    if(ans>x)
    printf("No\n");
    else
    printf("Yes\n");
	return 0;
}