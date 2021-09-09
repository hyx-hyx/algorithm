#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
vector<int> nextval(maxn);
void getNext(string s,vector<int>& nextval)
{
    nextval[0] = -1;
    int i = 0,j = -1;
    while(i < s.size())
    {
        if(j == -1 || s[i] == s[j])
            nextval[++i] = ++j;
        else
            j = nextval[j];
    }
}
int KMP(string text,string p)
{
    int i = 0,j = 0;
    while(i <= text.size())
    {
        if(j == -1 || text[i] == p[j])
        {
            i++;
            j++;
        }
        else
            j = nextval[j];
        if(j == p.size())
            return i - p.size();
    }
    return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        string p = "114514";
        nextval.assign(maxn,0);
        getNext(p,nextval);
        if(KMP(s,p) == -1)
            cout << "Abuchulaile" << endl;
        else
            cout << "AAAAAA" << endl;
    }
	return 0;
}