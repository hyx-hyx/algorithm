#define maxn 
int prime[maxn];
int visit[maxn];
void Prime(){
    memset(visit,0,sizeof(visit));
    memset(prime, 0,sizeof(prime));
    for (int i = 2;i <= maxn; i++) 
    {
        if (!visit[i])
            prime[++prime[0]] = i;      
        for (int j = 1; j <=prime[0] && i*prime[j] <= maxn; j++)
        {
            visit[i*prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
//======================================
//欧拉筛求质因子个数
#define maxn 
int prime[maxn];
int visit[maxn];
int num[maxn];//对应下标的质因子个数，不包括1
void Prime(){
    memset(visit,0,sizeof(visit));
    memset(prime, 0,sizeof(prime));
    for (int i = 2;i <= maxn; i++) 
    {
        if (!visit[i])
            prime[++prime[0]] = i,num[i]=1;    
        for (int j = 1; j <=prime[0] && i*prime[j] <= maxn; j++)
        {
            visit[i*prime[j]] = 1;
            num[i*prime[j]]=num[i]+1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
