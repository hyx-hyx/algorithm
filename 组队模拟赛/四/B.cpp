#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
#define maxn 2020
using namespace std;
int c[maxn],w[maxn],f[50050];
int main()
{
    int n,m,v;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&m,&v);
        for(int i = 1; i <= m; ++i)
            scanf("%d%d",&c[i],&w[i]);
        memset(f,0,sizeof(f));
        for(int i = 1; i <= v; ++i)
            f[i] = -0x3f3f3f3f;
        for(int i = 1; i <= m; ++i)
            for(int j = c[i]; j <= v; ++j)
                f[j] = max(f[j],f[j - c[i]] + w[i]);
            printf("%d\n",f[v]);
    }
    return 0;
}