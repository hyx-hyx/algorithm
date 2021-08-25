#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int maxn=1e9;
const int N=3;
//f[N]：可改变当前状态的方式，N为方式的种类，f[N]要在getsg之前先预处理
//sg[]：0~n的SG函数值
//s[]:为x后继状态的集合
int f[N],sg[maxn],s[maxn];
void getsg(int n)
{
    memset(sg,0,sizeof(sg));
    //因为sg[0]始终等于0，所以i从1开始
    for(int i=1;i<=n;++i)
    {
        //每一次都要将上一状态的后继集合重置
        memset(s,0,sizeof(s));
        for(int j=0;f[j]<=i&&j<=N;++j)
            s[sg[i-f[j]]]=1;   //将后继状态的sg函数值进行标记
        int j;
        for(int j=0;s[j];++j);  //查询当前后继状态sg值中最小的非0值
            sg[i]=j;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}