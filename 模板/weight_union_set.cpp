#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 10005
using namespace std;
int fa[maxn], value[maxn]={0};
void init(int n)
{
    for (int i = 0; i <=n; ++i)
        fa[i] = i;
}
int find(int x)
{
    if(x!=fa[x])
    {
        int t = fa[x];
        fa[x] = find(fa[x]);
        value[x] += value[t];
    }
    return fa[x];
}
void merge(int i, int j,int s)
{
    int x = find(i);
    int y = find(j);
    if(x!=y)
    {
        fa[x] = y;
        value[x] = -value[i] + value[j] + s;
    }
}
int main()
{
    return 0;
}