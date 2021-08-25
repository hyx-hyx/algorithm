#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
#define linf 99999999999999LL
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int n, K, l, r;
ll ans, mn = linf, f[100005];
int e[100005];
struct data {
    int num;
    ll v;
} q[100005];
int main() {
    // freopen("mowlawn.in","r",stdin);
    // freopen("mowlawn.out","w",stdout);
    n = read();
    K = read();
    for (int i = 1; i <= n; i++) e[i] = read(), ans += e[i];
    for (int i = 1; i <= n; i++) {
        f[i] = e[i] + q[l].v;
        while (q[r].v > f[i] && l <= r) r--;
        q[++r].v = f[i];
        q[r].num = i;
        while (q[l].num < i - K) l++;
    }
    for (int i = n - K; i <= n; i++) mn = min(mn, f[i]);
    printf("%I64d", ans - mn);
    system("pause");
    return 0;
}
