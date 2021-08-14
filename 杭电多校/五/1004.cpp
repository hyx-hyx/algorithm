/*
题目链接:https://vjudge.net/problem/HDU-7015
定义$F[i,j]$表示字符串$S$中分别以i,j为左端点的两个子串满足k-匹配的最大长度。
换句话说,$F[i,j]$等于使得$S[i,i+L-1]$与$S[j,j+L-1]$满足k-匹配的最大$L$。
考虑如何计算所有的$F[i,j](1\le{i}<j\le{n})$
* 我们枚举两个子串的左端点之差$d(d\in[1,n-1])$
* 对于每一个 ，利用k-匹配的单调性，通过双指针，我们可以在线性时间内计算出所有的$F[i,i+d](1\leq{i}\leq{n-d})$
* 因此，我们可以用 的时间复杂度计算出所有的$F[i,j]$
考虑如何计算串S的所有分割情况下的答案
定义$t(2\leq{t}\leq{n})$分割是将$S$分为$A=S[1,t-1]$和$B=S[t,n]$
对于$t$分割，不难发现，我们要统计的答案为$\sum_{i=1}^{t-1}$$\sum_{j=t}^{n}G[i,j]$，其中$G[i,j]=min(F[i,j],t-i)$
* 不妨从大到小枚举t，过程中维护G对答案的贡献
* 注意到$G[i,j]$的值不超过$t-i$。因此可以对每个$i$维护一个$count$数组来对有贡献的 计数。换句话说，$count_i[x]$表示${G[i,j]|2\leq{j}\leq{n}}$中此时对答案有贡献且值为x的个数
* 同时我们对每个$i$再维护一个$max_i$ 表示此时 中对答案有贡献的最大值。对于t的每次减小，我们通过维护$count_i$数组和$\max_i$，来计算答案的变化。
* 注意到过程中$G[i,j]\leq{t-i}$ ，因而 在单调减少。而每次新增产生贡献的$G[i,j]$的数量为
且值也不超过$t-i$。因此整个过程的时间复杂度是$O(n^2)$
综上所述，整个算法的时间复杂度为$O(n^2)$
*/
#include<bits/stdc++.h>
#define dd(x) cerr<<#x<<" = "<<x<<" "
#define de(x) cerr<<#x<<" = "<<x<<endl
#define de_arr(a,s,t) cout<<#a<<": ";for (int z=(s);z<=(t);++z)cout<<a[z]<<" ";cout<<endl;
#define sz(x) int(x.size())
#define All(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const double eps=1e-8;
const int mod=1e9+7;
inline int sign(double x){return (x>eps)-(x<-eps);}
inline int add(int a,int b){a+=b;return a<0?a+mod:a>=mod?a-mod:a;}
inline int mul(ll a,ll b){return a*b%mod;}
const int maxn=5e3+10,INF=0x3f3f3f3f;
char s[maxn];
int f[maxn][maxn],cnt[maxn][maxn],pt[maxn];
ll ANS[maxn];
void calc_f(int n,int k){
    for (int st=2;st<=n;++st){
        int dif=0;
        for (int i=1,j=st,len=-1; j<=n; ++i,++j,--len){
            while (i+len+1<=n&&j+len+1<=n&&dif<=k){
                len++; 
                dif+=s[i+len]!=s[j+len];
            }
            f[i][j]=len+(dif<=k);
            dif-=s[i]!=s[j];
        }
    }
}
void solve(int n){
    for (int i=0;i<=n;++i){
        pt[i]=n/2+1;
        for (int j=0;j<=n;++j)
            cnt[i][j]=0;
    }
    ll ans=0;
    for (int j=n;j>1;--j){
        //update
        for (int i=1;i<j;++i)
            while (pt[i]>j-i){
                ans-=cnt[i][pt[i]];
                cnt[i][pt[i]-1]+=cnt[i][pt[i]];
                pt[i]--;
            }
        //add
        for (int i=1;i<j;++i){
            int len=min(f[i][j],j-i);
            cnt[i][len]++;
            ans+=len;
        }
        ANS[j]=ans;
        //delete
        while (pt[j-1]>=0){
            ans-=ll(cnt[j-1][pt[j-1]])*pt[j-1];
            pt[j-1]--;
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while (T--){
        int n,k;
        scanf("%d%d%s",&n,&k,s+1);
        calc_f(n,k);
        solve(n);
        for (int i=2;i<=n;++i)
            printf("%d\n",ANS[i]);
    }
    return 0;
}