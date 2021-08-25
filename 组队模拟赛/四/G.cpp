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
typedef long long ll;
const int maxn = 5000005;
int nexti[maxn][26],cnt;
int countnum[maxn];
void init()
{
    memset(nexti,0,sizeof(nexti));
    cnt = 1;
}
void insert(const string& s)
{
    int cur = 1;
    for(int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        if(!nexti[cur][c - 'a'])
            nexti[cur][c - 'a'] = ++cnt;
        cur = nexti[cur][c - 'a'];
        countnum[cur]++;
    }
}
int find_prefix(const string& s)
{
    int cur = 1;
    for(int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        if(!nexti[cur][c - 'a'])
            return 0;
        cur = nexti[cur][c - 'a'];
    }
    return countnum[cur];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,m;
    init();
    cin >> n >> m;
    string str;
    for(int i = 0; i < n; ++i)
        cin >> str,insert(str);
    for(int i = 0; i < m; ++i)
    {
        cin >> str;
        cout << find_prefix(str) << endl;
    }
	return 0;
}
