#include <string>
#include <iostream>
using namespace std;
const int maxn = 100000;
int nextval[maxn][26];
int cnt, countnum[maxn] = { 0 };
void init()
{
    memset(nextval, 0, sizeof(nextval));
    cnt = 1;
}
void insert(const string& s)
{
    int cur = 1;
    for (int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        if (!nextval[cur][c - 'a'])
            nextval[cur][c - 'a'] = ++cnt;
        cur = nextval[cur][c - 'a'];
        countnum[cur]++;
    }
}
void ask(string s)
{
    int cur = 1;
    for (int i = 0; i < s.size(); ++i)
    {
        if (countnum[cur] == 1) break;
        int k = s[i] - 'a';
        printf("%c", s[i]);
        cur = nextval[cur][k];   
    }
}
int main()
{
    init();
    string s, table[1005], result;
    int n = 0;
    int cnt = 0;
    while(cin>>s)
    {
        insert(s);
        table[cnt++]=s;
    }
    for (int i = 0; i < cnt; ++i)
    {
        cout << table[i]<<" ";
        ask(table[i]);
        cout << endl;
    }
    return 0;
}