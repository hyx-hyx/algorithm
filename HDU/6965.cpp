//查找a的个数N，求2的N次幂
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define mod 1000000007
typedef long long ll;
using namespace std;
ll fastPower(ll base, ll power) {
    ll result = 1;
    while (power > 0)
    {
        if (power & 1)
            result = result * base % mod;
        power >>= 1;
        base = (base * base) % mod;
    }
    return result;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t)
    {
        int n;
        vector<int>flag(27, 0);
        scanf("%d", &n);
        getchar();
        char temp = ' ';
        int cnt = 0;
        int fail = 0;
        while (1)
        {
            char ch = getchar();
            if (ch == '\n')
                break;
            if (temp == ' ')
            {
                temp = ch;
                cnt++;
            }
            else
            {
                if (temp == ch && !fail)
                    cnt++;
                else
                    fail = 1;
            }
        }
        printf("%lld\n",fastPower(2, cnt - 1));
    }
    return 0;
}