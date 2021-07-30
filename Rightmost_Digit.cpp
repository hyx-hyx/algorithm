#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
const int MOD = 1e5;
typedef long long LL;
using namespace std;
LL f(LL a,LL b)
{
    LL res=1;
    while(b!=0)
    {
        if(b%2==1) res=res*a%MOD;
        a=a*a%MOD;
        b/=2;
    }
    return res;
}
int main()
{
    int t;
    unsigned long long n;
    scanf("%d", &t);
    for (int i = 0; i < t;++i)
    {
        scanf("%lld", &n);
        printf("%lld\n", ((unsigned long long)f(n, n))%10);
    }
    return 0;
}