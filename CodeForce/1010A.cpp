#include<bits/stdc++.h>
#define x first
#define y second
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<long,long> PLL;
typedef pair<char,char> PCC;
typedef long long LL;
const int N=2020;
const int M=150;
const int INF=0x3f3f3f3f;
const int MOD=998244353;
int a[N],b[N];
int n;
double m;
bool check(double res){
    double sum=res+m;
    for(int i=0;i<n-1;i++){
        sum-=(sum/a[i]);
        sum-=(sum/b[i+1]);
    }
    sum-=(sum/a[n-1]);
    sum-=(sum/b[0]);
    return sum>=m;
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    double l=0,r=1000000000;
    double eps=2e-7;
    while(l+eps<r){
        double mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }
    double res=l;
    for(int i=0;i<n-1;i++){
        res-=(res/a[i]);
        res-=(res/b[i+1]);
    }
    res-=(res/a[n-1]);
    res-=(res/b[0]);
    if(res>0) printf("%.10f\n",l);
    else printf("-1\n");
}
int main(){
    //IOS;
    solve();
    return 0;
}


//-------------------------------------------------------
//以下是自己写的未AC代码
// #define _CRT_SECURE_NO_WARNINGS
// #include<cstdio>
// #include<iostream>
// #include<vector>
// #include<string>
// #include<queue>
// using namespace std;
// int n, m, a[1000], b[1000];
// bool check(double mid)
// {
// 	double sum = mid + m;
// 	sum -= sum / a[0];
// 	for (int i = 1; i < n; ++i)
// 	{
// 		sum -= sum / b[i];
// 		sum -= sum / a[i];
// 	}
// 	sum -= sum / b[0];
// 	return sum >= m;
// }
// int main()
// {
// 	double eps = 2e-7;
// 	scanf("%d%d", &n, &m);
// 	for (int i = 0; i < n; ++i)
// 		scanf("%d", &a[i]);
// 	for (int i = 0; i < n; ++i)
// 		scanf("%d", &b[i]);
// 	double L = 0,r = 1e9;
// 	while (L+eps < r)
// 	{
// 		double mid = (L + r) / 2;
// 		if (check(mid))
// 			r = mid;
// 		else
// 			L = mid;
// 	}
// 	if (L+eps == r) 
// 	{
// 		printf("-1\n"); 
// 		return 0;
// 	}
// 	double ans = L;
// 	double sum=L;
// 	sum -= sum/a[0];
// 	for (int i = 1; i < n; ++i)
// 	{
// 		sum -= sum / b[i];
// 		sum -= sum / a[i];
// 	}
// 	sum -= sum / b[0];
// 	if (sum >= 0)
// 		printf("%.10f\n", ans);
// 	else
// 		printf("-1\n");
// 	return 0;
// }
