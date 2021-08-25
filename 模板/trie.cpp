#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
//========================================================
const int maxn=5000005;//不同节点的不同字符的数量，一般取字符串的个数乘以长度。
int nexti[maxn][26],cnt;
void init()
{
    memset(nexti,0,sizeof(nexti));
    cnt=1;
}
void insert(const string &s)
{
    int cur=1;
    for(int i=0;i<s.size();++i)
    {
        char c=s[i];
        if(!nexti[cur][c-'a'])
            nexti[cur][c-'a']=++cnt;
        cur=nexti[cur][c-'a'];
    }
    //countnum[cur]++;    记录每个节点的子节点数量
}
bool find_prefix(const string &s)
{
    int cur=1;
    for(int i=0;i<s.size();++i)
    {
        char c=s[i];
        if(!nexti[cur][c-'a'])
            return false;
        cur=nexti[cur][c-'a'];
    }
}
//====================================================================
int main()
{
    return 0;
}