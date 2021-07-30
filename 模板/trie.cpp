#include <bits/stdc++.h>
using namespace std;
const int maxn=5000005;
int next[maxn][26],cnt;
void init()
{
    memset(next,0,sizeof(next));
    cnt=1;
}
void insert(const string &s)
{
    int cur=1;
    for(auto c:s)
    if(!next[cur][c-'a'])
        next[cur][c-'a']=++cnt;
    cur=next[cur][c-'a'];
    //countnum[cur]++;    记录每个节点的子节点数量
}
bool find_prefix(const string &s)
{
    int cur=1;
    for(int i=0;i<s.size();++i)
    {
        char c=s[i];
        if(!next[cur][c-'a'])
            return false;
        cur=next[cur][c-'a'];
    }
}
int main()
{
    return 0;
}