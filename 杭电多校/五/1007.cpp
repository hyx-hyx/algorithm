#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int P=1e9+7;
ll n,ret1,ret2,ret3,q;
int T;

void file_put() {
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
}

ll Pow(ll x,ll k) {
    ll ret=1;
    for (; k; k>>=1,x=x*x%P) if (k&1) ret=ret*x%P;
    return ret;
}

int main() {
    scanf("%d",&T);
    
    while (T--) {
        scanf("%lld",&n),n%=P,q=Pow(24,P-2);
        ret1=n*n%P*(n+1)%P*(n+1)%P*(1+2*n)%P*Pow(12,P-2)%P*n%P*n%P;
        ret2=(-2 + n + n*n%P)%P*(((-6 + 2*n%P)%P + 3*n*n%P)%P + n*n%P*n%P)%P*Pow(6,P-2)%P;
        ret3=n*(n+1)%P*(2*n+1)%P*Pow(12,P-2)%P*n%P*(n+1)%P;
        printf("%lld\n",((ret3+ret2)%P+P)%P);
        printf("%lld\n",ret1);
    }
    return 0;
}
/*
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
const int mod = 1e9 + 7;
using namespace std;
//求取 (a/b)%p 等同于 求取 a∗(b的逆元)%p。
ll pow(ll a,ll n,ll p)    //快速幂 a^n % p
{
	ll ans = 1;
	while(n)
	{
		if(n & 1) ans = ans * a % p;
		a = a * a % p;
		n >>= 1;
	}
	return ans;
}

ll niyuan(ll a,ll p)   //费马小定理求逆元
{
	return pow(a,p - 2,p);
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		ll n;
		cin >> n;
		n %= mod;
		ll ret1 = (n + 1) * (n + 1) % mod * n % mod * n % mod * niyuan(4,mod) % mod;
		ll ret2 = (n + 2) * (n - 1) % mod * niyuan(2,mod) % mod;
		ll ret3 = n * (n + 1) % mod * (n + 1) % mod * ((2 * n%mod + 1)%mod) % mod * niyuan(6,mod) % mod;
		ll ret4 = n * n % mod * (n + 1) % mod * (n + 1) % mod * niyuan(4,mod) % mod;
		ll result = (ret1 + ret2 * ((ret3 - ret4)+mod) % mod) % mod;
		cout << result << endl;
		ll ret5 = (n + 1) * n % mod * niyuan(2,mod) % mod;
		ll ret6 = n * (n + 1) % mod * (2 * n % mod + 1) % mod * niyuan(6,mod) % mod;
		ll ans = n * n % mod * ret5 % mod * ret6 % mod;
		cout << ans << endl;
	}
	return 0;
}

*/
