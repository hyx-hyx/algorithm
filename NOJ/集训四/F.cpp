#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
const int maxn = 20005;
using namespace std;
int fa[maxn],ranki[maxn];
void init(int n)
{
    for(int i = 0; i <= n; ++i)
    {
        fa[i] = i;
        ranki[i] = 1;
    }
}
int find(int x)
{
    return fa[x] == x ? fa[x] : (fa[x] = find(fa[x]));
}
void merge(int i,int j)
{
    int x = find(i);
    int y = find(j);
    if(x == y)
        return;
    if(ranki[x] > ranki[y])
        fa[x] = y;
    else
        fa[y] = x;
    if(ranki[x] == ranki[y] && x != y)
        ranki[y]++;
}
int main()
{
    int N,M,a,b,q;
    scanf("%d%d",&N,&M);
    init(N);
    For(i,0,M)
        scanf("%d%d",&a,&b),merge(a,b);
    scanf("%d",&q);
    For(i,0,q)
    {
        int c,d;
        scanf("%d%d",&c,&d);
        if(find(c) == find(d))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}