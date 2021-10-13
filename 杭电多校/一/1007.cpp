#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
ll gcd(ll a,ll b)
{
    return b > 0 ? gcd(b,a % b) : a;
}
// 修改版的BSGS，额外带一个系数
ll BSGS(ll a,ll b,ll m,ll k = 1)
{
    static unordered_map<ll,ll> hs;
    hs.clear();
    ll cur = 1,t = sqrt(m) + 1;
    for(int B = 1; B <= t; ++B)
    {
        (cur *= a) %= m;
        hs[b * cur % m] = B; // 哈希表中存B的值
    }
    ll now = cur * k % m;
    for(int A = 1; A <= t; ++A)
    {
        auto it = hs.find(now);
        if(it != hs.end()) return A * t - it->second;
        (now *= cur) %= m;
    }
    return -INF; // 这里因为要多次加1，要返回更小的负数
}
ll exBSGS(ll a,ll b,ll m,ll k = 1)
{
    ll A = a %= m,B = b %= m,M = m;
    if(b == 1) return 0;
    ll cur = 1 % m;
    for(int i = 0;; i++)
    {
        if(cur == B) return i;
        cur = cur * A % M;
        ll d = gcd(a,m);
        if(b % d) return -INF;
        if(d == 1) return BSGS(a,b,m,k * a % m) + i + 1;
        k = k * a / d % m,b /= d,m /= d; // 相当于在递归求解exBSGS(a, b / d, m / d, k * a / d % m)
    }
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		ll n,x;
		cin >> n >> x;
        if(x == 0)
            cout << 1 << endl;
        else
            if(x == 1)
                cout << 0 << endl;
            else
            {
                ll p1 = (n * x % mod - (n - 1))%mod;
                ll p2 = (n * x % mod + (n- 1))%mod;
                ll t1 = exBSGS(n - 1,p1,mod);
                if(t1&1||t1==-INF)
                    t1 = -1;
                ll t2 = exBSGS(n - 1,p2,mod);
                if(t2%2==0||t2==-INF)
                    t2 = -1;
                if(t1 == -1)
                    if(t2 == -1)
                        cout << -1 << endl;
                    else
                        cout << t2 << endl;
                else
                    if(t2 == -1)
                        cout << t1 << endl;
                    else
                        cout << min(t1,t2) << endl;
            }
	}
	return 0;
}
