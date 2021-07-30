int visit[maxn];  
void Prime()
{
    mem(visit,0);           //初始化都是素数
    visit[0] = visit[1] = 1;  //0 和 1不是素数
    for (int i = 2; i <= maxn; i++) 
    {
        if (!visit[i]) 
        {         //如果i是素数，让i的所有倍数都不是素数
            for (int j = i*i; j <= maxn; j += i) 
                visit[j] = 1;
        }
    }
}